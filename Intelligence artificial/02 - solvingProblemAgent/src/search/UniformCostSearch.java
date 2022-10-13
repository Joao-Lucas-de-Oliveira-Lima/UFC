package src.search;

import java.util.ArrayList;

import src.graph.Map;
import src.graph.State;
import src.graph.Transition;
import src.searchStructures.Node;
import src.searchStructures.PriorityList;
import src.searchStructures.Solution;

public class UniformCostSearch{
    private PriorityList edge;
    private ArrayList<State> exploiters;

    public UniformCostSearch(){
        this.edge = new PriorityList();
        this.exploiters = new ArrayList<State>(); 
    }
    public Solution performSearch(Map map, String startingPoint, String destination){
        State startingPointState = map.get(startingPoint);
        State destinationState = map.get(destination);
        Solution solution = new Solution(0);
        if(startingPointState != null && destinationState != null){
            //Starting queue
            this.edge.add(new Node(null, startingPointState, 0));
            Node currentNode = recursiveSearch(destinationState, solution);
            if(currentNode != null){
                solution.getPath().add(currentNode.getState());
            }
            return solution;
        }
        return solution;
    }
    public Node recursiveSearch(State destinationState, Solution solution){
        if(!edge.isEmpty()){
           Node parentNode = edge.remove();
           if(parentNode.getState().equals(destinationState)){
                //Destination Found
                solution.getPath().add(parentNode.getState());
                solution.setCost(parentNode.getCost());
                return parentNode.getFather();
            }
            this.exploiters.add(parentNode.getState());
            for(Transition currentTransition: parentNode.getState().getAdjacentList()){
                Node childNode = new Node(parentNode, currentTransition.getNextCity(), 
                    currentTransition.getCost()+parentNode.getCost());
                Boolean isOnTheEdge = this.edge.contains(childNode);
                if(!checkExplorersList(childNode.getState()) && !isOnTheEdge){
                    edge.add(childNode);
                }else if(isOnTheEdge){
                    this.edge.swapNode(childNode);
                }
           }
           Node currentParent = recursiveSearch(destinationState, solution);
           if(currentParent != null){
                if(currentParent.getFather().getState().equals(parentNode.getState())){
                    solution.getPath().add(currentParent.getState());
                    return parentNode;
                }
           }
           return currentParent;
        }
        //There is no way
        return null;
    }
    public boolean checkExplorersList(State state){
        for(State currentState: this.exploiters){
            if(currentState.equals(state)){
                return true;
            }
        }
        return false;
    }
}

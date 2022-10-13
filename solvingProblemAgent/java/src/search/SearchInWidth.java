package src.search;

import java.util.Queue;

import src.graph.Map;
import src.graph.State;
import src.graph.Transition;
import src.searchStructures.Node;
import src.searchStructures.Solution;

import java.util.ArrayList;
import java.util.LinkedList;

public class SearchInWidth{
    private Queue<Node> edge;
    private ArrayList<State> exploiters;

    public SearchInWidth(){
        this.edge = new LinkedList<Node>();
        this.exploiters = new ArrayList<State>(); 
    }
    public Solution performSearch(Map map, String startingPoint, String destination){
        State startingPointState = map.get(startingPoint);
        State destinationState = map.get(destination);
        Solution solution = new Solution(0);
        if(startingPointState.equals(destinationState)){
            solution.getPath().add(startingPointState);
            return solution;
        }else{
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
    }
    public Node recursiveSearch(State destinationState, Solution solution){
        if(!edge.isEmpty()){
           Node parentNode = edge.poll();
           this.exploiters.add(parentNode.getState());
           for(Transition currentTransition: parentNode.getState().getAdjacentList()){
                Node childNode = new Node(parentNode, currentTransition.getNextCity(), 
                    currentTransition.getCost()+parentNode.getCost());
                if(!checkEdge(childNode.getState()) && !checkExplorersList(childNode.getState())){
                    if(childNode.getState().equals(destinationState)){
                        //Destination Found
                        solution.getPath().add(childNode.getState());
                        solution.setCost(childNode.getCost());
                        return childNode.getFather();
                    }
                    edge.add(childNode);
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
    public boolean checkEdge(State state){
        for(Node node: edge){
            if(node.getState().equals(state)){
                return true;
            }
        }
        return false;
    }
}

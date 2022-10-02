package src.model.searchInWidth;

import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;
import src.model.graph.Map;
import src.model.graph.State;
import src.model.validation.ValidateCityName;

public class SearchInWidth {
    private Queue<Node> edge;
    private ArrayList<State> exploiters;

    public SearchInWidth(){
        this.edge = new LinkedList<Node>();
        this.exploiters = new ArrayList<State>(); 
    }
    public Solution search(Map map, String startingPoint, String destination){
        ValidateCityName validateCityName = new ValidateCityName();
        //Validating states by the name
        int startingPointIndex = validateCityName.validate(map.getListOfStates(), startingPoint);
        int destinationIndex = validateCityName.validate(map.getListOfStates(), destination);
        if(startingPointIndex != -1 && destinationIndex != -1){
                State startingPointState = map.getListOfStates().get(startingPointIndex);
                State destinationState = map.getListOfStates().get(destinationIndex);
                //Starting queue
                this.edge.add(new Node(null, startingPointState, 0));
                Solution solution = new Solution(0);
                Node currentNode = recursiveSearch(destinationState, solution);
                if(currentNode != null){
                    solution.getPath().add(currentNode.getState());
                }
                return solution;
            }
        return new Solution(0);
    }
    public Node recursiveSearch(State destinationState, Solution solution){
        if(!edge.isEmpty()){
           Node parentNode = edge.poll();
           this.exploiters.add(parentNode.getState());
           for(int k=0; k<parentNode.getState().getAdjacentList().size(); k++){
                Node childNode = new Node(parentNode, 
                                parentNode.getState().getAdjacentList().get(k).getNextCity(), 
                                parentNode.getState().getAdjacentList().get(k).getCost()+parentNode.getCost());
                if(!checkState(childNode.getState())){
                    if(childNode.getState().getCityName().equals(destinationState.getCityName())){
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
                if(currentParent.getFather().getState().getCityName().equals(parentNode.getState().getCityName())){
                    solution.getPath().add(currentParent.getState());
                    return parentNode;
                }
           }
           return currentParent;
        }
        //There is no way
        return null;
    }
    public boolean checkState(State state){
        //Checking edge
        for(Node node: edge){
            if(node.getState().getCityName().equals(state.getCityName())){
                return true;
            }
        }
        //Checking exploiters
        for(int k=0; k<exploiters.size(); k++){
            if(exploiters.get(k).getCityName().equals(state.getCityName())){
                return true;
            }
        }
        return false;
    }
}

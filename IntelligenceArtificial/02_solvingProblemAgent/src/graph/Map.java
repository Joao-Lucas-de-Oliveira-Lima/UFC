package src.graph;

import java.util.ArrayList;

public class Map {
    private ArrayList<State> listOfStates;
    
    public Map(String[] cityNames){
        this.listOfStates = new ArrayList<State>();
        for(String currentName: cityNames){
            listOfStates.add(new State(currentName));
        }
    }
    public boolean initializeAdjacentList(String cityName, int[] costList, String[] adjacencies){
        int indexCityName = getIndex(cityName);
        if(indexCityName != -1){
            for(int index=0; index<adjacencies.length; index++){
                int adjacencyIndex = getIndex(adjacencies[index]);
                if(adjacencyIndex != -1){
                    this.listOfStates.get(indexCityName).getAdjacentList().add(new Transition(this.listOfStates.get(adjacencyIndex), costList[index]));
                }
            }
            return true;
        }
        return false;
    }
    private int getIndex(String cityName){
        for(int index=0; index<listOfStates.size(); index++){
            if(listOfStates.get(index).getCityName().toLowerCase().equals(cityName.toLowerCase())){
                return index;
            }
        }
        return -1;
    }
    public State get(String cityName){
        for(int index=0; index<listOfStates.size(); index++){
            if(this.listOfStates.get(index).getCityName().toLowerCase().equals(cityName.toLowerCase())){
                return this.listOfStates.get(index);
            }
        }
        return null;
    }
    public String toString(){
        String string = "";
        for(State currentState: this.listOfStates){
            string+=currentState.toString()+"\n";
        }
        return string;
    }
}

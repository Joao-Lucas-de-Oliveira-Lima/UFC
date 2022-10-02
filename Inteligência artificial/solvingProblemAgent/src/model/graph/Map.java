package src.model.graph;

import java.util.ArrayList;
import src.model.validation.ValidateCityName;

public class Map {
    private ArrayList<State> listOfStates;
    
    public Map(String[] cityNames){
        this.listOfStates = new ArrayList<State>();
        for(int k=0; k<cityNames.length; k++){
            listOfStates.add(new State(cityNames[k]));
        }
    }
    public boolean initializeAdjacentList(String cityName, int[] costList, String[] adjacencies){
        ValidateCityName validateCityName = new ValidateCityName();
        int indexCityName = validateCityName.validate(this.listOfStates, cityName);
        if(indexCityName != -1){
            for(int k=0; k<adjacencies.length; k++){
                int adjacencyIndex = validateCityName.validate(this.listOfStates, adjacencies[k]);
                if(adjacencyIndex != -1){
                    this.listOfStates.get(indexCityName).getAdjacentList().add(new Transition(this.listOfStates.get(adjacencyIndex), costList[k]));
                }
            }
            return true;
        }
        return false;
    }
    public ArrayList<State> getListOfStates(){
        return this.listOfStates;
    }
    public String toString(){
        String s = "";
        for(int k=0; k<listOfStates.size(); k++){
            s+=listOfStates.get(k).toString()+"\n";
        }
        return s;
    }
}

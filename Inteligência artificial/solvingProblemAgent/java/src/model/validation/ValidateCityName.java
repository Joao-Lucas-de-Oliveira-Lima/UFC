package src.model.validation;

import src.model.graph.State;
import java.util.ArrayList;

public class ValidateCityName{

    public int validate(ArrayList<State> listOfStates, String cityName){
        for(int k=0; k<listOfStates.size(); k++){
            if(listOfStates.get(k).getCityName().equals(cityName)){
                return k;
            }
        }
        return -1;
    }
}

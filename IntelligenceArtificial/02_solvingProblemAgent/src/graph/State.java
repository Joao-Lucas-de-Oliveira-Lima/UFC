package src.graph;

import java.util.ArrayList;

public class State {
    private String cityName;
    private ArrayList<Transition> adjacentList;

    public State(String cityName){
        this.adjacentList = new ArrayList<Transition>();
        this.cityName = cityName;
    }
    public String getCityName(){
        return this.cityName;
    }
    public ArrayList<Transition> getAdjacentList(){
        return this.adjacentList;
    }
    public String toString(){
        String string = "State: "+this.cityName+"\n";
        for(Transition currentTransition: this.adjacentList){
            string+=currentTransition.toString()+"\n";
        }
        return string;
    }
}

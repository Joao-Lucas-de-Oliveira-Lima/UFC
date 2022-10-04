package src.model.graph;

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
        String s = "State: "+this.cityName+"\n";
        for(int k=0; k<this.adjacentList.size(); k++){
            s+="\t"+adjacentList.get(k).toString()+"\n";
        }
        return s;
    }
}

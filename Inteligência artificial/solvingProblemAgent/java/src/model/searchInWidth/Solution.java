package src.model.searchInWidth;

import src.model.graph.State;
import java.util.Stack;

public class Solution {
    private Stack<State> path;
    private int cost;

    public Solution(int cost){
        this.path = new Stack<State>();
        this.cost = cost;
    }
    public Solution(Stack<State> path, int cost){
        this.path = path;
        this.cost = cost;
    }
    public Stack<State> getPath(){
        return this.path;
    }
    public int getCost(){
        return this.cost;
    }
    public void setCost(int cost){
        this.cost = cost;
    }
    public String toString(){
        String s = "Total cost: "+this.cost+"\n";
        int pathSize = path.size();
        for(int k=0; k<pathSize-1; k++){
            s+=this.path.peek().getCityName()+" -> ";
            this.path.pop();
        }
        s+=this.path.peek().getCityName();
        return s;
    }
}

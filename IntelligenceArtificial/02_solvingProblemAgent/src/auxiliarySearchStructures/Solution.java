package src.auxiliarySearchStructures;

import java.util.Stack;

import src.graph.State;

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
        String string = "Total cost: "+this.cost+"\n";
        int pathSize = path.size();
        if(pathSize != 0){
            for(int index=0; index<pathSize-1; index++){
                string+=this.path.peek().getCityName()+" -> ";
                this.path.pop();
            }
            string+=this.path.peek().getCityName();
        }else{
            string+="No path found";
        }
        return string;
    }
}

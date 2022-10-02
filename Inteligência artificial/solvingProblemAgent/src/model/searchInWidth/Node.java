package src.model.searchInWidth;

import src.model.graph.State;

public class Node {
    private Node father;
    private State state;
    private int cost;

    public Node(Node father, State state, int cost){
        this.father = father;
        this.state = state;
        this.cost = cost;
    }
    public Node getFather(){
        return this.father;
    }
    public State getState(){
        return this.state;
    }
    public int getCost(){
        return this.cost;
    }
}

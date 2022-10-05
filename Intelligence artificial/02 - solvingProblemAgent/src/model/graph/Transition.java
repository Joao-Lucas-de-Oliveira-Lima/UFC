package src.model.graph;

public class Transition {
    private State nextCity;
    private int cost;

    public Transition(State nextCity, int cost){
        this.nextCity = nextCity;
        this.cost = cost;
    }
    public State getNextCity(){
        return this.nextCity;
    }
    public int getCost(){
        return this.cost;
    }
    public String toString(){
        return "Destination: "+this.nextCity.getCityName()+" - Cost: "+this.cost;
    }
}
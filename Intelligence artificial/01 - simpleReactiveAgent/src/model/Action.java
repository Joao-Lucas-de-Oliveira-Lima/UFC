package src.model;

public class Action {
    private String name;

    public Action(){}
    public String getName(){
        return this.name;
    }
    public void setName(String name){
        this.name = name;
    }
    public String toString(){
        return this.name;
    }
}

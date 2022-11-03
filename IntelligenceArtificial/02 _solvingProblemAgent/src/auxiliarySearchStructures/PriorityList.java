package src.auxiliarySearchStructures;

import java.util.ArrayList;

public class PriorityList {
    private ArrayList<Node> list;  

    public PriorityList(){
        this.list = new ArrayList<Node>();
    }
    public Node remove(){
        /* int minInt = Integer.MAX_VALUE, indexOfHigherPriority = 0;
        for(int index=0; index<this.list.size(); index++){
            if(this.list.get(index).getCost() < minInt){
                indexOfHigherPriority = index;
                minInt = this.list.get(index).getCost();
            }
        } */
        return this.list.remove(0);
    }
    public Boolean swapNode(Node node){
        for(int index=0; index<this.list.size(); index++){
            if(this.list.get(index).getState().getCityName().equals(node.getState().getCityName())){
                //Higher priority node
                if(this.list.get(index).getCost() > node.getCost()){
                    this.list.remove(index);
                    this.list.add(node);
                    return true;
                }
            }
        }
        return false;
    }
    public void add(Node node){
        int index=0;
        for(index=0; index<this.list.size(); index++){
            if(this.list.get(index).getCost() > node.getCost()){
                break;
            }
        }
        this.list.add(index, node);
    }
    public Boolean isEmpty(){
        return this.list.isEmpty();
    }
    public Boolean contains(Node node){
        for(Node currentNode: this.list){
            if(currentNode.getState().equals(node.getState())){
                return true;
            }
        }
        return false;
    }
}

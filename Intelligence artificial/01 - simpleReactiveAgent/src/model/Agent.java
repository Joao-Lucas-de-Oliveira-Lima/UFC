package src.model;

public class Agent {
    public Perception perceives(Environment environment){
        boolean location = environment.isAgentLocation();
        boolean isDirty = false;
        if(location){
            isDirty = environment.isIsDirtyA();
        }else{
            isDirty = environment.isIsDirtyB();
        }
        return new Perception(location, isDirty);
    }
    public Action act(Perception perception){
        Action action = new Action();
        if(perception.isIsDirty()){
            action.setName("Aspirar");
        }else if(perception.isLocation()){
            action.setName("Direita");
        }else{
            action.setName("Esquerda");
        }
        return action;
    }
}

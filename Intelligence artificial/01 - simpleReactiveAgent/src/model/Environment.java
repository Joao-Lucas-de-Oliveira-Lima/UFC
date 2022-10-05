package src.model;

import java.util.Random;

public class Environment {
    private boolean isDirtyA;
    private boolean isDirtyB;
    private boolean agentLocation;

    public Environment(){}
    //Constructor designated for testing
    public Environment(boolean isDirtyA, boolean isDirtyB, boolean agentLocation){
        this.isDirtyA = isDirtyA;
        this.isDirtyB = isDirtyB;
        this.agentLocation = agentLocation;
    }
    public void initializeEnvironment(){
        this.isDirtyA = initializeHelperEnvironment();
        this.isDirtyB = initializeHelperEnvironment();
        this.agentLocation = initializeHelperEnvironment();
    }
    private boolean initializeHelperEnvironment(){
        Random generator = new Random();
        int aux = generator.nextInt(2);
        if(aux == 1){
            return true;
        }
        return false;
    }
    public void updateEnvironment(Action action){
        if(this.agentLocation){
            if(action.toString().equals("Aspirar")){
                this.isDirtyA = false;
            }else{
                this.agentLocation = false;
            }
        }else{
            if(action.toString().equals("Aspirar")){
                this.isDirtyB = false;
            }else{
                this.agentLocation = true;
            }
        }
    }
    public boolean isIsDirtyA(){
        return this.isDirtyA;
    }
    public boolean isIsDirtyB(){
        return this.isDirtyB;
    }
    public boolean isAgentLocation(){
        return this.agentLocation;
    }
    public String toString(){
        String string = "_________________\n";
        string+="|Room A |Room B |\n";
        if(this.agentLocation){
            string+="|  \\_/  |       |\n";
            string+="| (* *) |       |\n";    
        }else{
            string+="|       |  \\_/  |\n";
            string+="|       | (* *) |\n";
        }
        if(isDirtyA){
            string+="|Dirty  |";
        }else{
            string+="|       |";
        }
        if(isDirtyB){
            string+="Dirty  |\n";
        }else{
            string+="       |\n";
        }
        string+="\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"";
        return string;
    }
}

package src.model;

public class Perception {
    private boolean location;
    private boolean isDirty;
    
    public Perception(boolean location, boolean isDirty){
        this.location = location;
        this.isDirty = isDirty;
    }
    public boolean isLocation(){
        return this.location;
    } 
    public boolean isIsDirty(){
        return this.isDirty;
    }
}

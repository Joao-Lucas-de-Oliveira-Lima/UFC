package src.exec;

import src.model.*;
import java.util.Scanner;

public class VacuumWorld{
    
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Environment environment = new Environment();
        Agent agent = new Agent();
        environment.initializeEnvironment();
        System.out.print("Number of steps: ");
        int steps = Integer.parseInt(input.nextLine());
        for(int k=steps-1; k>=0; k--){
            System.out.println("Current state ("+k+"):");
            System.out.println(environment.toString());
            Perception perception = agent.perceives(environment);
            Action action = agent.act(perception);
            System.out.println("Action taken: "+action.toString()+"\n");
            environment.updateEnvironment(action);
        }
        input.close();
    }
}
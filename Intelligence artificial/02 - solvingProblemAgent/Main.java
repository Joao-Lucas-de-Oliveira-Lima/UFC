import java.util.Scanner;

import src.graph.Map;
import src.search.DepthSearch;
import src.search.SearchInWidth;
import src.search.UniformCostSearch;
import src.searchStructures.Solution;

public class Main {
    public static void main(String[] args){
        String[] cityNames = {"Arad", "Zerind", "Timisoara", "Oradea", "Sibiu", "Lugoj",
        "Mehadia", "Drobeta", "Craiova", "Rimnicu Vilcea", "Pitesti",
        "Bucharest", "Giurgiu", "Urziceni", "Fagaras", "Hirsova", "Eforie",
        "Vaslui", "Iasi", "Neamt"};    
        //Starting graph construction
        Map romaniaMap = new Map(cityNames);
        romaniaMap.initializeAdjacentList("Arad", new int[]{118, 140, 75}, new String[]{"Timisoara", "Sibiu", "Zerind"});
        romaniaMap.initializeAdjacentList("Timisoara", new int[]{118, 111}, new String[]{"Arad", "Lugoj"});
        romaniaMap.initializeAdjacentList("Zerind", new int[]{75, 71}, new String[]{"Arad", "Oradea"});
        romaniaMap.initializeAdjacentList("Oradea", new int[]{71, 151}, new String[]{"Zerind", "Sibiu"});
        romaniaMap.initializeAdjacentList("Sibiu", new int[]{151, 140, 99, 80}, new String[]{"Oradea", "Arad", "Fagaras", "Rimnicu Vilcea"});
        romaniaMap.initializeAdjacentList("Fagaras", new int[]{99, 211}, new String[]{"Sibiu", "Bucharest"});
        romaniaMap.initializeAdjacentList("Lugoj", new int[]{111, 70}, new String[]{"Timisoara", "Mehadia"});
        romaniaMap.initializeAdjacentList("Mehadia", new int[]{70, 75}, new String[]{"Lugoj", "Drobeta"});
        romaniaMap.initializeAdjacentList("Drobeta", new int[]{75, 120}, new String[]{"Mehadia", "Craiova"});
        romaniaMap.initializeAdjacentList("Craiova", new int[]{120, 146, 138,}, new String[]{"Drobeta", "Rimnicu Vilcea", "Pitesti"});
        romaniaMap.initializeAdjacentList("Rimnicu Vilcea", new int[]{80, 146, 97}, new String[]{"Sibiu", "Craiova", "Pitesti"});
        romaniaMap.initializeAdjacentList("Pitesti", new int[]{97, 138, 101}, new String[]{"Rimnicu Vilcea", "Craiova", "Bucharest"});
        romaniaMap.initializeAdjacentList("Bucharest",new int[]{90, 101, 211, 85}, new String[]{"Giurgiu", "Pitesti", "Fagaras", "Urziceni"});
        romaniaMap.initializeAdjacentList("Giurgiu", new int[]{90}, new String[]{"Bucharest"});
        romaniaMap.initializeAdjacentList("Urziceni", new int[]{85, 98, 142}, new String[]{"Bucharest", "Hirsova", "Vaslui"});
        romaniaMap.initializeAdjacentList("Hirsova", new int[]{98, 86}, new String[]{"Urziceni", "Eforie"});
        romaniaMap.initializeAdjacentList("Eforie", new int[]{86}, new String[]{"Hirsova"});
        romaniaMap.initializeAdjacentList("Vaslui", new int[]{142, 92}, new String[]{"Urziceni", "Iasi"});
        romaniaMap.initializeAdjacentList("Iasi", new int[]{92, 87}, new String[]{"Vaslui", "Neamt"});
        romaniaMap.initializeAdjacentList("Neamt", new int[]{87}, new String[]{"Iasi"});
        Scanner reader = new Scanner(System.in);
        SearchInWidth searchInWidth = new SearchInWidth();
        UniformCostSearch uniformCostSearch = new UniformCostSearch();
        DepthSearch depthSearch = new DepthSearch();
        System.out.print("\nEnter the target state: ");
        String destination = reader.nextLine();
        //Search in width result
        Solution solution = searchInWidth.performSearch(romaniaMap, "Arad", destination);
        System.out.println("\nSearch in width: "+solution.toString()+"\n");
        //Uniform cost search result
        solution = uniformCostSearch.performSearch(romaniaMap, "Arad", destination);
        System.out.println("Uniform cost search: "+solution.toString()+"\n");
        //Depth search result
        solution = depthSearch.performSearch(romaniaMap, "Arad", destination);
        System.out.println("Depth search: "+solution.toString());
        reader.close();
    }
}
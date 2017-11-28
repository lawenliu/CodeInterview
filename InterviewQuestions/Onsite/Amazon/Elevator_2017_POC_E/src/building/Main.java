/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package building;
/**
 * Main loop
 * @author Miao Li
 */
public class Main {
    public static void main(String[] args){
    	try {
    		Building b = new Building("./data/simulation_inputs.xml");
    		
    		System.out.printf("Test1 start...\n");    		
    		b.runTestCase(0);
    		System.out.printf("Test1 end...\n\n");
    		
    		System.out.printf("Test2 start...\n");
    		b.runTestCase(1);
    		System.out.printf("Test2 end...\n\n");
    		
    		System.out.printf("Test3 start...\n");
    		b.runTestCase(2);
    		System.out.printf("Test3 end...\n\n");
    		
    		System.out.printf("Test4 start...\n");
    		b.runTestCase(3);
    		System.out.printf("Test4 end...\n\n");
    		
    		b.shutdown();
    		
    	}catch(Exception e) {
    		e.printStackTrace();
    	}    	
    	
    }    
}

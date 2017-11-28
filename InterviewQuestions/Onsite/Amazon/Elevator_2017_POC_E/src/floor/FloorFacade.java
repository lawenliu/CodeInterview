
package floor;

import java.util.ArrayList;
import elevator.IElevator;
import person.IPerson;
import utils.InvalidArgumentException;

/**
 * FloorFacade class uses the facade pattern
 * @author Miao Li
 */


public class FloorFacade {
	/**
	 * Singleton, FloorFacade instance itself
	 */
    private static volatile FloorFacade self;
    
    /**
     * floors list of the building
     */
    private ArrayList<IFloor> floors;

    /**
     * Singleton pattern, get itself instance
     * @return self instance
     */
    public static FloorFacade getInstance(){
        if(self == null){
        	self = new FloorFacade();
        }
        return self;
    }
    
    /**
     * Create a list of floors
     * @param numFloor 
     */
    public void initFloors(int numFloors) throws InvalidArgumentException{
        floors = new ArrayList<>();        
        for(int i = 1; i <= numFloors; i++)
            getFloors().add(FloorFactory.create(i));        
    }
    
    /**
     * Get list of floors
     * @return floors
     */
    private ArrayList<IFloor> getFloors() {
        return floors;
    }
    
    /**
     * Get a specific floor by floorId
     * @param floorId
     * @return floor
     */
    private IFloor getFloor(int floorId) {
    	IFloor floor = null;
    	for(int i=0;i<floors.size();i++) {
    		if(floors.get(i).getFloorID() == floorId) {
    			floor = floors.get(i);
    			break;
    		}
    	}
    	return floor;
    }
    
    /** 
     * Get the size of the floor list 
     * @return floors' size
     */
    public int getNumOfFloors(){
        return floors.size();
    }
    
    /**
     * Adds a person to a floor
     * @param floorId
     * @param p
     */
    public void addPerson(int floorId, IPerson p) {
    	getFloor(floorId).addPerson(p);
    }
    
    /**
     * Adds a getting off person to a floor
     * @param floor Floor to add person to
     * @param p
     * @throws InvalidArgumentException 
     */
    public void receivePerson(int floorId, IPerson p) throws InvalidArgumentException {
    	getFloor(floorId).personGetOff(p);
    }
    
    /**
     * Adds a person that waiting on floorId to an elevator
     * @param floorId
     * @param elevator
     * @throws InvalidArgumentException 
     */
    public void addPersonToElevator(int floorId, IElevator elevator) throws InvalidArgumentException {
    	IFloor floor = getFloor(floorId);
    	ArrayList<IPerson> personList = floor.getWaitingPersons();
    	for(int i=0;i<personList.size();i++) {
    		IPerson p = personList.get(i);
    		if(elevator.addPerson(p)) {
    			floor.personGetIn(p,elevator.getElevatorID());
    		}else {
    			break;
    		}
    	}
    }
}


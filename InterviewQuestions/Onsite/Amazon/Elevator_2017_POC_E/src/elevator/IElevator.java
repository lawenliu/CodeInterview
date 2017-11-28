
package elevator;

import java.util.ArrayList;
import person.IPerson;
import utils.InvalidArgumentException;
/**
 * Interface of Elevator.
 * @author Miao Li
 * 
 */
public interface IElevator extends Runnable{
	/**
	 * Direction of elevator is going to
	 */
	enum Direction{
		IDLE, 
		GOING_UP, 
		GOING_DOWN
	}
	
	/**
	 * Get the elevator's Id
	 * @return elevatorId
	 */
	int getElevatorID();
	
	/**
	 * Get the current floor number that the elevator stay on
	 * @return floor number
	 */
	int getCurrentFloor();
	
	/**
	 * Get the max persons that the elevator can carry on
	 * @return the max number of persons
	 */
    int getMaxPersons();
    
    /**
     * Get the direction that the elevator is going to
     * @return direction
     */
	Direction getDirection();
	
	/**
	 * Get the persons on the elevator
	 * @return List of persons
	 */
	ArrayList<IPerson> getPersonList();
	
	/**
	 * Get the persons on the elevator by String type
	 * @return persons
	 */
	String getRidingPersons();
	
	/**
	 * Get the destinations of the elevator by String type
	 * @return destinations
	 */
    String getDestinations();
    
    /**
     * Add a person to the elevator
     * @param p
     * @return if the person can get in or not
     * @throws InvalidArgumentException
     */
	boolean addPerson(IPerson p) throws InvalidArgumentException;
	
	/**
	 * Call when there is a floor request
	 * @param floorID
	 * @throws InvalidArgumentException
	 */
	void floorRequest(int floorID) throws InvalidArgumentException;
	
	/**
	 * Call when there is a rider request
	 * @param floorID
	 * @throws InvalidArgumentException
	 */
	void riderRequest(int floorID) throws InvalidArgumentException;
	
    
    
    
    
    
}

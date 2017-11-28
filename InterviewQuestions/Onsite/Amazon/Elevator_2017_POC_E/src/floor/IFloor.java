package floor;

import java.util.ArrayList;
import person.IPerson;
import utils.InvalidArgumentException;

/**
 * Floor interface
 * @author Miao Li
 */
public interface IFloor {
	/**
	 * Get this Floor number
	 * @return number of this floor
	 */
	int getFloorID();
	
	/**
	 * Add a person on this floors
	 * @param p
	 */
    void addPerson(IPerson p);
    
    /**
     * Let the person get in the elevator
     * @param p
     * @param elevatorId
     * @throws InvalidArgumentException
     */
    void personGetIn(IPerson p,int elevatorId) throws InvalidArgumentException;
    
    /**
     * Let the person get off the elevator
     * @param p
     * @throws InvalidArgumentException
     */
    void personGetOff(IPerson p)  throws InvalidArgumentException ;
    
    /**
     * Get the waiting persons list 
     * @return list of waiting persons
     */
    ArrayList<IPerson> getWaitingPersons();
    
    /**
     * Get the arrival persons list
     * @return list of arrival persons
     */
    ArrayList<IPerson> getArrivalPersons();
}

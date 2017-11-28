package floor;

import java.util.ArrayList;
import person.IPerson;
import utils.InvalidArgumentException;

/**
 * SimpleFloorImpl Class
 * @author Miao Li
 */
public class SimpleFloorImpl implements IFloor{
    
    /**
     * List of persons waiting on this floor
     */
    private ArrayList<IPerson> waitingPersons;
    
    /**
     * List of persons arrival on this floor
     */
    private ArrayList<IPerson> arrivalgPersons;
    
    /**
     * Number of this floor
     */
    private int floorID;

    /**
     * Constructor 
     * @param floorId 
     */
    public SimpleFloorImpl(int floorId) throws InvalidArgumentException{
    	setFloorID(floorId);
        waitingPersons = new ArrayList<>();
        arrivalgPersons = new ArrayList<>();
    }

    /**
     * Get waiting person list
     * @return waitingPersons
     */
    @Override
    public ArrayList<IPerson> getWaitingPersons() {
        return waitingPersons;
    }
    
    /**
     * Get arrival person list
     * @return arrivalgPersons
     */
    @Override
    public ArrayList<IPerson> getArrivalPersons() {
        return arrivalgPersons;
    }
    
    /**
     * Let a person get off an elevator
     * @param p
     */
    @Override
    public void personGetOff(IPerson p) throws InvalidArgumentException {
    	p.arriveFloor();
    	getArrivalPersons().add(p);
    }
    
    /**
     * Let a person get in an elevator
     * @param p
     * @param elevatorId
     */
    @Override
    public void personGetIn(IPerson p,int elevatorId) throws InvalidArgumentException {
    	p.boardElevator(elevatorId);
    	getWaitingPersons().remove(p);
    }
    
    /**
     * Adds a person to the waiting list and than presses button
     * @param p
     */
    @Override
    public void addPerson(IPerson p) { 
    	getWaitingPersons().add(p);
        p.pressButton();
    }

    
    /**
     * Set this Floor number
     * @param floorID
     */
    private void setFloorID(int floorID) throws InvalidArgumentException{
        if(floorID < 1)
            throw new InvalidArgumentException("Floor id cannot < 1");
        else
        	this.floorID = floorID;
    }
    
    /**
     * Get this Floor number
     * @return floorID
     */
    @Override
    public int getFloorID() {
        return this.floorID;
    }
    
}

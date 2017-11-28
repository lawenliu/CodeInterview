package person;

import building.Building;
import elevator.IElevator;
import elevatorcontroller.ElevatorControllerFacade;
import floor.FloorFacade;
import utils.InvalidArgumentException;

/**
 * SimplePersonImpl
 * @author Miao Li
 */
public class SimplePersonImpl implements IPerson{
	
	/**
	 *  Id of this person
	 */
	private int personID;
	
    /**
     * person's direction
     */
    private Direction direction;
    
    /**
     * The floor number that the person is currently on
     */
    private int srcFloor;
    
    /**
     * The floor number that the person is going to go to
     */
    private int destFloor;
    
    /**
     * The elevator id that the person is riding
     */
    private int rideElevatorId;
    
    /**
     * The time of the person waited on the floor
     */
    private int waitingTime;
    
    /**
     * The time of the person spent on the elevator
     */
    private int ridingTime;
    
    /**
     * Status of the person
     */
    private Status status;
    
    /**
     * When the person starts to wait an elevator
     */
    private int startTimeWait;
    
    /**
     * When the person starts to ride an elevator
     */
    private int startTimeRide;
    
    /**
     * Constructor
     * @param personID ID of this person
     * @param srcFloor Floor number of this person is created on
     * @param destFloor Floor number of this person is going to
     * @throws InvalidArgumentException
     */
    public SimplePersonImpl(int personID,int srcFloor,int destFloor) throws InvalidArgumentException{
    	setPersonID(personID);
        setSrcFloor(srcFloor);
        setDestFloor(destFloor);
        setStatus(Status.INITAL);
        setWaittingTime(0);
        setRiddingTime(0);
        setDirection();
        
        String dir = "DOWN";
    	if(destFloor > srcFloor)
    		dir = "UP";
    	System.out.printf("%s Person P%d created on Floor %d, wants go %s to Floor %d\n",Building.getTimeString(),personID,srcFloor,dir,destFloor);        
    }
    
    /**
     * Set ID for this person
     * @param personID
     */
    private void setPersonID(int personID) {
    	this.personID = personID;
    }
    
    /**
     * Get this person's ID
     * @return this person's ID
     */
    @Override
    public int getPersonID() {
    	return this.personID;
    }
    
    /**
     * Set the elevator id that this person rides
     * @param rideElevatorId
     */
    private void setRideElevatorID(int rideElevatorId) {
    	if(getStatus() == Status.RIDING)
    		this.rideElevatorId = rideElevatorId;
    	else
    		this.rideElevatorId = -1;
    }
    
    /**
     * Get the elevator id that this person rides
     */
    @Override
    public int getRideElevatorID() {
    	return this.rideElevatorId;
    }
    
    /**
     * Set the floor number that this person is created
     * @param srcFloor - floor number
     */
    private void setSrcFloor(int srcFloor) throws InvalidArgumentException{
        if(srcFloor < 1 || srcFloor > FloorFacade.getInstance().getNumOfFloors())
            throw new InvalidArgumentException("Set Source Floor number out of range!");
        else
            this.srcFloor = srcFloor;
    }
    
    /**
     * Get the floor number that this person is created
     * @return srcFloor
     */
    @Override
    public int getSrcFloor() {
        return this.srcFloor;
    }
    
    /**
     * Set the floor number that this person is going to
     * @param destFloor
     */
    private void setDestFloor(int destFloor) throws InvalidArgumentException{
        if(destFloor < 0 || destFloor > FloorFacade.getInstance().getNumOfFloors())
            throw new InvalidArgumentException("Set Destination Floor number out of range!");
        else
            this.destFloor = destFloor;
    }
    
    /**
     * Get the floor number that this person is going to
     * @return destFloor
     */
    @Override
    public int getDestFloor() {
        return this.destFloor;
    }
    
    /**
     * Set person's status
     * @param status
     */
    private void setStatus(Status status) {
    	this.status = status;
    }
    
    /**
     * Get person's status
     * @return status
     */
    @Override
	public Status getStatus() {
		return this.status;
	}
    
    /**
     * Set the waiting time
     * @param waitingTime
     */
    private void setWaittingTime(int waitingTime) throws InvalidArgumentException {
        if(waitingTime < 0)
            throw new InvalidArgumentException("Wait time cannot < 0");
        else
            this.waitingTime = waitingTime;
    }    
    /**
     * Get the waiting time
     * @return waitingTime
     */
    @Override
    public int getWaitingTime() {
        return this.waitingTime;
    }

    
    /**
     * Set the riding time
     * @param ridingTime
     */
    private void setRiddingTime(int ridingTime) throws InvalidArgumentException {
        if(ridingTime < 0)
            throw new InvalidArgumentException("Ride time cannot < 0");
        else
            this.ridingTime = ridingTime;
    }
    
    /**
     * Get the riding time
     * @return ridingTime
     */
    @Override
    public int getRidingTime() {
        return this.ridingTime;
    }

    

    /**
     * Set the direction of the person is going to
     */
    private void setDirection() {
        if(this.srcFloor < this.destFloor) 
            this.direction = Direction.UP;
        else if(this.srcFloor > this.destFloor)
            this.direction = Direction.DOWN;
        else 
            this.direction = Direction.NONE;
    }
    
    /**
     * Get the person's direction
     * @return direction
     */
    @Override
    public Direction getDirection() {
        return this.direction;
    }
    
    
    /**
     * Presses the button on the elevator or on the floor
     */
    @Override
    public void pressButton() {
        if(getStatus().equals(Status.INITAL)) 
		{
        	String dir = "DOWN";
        	if(destFloor > srcFloor)
        		dir = "UP";
        	System.out.printf("%s Person P%d presses %s on Floor %d\n",Building.getTimeString(),personID,dir,srcFloor);
        	
			startTimeWait = Building.getCurrentTime();//LocalDateTime.now().toInstant(ZoneOffset.UTC).toEpochMilli();
			try {
				ElevatorControllerFacade.getInstance().doFloorRequest(getDirection(), getSrcFloor());
			} catch (InvalidArgumentException e) {
				e.printStackTrace();
			}
		    setStatus(Status.WAITING);
		} else
			try {
				if (getStatus().equals(Status.RIDING)) 
					ElevatorControllerFacade.getInstance().doRiderRequest(getRideElevatorID(), getDestFloor());
			} catch (Exception e) {
				e.printStackTrace();
			}
    }
    
    
    /**
     * Call this function when the person arrives the destination floor
     * @throws InvalidArgumentException 
     */
    @Override
    public void arriveFloor() throws InvalidArgumentException {
    	int currentTime = Building.getCurrentTime();//LocalDateTime.now().toInstant(ZoneOffset.UTC).toEpochMilli();
        
    	setRiddingTime(currentTime-startTimeRide);
        setStatus(Status.ARRIVAL);
        
        IElevator e = ElevatorControllerFacade.getInstance().getElevator(getRideElevatorID());
        System.out.printf("%s Person P%d has left Elevator %d [Riders: %s]\n",Building.getTimeString(),getPersonID(),e.getElevatorID(),e.getRidingPersons());

        
    }
    
    /**
     * Call this function when the person get in the elevator
     * @param elevatorId
     */
    @Override
    public void boardElevator(int elevatorId) throws InvalidArgumentException {
        
        setStatus(Status.RIDING);
        int currentTime = Building.getCurrentTime();//LocalDateTime.now().toInstant(ZoneOffset.UTC).toEpochMilli();
        setWaittingTime(currentTime - startTimeWait);
        startTimeRide = currentTime;

        setRideElevatorID(elevatorId);
        pressButton();
        
        IElevator e = ElevatorControllerFacade.getInstance().getElevator(elevatorId);
        System.out.printf("%s Person P%d has entered Elevator %d [Riders: %s]\n",Building.getTimeString(),getPersonID(),elevatorId,e.getRidingPersons());
    }

}

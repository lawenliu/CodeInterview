package elevator;

import static gui.ElevatorDisplay.Direction.UP;
import static gui.ElevatorDisplay.Direction.DOWN;
import java.util.ArrayList;
import java.util.Collections;
import building.Building;
import floor.FloorFacade;
import gui.ElevatorDisplay;
import person.IPerson;
import utils.InvalidArgumentException;

/**
 * SimpleElevatorImpl Class
 * @author Miao Li
 */
public class SimpleElevatorImpl implements IElevator {
	/**
	 * List of persons that on the elevator
	 */
    private volatile ArrayList<IPerson> personList;
    
    /**
     * List of the destination of the elevator
     */
    private volatile ArrayList<Integer> destinationList;
    
    /**
     * List of the floor request of the elevator
     */
    private volatile ArrayList<Integer> floorRequestList;
    
    /**
     * List of the rider request of the elevator
     */
    private volatile ArrayList<Integer> riderRequestList;

    /**
     * Current floor that the elevator stay on
     */
    private int curFloor;
    
    /**
     * The elevator Id
     */
    private int elevatorID;
    
    /**
     * The direction of the elevator
     */
    private Direction direction;

    /**
     * Number of the max persons that the elevator can carry on
     */
    private int maxPersons;
    
    /**
     * The speed of the elevator,in milliseconds
     */
    private int msPerFloor;
    
    /**
     * Door open time,in milliseconds
     */
    private int msStopFloor;
    
    /**
     * Idle time, in seconds
     */
    private int timeout;
    private int watchdog = 0;
    /**
     * Constructor
     * @param elevatorID
     * @param initFloor
     * @param maxPersons
     * @param msPerFloor
     * @param msStopFloor
     * @param timeout
     * @throws InvalidArgumentException
     */
    public SimpleElevatorImpl(int elevatorID,int initFloor,int maxPersons,int msPerFloor,int msStopFloor,int timeout) throws InvalidArgumentException {
        
    	personList = new ArrayList<>();
    	destinationList = new ArrayList<>();
    	floorRequestList = new ArrayList<>();
    	riderRequestList = new ArrayList<>();
        
        this.maxPersons = maxPersons;
        this.msPerFloor = msPerFloor;
        this.msStopFloor = msStopFloor;
        this.timeout = timeout;
        
        setElevatorID(elevatorID);
        setCurrentFloor(initFloor);
        setDirection(Direction.IDLE);
    }

    /**
     * Set the direction of the elevator.
     * @param direction
     */
    private void setDirection(Direction direction){
    	this.direction = direction;
    }
    
    /**
     * Get the direction of the elevator.
     * @return direction
     */
    public Direction getDirection() {
    	return direction;
    }

   /**
     * Set the current floor of the elevator.
     * @param floorId
     * @throws InvalidArgumentException
     */
    private void setCurrentFloor(int floorId) throws InvalidArgumentException {
        if(floorId < 1 || floorId > FloorFacade.getInstance().getNumOfFloors())
            throw new InvalidArgumentException("Floor ID is out of the range");
        
        this.curFloor = floorId;
    }
    
    /**
     * Get the current floor of the elevator.
     * @return curFloor
     */
    public int getCurrentFloor(){
        return this.curFloor;
    }

    /**
     * Set the ID of an elevator.
     * @param elevatorID
     * @throws InvalidArgumentException
     */
    private void setElevatorID(int elevatorID) throws InvalidArgumentException {
         
        if(elevatorID < 0)
            throw new InvalidArgumentException("ElevatorID shoule > = 0");
        else
            this.elevatorID = elevatorID;
    }
    
    /**
     * Get the ID of the current elevator.
     * @return elevatorID
     */
    public int getElevatorID(){
        return this.elevatorID;
    }

    /**
     * Get the max number of persons.
     * @return maxPersons
     */
    public int getMaxPersons() {
        return maxPersons;
    }
    
    /**
     * Get the next floor number that the elevator will stop
     * @return next floor number
     */
    public Integer getNextStopFloor(){
        if(destinationList.isEmpty())
            return null;
        return destinationList.get(0);
    }
    
    /**
     * UI of Moving elevator 
     */
    private void uiMoveElevator() {
    	if(getDirection() == Direction.GOING_UP)
    		ElevatorDisplay.getInstance().updateElevator(getElevatorID(), getCurrentFloor(), getRiderNumber(), UP);
    	else if(getDirection() == Direction.GOING_DOWN)
    		ElevatorDisplay.getInstance().updateElevator(getElevatorID(), getCurrentFloor(), getRiderNumber(), DOWN);
    	else {
    		ElevatorDisplay.getInstance().closeDoors(getElevatorID());
    		ElevatorDisplay.getInstance().setIdle(getElevatorID());
    	}
    }
    
    /**
     * The elevator goes to the next floor
     * @throws InterruptedException
     * @throws InvalidArgumentException
     */
    private void goToNextFloor() throws InterruptedException, InvalidArgumentException{
		while(getCurrentFloor() != getNextStopFloor()){
			Integer nextStopFloor = getNextStopFloor();
			if(nextStopFloor == null) {
				setDirection(Direction.IDLE);
				uiMoveElevator();
				return;
			}
			int fb = getCurrentFloor();			
			if(nextStopFloor > getCurrentFloor()){
				setDirection(Direction.GOING_UP);
				//uiMoveElevator();
				Thread.sleep(this.msPerFloor);
				curFloor++;
				uiMoveElevator();
			}else if(destinationList.get(0) < getCurrentFloor()){
				setDirection(Direction.GOING_DOWN);
				//uiMoveElevator();
				Thread.sleep(this.msPerFloor);
				curFloor--;
				uiMoveElevator();
			}
			int fa = getCurrentFloor();
			System.out.printf("%s Elevator %d moving from Floor %d to Floor %d [Current Floor Requests:%s][Current Rider Requests:%s]\n",Building.getTimeString(),getElevatorID(),fb,fa,getListString(floorRequestList),getListString(riderRequestList));
			watchdog = Building.getCurrentTime();
		}
		
		stopAtFloor();
	}
    
    /**
     * Call when the elevator arrive the destination floor
     * @throws InterruptedException
     * @throws InvalidArgumentException
     */
    private void stopAtFloor() throws InterruptedException, InvalidArgumentException{
    	boolean isNoRequest = true;
    	Integer destFloor = destinationList.get(0);    			
    	destinationList.remove(0);
		
		if(floorRequestList.contains(destFloor)) {
			floorRequestList.remove(destFloor);
			isNoRequest = false;
		}
		if(riderRequestList.contains(destFloor)) {
			riderRequestList.remove(destFloor);
			isNoRequest = false;
		}
		
		if(!isNoRequest) {
			System.out.printf("%s Elevator %d has arrived at Floor %d for Floor Request [Current Floor Requests:%s][Current Rider Requests:%s]\n",Building.getTimeString(),getElevatorID(),getCurrentFloor(),getListString(floorRequestList),getListString(riderRequestList));
			System.out.printf("%s Elevator %d Doors Open\n",Building.getTimeString(),getElevatorID());
			ElevatorDisplay.getInstance().openDoors(getElevatorID());
			
			personsOut();
			personsIn();
			Thread.sleep(this.msStopFloor);		
			System.out.printf("%s Elevator %d Doors Close\n",Building.getTimeString(),getElevatorID());
			
			ElevatorDisplay.getInstance().closeDoors(getElevatorID());
			uiMoveElevator();
		}
		
		if(destinationList.isEmpty()){
			setDirection(Direction.IDLE);
			uiMoveElevator();
		}
    }
    

    /**
     * Persons get off the elevator
     * @throws InvalidArgumentException 
     */
    private void personsOut() throws InvalidArgumentException {
    	for(int i = 0; i < personList.size(); i++){
			IPerson person = personList.get(i);
			if(person.getDestFloor() == getCurrentFloor()){
				personList.remove(i);
				FloorFacade.getInstance().receivePerson(getCurrentFloor(), person);				
			}
			
		}
    }
    
     /**
     * Persons get in the elevator
     * @throws InvalidArgumentException
     */
    private void personsIn() throws InvalidArgumentException {
        FloorFacade.getInstance().addPersonToElevator(getCurrentFloor(), this);
    }
    
    /**
     * Let a person get in the elevator
     * @throws InvalidArgumentException
     */
    @Override
    public boolean addPerson(IPerson p) throws InvalidArgumentException {		
		if(personList.size() < getMaxPersons()){
			personList.add(p);
			return true;
		}	
		return false;
	}
    
    /**
     * Turn a list into a String 
     * @param list
     * @return string
     */
    private String getListString(ArrayList<Integer> list) {
    	String str = "";
    	for(int i=0;i< list.size();i++) {
    		str += list.get(i);
    		if(i != list.size()-1)
    			str += ",";
    	}
    	return str;
    }
    
    /**
     * Get a string of the riding persons
     * @param string of rider
     */
    @Override
    public String getRidingPersons() {
    	String str = "";
    	for(int i=0;i< personList.size();i++) {
    		str += "P"+personList.get(i).getPersonID();
    		if(i != personList.size()-1)
    			str += ",";
    	}
    	return str;
    }
    
    /**
     * Call when a rider request occur
     * @param destFloor
     */
    @Override
    public void riderRequest(int destFloor)  throws InvalidArgumentException {
    	if(addDestination(destFloor)) {
			if(!riderRequestList.contains(destFloor)) {
				riderRequestList.add(destFloor);
    			Collections.sort(riderRequestList);
    		}
			
        	System.out.printf("%s Elevator %d Rider Request made for Floor %d [Current Floor Requests:%s][Current Rider Requests:%s]\n",Building.getTimeString(),getElevatorID(),destFloor,getListString(floorRequestList),getListString(riderRequestList));
    	}
    }
    
    /**
     * Call when a floor request occur
     * @param destFloor
     */
    @Override
    public void floorRequest(int destFloor)  throws InvalidArgumentException {
    	if(addDestination(destFloor)) {
    		if(!floorRequestList.contains(destFloor)) {
    			floorRequestList.add(destFloor);
    			Collections.sort(floorRequestList);
    		}
    		
    		String dir = "DOWN";
        	if(getDirection() == Direction.GOING_UP)
        		dir = "UP";
        	System.out.printf("%s Elevator %d is going to Floor %d for %s request[Current Floor Requests:%s][Current Rider Requests:%s]\n",Building.getTimeString(),getElevatorID(),destFloor,dir,getListString(floorRequestList),getListString(riderRequestList));
    	}
    }

    /**
     * Add a floor to an elevator's destinations list 
     * @param destFloor
     * @throws InvalidArgumentException 
     */    
    public boolean addDestination(int destFloor) throws InvalidArgumentException {
    	if(destFloor < 1 || destFloor > FloorFacade.getInstance().getNumOfFloors())
			throw new InvalidArgumentException("dest floor out of range.");
		
		if(getDirection() == Direction.GOING_UP && destFloor <= getCurrentFloor()){
			return false;
		}
		
		if(getDirection() == Direction.GOING_DOWN && destFloor >= getCurrentFloor()){
			return false;
		}
		
		if(getDirection() == Direction.IDLE){
			if(destFloor > getCurrentFloor())
				setDirection(Direction.GOING_UP);
			else if(destFloor < getCurrentFloor())
				setDirection(Direction.GOING_DOWN);
		}
		
		if(!destinationList.contains(destFloor))
			destinationList.add(destFloor);
		
		Collections.sort(destinationList);
		if(getDirection() == Direction.GOING_DOWN) {
			Collections.reverse(destinationList);
		}		
		return true;        
    }
    
    /**
     * Get a string of destinations
     * @return string of destinations
     */
    @Override
	public String getDestinations() {
		return null;
	}

    /**
     * Get a list of persons that on the elevator
     * @return personList
     */
	@Override
	public ArrayList<IPerson> getPersonList() {
		return personList;
	}
	
	/**
	 * Get the number of persons that on the elevator
	 * @return size of personList
	 */
	private int getRiderNumber() {
		return getPersonList().size();
	}

	/**
	 * Thread of elevator's main loop
	 */
	@Override
	public void run() {
		try{			
			while(Building.isRunning()){
				if(destinationList.size() == 0){
					if(getCurrentFloor() != 1){
						int curtime = Building.getCurrentTime();
						if(curtime - watchdog >= this.timeout)
							this.addDestination(1);
					}else {
						synchronized(this) {
							this.wait();
						}
					}
				}
				else{					
					goToNextFloor();
				}
				
			}
			
		}catch(InterruptedException | InvalidArgumentException e){
				e.printStackTrace();
		}
	}
}
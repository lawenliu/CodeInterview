package building;

import java.util.ArrayList;
import utils.InvalidArgumentException;

/**
 * DTO of building
 * @author Miao Li
 *
 */
public class BuildingDTO {
	/**
	 * Number of floors of the building
	 */
	private int numOfFloors;
	
	/**
	 * Number of elevators of the building
	 */
	private int numOfElevators;
	
	/**
	 * Max persons of the elevators
	 */
	private int maxPersonsPerElevator;
	
	/**
	 * Milliseconds, time per floor 
	 */
	private int timePerFloor;
	
	/**
	 * Milliseconds, door open time
	 */
	private int doorOpenTime;
	
	/**
	 * Seconds, Elevator timeout
	 */
	private int elevatorTimeout;
	
	/**
	 * A list that the simulator can use it to generate a person
	 */
	ArrayList<ArrayList<String>> testList;

	/**
	 * Constructor
	 * @param numOfFloors
	 * @param numOfElevators
	 * @param maxPersonsPerElevator
	 * @param timePerFloor
	 * @param doorOpenTime
	 * @param elevatorTimeout
	 * @param genPersonList
	 * @throws InvalidArgumentException
	 */
	public BuildingDTO(int numOfFloors, int numOfElevators, int maxPersonsPerElevator, int timePerFloor,
							int doorOpenTime, int elevatorTimeout,ArrayList<ArrayList<String>> testList) throws InvalidArgumentException{		
		setNumOfFloors(numOfFloors);
		setNumOfElevators(numOfElevators);
		setMaxPersonsPerElevator(maxPersonsPerElevator);
		setMsPerFloor(timePerFloor);
		setMsDoorOpen(doorOpenTime);
		setElevatorTimeout(elevatorTimeout);		
		setTestList(testList);
	}
	
	/**
	 * Constructor default
	 * @throws InvalidArgumentException
	 */
	public BuildingDTO() throws InvalidArgumentException{
		setNumOfFloors(24);
		setNumOfElevators(4);
		setMaxPersonsPerElevator(12);
		setMsPerFloor(1000);
		setMsDoorOpen(2000);
		setElevatorTimeout(10);
		
		ArrayList<String> genPersonList = new ArrayList<String>();
		genPersonList.add("1,2,2,9");
		genPersonList.add("2,3,6,9");
		
		testList.add(genPersonList);
	}

	/**
	 * Get the number of floors in the building
	 * @return numOfFloors
	 */
	public int getNumOfFloors() {
		return numOfFloors;
	}

	/**
	 * Set the number of floors in the building
	 * @param numOfFloors
	 * @throws InvalidArgumentException
	 */
	private void setNumOfFloors(int numOfFloors) throws InvalidArgumentException{
		if(numOfFloors <= 1)
			throw new InvalidArgumentException("At least two floors in a building");
		
		this.numOfFloors = numOfFloors;
	}

	/**
	 * Get the number of elevators in the building
	 * @return numOfElevators
	 */
	public int getNumOfElevators() {
		return numOfElevators;
	}

	/**
	 * Set the number of elevators in the building
	 * @param numOfElevators
	 */
	private void setNumOfElevators(int numOfElevators) throws InvalidArgumentException{
		if(numOfElevators < 1)
			throw new InvalidArgumentException("At least one elevator in a building");
		
		this.numOfElevators = numOfElevators;
	}

	/**
	 * Get the number of max persons of the elevators
	 * @return maxPersonsPerElevator
	 */
	public int getMaxPersonsPerElevator() {
		return maxPersonsPerElevator;
	}

	/**
	 * Set the max capacity of the elevators
	 * @param maxPersonsPerElevator
	 * @throws InvalidArgumentException
	 */
	private void setMaxPersonsPerElevator(int maxPersonsPerElevator) throws InvalidArgumentException{
		if(maxPersonsPerElevator < 1)
			throw new InvalidArgumentException("Elevator max persons must be > 0");
		
		this.maxPersonsPerElevator = maxPersonsPerElevator;
	}

	/**
	 * Get time per floor, Milliseconds
	 * @return timePerFloor
	 */
	public int getMsPerFloor() {
		return timePerFloor;
	}

	/**
	 * Set the time per floor, Milliseconds
	 * @param timePerFloor
	 * @throws InvalidArgumentException
	 */
	private void setMsPerFloor(int timePerFloor) throws InvalidArgumentException{
		if(timePerFloor <= 0)
			throw new InvalidArgumentException("Time Per Floor must be > 0");
		
		this.timePerFloor = timePerFloor;
	}

	/**
	 * Get the Door open time,Milliseconds
	 * @return doorOpenTime
	 */
	public int getMsDoorOpen() {
		return doorOpenTime;
	}

	/**
	 * Set the door open time,Milliseconds
	 * @param doorOpenTime
	 * @throws InvalidArgumentException
	 */
	private void setMsDoorOpen(int doorOpenTime) throws InvalidArgumentException{
		if(doorOpenTime <= 0)
			throw new InvalidArgumentException("Door open time must be > 0");
		
		this.doorOpenTime = doorOpenTime;
	}
	
	/**
	 * Get Elevator timeout, Seconds
	 * @return elevatorTimeout
	 */
	public int getElevatorTimeout() {
		return elevatorTimeout;
	}

	/**
	 * Set Elevator timeout, Seconds
	 * @param elevatorTimeout
	 */
	private void setElevatorTimeout(int elevatorTimeout) throws InvalidArgumentException{
		if(elevatorTimeout <= 0)
			throw new InvalidArgumentException("Elevator timeout must be > 0");
		
		this.elevatorTimeout = elevatorTimeout;
	}
	
	/**
	 * Set test list
	 * @param tlist
	 */
	private void setTestList(ArrayList<ArrayList<String>> tlist) {
		this.testList = tlist;
	}
	
	/**
	 * Get test list
	 * @return testList
	 */
	public ArrayList<ArrayList<String>> getTestList() {
		return this.testList;
	}

}

package person;

import utils.InvalidArgumentException;

/*
 * Interface of Person.
 * @author Miao Li
 */
public interface IPerson {
	/**
	 * Direction that the person wants to be.
	 */
	public enum Direction {
        UP,
        DOWN,
        NONE
    }
	/**
	 * Status that the person can be in. 
	 */
	public enum Status{
		INITAL,
		WAITING, 
		RIDING, 
		ARRIVAL
	}
	
	/**
	 * Get the Id of this person
	 * @return Person's Id
	 */
	public int getPersonID();
	
	/**
	 * Get the Floor number that this person was generated on.
	 * @return original floor number
	 */
	public int getSrcFloor();
	
	/**
	 * Get the destination floor number that this person wants to
	 * @return destination floor number
	 */
	public int getDestFloor();
	
	/**
	 * Get the elevator id that this person is riding.
	 * @return elevator id
	 */
	public int getRideElevatorID();
    
	/**
	 * Get the direction that this person is going to
	 * @return direction
	 */
	public Direction getDirection();
	
	/**
	 * Get the status of this person
	 * @return status
	 */
	public Status getStatus();
    
	/**
	 * Get how long this person waited for an elevator
	 * @return seconds of waiting
	 */
	public int getWaitingTime();
	
	/**
	 * Get how long this person ride for an elevator
	 * @return seconds of riding
	 */
	public int getRidingTime();
	
	/**
	 * Let this person get into the elevator
	 * @return
	 */
	public void boardElevator(int elevatorId)  throws InvalidArgumentException;
	
	/**
	 * This person arrived at the destination floor and get off the elevator
	 * @return
	 */
	public void arriveFloor() throws InvalidArgumentException;
	
	/**
	 * This person press the button on the floor or in the elevator
	 */
	public void pressButton();
}

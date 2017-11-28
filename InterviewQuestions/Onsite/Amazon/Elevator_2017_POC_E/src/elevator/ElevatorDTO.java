package elevator;

/**
 * DTO of elevator
 * @author Miao Li
 *
 */
public class ElevatorDTO {	
	/**
	 * The current floor of the Elevator
	 */
	public int curFloor;
	
	/**
	 * The current direction of the Elevator
	 */
	public IElevator.Direction direction;
	
	/**
	 * The destinations of the elevator
	 */
	public String destinations;

}

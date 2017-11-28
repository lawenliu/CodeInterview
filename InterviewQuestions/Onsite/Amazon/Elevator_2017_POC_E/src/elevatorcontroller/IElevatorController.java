package elevatorcontroller;

import elevator.ElevatorDTO;
import person.IPerson;

/**
 * Interface of IElevatorController
 * @author Miao Li
 *
 */
public interface IElevatorController {
	/**
	 * Get an elevator to respond to the request.
	 * @return elevator id. 
	 */
	public int chooseElevator(IPerson.Direction reqDir, int reqFloor, ElevatorDTO[] data);

}

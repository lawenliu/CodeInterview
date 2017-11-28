package elevatorcontroller;

import elevator.IElevator;
import person.IPerson;
import elevator.ElevatorDTO;

/**
 * SimpleElvevatorController Class
 * @author Miao Li
 *
 */
public class SimpleElevatorController implements IElevatorController{
	
	/**
	 * Chooses an elevator to respond to the floor request and rider request,
	 * @return The number of the elevator, if -1 there is no elevator can be used.
	 */
	public int chooseElevator(IPerson.Direction reqDir, int reqFloor, ElevatorDTO[] data) {		
		
		for(int i = 0; i < data.length; i++){
			ElevatorDTO elevator = data[i];
			if((elevator.direction == IElevator.Direction.GOING_UP && elevator.curFloor < reqFloor && reqDir == IPerson.Direction.UP) ||
				(elevator.direction == IElevator.Direction.GOING_DOWN && elevator.curFloor > reqFloor && reqDir == IPerson.Direction.DOWN)){
				return i;
			}			
		}
		
		for(int i = 0; i < data.length; i++){
			ElevatorDTO elevator = data[i];
			if(elevator.direction == IElevator.Direction.IDLE){
				return i;
			}
		}

		return -1;
	}

}

package elevatorcontroller;

/**
 * Factory class of IElevatorController
 * @author Miao Li
 *
 */
public class ElevatorControllerFactory {
	/**
	 * Create an elevator controller
	 * @return IElevatorController object reference
	 */
	public static IElevatorController create(){
		return new SimpleElevatorController();
	}

}

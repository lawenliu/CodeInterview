package elevator;
import utils.InvalidArgumentException;

/**
 * Factory class of IElevator
 * author Miao Li
 */

public class ElevatorFactory {
    /**
     * Default constructor
     */
    private ElevatorFactory() {}
    
    /**
     * Create method
     * @param elevatorID
     * @param initFloor
     * @param maxPersons
     * @param msPerFloor
     * @param msStopFloor
     * @param timeout
     * @return IElevator object reference
     * @throws InvalidArgumentException 
     */
    public static IElevator create(int elevatorID, int initFloor,int maxPersons,int msPerFloor,int msStopFloor,int timeout) throws InvalidArgumentException {
        return new SimpleElevatorImpl(elevatorID,initFloor,maxPersons,msPerFloor,msStopFloor,timeout);
    }
}

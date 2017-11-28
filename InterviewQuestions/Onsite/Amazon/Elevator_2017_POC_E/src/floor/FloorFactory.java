package floor;

import utils.InvalidArgumentException;

/**
 * Floor Factory class
 * @author Miao Li
 */

public class FloorFactory {   
    
	/**
	 * Default Constructor
	 */
    private FloorFactory(){}
    
    /**
     * Create method
     * @param floorID The floor number
     * @return IFloor object reference
     */
    public static IFloor create(int floorID) throws InvalidArgumentException{
        return new SimpleFloorImpl(floorID);
    }
}

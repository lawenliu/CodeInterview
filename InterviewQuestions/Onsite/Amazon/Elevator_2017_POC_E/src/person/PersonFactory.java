package person;

import utils.InvalidArgumentException;

/**
 * Factory class for creating Person implementations 
 * @author Miao Li
 */
public class PersonFactory {
    /*
     * Default constructor
     */
    private PersonFactory(){}
    /*
     * SimplePersonImpl Creator
     * @param personID
     * @param srcFloor
     * @param destFloor
     * @return IPerson object reference
     */
    public static IPerson create(int personID,int srcFloor, int destFloor) throws InvalidArgumentException
    {
        return new SimplePersonImpl(personID,srcFloor, destFloor);
    }
    
}

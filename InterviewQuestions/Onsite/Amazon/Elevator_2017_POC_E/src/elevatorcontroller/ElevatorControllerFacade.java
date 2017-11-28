package elevatorcontroller;

import java.util.ArrayList;
import building.BuildingDTO;
import elevator.IElevator;
import floor.FloorFacade;
import person.IPerson;
import elevator.ElevatorDTO;
import elevator.ElevatorFactory;
import utils.InvalidArgumentException;

/**
 * ElevatorControllerFacade class uses the facade pattern
 * @author Miao Li
 *
 */

public class ElevatorControllerFacade {

	/**
	 * Singleton, ElevatorControllerFacade instance itself
	 */
	private static volatile ElevatorControllerFacade self;
	
	/**
	 * List of all the Elevators in the building.
	 */
	private ArrayList<IElevator> elevators;
	
	/**
	 * List of going up floors requests that have not been resolved.
	 */
	private ArrayList<Integer> pendingUpRequests;

	/**
	 * List of going down floors requests that have not been resolved.
	 */
	private ArrayList<Integer> pendingDownRequests;
	
	/**
	 * elevatorController that can choose an elevator to respond to a request.
	 */
	private IElevatorController elevatorController;
	
	/**
	 * Default Constructor
	 */
	private ElevatorControllerFacade(){}
	
	/**
	 * Initializes all Elevators of the building.
	 * @param buildingData
	 * @throws InvalidArgumentException - If data passed into the new elevators is invalid
	 */
	public void startElevators(BuildingDTO buildingData) throws InvalidArgumentException{
		elevators = new ArrayList<IElevator>();
		pendingUpRequests = new ArrayList<Integer>();
		pendingDownRequests = new ArrayList<Integer>();
		elevatorController = ElevatorControllerFactory.create();
		
		for(int i=1; i <= buildingData.getNumOfElevators(); i++){
			elevators.add(ElevatorFactory.create(i,1,buildingData.getMaxPersonsPerElevator(),buildingData.getMsPerFloor(), buildingData.getMsDoorOpen(),buildingData.getElevatorTimeout()));
		}
		
		for(IElevator e : elevators){
			Thread t = new Thread(e);
			t.start();
		}
	}
	
	
	/**
     * Singleton pattern, get itself instance
     * @return self instance
     */
	public static ElevatorControllerFacade getInstance(){
		if(self == null)
			self = new ElevatorControllerFacade();
		
		return self;
	}
	
	/**
	 * Respond to a floor request
	 * @param direction
	 * @param destFloor
	 * @return if there is an elevator respond to the request or not
	 */
	public boolean doFloorRequest(IPerson.Direction direction, int destFloor) throws InvalidArgumentException{
		int elevatorID = elevatorController.chooseElevator(direction, destFloor, getElevatorData());
		
		if(elevatorID >= 0){
			if(destFloor < 1 || destFloor > FloorFacade.getInstance().getNumOfFloors())
				throw new InvalidArgumentException("Elevator being sent out of floor range.");
			IElevator elevator = elevators.get(elevatorID);
			synchronized(elevator){
				elevator.notify();
				elevator.floorRequest(destFloor);
			}
			return true;
		}else{			
			if(direction == IPerson.Direction.UP){
				if(!pendingUpRequests.contains(destFloor))
					pendingUpRequests.add(destFloor);
			}
			else if(direction == IPerson.Direction.DOWN){
				if(!pendingDownRequests.contains(destFloor))
					pendingDownRequests.add(destFloor);
			}
			
		}
		return false;
	}
	
	/**
	 * Get an elevator by its id
	 * @return elevator
	 */
	public IElevator getElevator(int elevatorId) {
		IElevator elevator = null;
		for(int i=0;i<elevators.size();i++){
			if(elevators.get(i).getElevatorID() == elevatorId)
				elevator = elevators.get(i);
		}
		
		return elevator;
	}
	
	/**
	 * Respond to a rider request
	 * @param elevatorId
	 * @param destFloor
	 * @return if there is an elevator respond to the request or not
	 */
	public boolean doRiderRequest(int elevatorId, int destFloor) throws InvalidArgumentException{
		IElevator elevator = getElevator(elevatorId);
		if(elevator == null) {
			return false;
		}
		synchronized(elevator){
			elevator.riderRequest(destFloor);
		}
		return true;
	}
	
	
	/**
	 * Check the pending floor requests list, and execute it
	 * @throws InvalidArgumentException
	 */
	public void checkPendingRequest() throws InvalidArgumentException{
		for(int i = 0; i < pendingUpRequests.size(); i++){
			if(doFloorRequest(IPerson.Direction.UP, pendingUpRequests.get(i))){
				pendingUpRequests.remove(pendingUpRequests.get(i));
			}
		}
		
		for(int i = 0; i < pendingDownRequests.size(); i++){
			if(doFloorRequest(IPerson.Direction.DOWN, pendingDownRequests.get(i))){
				pendingDownRequests.remove(pendingDownRequests.get(i));
			}
		}
	}
	
	/**
	 * Get a List of ElevatorDTO
	 * @return List of elevator's DTO
	 */
	public ElevatorDTO[] getElevatorData(){
		ElevatorDTO[] data = new ElevatorDTO[elevators.size()];
		
		for(int i = 0; i < elevators.size(); i++){
			ElevatorDTO dto = new ElevatorDTO();
			dto.curFloor = elevators.get(i).getCurrentFloor();
			dto.direction = elevators.get(i).getDirection();
			dto.destinations = elevators.get(i).getDestinations();
			data[i] = dto;
		}
		
		return data;
	}
}

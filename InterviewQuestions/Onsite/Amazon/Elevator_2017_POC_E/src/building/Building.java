package building;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import elevatorcontroller.ElevatorControllerFacade;
import floor.FloorFacade;
import gui.ElevatorDisplay;
import person.IPerson;
import person.PersonFactory;
import utils.InvalidArgumentException;
import utils.XMLLoader;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import elevator.IElevator;
import elevator.IElevator.Direction;

/**
 * Building Class
 * @author Miao Li
 *
 */

public class Building {
	
	/**
	 * DTO of building
	 */
	private BuildingDTO buildingData;
	
	/**
	 * Current time counter. 
	 */
	private static volatile int currentTime;
	
	/**
	 * Running state of the simulator
	 */
	private static volatile boolean isRunning;
	
	private final static int msSleepTime = 200;
	private final static int countInOneSec = 1000/msSleepTime;
	/**
	 * Creates a Building
	 * @param inputFile
	 * @throws IllegalStateException
	 * @throws InvalidArgumentException
	 * @throws FileNotFoundException
	 */
	public Building(String inputFile) throws IllegalStateException, InvalidArgumentException, FileNotFoundException{
		isRunning = true;
		currentTime = 0;
		
		buildingData = getBuildingList(inputFile).get(0);
		
		ElevatorDisplay.getInstance().initialize(buildingData.getNumOfFloors());
		for (int i = 1; i <= buildingData.getNumOfElevators(); i++) {
            ElevatorDisplay.getInstance().addElevator(i, 1);
        }
		
		FloorFacade.getInstance().initFloors(buildingData.getNumOfFloors());
		ElevatorControllerFacade.getInstance().startElevators(buildingData);
	}
	
	/**
	 * Get a list of BuildingDTO from the input xml file
	 * @param inputFile
	 * @return BuildingDTO list
	 * @throws InvalidArgumentException
	 */
	private ArrayList<BuildingDTO> getBuildingList(String inputFile) throws InvalidArgumentException{
		ArrayList<BuildingDTO> blist = new ArrayList<>();
		
		XMLLoader xml = new XMLLoader(inputFile);
		if(xml.load()) {
			Element root = xml.getXMLRoot();
            if (!root.getNodeName().equals("Simulation")) {
                throw new InvalidArgumentException(inputFile + " is a vaild Simulation XML file.");
            }
            NodeList buildingList = root.getChildNodes();
            for (int i = 0; i < buildingList.getLength(); i++) {
            	if (buildingList.item(i).getNodeType() == Node.TEXT_NODE) {
                    continue;
                }
            	if (!buildingList.item(i).getNodeName().equals("Building")) {
                    throw new InvalidArgumentException(inputFile + " is a vaild Simulation XML file.");
                }
                Element eleItem = (Element) buildingList.item(i);
                int numOfFloors = Integer.parseInt(eleItem.getElementsByTagName("numOfFloors").item(0).getTextContent());
                int numOfElevators = Integer.parseInt(eleItem.getElementsByTagName("numOfElevators").item(0).getTextContent());
                int maxPersonsPerElevator = Integer.parseInt(eleItem.getElementsByTagName("maxPersonsPerElevator").item(0).getTextContent());
                int timePerFloor = Integer.parseInt(eleItem.getElementsByTagName("timePerFloor").item(0).getTextContent());
                int doorOpenTime = Integer.parseInt(eleItem.getElementsByTagName("doorOpenTime").item(0).getTextContent());
                int elevatorTimeout = Integer.parseInt(eleItem.getElementsByTagName("elevatorTimeout").item(0).getTextContent());
                
                ArrayList<ArrayList<String>> testGenList = new ArrayList<>();
                NodeList testList = eleItem.getElementsByTagName("Test");
                for (int j = 0; j < testList.getLength(); j++) {
                    Element eleTest = (Element) testList.item(j);
                    ArrayList<String> genPersonList = new ArrayList<String>();
                    NodeList pist = eleTest.getElementsByTagName("genPerson");
                    for (int k = 0; k < pist.getLength(); k++) {
                        Element eleGen = (Element) pist.item(k);
                        int id = Integer.parseInt(eleGen.getAttribute("Id"));
                        int genTime = Integer.parseInt(eleGen.getAttribute("GenTime"));
                        int srcFloor = Integer.parseInt(eleGen.getAttribute("SrcFloor"));
                        int destFloor = Integer.parseInt(eleGen.getAttribute("DestFloor"));
                        String person = ""+id+","+genTime+","+srcFloor+","+destFloor;
                        genPersonList.add(person);
                    }
                    testGenList.add(genPersonList);
                }

                blist.add(new BuildingDTO(numOfFloors,numOfElevators,maxPersonsPerElevator,timePerFloor,doorOpenTime,elevatorTimeout,testGenList));
                break;
            }
		}
		else
			blist.add(new BuildingDTO());
		
		return blist;
	}
	
	/**
	 * Generate persons
	 */
	void generatePerson(int testId) {
		if(testId < buildingData.getTestList().size()) {
			ArrayList<String> genPersonList = buildingData.getTestList().get(testId);
			if(genPersonList.size() == 0)
				return;
			String params[] = genPersonList.get(0).split(",");
			int personId = Integer.parseInt(params[0]);
			int genTime = Integer.parseInt(params[1]);
			int srcFloor = Integer.parseInt(params[2]);
			int destFloor = Integer.parseInt(params[3]);
			
			try {
				if(genTime == currentTime/countInOneSec) {
					IPerson person = PersonFactory.create(personId, srcFloor, destFloor);
					FloorFacade.getInstance().addPerson(srcFloor, person);
					person.pressButton();
					genPersonList.remove(0);
				}
			}
			catch(InvalidArgumentException ex) {
				ex.printStackTrace();
			}
		}
	}  
	
	/**
	 * Main loop of simulator
	 * @throws InvalidArgumentException
	 */
	public void runTestCase(int testId) throws InvalidArgumentException{
		try {
			currentTime = 0;
			while(isRunning){
				generatePerson(testId);				
				Thread.sleep(msSleepTime);
				currentTime++;
				ElevatorControllerFacade.getInstance().checkPendingRequest();
				
				if(buildingData.getTestList().get(testId).size() == 0) {
					boolean isFinished = true;
					for(int i=1;i<=buildingData.getNumOfElevators();i++) {
						IElevator e = ElevatorControllerFacade.getInstance().getElevator(i);
						if(e.getDirection() != Direction.IDLE || e.getCurrentFloor() != 1) {
							isFinished = false;
							break;
						}
					}
					if(isFinished)
						break;
				}
			}			
			
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Get time string
	 * @return time string in hh:mm:ss format
	 */
	public static String getTimeString(){
		int sec = currentTime/countInOneSec;
		return String.format("%02d:%02d:%02d", sec / 3600, (sec / 60) % 60, sec % 60);
		
	}
	
	/**
	 * Set Building simulation shutdown
	 * @throws InterruptedException 
	 */
	public void shutdown() throws InterruptedException {
		isRunning = false;
		Thread.sleep(2000);		
		ElevatorDisplay.getInstance().shutdown();
	}
	
	/**
	 * Get running state of the simulator
	 * @return running state
	 */
	public static boolean isRunning(){
		return isRunning;
	}
	
	/**
	 * Get current time count by 1sec
	 * @return seconds from the simulator started
	 */
	public static int getCurrentTime(){
		return currentTime/countInOneSec;
	}
	
}

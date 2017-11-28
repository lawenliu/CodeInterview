package utils;

import java.io.File;
import java.io.IOException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;

/**
 * XML Loader helper class
 * @author Miao Li
 */
public class XMLLoader{
	private String fileName = null;
    private File file = null;
    private Document xml = null;
    
    /**
     * Constructor
     * @param filename
     */
    public XMLLoader(String filename) {
    	fileName = filename;
    }
    
    /**
     * Get the root element of the XML document. 
     * @return root element
     */
    public Element getXMLRoot() {
        return xml.getDocumentElement();
    }
    
    /**
     * Load the XML file
     */
    public boolean load(){
        try {
        	if(fileName == null || fileName.length() == 0) 
        		return false;
        	
            file = new File(fileName);
            if (!file.exists()) {
                return false;
            }
            
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            DocumentBuilder db = dbf.newDocumentBuilder();
            xml = db.parse(file);
            xml.getDocumentElement().normalize();
        }
        catch (ParserConfigurationException | SAXException | IOException ex) {
        	return false;
        }
        return true;
    }
}

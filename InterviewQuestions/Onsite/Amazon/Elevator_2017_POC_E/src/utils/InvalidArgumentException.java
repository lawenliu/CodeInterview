package utils;

/**
 * InvalidArgumentException is thrown when a method get a wrong input parameter
 * @author Miao Li
 */
public class InvalidArgumentException extends Exception {
	private static final long serialVersionUID = 1973318178916096076L;

	public InvalidArgumentException(String msg) {
        super(msg);
    }
}

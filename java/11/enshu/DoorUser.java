public class DoorUser extends Thread {
    private final Door door;
    private final String name;

    public DoorUser(Door d, String s) {
        door = d;
        name = s;
    }
    
    public void run() {
    	while (true) {
    		try {
    			door.pass(name);
    		} catch(InterruptedException ie) {
    		}
    	}
    }
}

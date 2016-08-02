public class Door {

    private String name = "----";

    private final Mutex mutex = new Mutex();

    public void pass(String s) throws InterruptedException {
        mutex.lock();
        try {
        	name = s;
        	Thread.sleep(1);
        	check(s);
            System.out.println(name + " passed.");
        } finally {
            mutex.unlock();
        }
    }

    private void check(String s) {
        if (!s.equals(name)) {
            System.out.println(s + " does not match to the name: " + name);
            System.exit(-1);
        }
    }

    public static void main(String[] args) {
    	Door door = new Door();
        new DoorUser(door, "XXXX").start();
        new DoorUser(door, "YYYY").start();
        new DoorUser(door, "ZZZZ").start();
    }

}
 

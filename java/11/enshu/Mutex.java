public final class Mutex {

	private boolean busy = false;

	Thread prevThread;

	public synchronized void lock() throws InterruptedException{
		while (busy){
			wait();
		}
		busy=true;
	}

	public synchronized void unlock() throws InterruptedException{
		notifyAll();
		busy=false;
		}
}

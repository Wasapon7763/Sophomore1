public class ReaderThread extends Thread {
	private final DataBuffer data;
	
	public ReaderThread(DataBuffer d) {
		data = d;
	}
	
	public void run() {
		try {
			while (true) {
				System.out.println(Thread.currentThread().getName() + " reads " + data.read());
			}
		} catch (InterruptedException e) {
		}
	}
}

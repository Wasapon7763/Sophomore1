public class CountdownThread extends Thread {

	private int value = 0;

	public CountdownThread(int v) {
		value = v;
	}

	public void run() {
		for(int i = 10; i >= 0; i--) {
			try {
				Thread.sleep(i * value);
			} catch(InterruptedException ie) {
			}
			System.out.println(Thread.currentThread() + ": " + i * value);
		}
	}

	public static void main(String[] args) {
		Thread[] threads = new Thread[10];
		for(int i = 0; i < 10; i++) {
			threads[i] = new CountdownThread(i + 1);
			threads[i].start();
		}
		try{
			for (int i=0;i<10;i++){
				threads[i].join();
			}
		} catch (InterruptedException e) {}
		System.out.println("FINISHED.");
	}
}

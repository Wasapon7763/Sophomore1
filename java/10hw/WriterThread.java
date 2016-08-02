import java.util.Random;

public class WriterThread extends Thread {
	private final DataBuffer data;
	private static final Random random = new Random();
	
	public WriterThread(DataBuffer d) {
		data = d;
	}
	
	public void run() {
		try {
			for(int i = 0; i < 10; i++) {
				char c = (char)('0' + i);
				data.append(c);
				System.out.println(Thread.currentThread().getName() + " appends " + c);
				Thread.sleep(random.nextInt(3000));
			}
		} catch (InterruptedException e) {
		}
	} 

}

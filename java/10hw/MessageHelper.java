public class MessageHelper {
	public void handle(int v) {
		try {
			Thread.sleep(100);
			System.out.println("Handled: " + v);
		} catch (InterruptedException e) {
		}
	}
}

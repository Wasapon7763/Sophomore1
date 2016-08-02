public class MessageHost {

	private final MessageHelper helper = new MessageHelper();

	public void request(final int number) {
		new Thread(){
			public void run(){
				for(int i = 1; i <= 10; i++) {
           	helper.handle(number + i);
    		}
			}
		}.start();
	}

	public static void main(String[] args) {
		MessageHost host = new MessageHost();
		host.request(10);
		host.request(100);
		host.request(1000);
	}
}

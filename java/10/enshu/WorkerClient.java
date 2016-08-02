public class WorkerClient {

	public static void main(String[] args) {
		Room room = new Room();
		new Worker(room).start();
		new Worker(room).start();
		new Worker(room).start();
	}

}

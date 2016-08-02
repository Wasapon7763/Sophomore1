public class Scanner extends Thread {
	String data = null;

	public synchronized void run() {
		while(true) {
			notifyAll();
				while (data == null) {
					data="値が設定されています";
					System.out.println("scan: " + data);
				}
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner();
		Fax fax = new Fax(scanner);
		scanner.start();
		fax.start();
	}
}

class Fax extends Thread {
	Scanner scanner = null;

	public Fax(Scanner s) {
		super();
		scanner = s;
	}

	public synchronized void run() {
		while(true) {
			notifyAll();
				while (scanner.data != null) {
					System.out.println("fax : " + scanner.data);
					scanner.data=null;
				}
		}
	}
}

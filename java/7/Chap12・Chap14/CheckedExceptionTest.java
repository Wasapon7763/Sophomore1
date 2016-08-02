import java.io.IOException;

class CheckedExceptionTest {
	
	public static void main(String[] args) {
		CheckedExceptionTest c = new CheckedExceptionTest();
		c.first();
		c.someMethod();
	}
	
	void first() {
		second();
	}
	
	void second() {
		third();
	}
	
	void third() {
		try {
			throw new IOException();
		} catch(IOException ioe)  {
			System.out.println(ioe);
		}
	}
	
	void someMethod() {
		/*
		double[] d = new double[100];
		int i = 100;
		d[i] = 5;
		*/

		try {
			throw new IOException();
		} catch(IOException e) {
			System.out.println("catch 1");
		} catch(Exception ioe) {
			System.out.println("catch 2");
		}
	}

}

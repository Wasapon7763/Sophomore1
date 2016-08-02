abstract class AbstractClassTest {

	abstract void hook();
	
	public static void main(String[] args) {
		// AbstractClassTest c = new AbstractClassTest();
		AbstractClassTest c = new ConcreteClass();
		c.hook();
	}

}

class FactoryTest {
	public static void main(String[] args) {
		Factory[] factories = new Factory[] {
			new BikeFactory(),
			new CarFactory(),
			new CarFactory()
		};
		for(int i = 0; i < factories.length; i++) {
			System.out.println(factories[i].name + "の" + factories[i].produce());
		}
	}
}

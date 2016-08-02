public class Person {

	private final Address address;

	public Person(String s) {
		address = new Address(s);
	}

	public String toString() {
		return "Living in " + address.getText().toString();
	}
}

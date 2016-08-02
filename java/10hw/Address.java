
public class Address {
	
	private final StringBuffer text;
	
	public Address(String s) {
		text = new StringBuffer(s);
	}
	
	public StringBuffer getText() {
		return text;
	}
}

class NamedRectangle extends Rectangle {
	String name = null;
	
	// String width = "TEXT";
	
	String getName() {
		return name;
	}
	
	NamedRectangle() {
		this("TEST");
		// System.out.println(width);
	}
	
	NamedRectangle(String n) {
		super();
		name = n;
		
	}
}

package test;

class Access {

	public String name = null;

	private Access() {
		super();
	}

	public Access(String s) {
		this();
		name = s;
	}

	protected void dosome() {
		System.out.println("didsome");
	}
}

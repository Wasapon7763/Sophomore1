class MyNumber implements DebugPrintable {
	int number;
	
	MyNumber(int n) {
		number = n;
	}
	
	public void debugPrint() {
		System.out.println("MyNumber: " + number);
		/*
		System.out.println(PREFIX + "MyNumber: " + number); 
		System.out.println(DebugPrintable.PREFIX + "MyNumber: " + number);
		*/
	}
	
	public static void main(String[] args) {
		// DebugPrintable d =  new DebugPrintable();
		Rectangle d1 = new Rectangle(200,100);
		MyNumber d2 = new MyNumber(999);
		d1.debugPrint();
		d2.debugPrint();
		
		/*
		DebugPrintable[] set = new DebugPrintable[5];
		set[0] = new Rectangle(200,100);
		set[1] = new MyNumber(999);
		set[2] = new MyNumber(100);
		set[3] = new Rectangle(10,10);
		set[4] = new MyNumber(3);
		for(int i = 0; i < set.length; i++) {
			set[i].debugPrint();
		}
		*/
	}

	public boolean sendTo(String email) {
		if(email != null) {
			return true;
		} else {
			return false;
		}
	}
	
	/*
	public String anotherMethod() {
		return PREFIX + anotherField;
	}
	*/
 
}
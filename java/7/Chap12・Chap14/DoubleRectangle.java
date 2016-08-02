class DoubleRectangle extends Rectangle {
	
	int getArea() {
		return width * height * 2;
		// return super.getArea() * 2;
	}
	
	 static int getCounter() {
		 return counter + 1000;
	 }
	
	 public static void main(String[] args) {
		 Rectangle r1 = new Rectangle();
		 Rectangle r2 = new DoubleRectangle();
		 DoubleRectangle r3 = new DoubleRectangle();
		 System.out.println(r1.getCounter());
		 System.out.println(r2.getCounter());
		 System.out.println(Rectangle.getCounter());
		 System.out.println(r3.getCounter());
		 System.out.println(DoubleRectangle.getCounter());
	 }

}

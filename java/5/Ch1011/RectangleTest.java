class RectangleTest {

	public static void main(String[] args) {
		NamedRectangle nr = new NamedRectangle();
		nr.name = "TEST";
		System.out.println(nr.name);
		System.out.println(nr.getName());
		
		/*
		nr.width = 123;
		System.out.println(nr.width);
		System.out.println(nr.getArea());
		*/
		
		// Rectangle r1 = new Rectangle();
		// Rectangle r2 = new Rectangle(99,99);
		// NamedRectangle nr3 = new NamedRectangle();
		// NamedRectangle nr4 = new NamedRectangle("foo");
		// NamedRectangle nr5 = new NamedRectangle(99,99);
		
		/*
		System.out.println(nr.getName());
		System.out.println(((NamedRectangle) nr).getName());
		if(nr instanceof NamedRectangle) {
			System.out.println(((NamedRectangle) nr).getName());
		}
		*/
		
		/*
		Rectangle rr1 = new Rectangle();
		Rectangle rr2 = new DoubleRectangle();
		DoubleRectangle rr3 = new DoubleRectangle();
		System.out.println(rr1.getCounter());
		System.out.println(rr2.getCounter());
		System.out.println(Rectangle.getCounter());
		System.out.println(rr3.getCounter());
		System.out.println(DoubleRectangle.getCounter());
		 */
	}
}

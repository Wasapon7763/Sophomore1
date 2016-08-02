class RectangleTest {

	public static void main(String[] args) {
		Rectangle nr = new NamedRectangle();
		// System.out.println(nr.getName());
		System.out.println(((NamedRectangle) nr).getName());
		if(nr instanceof NamedRectangle) {
		 System.out.println(((NamedRectangle) nr).getName());
		}
		
		Rectangle r = new Rectangle();
		r.setSize(10,5);
		System.out.println(r);
		r.setSize(10,5,10);
		System.out.println(r);
	}
}

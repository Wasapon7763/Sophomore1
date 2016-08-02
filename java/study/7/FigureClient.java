public class FigureClient {
	public static void main(String[] args) {
		Figure[] figures = new Figure[2];
		figures[0] = new Point(0,0);
		figures[1] = new Line(new Point(5,8), new Point(10,20));
		for(int i = 0; i < figures.length; i++) {
			figures[i].move(100,200);
			System.out.println(figures[i].draw());
		}
	}
}

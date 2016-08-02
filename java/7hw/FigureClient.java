public class FigureClient {
	public static void main(String[] args) {
		Figure[] figures = new Figure[2];
		figures[0] = new Point2(0,0);
		figures[1] = new Line2(new Point2(5,8), new Point2(10,20));
		for(int i = 0; i < figures.length; i++) {
			figures[i].move(100,200);
			System.out.println(figures[i].draw());
		}
	}
}

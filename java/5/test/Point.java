public class Point{
    int x, y;
    static int totx=0;
    static int toty=0;
    Point(int kx, int ky){
	x=kx;
	y=ky;
	totx+=kx;
	toty+=ky;
    }
    public String toString(){
	return "("+x+", "+y+")";
    }
    public static void main(String[] args){
	Point[] pt={new Point(100, 10), new Point(-5, 20), new Point(0, 0)};
	for (int i=0;i<3;i++) System.out.println(pt[i]);
	System.out.println("x座標値の合計="+Point.totx);
	System.out.println("y座標値の合計="+Point.toty);
    }
}
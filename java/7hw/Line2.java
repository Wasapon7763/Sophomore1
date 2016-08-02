class Line2 extends Figure{
    Point2 p1;
    Point2 p2;
    Line2(Point2 p1, Point2 p2){
      this.p1=p1;
      this.p2=p2;
    }
    public String draw(){
      return "(("+p1.x+","+p1.y+")"+"("+p2.x+","+p2.y+"))";
    }
    public void move(int mx, int my){
      p1.x+=mx;
      p1.y+=my;
      p2.x+=mx;
      p2.y+=my;
    }
}

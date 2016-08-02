class Point2 extends Figure{
  int x, y;
  Point2(int x, int y){
    this.x=x;
    this.y=y;
  }
  public String draw(){
    return "("+x+","+y+")";
  }
  public void move(int mx, int my){
    x+=mx;
    y+=my;
  }
}

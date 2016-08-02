class Point extends Figure{
  int x, y;
  Point(int x, int y){
    this.x=x;
    this.y=y;
  }
  String draw(){
    return "("+x+","+y+")";
  }
  void move(int mx, int my){
    x+=mx;
    y+=my;
  }
}

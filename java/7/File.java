class File{
  String name;
  static int size;
  File(String n, int s){
    name=n;
    size=s;
  }
  String getName(){
    return name;
  }
  int getSize(){
    return size;
  }
}

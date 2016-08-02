class A{
  static int tot=0;
  A(){
    tot++;
  }
  String m(){
    return "a";
  }
  static int getCounter(){
    return tot;
  }
}

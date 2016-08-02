class Text implements Countable{
  String text;
  Text(String s){
    if (s==null) text="";
    else text=s;
  }
  public int count(){
    return text.length();
  }
}

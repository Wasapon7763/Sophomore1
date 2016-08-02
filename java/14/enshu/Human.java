public class Human implements Namable{
  public String name="";
  public Human(String name){
    this.name=name;
  }
  public void getName(){
    System.out.println(name);
  }
}

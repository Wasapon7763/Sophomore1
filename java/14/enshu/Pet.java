public class Pet implements Namable{
  public String name="";
  public Pet(String name){
    this.name=name;
  }
  public void getName(){
    System.out.println(name);
  }
}

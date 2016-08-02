package animal;

public class Cat extends Animal{
  public static Cat c;
  Cat(){
    
  }
  public static Cat getInstance(){
    c=new Cat();
    return c;
  }
  public String say(){
    return "ニャー";
  }
}

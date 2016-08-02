package animal;

public class Cat extends Animal{
  private static Cat instance=new Cat();
  public static Cat getInstance(){
    return instance;
  }
  public String say(){
    return "ニャー";
  }
}

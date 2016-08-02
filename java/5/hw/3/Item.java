public class Item {
  String name;
  int price;
  int num;
  static int counter=0;

  Item(String n, int p){
    name=n;
    price=p;
    num=counter;
    counter++;
  }

  static int getNumberOfInstances(){
    return counter;
  }

  public String toString(){
    return name+", "+price;
  }
}

import java.util.*;
import java.io.*;
public class House {
  List<Human> listH=new ArrayList<Human>();
  List<Pet> listP=new ArrayList<Pet>();
  int cost=0;

  public void add(Human h) throws RuntimeException{
    listH.add(h);
    cost+=4;
    if (cost>20) throw new RuntimeException();
  }
  public void remove(Human h){
    listH.remove(h);
    cost-=4;
  }

  public void add(Pet p) throws RuntimeException{
    listP.add(p);
    cost+=1;
    if (cost>20) throw new RuntimeException();
  }
  public void remove(Pet p){
    listP.add(p);
    cost-=1;
  }

  public void showList(){
    System.out.println("Human");
    for (int i=0;i<listH.size();i++){
      listH.get(i).getName();
    }
    System.out.println("Pet");
    for (int i=0;i<listP.size();i++){
      listP.get(i).getName();
    }
  }
}

import java.util.*;
public class Folder extends Text {
  public List<Text> list = new ArrayList<Text>();
  public Folder() {
    super(null);
  }
  public void add(Text text) { list.add(text); }
  public void remove(Text text) { list.remove(text); }
  public String toString() {
    String result = "";
    for(Text text: list) result += text; return result;
  }

  public String breadth() {
    String result = "";
    Queue<Text> queue = new LinkedList<Text>();
    for(Text text: list) queue.add(text);

    while(!queue.isEmpty()) {
      Text i = queue.poll();
      if(i instanceof Folder)
      for(Text j: ((Folder) i).list) queue.add(j);
      else result += i;
    }
    return result;
  }
  public String breadth(){
    String result = "";
    Queue<Text> queue = new LinkedList<Text>();
    for(Text text: list) queue.add(text);

    while(!queue.isEmpty()) {
      Text i = queue.poll();
      if(i instanceof Folder)
        for(Text j: ((Folder) i).list) queue.add(j);
      else result += i;
    }
    return result;
  }
}

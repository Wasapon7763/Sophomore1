class ThreadXX2 extends Thread {
  MessagePrint m = null;
  public ThreadXX2(MessagePrint nm) {
    super();
    m = nm;
  }
  public void run() {
    try{
      while(true) {
        m.message("XX");
      }
    } catch (InterruptedException e){

    }
  }
}

class ThreadYY2 extends Thread {
  MessagePrint m = null;
  public ThreadYY2(MessagePrint nm) {
    super();
    m = nm;
  }
  public void run() {
    try{
      while(true) {
        m.message("YY");
      }
    } catch (InterruptedException e){

    }
  }
}

class MessagePrint {
  static int n;
  public synchronized void message(String text) throws InterruptedException{
    int p=Thread.currentThread();
    System.out.println(text);
    notifyAll();
    Thread.currentTherad()=wait();
  }
}

public class ThreadEx2 {
  public static void main(String[] args) {
    MessagePrint m = new MessagePrint();
    new ThreadXX2(m).start();
    new ThreadYY2(m).start();
  }
}

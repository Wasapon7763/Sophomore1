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
    }
    catch(InterruptedException ie){

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
    }
    catch(InterruptedException ie){}
  }
}

class MessagePrint {
  Thread t=null;
  public synchronized void message(String text) throws InterruptedException{
    while (t==Thread.currentThread()){
      wait();
    }
    t=Thread.currentThread();
    System.out.println(text);
    notifyAll();
  }
}

public class ThreadEx2 {
  public static void main(String[] args) {
    MessagePrint m = new MessagePrint();
    new ThreadXX2(m).start();
    new ThreadYY2(m).start();
  }
}

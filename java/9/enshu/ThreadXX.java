public class ThreadXX extends Thread{
  public void run() {
    while (true){
      System.out.println("XX");
      try{
        Thread.sleep(2000);
      }
      catch (InterruptedException ie){ }
    }
  }
}

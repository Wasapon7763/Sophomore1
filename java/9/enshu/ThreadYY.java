public class ThreadYY implements Runnable{
  public void run() {
    while (true){
      System.out.println("YY");
      try{
        Thread.sleep(500);
      }
      catch (InterruptedException ie){ }
    }
  }
}

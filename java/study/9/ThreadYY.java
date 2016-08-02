class ThreadYY implements Runnable{
  public void run(){
    while (true){
      try{
        Thread.sleep(500);
        System.out.println("YY");
      }
      catch (InterruptedException ie){}
    }
  }
}

class ThreadXX extends Thread{
  public void run(){
    while (true){
      try{
        sleep(2000);
        System.out.println("XX");
      }
      catch (InterruptedException ie){}
    }
  }
}

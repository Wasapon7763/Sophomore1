import java.util.Random;

public class Room {
    private Random random = new Random();
    static boolean fill=false;
    public synchronized void rest() throws InterruptedException{
      if (fill) throw new InterruptedException();
      fill=true;
      System.out.println("Start resting :" + Thread.currentThread().getName());
        try {
          Thread.sleep(random.nextInt(5000));
        } catch (InterruptedException e) {
        }
        fill=false;
        System.out.println("End resting :" + Thread.currentThread().getName());
    }

}

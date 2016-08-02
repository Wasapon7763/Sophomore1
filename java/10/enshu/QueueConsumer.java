class QueueConsumer extends Thread {
    Queue queue = null;
    QueueConsumer(Queue q) {
	     queue = q;
    }

    public void run() {
      try{
	     while (true) {
	        int x = queue.dequeue();
	         System.out.println(getName() + " " + x + " を消費");
	          sleepRandomly();
	     }
      }
      catch (InterruptedException ie){ }
    }

    void sleepRandomly() {
	     try {
	        int n = (int)(Math.random() * 1000);
	         Thread.sleep(n);
	     } catch (InterruptedException e) {
	     }
    }
}

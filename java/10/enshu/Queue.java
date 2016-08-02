public class Queue {
	private int[] values = null;
	private int first = 0;
	private int last = 0;

	public Queue(int size) {
		values = new int[size+1];
	}

	public synchronized void enqueue(int data) throws InterruptedException{
		while (isFull()){
			wait();
		}
		values[last] = data;
		last = (last + 1) % values.length;
		System.out.println("Enqueue: " + data);
	}

	public synchronized int dequeue() throws InterruptedException{
		while (isEmpty()){
			wait();
		}
		int data = values[first];
		first = (first + 1) % values.length;
	    	System.out.println("Dequeue: " + data);
	        return data;
	}

	public boolean isFull() {
		return (((last + 1) % values.length) == first);
	}

	public boolean isEmpty() {
		return (last == first);
	}

	public static void main(String[] args) {
		Queue q = new Queue(3);
		try {
		for(int i = 0; !q.isFull(); i++) q.enqueue(i);
		q.dequeue();
		q.enqueue(4);
		q.dequeue();
		while (!q.isEmpty()) q.dequeue();
	} catch	(InterruptedException ie){}
	}
}

public class Queue {
	private int[] values = null;
	private int first = 0;
	private int last = 0;

	public Queue(int size) {
		values = new int[size+1];
	}

	public void enqueue(int data) {
		if (isFull()) throw new RuntimeException();
		values[last] = data;
		last = (last + 1) % values.length;
		System.out.println("Enqueue: " + data);
	}

	public int dequeue() {
		if(isEmpty()) throw new RuntimeException();
		int data = values[first];
		first = (first + 1) % values.length;
	    	System.out.println("Dequeue: " f+ data);
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
		for(int i = 0; !q.isFull(); i++) q.enqueue(i);
		q.dequeue();
		q.enqueue(4);
		q.dequeue();
		while (!q.isEmpty()) q.dequeue();
	}
}

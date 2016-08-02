public class QueueClient {
	public static void main(String[] args) {
		Queue queue = new Queue(3);
		QueueProducer producer = new QueueProducer(queue);
		QueueConsumer consumer = new QueueConsumer(queue);
		producer.start();
		consumer.start();
	}
}

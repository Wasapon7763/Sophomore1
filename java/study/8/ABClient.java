public class ABClient {
	public static void main(String[] args) {
		System.out.println( A.getCounter() );
		System.out.println( new A().m() );
		System.out.println( new B( new A() ).m() );
		System.out.println( new B( new B( new A() ) ).m() );
		System.out.println( A.getCounter() );
	}
}

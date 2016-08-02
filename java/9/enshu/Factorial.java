public class Factorial {

	public static int factorial1(int n){
		int fact=1;
		for (int i=n;i>=1;i--) fact*=i;
		return fact;
	}

	public static int factorial2(int n){
		if (n==0) return 1;
		if (n==1) return 1;
		else return n*factorial2(n-1);
	}

	public static int factorial3(int n) throws RuntimeException {
		int fact=1;
		long lfact;

		for (int i=n;i>=1;i--){
			fact*=i;
			lfact=fact;
			if (fact>Integer.MAX_VALUE/2){
				 throw new RuntimeException();
			}
		}
		return fact;
	}

	public static void main(String[] args) {
		try{
			System.out.println(factorial1(0));
			System.out.println(factorial2(0));
			System.out.println(factorial1(10));
			System.out.println(factorial2(10));
			System.out.println(factorial3(13));
		}
		catch (RuntimeException re){
			System.out.println(re);
		}
	}
}

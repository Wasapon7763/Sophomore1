
public class GCD_LCM {

	public static int gcd1(int a, int b){
		int c;
		while (b!=0){
			c=a%b;
			a=b;
			b=c;
		}
		return a;
	}

	public static int gcd2(int a, int b) {
		if (b==0) return a;
		return gcd2(b, a%b);
	}

	public static int lcm(int a, int b) {
		return a*b/gcd1(a, b);
	}

	public static void main(String[] args) {
		System.out.println(gcd1(6, 3));
		System.out.println(lcm(6, 3));
		System.out.println(gcd2(6, 8));
		System.out.println(lcm(6, 8));
	}
}

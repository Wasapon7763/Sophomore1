public class Method {
    public static void main(String[] args) {
	System.out.println(getPower(0, 0));
    }
    public static int getPower(int base, int exponent) { 
	int power = 1;
	for (int i = 0; i < exponent; i++) {
	    power = power * base;
	}
	return power;
    }
}
public class DiscTower {

	public static void disc1(char start, char mid, char target, int n) {
		if(n == 1) {
			move(start, target);
		} else if(n == 2) {
			move(start, mid);
			move(start, target);
			move(mid, target);
		}
	}

	public static void disc2(char start, char mid, char target, int n) {
		if (n==0) return;
		disc1(start, target, mid, n-1);
		move(start, target);
		disc1(mid, start, target, n-1);
	}

	public static void move(char start, char target) {
		System.out.println(start + " -> " + target);
	}

	public static void main (String[] args) {
		System.out.println("Move 1 Disc from A to C");
		disc1('A', 'B', 'C', 1);
		System.out.println("Move 2 Discs from A to C");
		disc1('A', 'B', 'C', 2);
		System.out.println("Move 3 Discs from A to C");
		disc2('A', 'B', 'C', 3);
	}

}

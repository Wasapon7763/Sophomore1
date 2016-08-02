public class CountableTest {
	public static void main(String[] args) {
		Countable[] countables = new Countable[3];
		countables[0] = new Text("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		countables[1] = new Text(null);
		countables[2] = new IntArray(null);
		for(int i = 0; i < countables.length; i++) {
			System.out.println(countables[i].count());
		}
	}
}

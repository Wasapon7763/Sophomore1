import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int c=0;
		int[] t={-10, -5, -1, 1, 5, 10};
		Queue<Integer> q = new LinkedList<Integer>();
		HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
		q.add(A);
		map.put(A, c);
		while (true){
			int temp=q.poll();
			int n=map.get(temp);
			if (temp==B){
				System.out.println(map.get(temp));
				break;
			}
			for (int i:t){
				if (map.get(temp+i)==null){
					q.add(temp+i);
					map.put(temp+i, n+1);
				}
			}
		}
	}
}

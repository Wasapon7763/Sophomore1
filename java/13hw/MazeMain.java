import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class MazeMain {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int startX = 0, startY = 0;
		int goalX = 0, goalY = 0;
		char[][] map = new char[10][10];
		int[][] distance = new int[10][10]; // Distance from starting point
		for(int y = 0; y < 10; y++) {
			String line = scanner.nextLine();
			for(int x = 0; x < 10; x++) {
				map[x][y] = line.charAt(x);
				switch(map[x][y]) {
				case 'S': startY = y; startX = x; distance[x][y] = 0; break;
				case 'G': goalY = y; goalX = x; distance[x][y] = -1; break;
				case '.': distance[x][y] = -1; break;
				default: break;
				}
			}
		}
		Queue<Point> queue = new LinkedList<Point>();
		int[] directionX = { -1, 0, 1, 0 }; // Left, Up, Right, Down
		int[] directionY = { 0, -1, 0, 1 }; // Left, Up, Right, Down
		queue.add(new Point(startX, startY)); // Add starting point to queue.
		while(!queue.isEmpty()) {
			// Poll point from queue.
			Point p=queue.poll();
			// If the point is goal, break loop.
			if (p.x==goalX&&p.y==goalY) break;
			// For all possible directions,
			//   if corresponding distance is not set and point is valid,
			//   then set its distance from starting point, and add the point to queue.
			for (int i=0;i<4;i++){
				int nx=p.x+directionX[i], ny=p.y+directionY[i];
				if ((nx<=9&&nx>=0)&&(ny<=9&&ny>=0)&&distance[nx][ny]==-1){
					distance[nx][ny]=distance[p.x][p.y]+1;
					queue.add(new Point(nx, ny));
				}
			}
		}
		System.out.println(distance[goalX][goalY]);
	}
}

class Point {
	int x = 0;
	int y = 0;
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

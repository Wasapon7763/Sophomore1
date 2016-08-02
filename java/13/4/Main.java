import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char[][] board = new char[8][8];
		for(int i = 0; i < 8; i++) {
			String st = scanner.next();
			for(int j = 0; j < 8; j++) {
				board[i][j] = st.charAt(j);
			}
		}
		if(dfs(0, board)) {
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					System.out.print(board[i][j]);
				}
				System.out.println();
			}
		} else {
			System.out.println("No Answer");
		}
	}

	static boolean dfs(int y, char[][] board) {
	  // If eight queens are put, return true.
	  if (y==8) return true;
		// If a queen is already put on the row, store its location in "target".
		int c=0, target=-1;
    for (int i=0;i<8;i++){
      if (board[y][i]=='Q'){
        c++;
        target=i;
      }
    }
    if (c==2){
    // Moreover if there are two or more queens on the row, return false.
      return false;
    }
    else if (c==1){
		// If the row already has one queen, check whether its location is puttable.
		// And if it is puttable, continue search for next row.
      if (!isPuttable(y, target, board)) return false;
      return dfs(y+1, board);
    }
    else if(c==0){
		// If the row contains no queen, for all columns,
		//     Try to put a queen and
		//     continue search for next row.
		//     If it failed, remove the queen.
      for (int i=0;i<8;i++){
        if (isPuttable(y, i, board)){
          board[y][i]='Q';
          if (dfs(y+1, board)) return true;
          board[y][i]='.';
        }
      }
    }
		return false;
	}

	static boolean isPuttable(int y, int x, char[][] board) {
		for(int vy = -1; vy <= 1; vy++) {
			for(int vx = -1; vx <= 1; vx++) {
				if(vy == 0 && vx == 0) continue;
				int ty = y;
				int tx = x;
				while(true) {
					ty += vy;
					tx += vx;
					if(ty < 0 || ty >= 8 || tx < 0 || tx >= 8) break;
					if(board[ty][tx] == 'Q') return false;
				}
			}
		}
		return true;
	}

}

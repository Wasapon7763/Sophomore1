import java.io.*;
import java.util.Scanner;
public class Main{
    public static int cnt;
    public static void main(String[] args){
	Scanner sc= new Scanner(System.in);
	while (true){
	    cnt=0;
	    int w=sc.nextInt();
	    int h=sc.nextInt();
	    if (w==0&&h==0) break;
	    int grid[][]=new int[h+2][w+2];
	    for (int i=0;i<h+2;i++){
		for (int j=0;j<w+2;j++){
		    if (i==0||i==h+1||j==0||j==w+1)
			grid[i][j]=-1;
		    else
			grid[i][j]=sc.nextInt();
		}
	    }
	    for (int i=1;i<h+1;i++){
		for (int j=1;j<w+1;j++){
		    if (grid[i][j]==1){
			grid=get_island(j, i, grid);
			cnt++;
		    }
		}
	    }
	    System.out.println(cnt);
	}
    }
    public static int[][] get_island(int x, int y, int grid[][]){
	grid[y][x]=0;
	if (grid[y+1][x]==1) get_island(x, y+1, grid);
	if (grid[y-1][x]==1) get_island(x, y-1, grid);	
	if (grid[y][x+1]==1) get_island(x+1, y, grid);
	if (grid[y][x-1]==1) get_island(x-1, y, grid);
	if (grid[y+1][x+1]==1) get_island(x+1, y+1, grid);
	if (grid[y-1][x-1]==1) get_island(x-1, y-1, grid);
	if (grid[y+1][x-1]==1) get_island(x-1, y+1, grid);
       	if (grid[y-1][x+1]==1) get_island(x+1, y-1, grid);
	return grid;
    }
}
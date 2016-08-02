import java.io.*;
import java.util.Scanner;
public class Triangle{
  public static int[][] tri;
  public static int max=0, N;
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    N=sc.nextInt();
    tri=new int[N][N];
    for (int i=0;i<N;i++){
      for (int j=0;j<i+1;j++) tri[i][j]=sc.nextInt();
    }
    solve(0, tri[0][0]);
    System.out.println(max);
  }
  public static void solve(int level, int cost){
    if (max<cost) max=cost;
    if (level+1>=N) return;
    for (int i=0;i<level+2;i++){
      solve(level+1, cost+tri[level+1][i]);
    }
  }
}

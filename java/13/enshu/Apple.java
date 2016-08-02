import java.util.Scanner;
import java.io.*;
public class Apple{
  public static int[][] dp;
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int M=sc.nextInt();
    int N=sc.nextInt();
    dp=new int[M+1][N+1];
    long start=System.currentTimeMillis();
    System.out.println(dfs(M, N));
    long t1=System.currentTimeMillis();
    System.out.println(dfsM(M, N));
    long t2=System.currentTimeMillis();
    System.out.println(Math.abs(t1-t2));

  }
  public static int dfs(int m, int n){
    if (n==1) return 1;
    int ret=0;
    for (int i=0;i<=m;i++){
      ret+=dfs(m-i, n-1);
    }
    return ret;
  }
  public static int dfsM(int m, int n){
    if (dp[m][n]!=0) return dp[m][n];
    if (n==1) return dp[m][n]=1;
    int ret=0;
    for (int i=0;i<=m;i++) ret+=dfs(m-i, n-1);
    return dp[m][n]=ret;
  }
}

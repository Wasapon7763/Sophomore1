import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	while (true){
	    int n=sc.nextInt();
	    int r=sc.nextInt();
	    if (n==0&&r==0) break;
	    int yama[]=new int[n+1];
	    for (int i=1;i<n+1;i++) yama[i]=i;
	    for (int i=0;i<r;i++){
		int p=sc.nextInt();
		int c=sc.nextInt();
		int cpy[]=new int[p-1];
		for (int j=0;j<p-1;j++) cpy[j]=yama[n-j];
		for (int j=0;j<c;j++){
		    yama[n-j]=yama[n-p-j+1];
		}
		for (int j=0;j<p-1;j++){
		    yama[n-c-j]=cpy[j];
		}
	    }
	    System.out.println(yama[n]);
	}
    }
}
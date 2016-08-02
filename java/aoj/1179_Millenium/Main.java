import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	int n, y, m, d, mil;
	mil=getDate(1000, 1, 1);
	Scanner sc=new Scanner(System.in);
	n=sc.nextInt();
	for (int i=0;i<n;i++){
	    y=sc.nextInt();
	    m=sc.nextInt();
	    d=sc.nextInt();
	    System.out.println(mil-getDate(y, m, d));
	}
    }
    public static int getDate(int y, int m, int d){
	int c=0;
	Boolean b=false;
	for (int i=1;i<=y;i++){
	    if (i%3==0) b=true;
	    if (i!=y){
		for (int j=1;j<=10;j++){
		    if (j%2==0&&!b) c+=19;
		    else c+=20;
		}
	    }
	    else{
		for (int j=1;j<m;j++){
		    if (j%2==0&&!b) c+=19;
                    else c+=20;
		}
	    }
	    b=false;
	}
	c+=(d-1);
	return c;
    }
}
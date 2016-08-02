import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	for (int i=0;i<n;i++){
	    int y=sc.nextInt();
	    int c=0;
	    if (y%4!=0){
		c=-1;	
	    }
	    while (c!=-1&&y>=1896){
		y-=4;
		c++;
	    }
	    System.out.println(c);
	}
    }
}
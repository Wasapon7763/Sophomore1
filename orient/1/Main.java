import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	String ss=sc.nextLine();
	for (int i=0;i<n;i++){
	    int min=200000;
	    String s=sc.nextLine();
	    Scanner kb=new Scanner(s);
	    int num[]=new int[3];
	    int k=0;
	    while (kb.hasNextInt()){
		num[k]=kb.nextInt();
		k++;
	    }
	    for (int j=k;j<3;j++){
		num[j]=10001;
	    }
	    for (int j=1;j<3;j++){
		if (Math.abs(num[0]-num[j])<min) min=Math.abs(num[0]-num[j]);
	    }
	    for (int j=1;j>=0;j--)
		if (Math.abs(num[2]-num[j])<min) min=Math.abs(num[0]-num[j]);
	    System.out.println(min);
	}
    }
}
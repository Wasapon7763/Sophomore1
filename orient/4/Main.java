import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	while (true){
	    int n=sc.nextInt();
	    if (n==0) break;
	    String ss=sc.nextLine();
	    String s=sc.nextLine();
	    int a=(int)'a';
	    for (int i=0;i<n;i++){
		
		if (s.charAt(i)=='+'){
		    if (a==(int)'z') a=(int)'a';
		    else  a++;
		}
		if (s.charAt(i)=='-'){
		    if (a==(int)'a') a=(int)'z';
                    else  a--;
		}
		if (s.charAt(i)=='.'){
		    System.out.print((char)a);
		}
	    }
	    System.out.println();
	}
    }
}
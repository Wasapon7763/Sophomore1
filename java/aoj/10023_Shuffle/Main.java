import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	while (true){
	    String s=sc.nextLine();
	    if (s.equals("-")) break;
	    int n=sc.nextInt();
	    int move[]=new int[n];
	    for (int i=0;i<n;i++) move[i]=sc.nextInt();
	    for (int i=0;i<n;i++){
		String s1=s.substring(0,move[i]);
		String s2=s.substring(move[i],s.length());
		s=s2+s1;
	    }
	    System.out.println(s);
	    sc.nextLine();
	}
    }
}
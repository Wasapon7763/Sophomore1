import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	while (true){
	    int n=sc.nextInt();
	    if (n==0) break;
	    int score[]=new int[n];
	    int max=0,min=0,tot=0;
	    boolean mx=true;
	    boolean mn=true;
	    for (int i=0;i<n;i++){
		score[i]=sc.nextInt();
		if (i==0){
		    max=score[i];
		    min=score[i];
		}
		if (score[i]>=max) max=score[i];
		if (score[i]<=min) min=score[i];
	    }
	    for (int i=0;i<n;i++){
		if (score[i]==max&&mx) mx=false;
		else if(score[i]==min&&mn) mn=false;
		else{
		    tot+=score[i];
		}
	    }
	    System.out.println(tot/(n-2));
	}
    }
}
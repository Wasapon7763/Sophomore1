import java.io.*;
import java.util.Scanner;
import java.lang.Math;
public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	while (true){
	    int n=sc.nextInt();
	    if (n==0) break;
	    int s[]=new int[n];
	    double m=0;
	    double tot=0;
	    double a;
	    for (int i=0;i<n;i++){
		s[i]=sc.nextInt();
		m+=s[i];
	    }
	    m/=n;
	    for (int i=0;i<n;i++){
		tot+=((s[i]-m)*(s[i]-m));
	    }
	    tot/=n;
	    a=Math.sqrt(tot);
	    System.out.printf("%f\n",a);
	}
    }
}
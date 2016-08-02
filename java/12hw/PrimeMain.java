import java.io.*;
import java.util.*;
public class PrimeMain{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	System.out.println(getPrime(n));
    }
    public static int getPrime(int n){
	int[] p=new int[n+1];
	int c=0;
	p[1]=0;
	for (int i=2;i<=n;i++){
	    p[i]=1;
	    if (i%2==0&&i!=2){
		p[i]=0;
		continue;
	    }
	    for (int j=3;j<=Math.sqrt(n);j++){
		if (i%j==0&&i!=j){
		    p[i]=0;
		    break;
		}
	    }
	}
	for (int i=1;i<=n;i++){
	    if (p[i]==1) c++;
	}
	return c;
    }
}
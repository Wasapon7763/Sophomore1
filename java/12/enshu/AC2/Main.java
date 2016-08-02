import java.util.*;
public class Main{
    public static void main(String[] args){
	int m, n, N, r=0, tot;
	Scanner sc=new Scanner(System.in);
	m=sc.nextInt();
	n=sc.nextInt();
	N=sc.nextInt();
	tot=N;
	while (m<=N){
	    r=N%m;
	    N=(N/m)*n;
	    tot+=N;
	    N+=r;
	}
	System.out.println(tot);
    }
}
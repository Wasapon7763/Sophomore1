import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
	int N;
	double max=0;
	double x[]=new double[100];
	double y[]=new double[100];
	Scanner sc=new Scanner(System.in);
	N=sc.nextInt();
	for (int i=0;i<N;i++){
	    x[i]=sc.nextDouble();
	    y[i]=sc.nextDouble();
	}
	for (int i=0;i<N;i++){
	    for (int j=0;j<N;j++){
		double d=Math.sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		if (max<d) max=d;
	    }
	}
	System.out.println(max);
    }
}
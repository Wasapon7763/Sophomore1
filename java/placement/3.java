import java.io.*;
import java.util.Scanner;
public class Main{
    public static int f(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	return f(n-1)+f(n-2);
    }
    public static void main(String[] args){
	int i=0;
	while (f(i)<10000){
	    System.out.println("F["+i+"]="+f(i));
	    i++;
	}
	System.out.println("F["+i+"]="+f(i));
    }
}
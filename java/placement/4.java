import java.io.*;
import java.util.Scanner;
public class Main{
    public static int t(int n){
        if (n==0) return 0;
        if (n==1) return 0;
	if (n==2) return 1;
        return t(n-1)+t(n-2)+t(n-3);
    }
    public static void main(String[] args){
        int i=0;
        while (t(i)<10000){
            System.out.println("F["+i+"]="+t(i));
            i++;
        }
        System.out.println("F["+i+"]="+t(i));
    }
}

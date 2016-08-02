import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	System.out.println("円札 : "+n/10000+"枚");
	n=n-(n/10000)*10000;
	System.out.println("円札 : "+n/5000+"枚");
	n=n-(n/5000)*5000;
	System.out.println("円札 : "+n/1000+"枚");
	n=n-(n/1000)*1000;
	System.out.println("円札 : "+n/500+"枚");
	n=n-(n/500)*500;
	System.out.println("円札 : "+n/100+"枚");
	n=n-(n/100)*100;
	System.out.println("円札 : "+n/50+"枚");
	n=n-(n/50)*50;
	System.out.println("円札 : "+n/10+"枚");
	n=n-(n/10)*10;
	System.out.println("円札 : "+n+"枚");
    }
}
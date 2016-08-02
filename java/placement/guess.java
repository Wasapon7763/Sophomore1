import java.io.*;
import java.util.Scanner;
import java.util.Random;
public class guess{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	Random r=new Random();
	int n,i=1;
	int num=r.nextInt(1000);
	while (i<=10){
	    System.out.println(i+"回目 : 0～999までの整数を入力してください。");
	    n=sc.nextInt();
	    if (n<num)		
		System.out.println("入力は正解よりも小さいです。");
	    if (n>num)
		System.out.println("入力は正解よりも大きいです。");
	    if (n==num){
		System.out.println(i+"回目で正解です");
		i=-1;
		break;
	    }
	    else if (i==10)
		System.out.println("正解は "+num+" でした。Game Over");
	    i++;
	}
    }
}
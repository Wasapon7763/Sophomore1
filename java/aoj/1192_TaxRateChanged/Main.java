import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String argsp[]){
	int x, y, s, p1, p2, max;
	Scanner sc=new Scanner(System.in);
	while (true){
	    x=sc.nextInt();
	    y=sc.nextInt();
	    s=sc.nextInt();
	    if (x==0&&y==0&&s==0) break;
	    max=0;
	    for (int i=1;i<s;i++){
	    for (int j=1;j<s;j++){
		p1=i*(100+x)/100;
		p2=j*(100+x)/100;
		if (p1+p2==s){
		    p1=i*(100+y)/100;
		    p2=j*(100+y)/100;
		    if (p1+p2>max) max=p1+p2;
		    break;
		}
	    }
	}
	System.out.println(max);
	}
    }
}
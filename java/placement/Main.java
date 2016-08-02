import java.io.*;
import java.util.Random;
public class Main{
    public static void main(String[] args){
	double min=0,max=0,tot=0,n;
	Random rndm=new Random();
	for (int i=0;i<1000;i++){
	    n=rndm.nextDouble()*100;
	    tot+=n;
	    if (i==0){
		max=n;
		min=n;
	    }
	    if (n>max) max=n;
	    if (n<min) min=n;
	}
	System.out.println("最大値は"+max+"です。");
	System.out.println("最小値は"+min+"です。");
	System.out.println("平均値は"+tot/1000+"です。");
    }
}
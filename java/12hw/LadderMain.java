import java.io.*;
import java.util.*;
public class LadderMain{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int[] num={1, 2, 3, 4, 5, 6, 7, 8};
	for (int i=0;i<8;i++){
	    String[] c=sc.nextLine().split("\\|");
	    for (int j=0;j<c.length;j++){
		if (c[j].equals("-")){
		    int hoge=num[j-1];
		    num[j-1]=num[j];
		    num[j]=hoge;
		}
	    }
	}
	for (int i=0;i<num.length;i++)
	    System.out.print(num[i]+" ");
	System.out.println();
    }
}
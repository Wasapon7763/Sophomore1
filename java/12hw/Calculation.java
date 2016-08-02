import java.io.*;
import java.util.*;
public class Calculation{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	ArrayList<Integer> num=new ArrayList<Integer>();
	boolean cont=true;
	while (cont){
	    String command;
	    int n, sum;
	    System.out.print("> ");
	    command=sc.next();
	    switch (command){
	    case "add":
		n=sc.nextInt();
		num.add(n);
		break;
	    case "remove":
		n=sc.nextInt();
		for (int i=0;i<num.size();i++){
		    if (num.get(i)==n){
			num.remove(i);
			break;
		    }
		}
		break;
	    case "list":
		for (int i=0;i<num.size();i++)
		    System.out.print(num.get(i)+", ");
		System.out.println();
		break;
	    case "sort":
		Collections.sort(num);
		break;
	    case "sum":
		sum=0;
		for (int i=0;i<num.size();i++) sum+=num.get(i);
		System.out.println(sum);
		break;
	    case "mean":
		sum=0;
		for (int i=0;i<num.size();i++) sum+=num.get(i);
		System.out.println(sum/num.size());
		break;
	    case "end":
		cont=false;
		break;
	    }
	}
    }
}
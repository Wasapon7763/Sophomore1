import java.io.*;
import java.util.Scanner;
import java.util.HashSet;
import java.util.Iterator;
public class Main{
    public static void main(String[] args){
	int c=0;
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	HashSet<Integer> s=new HashSet<Integer>();
	for (int i=0;i<n;i++){
	    s.add(sc.nextInt());
	}
	int q=sc.nextInt();
	HashSet<Integer> t=new HashSet<Integer>();
	for (int i=0;i<q;i++){
	    t.add(sc.nextInt());
	}
	Iterator<Integer> it=s.iterator();
	while (it.hasNext()){
	    if (t.contains(it.next())) c++;
	}
	System.out.println(c);
    }
}
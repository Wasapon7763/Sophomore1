import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	int count[]=new int[26];
	String s="";
	Scanner sc=new Scanner(System.in);
	for (int i=0;i<26;i++) count[i]=0;
	while (sc.hasNext()){
	    String input=sc.nextLine();
	    s+=input;
	}
	Scanner kb=new Scanner(s);
	while (kb.hasNext()){
	    String hoge=kb.next();
	    for (int i=0;i<hoge.length();i++){
		int n=(int)hoge.charAt(i);
		if (n<97) n+=32;
		if (n>=97&&n<=122) count[n-97]++;
	    }
	}
	for (int i=0;i<26;i++){
	    System.out.println((char)(i+97)+" : "+count[i]);
	}
    }
}


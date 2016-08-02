import java.io.*;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner sc= new Scanner(System.in);
	int w=sc.nextInt();
	int n=sc.nextInt();
	int amida[]=new int[w];
	for (int i=0;i<w;i++){
	    amida[i]=i+1;
	}
	sc.nextLine();
	for (int i=0;i<n;i++){
	    String s=sc.nextLine();
	    Scanner kb=new Scanner(s);
	    int count=0;
	    String snum[]={"", ""};
	    int num[]={0, 0};
	    for (int j=0;j<s.length();j++){
		if (s.charAt(j)==','){
		    count++;
		}
		else{
		    snum[count]+=s.charAt(j);
		}
	    }
	    for (int j=0;j<2;j++){
		for (int k=0;k<snum[j].length();k++){
		    num[j]+=(snum[j].charAt(k)-'0')*Math.pow(10, snum[j].length()-k-1);
		}
	    }
	    int hoge=amida[num[0]-1];
	    amida[num[0]-1]=amida[num[1]-1];
	    amida[num[1]-1]=hoge;
	}

	for (int i=0;i<w;i++){
	    System.out.println(amida[i]);
	}
    }
}
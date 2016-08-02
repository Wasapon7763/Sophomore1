import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
public class Main{
    public static void main(String[] args){
	Scanner sc= new Scanner(System.in);
	int t=sc.nextInt();
	int result=0;
	for (int i=0;i<t;i++){
	    int num[]=new int[9];
	    for (int j=0;j<9;j++) num[j]=sc.nextInt();
	    ArrayList<Integer> r=new ArrayList<Integer>();
            ArrayList<Integer> g=new ArrayList<Integer>();
            ArrayList<Integer> b=new ArrayList<Integer>();
	    for (int j=0;j<9;j++){
		char c=sc.next().charAt(0);
		switch(c){
		case 'R':
		    r.add(num[j]);
		    break;
		case 'G':
		    g.add(num[j]);
		    break;
		case 'B':
		    b.add(num[j]);
		    break;
		}
	    }
	    Collections.sort(r);
	    Collections.sort(g);
	    Collections.sort(b);
	    int color[][]=new int[3][9];
	    for (int j=0;j<9;j++){
		if (j>r.size()) color[0][j]=r.get(j);
		else  color[0][j]=-1;
		if (j>g.size()) color[1][j]=g.get(j);
		else  color[1][j]=-1;
		if (j>b.size()) color[2][j]=b.get(j);
		else  color[2][j]=-1;
	    }
	    for (int j=0;j<9;j++){
		for (int k=0;k<9;k++){
		    System.out.print(color[j][k]+" ");
		}
		System.out.println("");
	    }
	    /*if (r.size()%3!=0||g.size()%3!=0||b.size()%3!=0) break;
	      else{
		for (int j=0;j<r.size()/3;j++){
		    if (r.get(j)==r.get(j+1)&&r.get(j+1)==r.get(j+2)){
			r.set(j,-1);
			r.set(j+1,-1);
			r.set(j+2,-1);
		    }
		}
		}*/
	    System.out.println(r);
	}
    }
}
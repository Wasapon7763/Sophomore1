import java.io.*;
import java.util.Scanner;
public class Main{
    public static String check_p(String s){
	int start=-1,end=-1;
	for (int i=0;i<s.length();i++){
	    if (s.charAt(i)=='('){
		start=i;
		for (int j=s.length()-1;j>start;j--){
		    if (s.charAt(j)==')'){
			end=j;
			return check_p(s.substring(start+1, end));
		    }
		    if (s.charAt(j)=='('||s.charAt(j)==']') return s;
		}
	    }
	    if (s.charAt(i)=='['){
                start=i;
                for (int j=s.length()-1;j>start;j--){
                    if (s.charAt(j)==']'){
                        end=j;
                        return check_p(s.substring(start+1, end));
                    }
		    if (s.charAt(j)=='['||s.charAt(j)==')');
                }
            }
	}
	return s;
    }
    public static boolean check(String s){
	for (int i=0;i<s.length();i++){
	    if (s.charAt(i)=='('||s.charAt(i)==')'||s.charAt(i)=='['||s.charAt(i)==']') return false;
	}
	return true;
    }
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	String s="";
	while (true){
	    s=sc.nextLine();
	    if (s.equals(".")) break;
	    String hoge=check_p(s);
	    if(check(hoge))
		System.out.println("yes");
	    else
		System.out.println("no");
	}
    }
}
import java.io.*;
public class WhileStatement {
    public static void main(String[] args) {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
	try {
	    String line;
	    for (int i=0;(line = reader.readLine()) != null;i++) {
		System.out.println(line); 
	    }
	} 
	catch (Exception e) { 
	    System.out.println(e);
	}
    }
}
import java.io.*;
public class KeyboardInput {
    public static void main(String[] args) {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	try {
	    String line = reader.readLine();
	    float number = Float.parseFloat(line);
	    System.out.println("入力された整数: " + number);
	} catch (Exception e) {
	    System.out.println(e);
	}
    } 
}
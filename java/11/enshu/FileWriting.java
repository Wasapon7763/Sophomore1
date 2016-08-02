import java.io.*;

class FileWriting {
    public static void main(String[] args) {
        PrintWriter os = null;
        BufferedReader br = null;
        String data;
        try {
            os= new PrintWriter(new FileOutputStream(args[0]));
	    br= new BufferedReader(new InputStreamReader(System.in));
            while(!(data = br.readLine()).equals("END")) {
                os.write(data+"\n");
            }
        } catch(Exception e) {
            e.printStackTrace();
            // Throwing new RuntimeException by wrapping original exception
            throw new RuntimeException(e);
        } finally {
            try {
                if (os != null) os.close();
            } catch (Exception e){}
        }
    }
}
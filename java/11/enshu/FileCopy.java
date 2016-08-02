import java.io.*;
public class FileCopy {
	public static void main(String[] args) {
		int data = 0;
		InputStream is=null;
		OutputStream os=null;
		try{
			is=new BufferedInputStream(new FileInputStream(args[0]));
			os= new BufferedOutputStream(new FileOutputStream(args[1]));
			while((data = is.read()) != -1) {
				os.write(data);
			}
			is.close();
			os.close();
		} catch(Exception e) {
			e.printStackTrace();
			// Throwing new RuntimeException by wrapping original exception
			throw new RuntimeException(e);
		} finally {
			try {
				if (is!=null) is.close();
				if (os!=null) os.close();
			} catch (IOException ie) {}
		}
	}
}

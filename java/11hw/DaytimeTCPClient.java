import java.net.*;
import java.io.*;
public class DaytimeTCPClient {
	public static void main(String[] args) throws Exception {
		Socket socket = null;
		BufferedReader br = null;
		try {
			socket = new Socket(args[0], 13);
			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String line = null;
			while ((line = br.readLine()) != null) {
				System.out.println(line);
			}
			br.close();
		} catch (UnknownHostException uhe) {
			System.out.println("ホストが見付かりません:" + uhe);
		} catch (IOException ioe) {
			System.out.println("I/Oエラーです:" + ioe);
		} finally {
			if(socket != null) {
				socket.close();
			}
		}
	}
}

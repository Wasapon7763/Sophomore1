import java.net.*;
import java.io.IOException;

public class EchoUDPServer {
	public static void main(String args[]) {
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket(7);
			while (true) {
				// Prepare data.
				byte[] inData=new byte[256];
				// Make DatagramPacket for input.
				DatagramPacket inPacket=new DatagramPacket(inData, inData.length);
				// Receive packet.
				socket.receive(inPacket);
				// Make DatagramPacket for output.
				DatagramPacket outPacket=new DatagramPacket(inData, inData.length, inPacket.getSocketAddress());
				// Send packet.
				socket.send(outPacket);
			}
		} catch (IOException ioe) {
			System.err.println("Error: "+ioe);
		} finally {
			if (socket != null) socket.close();
		}
	}
}

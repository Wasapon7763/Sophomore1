import java.net.*;

public class DaytimeUDPServer {
	public static void main(String args[]) {
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket(13);
			byte[] inData = new byte[256];
			byte[] outData = null;
			DatagramPacket inPacket = new DatagramPacket(inData, inData.length);
			DatagramPacket outPacket = null;
			while (true) {
				socket.receive(inPacket);
				outData = (new java.util.Date()).toString().getBytes();
				outPacket = new DatagramPacket(
						outData, outData.length, inPacket.getSocketAddress());
				socket.send(outPacket);
			}
		} catch (Exception e) {
			System.out.println("エラー:" + e);
		} finally {
			if (socket != null) socket.close();
		}
	}
}

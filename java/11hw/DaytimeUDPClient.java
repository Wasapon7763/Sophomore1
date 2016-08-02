import java.net.*;
public class DaytimeUDPClient {
	public static void main(String[] args) {
		DatagramSocket socket = null;
		try {
			byte[] outData = new byte[256];
			byte[] inData = new byte[256];
			InetAddress address = InetAddress.getByName(args[0]);
			socket = new DatagramSocket();
			DatagramPacket outPacket = new DatagramPacket(outData, outData.length, address, 13);
			DatagramPacket inPacket = new DatagramPacket(inData, inData.length);
			socket.setSoTimeout(5000);
			socket.send(outPacket);
			socket.receive(inPacket);
			System.out.write(inData);
		} catch (Exception e) {
			System.out.println("エラー:" + e);
		} finally {
			if(socket != null) {
				socket.close();
			}
		}
	}

}

public class DataClient {

	public static void main(String[] args) {
		Data d = new Data();
		d.setNum(100);
		d.setTxt("NEW");
		System.out.println(d.getNum());
		System.out.println(d.getTxt());
	}

}

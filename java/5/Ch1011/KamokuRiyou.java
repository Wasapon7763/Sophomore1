public class KamokuRiyou {
	public static void main(String[] args) {
		Kamoku kokugo = new Kamoku();
		kokugo.namae = "����";
		kokugo.tensuu = 63;
		Kamoku suugaku = new Kamoku();
		suugaku.namae = "���w";
		suugaku.tensuu = 90;
		System.out.println(kokugo.namae);
		System.out.println(kokugo.tensuu);
		System.out.println(suugaku.namae);
		System.out.println(suugaku.tensuu);
		
		/*
		Kamoku kokugo = new Kamoku("����", 63);
		Kamoku suugaku = new Kamoku("���w", 90);
		String s = kokubo.toString();
		System.out.println(s);
		System.out.println(kokugo.toString());
		System.out.println(kokugo);
		*/
	}
}

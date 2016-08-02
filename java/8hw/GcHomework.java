
class Person {
	String name = null;
	Person friend = null;
	Person(String s) {
		name = s;
		System.out.println(s+"が作られました");
	}

	void setFriend(Person p) {
		friend = p;
	}

	protected void finalize(){
		System.out.println(name+"が収集されます");
	}
}

public class GcHomework {

	public static void main(String[] args) {
		Person p1 = new Person("P1");
		Person p2 = new Person("P2");
		Person p3 = new Person("P3");
		p1.setFriend(p2);
		p2.setFriend(p3);
		p3.setFriend(p1);
		p1 = null;
		p2 = null;
		//p3 = null;
		//System.out.println(p1.name+p1.friend);
		//System.out.println(p2.name+p2.friend);
		System.out.println(p3.name+" "+(p3.friend).name);
		System.out.println((p3.friend).name+" "+((p3.friend).friend).name);
		System.gc();
	}

}

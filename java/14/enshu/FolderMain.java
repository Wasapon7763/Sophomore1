public class FolderMain {
	
	public static void main(String[] args) {
		/*
		 folder1
		   + folder2
		   |   + A
		   |   + folder3
		   |   |   + B
		   |   + C
		   |
		   + folder4
  		   |   + D
  		   | 
		   + E  
		 */
		Folder folder1 = new Folder();
		Folder folder2 = new Folder();
		Folder folder3 = new Folder();
		Folder folder4 = new Folder();
		Text a = new Text("A");
		Text b = new Text("B");
		Text c = new Text("C");
		Text d = new Text("D");
		Text e = new Text("E");
		folder1.add(folder2);
		folder2.add(a);
		folder2.add(folder3);
		folder3.add(b);
		folder2.add(c);
		folder1.add(folder4);
		folder4.add(d);
		folder1.add(e);
		System.out.println(folder1.toString());
		System.out.println(folder1.breadth());
		folder2.remove(folder3);
		folder1.remove(d);
		System.out.println(folder1.toString());
		System.out.println(folder1.breadth());
	}
	
}

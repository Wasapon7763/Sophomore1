public class StringMain {
	static String text = "helloworld";

	static void sort() {
		int len=text.length();
		char[] c=new char[len];
		for (int i=0;i<len;i++) c[i]=text.charAt(i);
		for (int i=len-1;i>=1;i--){
			for (int j=0;j<i;j++){
				if (c[j+1]<c[j]){
					char temp=c[j+1];
					c[j+1]=c[j];
					c[j]=temp;
				}
			}
		}
		for (int i=0;i<len;i++) System.out.print(c[i]);
		System.out.println();
	}

	public static void main(String[] args) {
		sort();
	}
}

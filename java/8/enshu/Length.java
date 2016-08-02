public class Length {

	public static char[] encode(char[] data) {
		char ans[]=new char[100];
		int count=1, length=0, i;
		for (i=1;i<data.length;i++){
			if (data[i]==data[i-1]){
				count++;
			}
			else{
				ans[length++]=(char)(count+'0');
				ans[length++]=data[i-1];
				count=1;
			}
			if (count==9){
				ans[length++]=(char)(count+'0');
				ans[length++]=data[i-1];
				count=0;
			}
		}
		ans[length++]=(char)(count+'0');
		ans[length++]=data[i-1];
		return ans;
	}

	public static char[] decode(char[] data) {
		int i, length=0;
		char ans[]=new char[100];
		for (i=0;i<data.length;i++){
			if (data[i]>='0'&&data[i]<='9'){
				int j=(int)data[i]-'0';
				char c=data[i+1];
				for (int k=0;k<j;k++){
					ans[length++]=c;
				}
			}
		}
		if (length==0){
			try{
				throw new RuntimeException();
			} catch (RuntimeException e){
				System.out.println(e);
			}
		}
		return ans;
	}

	public static void print(char[] data) {
		for (int i = 0; i < data.length; i++) {
			System.out.print(data[i]);
		}
		System.out.println();
	}

	public static void main(String[] args) {
		char input[] = {
				'a','a','a','a','a','a','a','a','a','a',
				'b','b','b','b','b',
				'c','c',
		};
			print(input);
			print(encode(input));
			print(decode(encode(input)));
			print(decode(input));

	}
}

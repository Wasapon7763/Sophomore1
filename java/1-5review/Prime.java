public class Prime {

	public static void listPrime1() {
		for (int n = 2; n <= 100; n++) {
			int i;
			for (i=2;i<=n;i++){
				if (n%i==0&&n!=i) break;
			}
			if (n==i-1) System.out.print(n+",");
		}
		System.out.println();
	}

	public static void listPrime2() {
		int[] prime=new int[101]; //1~100までの配列を用意
		prime[1]=-1; //1は素数ではないので、-1を代入
		//偶数を除去
		for (int i=2;i<=100;i++){
			if (i%2==0&&i!=2) prime[i]=-1;
			else prime[i]=i;
		}
		for (int i=2;i<=100;i++){
			//iの平方根までの数で割り切れるか調べる
			for (int j=2;j<=Math.sqrt(i);j++){
				if (i%j==0&&i!=j){
					prime[i]=-1;
					break;
				}
			}
			if (prime[i]!=-1){
				//素数の倍数を除去
				for (int j=prime[i]+1;j<=100;j++){
					if (j%prime[i]==0) prime[j]=-1;
				}
			}
		}
		for (int i=1;i<=100;i++){
			if (prime[i]!=-1) System.out.print(prime[i]+",");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		listPrime1();
		listPrime2();
  }
}

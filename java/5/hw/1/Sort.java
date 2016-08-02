public class Sort {
	
	static void printArray(int[] a) {
		for(int i = 0; i < a.length; i++) {
			System.out.print(a[i] + ", ");
		}
		System.out.println();
	}
	
	static int binarySearch(int[] a, int k) {
		int low = 0;
		int high = a.length - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if(k < a[mid]) high = mid - 1;
			else if(k > a[mid]) low = mid + 1;
			else return mid;
		}
		return -1;
	}
	
	static void sortArray(int a[]) {
		for(int i = 0; i < a.length - 1; i++){
			for(int j = i + 1; j < a.length; j++) {
				if(a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		int[] array = {
			100, 10, 1000, 50, 10000, 999, 5
		};
		int key = 10000;
		printArray(array);
		System.out.println(key + " at " + binarySearch(array, key));
		sortArray(array);
		printArray(array);
		System.out.println(key + " at " + binarySearch(array, key));
	}
}

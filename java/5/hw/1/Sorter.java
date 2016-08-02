public class Sorter {
	int[] values;

	Sorter(int[] a){
		values=a;
	}
	
	void printArray() {
		for(int i = 0; i < values.length; i++) {
			System.out.print(values[i] + ", ");
		}
		System.out.println();
	}

	int binarySearch(int k) {
		int low = 0;
		int high = values.length - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if(k < values[mid]) high = mid - 1;
			else if(k > values[mid]) low = mid + 1;
			else return mid;
		}
		return -1;
	}

	void sortArray() {
		for(int i = 0; i < values.length - 1; i++){
			for(int j = i + 1; j < values.length; j++) {
				if(values[i] > values[j]) {
					int temp = values[i];
					values[i] = values[j];
					values[j] = temp;
				}
			}
		}
	}

	public static void main(String[] args) {
		int[] array = {
			100, 10, 1000, 50, 10000, 999, 5
		};
		int key = 10000;

		Sorter s=new Sorter(array);

		s.printArray();
		System.out.println(key + " at " + s.binarySearch(key));
		s.sortArray();
		s.printArray();
		System.out.println(key + " at " + s.binarySearch(key));
	}
}

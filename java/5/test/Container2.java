public class Container2 {
    int[] values=new int[10000];
    int size;
    
    Container2(int[] temp) {
	size=temp.length;
	for (int i=0;i<size;i++){
	    values[i]=temp[i];
	}
    }
	
    void printArray() {
	for (int i=0;i<size;i++){
	    if (i==size-1)
		System.out.print(values[i]);
	    else
		System.out.print(values[i]+", ");
	}
	System.out.println();
    }

    int search(int k) {
	for (int i=0;i<size;i++){
	    if (values[i]==k) return i;
	}
	return -1;
    }

    public static void main(String[] args) {
	int[] array = {
	    100, 10, 1000, 50, 10000, 999, 5
	};
	int key = 10000;
	Container2 ctn=new Container2(array);
	ctn.printArray();
	System.out.println(key+" at "+ctn.search(key));

    }
}

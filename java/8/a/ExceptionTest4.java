public class ExceptionTest4 {
    public static void main(String[] args) {
	int[] myarray = new int[3];
	myAssign(myarray, 100, 0);
    }
    static void myAssign(int[] a,int i, int v){
	try {
	    System.out.println("myAssignに来ました");
	    a[i] = v;
	    System.out.println("myAssignから帰ります");
	} catch (ArrayIndexOutOfBoundsException e){
	    // e.printStackTrace();
	    System.out.println(e);
	}
    }
}
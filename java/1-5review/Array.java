public class Array {
    public static void main(String[] args) {
	int[] values = new int[]{ 62, 90, 75 };
	int max=0, min=0;
	double sum = 0;
	for (int i = 0; i < values.length; i++) {
	    if (values[i]>max||i==0) max=values[i];
	    if (values[i]<min||i==0) min=values[i];
	    sum += values[i];
	}
	System.out.println("平均値: "+sum/values.length); 
	System.out.println("最大値: "+max);
	System.out.println("最小値: "+min);
    }
}
public class Array2 {
    public static void main(String[] args) {
	int[][] vs = new int[][]{ 
	    { 62, 90, 75 },
	    { 100, 0, 50 },
	    { 30, 40 } 
	};
	int l=0, min=0, max=0;
	double sum = 0;
	for (int i = 0; i < vs.length; i++) {
	    for (int j = 0; j < vs[i].length; j++){ 
		if (vs[i][j]>max||(i==0&&j==0)) max=vs[i][j];
		if (vs[i][j]<min||(i==0&&j==0)) min=vs[i][j];
		sum += vs[i][j];
		l++;
	    } 
	}
	System.out.println("平均値: "+sum/l); 
	System.out.println("最大値: "+max);
	System.out.println("最小値: "+min);
    }
}
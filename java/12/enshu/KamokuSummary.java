import java.util.ArrayList;
public class KamokuSummary{
    public static void main(String[] args){
	int sum=0;
	ArrayList<Integer> list=new ArrayList<Integer>();
	list.add(80);
	list.add(100);
	list.add(90);
	list.add(75);
	list.add(90);
	for (int n: list){
	    sum+=n;
	    System.out.println(n);
	}
	System.out.println("合計: "+sum);
	System.out.println("平均: "+sum/list.size());
    }
}
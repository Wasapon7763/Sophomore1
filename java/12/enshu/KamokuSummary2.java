import java.util.HashMap;
public class KamokuSummary2{
    public static void main(String[] args){
	int sum=0;
	HashMap<String, Integer> map=new HashMap<String, Integer>();
	map.put("高橋", 90);
	map.put("山本", 90);
	map.put("佐藤", 100);
	map.put("田中", 80);
	map.put("渡辺", 75);
	for (String name: map.keySet()){
	    int score=map.get(name);
	    System.out.println(name+" -> "+score);
	    sum+=score;
	}
	System.out.println("合計: "+sum);
	System.out.println("平均: "+sum/map.size());
    }
}
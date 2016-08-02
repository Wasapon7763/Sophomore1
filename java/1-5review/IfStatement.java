public class IfStatement {
    public static void main(String[] args) {
	int x = 60;
	if(x >= 0 && x <= 100) {
	    if(x >= 80) { 
		System.out.println("合格");
	    } 
	    else { 
		System.out.println("不合格");
	    }
	} 
	else {
	    System.out.println("エラー"); 
	}
    } 
}
public class CountTen extends Thread{
    public static void main(String[] args){
	CountTen ct=new CountTen();
	ct.start();
	for (int i=0;i<100;i++){
	    System.out.println("main:i = "+i);
	}
    }
    public void run(){
	for (int i=0;i<100;i++){
	    System.out.println("run:i = : "+i);
	}
    }
}
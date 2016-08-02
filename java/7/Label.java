public class Label{
    String caption;
    static String common;
    Label(String s){
	caption=s;
    }
    void output(){
	System.out.println(common+": "+caption);
    }
}
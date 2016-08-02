public class Park{
    String name;
    static String common;
    void setName(String n){
	name=n;
    }
    void print(){
	System.out.println(name+common);
    }
    static void setCommon(String s){
	common=s;
    }
}
public class Student{
    String name;
    int credit;
    
    Student(String n, int c){
	name=n;
	credit=c;
    }
    
    public String getName(){
	return name;
    }
    
    boolean isOK(){
	if (credit>=100) return true;
	else return false;
    }
}
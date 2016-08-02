public class University{
    Student[] students=new Student[100];
    
    public void list(){
	for (int i=0;i<students.length;i++)
	    System.out.println(students[i].name+"は卒業できる:"+students[i].isOK());
    }
}
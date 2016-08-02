public class ForStatement{
    public static void main(String[] args) {
	int i=0, j;
	while (i<10){
            System.out.print(i + ":");
	    j=0;
	    while (j<i){
                System.out.print("*");
		j++;
            }
            System.out.println("");
	    i++;
        }
    }
}

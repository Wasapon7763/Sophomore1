class Rectangle {
    int width = 0;
    int height = 0;
    static int counter = 0;
    int number;
    
    Rectangle() {
    	setSize(200,100);
	number=counter;
	counter++;
    }
    
    Rectangle(int nw, int nh) {
    	setSize(nw, nh);
	number=counter;
	counter++;
    }
    
    void setSize(int nw, int nh) {
    	width = nw;
    	height = nh;
    }
    
    int getArea() { 
    	return width * height;
    }  
    
    static void setCounter(int newCounter) {
    	counter = newCounter;
    }
    

    static int getCounter() {
   	return counter;
    }
    
    int getNumber(){
	return number;
    }
    

    /*    public String toString() {
    		return "" + number;
		}*/

    
    public String toString() {
    	return "Rectangle: " + width + "," + height;
    }
   
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        System.out.println(Rectangle.getCounter());
        Rectangle r2 = new Rectangle(123, 45);
        System.out.println(Rectangle.getCounter());
        System.out.println(r1.getArea());
        System.out.println(r2.getArea());
        System.out.println("r1 number: " + r1);
        System.out.println("#r1: " + r1.getNumber());
        System.out.println("r2 number: " + r2);
        System.out.println("#r2: " + r2.getNumber());

    }
}

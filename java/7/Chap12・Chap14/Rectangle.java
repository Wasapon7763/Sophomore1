class Rectangle {
    int width = 0;
    int height = 0;
    static int counter = 0;
    int number;
    
    Rectangle() {
    	setSize(200,100);
    	number = counter;
    	counter++;
    }
    
    Rectangle(int nw, int nh) {
    	setSize(nw, nh);
    	number = counter;
    	counter++;
    }
    
    void setSize(int nw, int nh) {
    	width = nw;
    	height = nh;
    }
    
    void setSize(int nw, int nh, int level) {
    	width = nw * level;
    	height = nh * level;
    }
    
    int getArea() { 
    	return width * height;
    }  
    
    static int getCounter() {
    	return counter;
    }
    
    public String toString() {
    	return "Rectangle: " + width +"," + height;
    }
    

    public void debugPrint() {
    	System.out.println("Rectangle: " + width + "," + height);
    }
    
}

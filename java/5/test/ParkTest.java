class ParkTest {
    public static void main(String[] args) {
	Park.setCommon("公園");
	Park p1 = new Park();
	Park p2 = new Park();
	p1.setName("上野");
	p2.setName("戸山");
	p1.print();
	p2.print();
	Park.setCommon("Park");
	p1.print();
	p2.print();
    }
}


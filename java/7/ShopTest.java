class ShopTest {
    public static void main(String[] args) {
	Shop[] mall = new Shop[] {
	    new Bakery(),
	    new FlowerShop(),
	    new FlowerShop()
	};
	for(int i = 0; i < mall.length; i++) {
	    System.out.println(mall[i].name + "の" + mall[i].sell());
	}
    }
}
public class Cart {
	Item[] items=new Item[10];


	void addItem(Item i){
		if (Item.getNumberOfInstances()<10){
			items[i.num]=i;
		}
	}

	void info(){
		for (int i=0;i<Item.getNumberOfInstances();i++){
			System.out.println(items[i]);
		}
	}

	public static void main(String[] args) {
		System.out.println(Item.getNumberOfInstances());
		Cart cart = new Cart();
		Item i1 = new Item("PC", 98000);
		Item i2 = new Item("Display", 40000);
		cart.addItem(i1);
		cart.addItem(i2);
		cart.info();
		System.out.println(Item.getNumberOfInstances());
	}
}

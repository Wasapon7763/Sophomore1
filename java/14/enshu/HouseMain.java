public class HouseMain{
    public static void main(String[] args){
	Human a=new Human("a");
	Human b=new Human("b");
	Human c=new Human("c");
	Human d=new Human("d");
	Human e=new Human("e");
	Human f=new Human("f");

	Pet aa=new Pet("aa");
	Pet bb=new Pet("bb");
	Pet cc=new Pet("cc");
	Pet dd=new Pet("dd");
	Pet ee=new Pet("ee");
	Pet ff=new Pet("ff");
	Pet gg=new Pet("gg");
	Pet hh=new Pet("hh");


	House h=new House();

	h.add(a);
	h.add(b);
	h.add(c);
	h.add(d);
	h.add(e);
	h.add(aa);
	h.add(bb);
	h.add(cc);
	h.add(dd);

	h.showList();

    }
}
class Paragraph extends Element{
  static int total=0;
  int num;
  Element[] el=new Element[10];
  int index=0;
  Paragraph(){
    total++;
    num=total;
  }
  public void add(Element e){
    if (index==10) throw new RuntimeException();
    el[index++]=e;
  }
  public void print(){
    System.out.println("<p"+num+">");
    for (int i=0;i<index;i++){
      el[i].print();
    }
    System.out.println("</p"+num+">");
  }

}

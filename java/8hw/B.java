public class B extends A{
  A a;
  B(A a){
    this.a=a;
  }
  String m(){
    return "b"+a.m()+"b";
  }
}

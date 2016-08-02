class IntArray implements Countable{
  int[] ar;
  IntArray(int n[]){
    if (n==null) ar=new int[0];
    else ar=n;
  }
  public int count(){
    return ar.length;
  }
}

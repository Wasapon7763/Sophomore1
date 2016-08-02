class IntArray implements Countable{
    int arr[];
    IntArray(int arr[]){
      if (arr==null) this.arr=new int[0];
      else this.arr=arr;
    }
    public int count(){
      return arr.length;
    }
}

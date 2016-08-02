class ExceptionExam {
  public static void main(String[] args) {
    try{
      int[] array = new int[3];
      for(int i = 0; i < 4; i++){
        array[i] = 0;
      }
    }
    catch (ArrayIndexOutOfBoundsException e){
      System.out.println(e+"\nプログラムを終了します。");
    }
  }
}

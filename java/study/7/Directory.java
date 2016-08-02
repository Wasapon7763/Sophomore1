class Directory extends File{
  File[] f=new File[10];
  int num=0;

  Directory(String n){
    super(n, 1);
  }
  void add(File file){
    if (num>9) return;
    f[num++]=file;
  }
  int getSize(){
    int n=size;
    for (int i=0;i<num;i++){
        n+=f[i].getSize();
    }
    return n;
  }
}

class Directory extends File{
  String name;
  int cf=0;
  int cd=0;
  File[] F=new File[10];
  Directory[] D=new Directory[10];
  Directory(String n){
    name=n;
  }
  void add(File f){
    F[cf]=f;
    cf++;
  }
  void add(Directory d){
    D[cd]=d;
    cd++;
  }
}

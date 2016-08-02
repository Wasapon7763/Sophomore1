import java.io.*;
public class DeepCopy {

    public static void main(String[] args) {
      copyFileOrDirectory(args[0], args[1]);
    }

    public static void copyFileOrDirectory(String srcName, String dstName) {
      File srcFile = new File(srcName);
      if(srcFile.isFile()/* srcFileがファイルの場合*/) {
        copyFile(srcFile.getAbsolutePath(), dstName);
      } else if(srcFile.isDirectory() /* srcFileがディレクトリの場合 */ ) {
        File dstDir = new File(dstName);
        dstDir.mkdirs();
        /*
	      * srcFile から配下のファイルやディレクトリの一覧を得て、
	      * それぞれについて copyFileOrDirectoryの再帰呼び出し。
	      */
        String[] srclist=srcFile.list();
        for (int i=0;i<srclist.length;i++){
          copyFileOrDirectory(srcFile.getAbsolutePath()+"//"+srclist[i], dstDir.getAbsolutePath()+"//"+srclist[i]);
        }
      }
    }

    public static void copyFile(String srcName, String dstName) {
      /*
	    * FileCopy を参考にして、srcNameで指定されるファイルの内容を
	    * dstName で示されるファイルに書き出す。
	    */
      int data = 0;
      InputStream is=null;
      OutputStream os=null;
      try{
        is=new BufferedInputStream(new FileInputStream(srcName));
        os= new BufferedOutputStream(new FileOutputStream(dstName));
        while((data = is.read()) != -1) {
                os.write(data);
        }
        is.close();
        os.close();
      } catch(Exception e) {
        e.printStackTrace();
        throw new RuntimeException(e);
      } finally {
        try {
          if (is!=null) is.close();
          if (os!=null) os.close();
        } catch (IOException ie) {}
      }

    }

}

public class Sort{
    static short[] v;
    public static short[] Sort(){
	for (int i=1;i<v.length;i++){
	    for (int j=0;j<v.length-i;j++){
		if (v[j]<v[j+1]){
		    short hoge=v[j];
		    v[j]=v[j+1];
		    v[j+1]=hoge;
		}
	    }
	}
	return v;
    }
}
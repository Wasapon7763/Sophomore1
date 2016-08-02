import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
public class a{
    public static void main(String[] args){
	Scanner sc= new Scanner(System.in);
	int t=sc.nextInt();
	for (int i=0;i<t;i++){
	    int win=1;
	    int color[][]=new int[3][9];
	    for (int j=0;j<3;j++) Arrays.fill(color[j],10);
	    int num[]=new int[9];
	    for (int j=0;j<9;j++) num[j]=sc.nextInt();
	    int color_num[]=new int[3];
	    for (int j=0;j<9;j++){
		char c=sc.next().charAt(0);
		if (c=='R') color[0][color_num[0]++]=num[j];
		if (c=='G') color[1][color_num[1]++]=num[j];
		if (c=='B') color[2][color_num[2]++]=num[j];
	    }
	    for (int j=0;j<3;j++) Arrays.sort(color[j]);
	    if (color_num[0]%3!=0||color_num[1]%3!=0||color_num[2]%3!=0) win=0;
	    for (int j=0;j<3&&win!=0;j++){
		for (int k=0;k<color_num[j]/3;k++){
		    if (color[j][k*3]==color[j][k*3+2]){
			color[j][k*3]=0;
			color[j][k*3+1]=0;
			color[j][k*3+2]=0;
		    }
		    if (color[j][k*3]==color[j][k*3+1]-1&&color[j][k*3]==color[j][k*3+2]-2){
			color[j][k*3]=0;
			color[j][k*3+1]=0;
			color[j][k*3+2]=0;
		    }
		}
	    }

	    for (int j=0;j<3&&win!=0;j++){
		int n=color_num[j];
		int changed=0;
		for (int l=0;l<n/3;l++){
		    int bef=-2;
		    changed=0;
		    for (int k=0;k<color_num[j];k++){
			if ((k==color_num[j]-2&&changed==0)||(k==color_num[j]-1&&changed<=1)) break;
			int now=color[j][k];
			if ((now!=0&&changed==0)||now==bef+1){
                            color[j][k]=0;
                            changed++;
                            bef=now;
                        }
			if (changed==3){
			    changed=0;
			    bef=-2;
			}
		    }
		    /*for (int a=0;a<3;a++){
			for (int b=0;b<color_num[a];b++){
			    System.out.print(color[a][b]);
			}
			System.out.println();
			}*/
		}
		if (changed!=0) win=0;
	    }

	    for (int j=0;j<3;j++){
		for (int k=0;k<color_num[j];k++){
		    if (color[j][k]!=0) win=0;
		}
	    }

	    System.out.println(win);
	}
    }
}
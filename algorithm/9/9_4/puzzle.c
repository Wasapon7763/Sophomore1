#include <stdio.h>/*ライブラリを読み込む*/
int correct[16],puzzle[16],cpuzzle[16],found=0,limit,MDs[16];
int spaceplace,answer;/*各関数をプロトタイプ宣言*/
void printpuzzle(void);/*パズルを表示する関数(使ってないかも)*/
void printcpuzzle(void);
void swapcpuzzle(int a,int b);/*パズルを入れ替える関数*/
void swappuzzle(int a,int b);
void solvepuzzle(int trial,int from,int change);
int main(void){
    int i,j,c,count,swapnumber,MD=0,CMD1=0,CMD2=0;/*count:空白が定位置に戻るために必要なマンハッタン距離  MD:パズルの定位置までの距離の総和　CMD1,2:*MDを縦、横に分割したもの*/
    char s;/*文字を読み取る変数*/
    c=0,swapnumber=0;/*swapnumber: 置換回数を格納*/
    for(i=0;i<20;i++){/*入力されたパズルの形をchar型で読み込み、int型で一次元配列に変換する*/
        scanf("%c ",&s);
        if('0'<=s && s<='9'){
            puzzle[c++]=s-'0';
        }else if('a'<=s && s<='f'){
            puzzle[c++]=10+s-'a';
        }else if(s=='-'){
            puzzle[c++]=16;
        }
    }
    for(i=0;i<16;i++) correct[i]=i+1;/*正解のパズルの形を作る*//*もしかしたら使ってないかも*/
    for(i=0;i<16;i++) cpuzzle[i]=puzzle[i];/*パズルの形をコピー*/
    for(i=0;i<15;i++){/*不可能なパズルかどうかを検出*/
        if(cpuzzle[i]!=i+1){/*空白パネルを無視して各パネルを正解の位置のものと直接置換*/
            for(j=i+1;j<16;j++){
                if(cpuzzle[j]==i+1){
                    swapcpuzzle(j,i);
                    swapnumber++;/*その合計を格納*/
                    break;
                }
            }
        }
    }
    for(i=0;i<16;i++){/*空白パネルを解答位置に移動するまでのマンハッタン距離をcountに入れる。(これと解答の偶奇は一致する)*/
        if(puzzle[i]==16){
            spaceplace=i;
            count=15-i;
            count=(count/4)+count%4;/*空白の位置でしか計算できないマンハッタン距離の計算方法*/
        }
    }
    if(count%2!=swapnumber%2){/*2種類の偶奇が一致しない時パズルは解くことが出来ない(線形代数のn回置換した行列は元の位置に戻すときの経路によらず置換回数の偶奇は一致するという定理を利用)*/
        printf("impossible\n");
    }else{/*パズルが解けるときそのパネル移動の必要最低限の距離を計算*/
        CMD1=0;/*最低限の距離は各パネルのマンハッタン距離の総和とする*/
        CMD2=0;
        for(i=0;i<15;i++){/*各パネルの正解までの位置の合計を必要最低限の距離とする*/
            if(puzzle[i]!=i+1){
                for(j=0;j<16;j++){
                    if(puzzle[j]==i+1){
                        CMD1=abs(j/4-i/4);/*4で割った商が行*/
                        CMD2=abs(j%4-i%4);/*4で割った余りが列*/
                        MDs[i]=CMD1+CMD2;/*各パネルの距離を配列にいったん格納(時間短縮のため)*/
                        MD+=MDs[i];/*距離の総和を計算*/
                        break;
                    }
                }
            }
        }
        if(MD%2!=swapnumber%2) MD++;/*必要最低限の距離の偶奇を深さの偶奇と合わる*/
        limit=MD;/*最低限の距離の深さから探索スタート*/
        while(!found){/*反復深さ優先探索を用いてパズルを解く*//*解答が見つかったらfoundが1になる*/
            solvepuzzle(0,0,16);/*パズルを解く*/
            limit+=2;/*正解の偶奇は決まっているから深さの偶奇を合わせる(2ずつインクリメント)*/
        }
        printf("%d\n",answer);/*解答を出力*/
    }
    return 0;
}
void swapcpuzzle(int a,int b){/*コピーしたパズルのパネルを入れ替える関数*/
    int c;
    c=cpuzzle[a];
    cpuzzle[a]=cpuzzle[b];
    cpuzzle[b]=c;
}
void swappuzzle(int a,int b){/*パズルのパネルを入れ替える関数*/
    int c;
    c=puzzle[a];
    puzzle[a]=puzzle[b];
    puzzle[b]=c;
}
void solvepuzzle(int trial,int from,int change){/*trail: 移動回数 from:一手前に移動した場所を記憶しておく(一手戻りを防ぐ) change:一手前に空白をswap下したパネル*/
    int i,j,MD=0,d1,d2,MMD;
    if(found)return ;/*解答が見つかっている時一つ前の再起に戻る*/
    //if(change!=16){/*位置を変更した空白でないパネルの最低距離を更新(初期条件は16)*/
        d1=abs((puzzle[change]-1)/4-(change)/4);/*前述したマンハッタン距離の計算法*/
        d2=abs((puzzle[change]-1)%4-(change)%4);
        MDs[puzzle[change]-1]=d1+d2;/*更新*/
    }
    for(i=0;i<15;i++) MD+=MDs[i];/*マンハッタンの総和を更新*/
    if(trial+MD>limit) return;/*実行回数+これからかかる距離が探索する限界を超えたらその限界では解けない*/
    if(!MD){ /*必要最低距離が0の時つまりパズルが完成した時再起を終了する*/
        found=1;
        answer=trial;/*答えは実行回数*/
        return;
    }/*バックトラックを用いることでパネル移動をif文ごとにリセットする*/
    if(spaceplace%4 && from!=2){/*空白パネルを右に移動　fromで一手戻りを回避*/
        swappuzzle(spaceplace,spaceplace-1);/*パネルを移動させて*/
        //MMD=MDs[puzzle[spaceplace]-1];/*次の再起で更新される距離を記憶*/
        spaceplace--;/*空白の位置を訂正*/
        MMD=MDs[puzzle[spaceplace+1]-1];/*距離を元に戻す*/
        solvepuzzle(trial+1,1,spaceplace+1);
        spaceplace++;/*空白を元に戻す*/
        MDs[puzzle[spaceplace]-1]=MMD;
        //swappuzzle(spaceplace,spaceplace-1);
        if(found)return;/*見つかったら即座に終了*/
    }
    if(spaceplace%4 != 3 && from!=1){/*空白パネルを左に移動*/
        swappuzzle(spaceplace,spaceplace+1);
        MMD=MDs[puzzle[spaceplace]-1];
        spaceplace++;
        solvepuzzle(trial+1,2,spaceplace-1);
        spaceplace--;
        MDs[puzzle[spaceplace]-1]=MMD;
        //swappuzzle(spaceplace,spaceplace+1);
        if(found)return;
    }
    if(spaceplace/4 != 3 && from !=4){/*空白パネルを下に移動*/
        swappuzzle(spaceplace,spaceplace+4);
        MMD=MDs[puzzle[spaceplace]-1];
        spaceplace+=4;
        solvepuzzle(trial+1,3,spaceplace-4);
        spaceplace-=4;
        MDs[puzzle[spaceplace]-1]=MMD;
        //swappuzzle(spaceplace,spaceplace+4);
        if(found)return;
    }
        if(spaceplace/4 && from != 3){/*空白パネルを上に移動*/
        swappuzzle(spaceplace,spaceplace-4);
        MMD=MDs[puzzle[spaceplace]-1];
        spaceplace-=4;
        solvepuzzle(trial+1,4,spaceplace+4);
        spaceplace+=4;
        MDs[puzzle[spaceplace]-1]=MMD;
        //swappuzzle(spaceplace,spaceplace-4);
        if(found)return;
    }
}
/*
参考文献:
1)１５パズル自動解答プログラムの作り方,http://woj-kyc.kake.info.waseda.ac.jp/develop/303
2)１５ゲーム,http://homepage3.nifty.com/funahashi/game/game66.html
*/

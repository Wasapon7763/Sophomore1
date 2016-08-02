#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//puz:入力される15パズル goal:15パズルの完成形
char puz[4][4], goal[4][4]={{'1','2','3','4'}, {'5','6','7','8'}, {'9','a','b','c'}, {'d','e','f','-'}};
//MD:各マスの値と目標とのマンハッタン距離 limit:深さの制限 found:解が見つかったら1, そうでなかったら0，存在しない場合-1 ans:出力する最短手順
int MD[4][4]={0}, limit, found=0, ans; 
//引数の15パズルpが解けるかどうか調べる関数．解ける場合1を返し、解けない場合0を返す
int canSolve(char p[][4]){
  int i, j, u, v;
  int d, swap=0; //d:空白とその目標の位置とのマンハッタン距離 swap:パネルをgoalのようにするために交換した回数
  char a[4][4]; //pのコピー
  for (i=0;i<4;i++){
    for (j=0;j<4;j++) a[i][j]=p[i][j]; //pをaにコピー
  }
  //aのパネルとgoalのパネルを１つずつ比べ、aのパネルをgoalのようにしていく
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (a[i][j]==goal[i][j]||a[i][j]=='-') continue; //aのパネルが目標の位置にあるまたは空白である時、continue
      for (u=0;u<4;u++){
        for (v=0;v<4;v++){
          if (a[u][v]==goal[i][j]){ //a上のパネルの値とgoal上のパネルの値が一致した時
            //パネルを目標の位置と交換
            int temp=a[i][j];
            a[i][j]=a[u][v];
            a[u][v]=temp;
            swap++; //swapをインクレメント
            u=4; //goal[i][j]の探索を終了させる
            break;
          }
        }
      }
    }
  }
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (p[i][j]=='-') d=abs(i-3)+abs(j-3); //空白があるパネルとその目標の位置とのマンハッタン距離を計算し、dに代入する
    }
  }
  if (swap%2!=d%2) return 0; //swapとdの偶奇が一致しない時、0を返す
  return 1;
}
//pの各パネルとその目標のパネルとのマンハッタン距離を計算する．また、各パネルのマンハッタン距離を返す．
int getMD(char p[][4]){
  int i, j, u, v;
  int tot=0; //各マンハッタン距離の合計
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (p[i][j]==goal[i][j]||goal[i][j]=='-') continue; //パネルが目標の位置にあるまたは空白の時continue
      for (u=0;u<4;u++){
        for (v=0;v<4;v++){
          if (p[u][v]==goal[i][j]){
            MD[u][v]=abs(i-u)+abs(j-v); //マンハッタン距離を計算し、MDに記録
            tot+=MD[u][v]; //totにいま計算した距離を加える
            u=4; //goal[i][j]の探索を終了させる
            break;
          }
        }
      }
    }
  }
  return tot; //totを返す
}
//puz上のa行b列目のパネルとx行y列目のパネルを交換する関数
void swap(int a, int b, int x, int y){
  int temp=puz[a][b];
  puz[a][b]=puz[x][y];
  puz[x][y]=temp;
}
//操作 1:右 2:左 3:上 4:下
//level:現在の深さ bef:前の操作 u, v:空白パネルの位置の座標
void solve(int level, int bef, int u, int v){
  int i, j, temp, md=0; //md:puzの各パネルのマンハッタン距離の合計
  if (bef!=0){ //初期呼び出しではない場合
    int a=u, b=v; //a, b:ひとつ前の呼び出しで動かしたパネルの座標
    if (bef==1) b--; //前回右に動かした時、bをデクレメント
    if (bef==2) b++;
    if (bef==3) a++;
    if (bef==4) a--;
    //動かしたパネルpuz[a][b]とその目標の位置とのマンハッタン距離を計算し、MDを更新する
    for (i=0;i<4;i++){
      for (j=0;j<4;j++){
        if (puz[a][b]==goal[i][j]){
          MD[a][b]=abs(a-i)+abs(b-j);
          i=4; //探索を終了させる
          break;
        }
      }
    }
    //各パネルのマンハッタン距離の合計を計算し、mdに保存する
    for (i=0;i<4;i++){
      for (j=0;j<4;j++){
        if (puz[i][j]!='-') md+=MD[i][j];
      }
    }
  }
  else md=limit; //初期入力の時、mdにlimitを代入

  if (found) return; //解が見つかっている時、戻る
  if (level+md>limit) return; //深さ制限を超えた時、戻る
  if (md==0){ //mdが０、つまり解が見つかった時
    ans=level; //深さ(移動回数)をansに記録
    found=1; //foundに1を代入
    return;
  }
  //空白パネルを右に動かす操作
  if (bef!=2&&v<3){ //前の操作が左でなく、空白パネルが右端にない時
    swap(u, v, u, v+1); //空白パネルとその上のパネルを交換
    v++; //空白パネルの座標を更新
    temp=MD[u][v]; //動かす前の動かされたパネルのマンハッタン距離をtempに記録
    solve(level+1, 1, u, v); //solveを呼び出す
    swap(u, v, u, v-1); //パネルを元に戻す
    MD[u][v]=temp; //マンハッタン距離を元に戻す
    v--; //空白パネルの座標を元に戻す
    if (found) return; //解が見つかっていたら戻る
  }
  //空白パネルを左に動かす操作
  if (bef!=1&&v>0){
    swap(u, v, u, v-1);
    v--;
    temp=MD[u][v];
    solve(level+1, 2, u, v);
    swap(u, v, u, v+1);
    MD[u][v]=temp;
    v++;
    if (found) return;
  }
  //空白パネルを上に動かす操作
  if (bef!=4&&u>0){
    swap(u, v, u-1, v);
    u--;
    temp=MD[u][v];
    solve(level+1, 3, u, v);
    swap(u, v, u+1, v);
    MD[u][v]=temp;
    u++;
    if (found) return;
  }
  //空白パネルを下に動かす操作
  if (bef!=3&&u<3){
    swap(u, v, u+1, v);
    u++;
    temp=MD[u][v];
    solve(level+1, 4, u, v);
    swap(u, v, u-1, v);
    MD[u][v]=temp;
    u--;
    if (found) return;
  }

}
int main(void){
  int i, j;
  int u=0, v=0; //puz上の空白の座標
  for (i=0;i<4;i++){
    for (j=0;j<4;j++) scanf("%c ", &puz[i][j]); //15パズルを入力し、puzに格納
  }
  if(!canSolve(puz)){ //puzが解けない場合
    printf("impossible\n"); //"impossible"を出力する
    found=-1; //foundに-1を代入
  }
  limit=getMD(puz); //深さ制限を初期状態のパズルのマンハッタン距離の合計に設定
  //puzの空白パネルの位置を探索し、記録する
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (puz[i][j]=='-'){
        u=i;
        v=j;
        break;
      }
    }
  }
  //解が見つかるまで探索を続ける
  while (found==0){
    solve(0, 0, u, v); //solveを呼び出す
    limit+=2; //深さ制限を深くする
  }
  if (found!=-1) printf("%d\n", ans); //解が存在する場合、最短手順を出力
  return 0;
}
/*参考文献
    http://homepage3.nifty.com/funahashi/game/game66.html
    http://www.geocities.jp/m_hiroi/func/ocaml20.html
*/

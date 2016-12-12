//全探索のくじ引きを2分探索で高速化する
//n枚のくじに数字が書いてあり、くじを取り出して数字を足していく。
//取り出す回数が４回。４回の和がmになる取り出し方が存在するかどうか。

#include <iostream>
#define MAX_N 1000

int n , m;
int k[MAX_N]={1,3,5};


bool binary_search(int x){
  //xの存在しうる範囲k[l],k[l+1],...k[r-1]
  
  int l=0, r=n;
  while (r-1>=l){
    int i=(l+r)/2;
    if(k[i]==x)return true;
    else if (k[i]<x)l=i+1;
    else r=i;
  
  }
  
  return false;//見つからない

}


/* 比較関数 */
int comp( const void *c1, const void *c2 )
{
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;

  if( tmp1 < tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 > tmp2 )  return  1;
}


void solve(){
  //二分探索を行うためにソート
  //sort(k,k+n);
  qsort( k, 3, sizeof(int), comp );
  bool f=false;
  
  for (int a=0; a<n; a++){
    for (int b=0;b<n;b++){
      for (int c=0;c<n;c++){
        //最も内側のループの代わりに二分探索
        if (binary_search(m-k[a]-k[b]-k[c])){
          f=true;      
        }     
      }
    }
  }
  if (f)puts("yes");
  else puts("no");
   
  

}


int main(){
    n=3;//くじの数
    m=9;//和

    solve();    
    
    return 0;
}



#include <stdio.h>
#include <iostream>

//棒の長さとありの数
int L;
int n;


void solve(int x[]){
  //最小の時間導出
  int minT=0;
  int maxT=0;
  for (int i =0;i<n;i++){
    //左端または右端との距離のうち小さい方と、今までの最小値とを比較し、大きい方を返す
    //(小さい方ではない。移動時間は必ずかかるので大きい方がボトルネックになって全体の時間が伸びる)
    minT=std::max(minT,std::min(x[i],L-x[i]));
       
  }
  //最大時間
  for (int i=0;i<n;i++){
    maxT=std::max(maxT,std::max(x[i],L-x[i]));  
  }
  
  printf("min time = %d max time = %d\n",minT,maxT);
    
  
}



int main(void){
  L=10;
  n=3;
  int x[]={2,6,7};
  solve(x);
  
}


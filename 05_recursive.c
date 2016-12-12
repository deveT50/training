//再帰呼び出しのメモ

#include<stdio.h>
#include<iostream>
#define MAX_N 50


int memo[MAX_N+1];


int fact(int n){
  if (n==0) return 1;
  return n*fact(n-1);
}


//フィボナッチ数列
int fib(int n){
  if(n<=1)return n;
  return fib(n-1)+fib(n-2);
  
  
  
}

//計算値をメモする
int fibmem(int n){
  if(n<=1) return n;
  if(memo[n]!=0)return memo[n];
  return memo[n]=fibmem(n-1)+fibmem(n-2);
  
  
  
}


int main(void){
  for(int i=0;i<MAX_N;i++){
        memo[i]=0;  
      
    }
  int num=0;
  num=fact(4);
  printf("%d\n",num);
  printf("%d\n", fibmem(30));
  printf("%d\n", fibmem(30));  
  return 0;
  
}
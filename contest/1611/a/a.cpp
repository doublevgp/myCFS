#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    char s[20];
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int a[20] = {0};
    for(int i = 1; i <= len; i++){
      a[i] = s[i] - '0';
    }
    if(a[len] % 2 == 0){
      puts("0");
    }
    else{
      int ind = 0;
      for(int i = 1; i <= len; i++){
        if(a[i] % 2 == 0){
          ind = i;
          break;
        }
      }
      if(ind == 1){
        puts("1");
      }
      else if(ind > 1){
        puts("2");
      }
      else{
        puts("-1");
      }
    }
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a == 0 || b == 0){
      puts("0");
    }
    else{
      long long mx = 0;
      if(a > b){
        swap(a, b);
      }
      // cout << a << ' ' << b << endl;
      if(a * 3ll <= 1ll * b){
        mx = 1ll * a;
      }
      else{
        mx = (a + b) / 4;
        // puts("3");
      }
      printf("%d\n", (int)mx);
    }
  }

  return 0;
}
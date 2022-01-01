#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T> using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int N = 1e5 + 5;

void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  if(t != "abc"){
    cout << s << endl;
  }
  else{
    if(s.find("a") != s.npos && s.find("b") != s.npos && s.find("c") != s.npos){
      int cnt = 0;
      for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'c'){
          cnt++;
        }
      }
      int first = 0;
      for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'c'){
          continue;
        }
        if(s[i] == 'b' && first == 0){
          first = 1;
          for(int j = 0; j < cnt; j++){
            cout << 'c';
          }
          cout << 'b';
        }
        else{
          cout << s[i];
        }
      }
      cout << endl;
    }
    else{
      cout << s << endl;
    }
    
  }
}

int main() {
  int t;
  // scanf("%d", &t);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

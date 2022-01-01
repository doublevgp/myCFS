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
  string a, s;
  cin >> a >> s;
  int cnt = s.size() - 1;
  int an = a.size();
  if(s.size() < a.size()){
    cout << "-1\n";
    return ;
  }
  std::vector<int> b;
  for(int i = an - 1; i >= 0; i--){
    if(a[i] <= s[cnt]){
      b.pb(s[cnt] - a[i]);
      cnt--;
    }
    else{
      cnt--;
      int x = (s[cnt] - '0') * 10 + s[cnt + 1] - '0';
      // cout << "x = " << x << endl;
      // cout << a[i] - '0' << endl;
      if((a[i] - '0') <= x){
        if(x - (a[i] - '0') < 10){
          b.pb(x - (a[i] - '0'));
          cnt--;
        }
        else{
          cout << "-1\n";
          return ;
        }
      }
      else{
        cout << "-1\n";
        return ;
      }
    }
  }
  while(cnt >= 0){
    b.pb(s[cnt--] - '0');
  }
  reverse(b.begin(), b.end());
  bool ok = false;
  for(int i = 0; i < (int)b.size(); i++){
    if(b[i] != 0){
      ok = true;
    }
    if(!ok){
      continue;
    }
    cout << b[i];
  }
  cout << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

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
int n;
int a[N];
#define no {cout << -1 << endl; return ;}
void solve() {
  cin >> n;
  bool ok = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    if(a[i] >= n){
      ok = 1;
      break;
    }
  }
  if(!ok){
    no
  }
  int ans = 0;
  map<int, bool> m;
  map<ll, bool> l;
  m.clear();
  l.clear();
  for(int i = 1; i <= n; i++){
    if(a[i] <= n && m[a[i]] == false){
      m[a[i]] = true;
    }
    else{
      l[a[i]] = true;
    }
  }
  for(int i = 1; i <= n; i++){
    if(m[i] == false){
      for(auto x : l){
        if(x.second == false){
          continue;
        }
        if((x.first - 1) / 2 >= i){
          l[x.first] = false;
          ans++;
          break;
        }
        else{
          no
        }
      }
    }
  }
  cout << ans << endl;
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

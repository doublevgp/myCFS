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

const int N = 2e5 + 5;
int n;
int b[N], p[N];
int val[N], w[N];
void init(){
  for(int i = 0; i < N; i++){
    val[i] = -1;
    w[i] = 0;
  }
}
void solve() {
  cin >> n;
  int rt = 0;
  for(int i = 1; i <= n; i++){
    cin >> b[i];
    if(b[i] == i){
      rt = i;
    }
  }
  for(int i = 1; i <= n; i++){
    cin >> p[i];
  }

  if(p[1] != rt){
    cout << "-1\n";
    return ;
  }
  init();
  bool tag = true;
  val[rt] = 0;
  int v = 0;
  for(int i = 2; i <= n; i++){
    int cur = p[i];
    if(val[b[cur]] == -1){
      tag = false;
      cout << "-1\n";
      return ;
    }
    val[cur] = ++v;
    w[cur] = val[cur] - val[b[cur]];
  }

  for(int i = 1; i <= n; i++){
    cout << w[i] << ' ';
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

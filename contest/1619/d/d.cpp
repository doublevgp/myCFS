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
int n, m;
std::vector<int> p[N];
void solve() {
  cin >> m >> n;
  int mx[n + 1];
  for(int i = 1; i <= n; i++){
    mx[i] = 0;
  }
  for(int i = 1; i <= m; i++){
    p[i].clear();
    for(int j = 1; j <= n; j++){
      int x;
      cin >> x;
      p[i].pb(x);
      mx[j] = max(mx[j], x);
    }
  }
  int ans = 0x3f3f3f3f;
  for(int i = 1; i <= n; i++){
    ans = min(ans, mx[i]);
  }
  if(n > m){
    cout << ans << endl;
  }
  else{
    int mxi = 0;
    for(int i = 1; i <= m; i++){
      sort(p[i].begin(), p[i].end(), greater<int>());
      mxi = max(mxi, p[i][1]);
    }
    cout << min(mxi, ans) << endl;
  }
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

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

const int N = 105;

int n, l, r, k;
int a[N];
void solve() {
  cin >> n >> l >> r >>  k;
  std::vector<int> ok;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    if(a[i] >= l && a[i] <= r){
      ok.pb(a[i]);
    }
  }

  sort(ok.begin(), ok.end());
  ll ans = 0;
  for(int i = 0; i < (int)ok.size(); i++){
    int x = ok[i];
    if(k >= x){
      ans++;
      k -= x;
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

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

ll a[20], cnt[20];
void solve() {
  int n;
  cin >> n;
  int tm = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n - 1; i++){
    while(a[i] % 2 == 0){
      a[n] *= 2ll;
      a[i] /= 2;
      // cout << a[n] << endl;
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    ans += a[i];
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

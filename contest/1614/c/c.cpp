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

const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, m;
ll qpow(ll a, ll b){
  ll ans = 1;
  while(b){
    if(b & 1){
      ans = ans * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  ll ans = 0, g = 0;
  for(int i = 1; i <= m; i++){
    ll l, r, x;
    cin >> l >> r >> x;
    g |= x;
  }
  for(int i = 0; i < 30; i++){
    if(g >> i & 1){
      ans = (ans + qpow(2ll, n + i - 1)) % mod;
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

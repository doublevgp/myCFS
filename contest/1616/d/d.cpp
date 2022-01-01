// Problem: D. Keep the Average High
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <array>
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

#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
template <typename T>
#define pair2 pair<T, T>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int N = 50005;
const int INF = (int)1e9 + 5;
int n;
void solve() {
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto get_sum = [&](int l, int r) -> ll {
    ll sum = 0;
    for (int i = l; i < r; i++) {
      sum += a[i];
    }
    return sum;
  };
  ll x;
  cin >> x;
  array<int, 4> dp = {0, -INF, -INF, -INF};
  for (int i = 0; i < n; i++) {
    array<int, 4> ndp = {0, -INF, -INF, -INF};
    for (int before = 0; before <= 3; before++) {
      ndp[0] = max(ndp[0], dp[before]);
      int after = min(before + 1, 3);
      bool good = true;
      for (int len = 2; len <= 3; len++) {
        if (len > before + 1 || len > i + 1) {
          break;
        }
        ll sum = get_sum(i + 1 - len, i + 1);
        if (sum < x * len) {
          good = false;
        }
      }
      if (good) {
        ndp[after] = max(ndp[after], dp[before] + 1);
      }
    }
    dp = ndp;
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
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

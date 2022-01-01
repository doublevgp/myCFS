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
int a[N], b[N];
int mx = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  int l = 1, r = n;
  int mx = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid - cnt - 1 && b[i] >= cnt) {
        cnt++;
      }
    }
    if (cnt >= mid) {
      mx = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << mx << endl;
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

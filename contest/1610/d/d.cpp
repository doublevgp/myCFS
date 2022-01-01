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
const int mod = 1e9 + 7;

int n;
ll a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

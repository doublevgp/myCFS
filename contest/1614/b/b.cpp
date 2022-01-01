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
pll a[N];
ll ans[N];
bool cmp(pll o1, pll o2){
  return o1.first > o2.first;
}
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  // for(int i = 1; i <= n; i++){
  //   cout << a[i].second << ' ' << a[i].first << endl;
  // }
  ans[0] = 0;
  ll minTime = 0;
  int l = 0, r = 0;
  for(int i = 1; i <= n; i++){
    int x = a[i].second;
    ans[x] = (i % 2 == 1 ? --l : ++r);
    minTime += 2ll * a[i].first * abs(ans[x]);
  }
  cout << minTime << endl;
  for(int i = 0; i <= n; i++){
    cout << ans[i] << ' ';
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

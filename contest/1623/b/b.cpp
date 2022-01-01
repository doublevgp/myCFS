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

const int N = 1005;
bool cmp(pii o1, pii o2) {
  return o1.first < o2.first    ? true
         : o1.first == o2.first ? o1.second > o2.second
                                : false;
}
void solve() {
  int n;
  cin >> n;
  vector<pii> a;
  vector<int> b(n);
  map<int, int> cnt;
  cnt.clear();
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.pb(mp(l, r));
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++) {
    int l = a[i].first, r = a[i].second;
    if (l == r) {
      cout << l << ' ' << l << ' ' << l << endl;
    } else if (l == a[i + 1].first) {
      cout << l << ' ' << r << ' ' << a[i + 1].second + 1 << endl;
    } else if (r == a[i + 1].second) {
      cout << l << ' ' << r << ' ' << a[i + 1].first - 1 << endl;
    }
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

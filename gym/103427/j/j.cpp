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

const int N = 1e4 + 5;
int a1[N], a2[N], dif[N];
int op(int l, int r, int x, int ad) {
  int tx = x;
  for (int i = 1; i <= 4; i++) {
    a1[i] = tx % 10;
    tx /= 10;
  }
  for (int i = l; i <= r; i++)
    a1[i] = (a1[i] + ad + 10) % 10;
  int res = 0;
  for (int i = 4; i >= 1; i--)
    res = res * 10 + a1[i];
  return res;
}
int dp[N];
void bfs() {
  queue<int> q;
  for (int i = 0; i < N; i++) {
    dp[i] = 0x3f3f3f3f;
  }
  dp[0] = 0;
  q.push(0);
  int u, v;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = 1; i <= 4; i++) {
      for (int j = i; j <= 4; j++) {
        for (int x = -1; x <= 1; x++) {
          v = op(i, j, u, x);
          if (dp[u] + 1 < dp[v]) {
            dp[v] = dp[u] + 1;
            q.push(v);
          }
        }
      }
    }
  }
}
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < 4; i++) {
    a1[i + 1] = s1[i] - '0' + 1;
    a2[i + 1] = s2[i] - '0' + 1;
    dif[i + 1] = (a2[i + 1] - a1[i + 1] + 10) % 10;
  }
  int tar = 0;
  for (int i = 1; i <= 4; i++) {
    tar = tar * 10 + dif[i];
  }
  cout << dp[tar] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bfs();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

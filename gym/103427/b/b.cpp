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
const int M = 4e5 + 5;
int linker[M], head[N], adj[M], wei[M], tot = 0;
void addedge(int u, int v, int w) {
  linker[++tot] = head[u], head[u] = tot, adj[tot] = v, wei[tot] = w;
  linker[++tot] = head[v], head[v] = tot, adj[tot] = u, wei[tot] = w;
}
int val[N], c[35];
int sz = 0;
void dfs(int x) {
  sz++;
  for (int i = 0; i < 30; i++) {
    if (val[x] & (1 << i))
      c[i]++;
  }
  for (int e = head[x]; e; e = linker[e]) {
    if (val[adj[e]] == -1) {
      val[adj[e]] = val[x] ^ wei[e];
      dfs(adj[e]);
    } else {
      if ((val[adj[e]] ^ val[x]) != wei[e]) {
        cout << "-1\n";
        exit(0);
      }
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
  }
  memset(val, -1, sizeof(val));
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (val[i] == -1) {
      val[i] = 0, sz = 0;
      dfs(i);
      for (int j = 0; j < 30; j++) {
        ans += (1ll << j) * min(c[j], sz - c[j]), c[j] = 0;
      }
    }
  }
  cout << ans << endl;
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

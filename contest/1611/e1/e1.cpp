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
#define INF 0x7fffffff
int g[N][N];
int n, k;
void init(){
  for(int i = 1; i <= n; i++){
    g[i][i] = 0;
    for(int j = 1; j <= n; j++){
      if(i != j){
        g[i][j] = INF;
      }
    }
  }
}
map<int, int> du;
void addEdge(int u, int v){
  // g[u].pb(v);
  // g[v].pb(u);
  g[u][v] = 1;
  du[u]++;
  g[v][u] = 1;
  du[v]++;
}
int dis[N][N];
void Floyd() {
  int i, j, k;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      dis[i][j] = g[i][j];
    }
  }
  for (k = 1; k <= n; k++) {            //一次考察所有顶点
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (dis[i][j] > dis[i][k] + dis[k][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];    //修改最短路径长度
        }
      }
    }
  }
}
int xx[N];
void solve() {
  init();
  cin >> n >> k;
  for(int i = 1; i <= k; i++){
    cin >> xx[i];
  }
  for(int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
  }
  Floyd();
  std::vector<int> leaf;
  for(auto x : du){
    if(x.second == 1){
      leaf.pb(x.first);
    }
  }
  bool tagall = false;
  for(auto x : leaf){
    int dist = dis[x][1];
    bool tag = false;
    for(int j = 1; j <= k; j++){
      if(dist >= dis[x][xx[j]]){
        tag = true;
        break;
      }
    }
    if(tag == false){
      tagall = true;
      break;
    }
  }
  cout << (tagall ? "YES" : "NO") << endl;
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

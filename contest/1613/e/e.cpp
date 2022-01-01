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
#define ij (i * m + j + 1)
const int N = 1e6 + 5;
const int movx[] = {0, 1, 0, -1};
const int movy[] = {1, 0, -1, 0};
int n, m;
bool vis[N];  
vector<char> g[N];
vector<int> e[N];
vector<int> deg(N);
void addEdge(int u, int x, int y){
  e[u].emplace_back(x * m + y + 1);
  deg[u]++;
}
void init(){
  for(int i = 0; i < N; i++){
    vis[i] = false;
    deg[i] = 0;
    e[i].clear();
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    g[i].resize(m);
  for(int i = 0; i < n; i++){
    char s[m];
    scanf("%s", s);
    for(int j = 0; j < m; j++){
      g[i][j] = s[j]; 
    }
  }
  int lab = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] != '#'){
        if(g[i][j] == 'L'){
          lab = ij;
        }
        for(int step = 0; step < 4; step++){
          int nx = i + movx[step], ny = j + movy[step];
          if(nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '#'){
            continue;
          }
          addEdge(ij, nx, ny);
        }
      }
    }
  }
  queue<int> q;
  q.push(lab);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    vis[u] = true;
    for(int i = 0; i < (int)e[u].size(); i++){
      if(deg[e[u][i]] <= 2 && !vis[e[u][i]]){
        q.push(e[u][i]);
      }
      else{
        --deg[e[u][i]];
      }
    }
  }
  char ans[m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '.' && vis[ij]){
        putchar('+');
      }
      else{
        putchar(g[i][j]);
      }
    }
    printf("\n");
  }
  init();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}

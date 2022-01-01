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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int N = 2e5 + 5;
int pre[N][32];
void findPrefixCount()
{
  for(int i = 1; i < N; i++){
    for(int j = 0; j < 32; j++){
      if((i >> j) & 1){
        pre[i][j] = pre[i - 1][j] + 1;
      }
      else{
        pre[i][j] = pre[i - 1][j];
      }
    }
  }
}
int l, r;
void solve() {
  cin >> l >> r;
  int cur[32];
  int mx = 0;
  for(int i = 0; i < 32; i++){
    cur[i] = pre[r][i] - pre[l - 1][i];
    mx = max(mx, cur[i]);
  }
  cout << (r - l + 1 - mx) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  findPrefixCount();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}



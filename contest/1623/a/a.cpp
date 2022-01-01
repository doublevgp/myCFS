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

const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  int rb, cb, rd, cd;
  cin >> rb >> cb >> rd >> cd;
  int ans = 0;
  int dr, dc;
  dr = dc = 1;
  if(rd == rb || cb == cd){
    ans = 0;
  }
  else{
    if(rd < rb && cd > cb){
      ans = min(cd - cb, 2 * n - (rd + rb));
    }
    else if(rd > rb && cd > cb){
      ans = min(rd - rb, cd - cb);
    }
    else if(rd < rb && cd < cb){
      ans = min(2 * n - (rd + rb), 2 * m - (cb + cd));
    }
    else if(rd > rb && cd < cb){
      ans = min(rd - rb, 2 * m - (cd + cb));
    }
  }
  cout << ans << endl;
  // while(1){
  //   if(rb == rd || cb == cd){
  //     break;
  //   }
  //   int nr = rb + dr, nc = cb + dc;
  //   if(nr == 1 || nr == n){
  //     dr = -dr;
  //   }
  //   if(nc == 1 || nc == m){
  //     dc = -dc;
  //   }
  //   rb = nr;
  //   cb = nc;
  //   ans++;
  // }
  // cout << ans << endl;
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

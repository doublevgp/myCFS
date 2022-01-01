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
int query(int a, int b, int c){
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  fflush(stdout);
  int x;
  cin >> x;
  return x;
}
void solve() {
  int n;
  cin >> n;
  std::vector<int> ans(n / 3);
  for(int i = 0; i < n / 3; i++){
    ans[i] = query(i * 3 + 1, i * 3 + 2, i * 3 + 3);
  }
  int g = find(ans.begin(), ans.end(), 1) - ans.begin();
  int b = find(ans.begin(), ans.end(), 0) - ans.begin();
  vector<int> a{g * 3 + 1, g * 3 + 2, g * 3 + 3, b * 3 + 1, b * 3 + 2, b * 3 + 3};
  int id = 0;
  if(query(a[1], a[2], a[3])){
    if(query(a[2], a[3], a[4])){
      id = 2;
    }
    else{
      id = 1;
    }
  }
  int x = a[id], y = a[id + 3];
  vector<int> r{y};
  for(int i = 1; i <= n; i++){
    if(i != x && i != y){
      if(query(x, y, i) == 0){
        r.pb(i);
      }
    }
  }
  cout << "! " << r.size();
  for(auto x : r) cout << ' ' << x;
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

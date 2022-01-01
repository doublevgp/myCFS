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

const int N = 1e2 + 5;
ll n;
ll h;
ll a[N];
ll checkMid(ll mid){
  ll sum = 0;
  ll se = a[1];
  for(int i = 1; i < n; i++){
    sum += min(mid, a[i + 1] - a[i]);
    se = a[i] + mid;
  }
  sum += mid;
  // cout << sum << endl;
  return sum;
}
void solve() {
  cin >> n >> h;
  for(ll i = 1; i <= n; i++){
    cin >> a[i];
  }
  ll l = 1, r = h;
  while(r >= l){
    ll mid = (l + r) >> 1;
    if(checkMid(mid) > h){
      r = mid - 1;
    }
    else if(checkMid(mid) == h){
      cout << mid << endl;
      return ;
    }
    else{
      l = mid + 1;
    }
  }
  cout << l << endl;
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

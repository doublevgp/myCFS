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

const int N = 2e6 + 5;
ll n;
ll cnt[N], ans[N];
priority_queue<ll> q;
void solve() {
  cin >> n;
  while(!q.empty())
    q.pop();
  for(ll i = 0; i <= n + 1; i++){
    cnt[i] = 0;
    ans[i] = 0;
  }
  for(ll i = 0; i < n; i++){
    ll x;
    cin >> x;
    if(x >= n){
    }else{
      cnt[x]++;
    }
  }
  ll mex = 0;
  for(ll i = 0; i < n; i++){
    if(cnt[i] == 0){
      break;
    }
    else{
      mex++;
    }
  }
  ans[mex] = 0;
  for(ll i = 0; i < mex; i++){
    ans[i] = cnt[i];
  }

  for(ll i = 0; i <= mex; i++){
    while(cnt[i] > 1){
      q.push(i);
      cnt[i] -= 1;
    }
  }
  bool ok = false;
  ll m = 0;
  for(int i = mex + 1; i <= n; i++){
    if(ok){
      ans[i] = -1;
      continue;
    }
    if(cnt[i - 1]){
      ans[i] = cnt[i] + m;
    }
    else{
      if(q.empty()){
        ok = true;
        ans[i] = -1;
      }
      else{
        ll x = q.top();
        q.pop();
        m += i - x - 1;
        ans[i] = m + cnt[i];
      }
    }
    while(cnt[i - 1] > 1){
      q.push(i - 1);
      cnt[i - 1] -= 1;
    }
  }
  for(ll i = 0; i <= n; i++){
    cout << ans[i] << (i == n ? "\n" : " ");
  }
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

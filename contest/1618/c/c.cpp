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
ll gcd(ll x, ll y){
  return y == 0 ? x : gcd(y, x % y);
}
const int N = 1e5 + 5;
int n;
void solve() {
  cin >> n;
  std::vector<ll> a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  ll j = a[1], k = a[2];
  for(int i = 3; i <= n; i++){
    if(i & 1){
      j = gcd(j, a[i]);
    }
    else{
      k = gcd(k, a[i]);
    }
  }
  // cout << j << ' ' << k << endl; 
  bool ok = false;
  for(int i = 1; i < n; i++){
    if(a[i] % j == 0 && a[i + 1] % j == 0){
      ok = true;
      break;
    }
  }
  if(!ok){
    cout << j << endl;
    return;
  }
  ok = false;
  for(int i = 1; i < n; i++){
    if(a[i] % k == 0 && a[i + 1] % k == 0){
      ok = true;
      break;
    }
  }
  if(!ok){
    cout << k << endl;
  }
  else{
    cout << "0\n";
  }
  // if(j == k){
  //   cout << '0' << endl;
  // }
  // if(j != k){
  //   if(!tag)
  //     cout << max(j, k) << endl;
  //   else
  //     cout << "0\n";
  // }
  // for(int i = 1; i < n; i++){
  //   if(a[i] % a[i + 1] == 0 || a[i + 1] % a[i] == 0){

  //   }
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

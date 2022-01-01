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

const int N = 4e4 + 5;
int n, b[N];

void solve() {
  cin >> n;
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> b[i];
    sum += b[i];
  }
  if(sum % ((n * n + n) / 2) == 0){
    int a[n];
    ll bsum = sum / ((n * n + n) / 2);
    for(int i = 0; i < n; i++){
      ll dif = b[i] - b[(i + n - 1) % n];
      ll check = bsum - dif;
      if(check <= 0 || check % n != 0){
        cout << "NO\n";
        return ;
      }
      a[i] = check / n;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
      cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
  }
  else{
    cout << "NO\n";
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

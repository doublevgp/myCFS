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
int n;
int a[N];
int p[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if(a[1] == n || a[n] == n){
    deque<int> q;
    int i = 1, j = n;
    while(i <= j){
      if(a[i] < a[j]){
        q.push_front(a[i]);
        i++;
      }
      else{
        q.push_back(a[j]);
        j--;
      }
    }
    for(int i = 0; i < n; i++){
      cout << q[i] << ' ';
    }
    cout << endl;
  }
  else{
    cout << "-1" << endl;
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

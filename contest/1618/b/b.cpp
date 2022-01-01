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
int n;
void solve() {
  cin >> n;
  std::vector<string> a(n - 2);
  string all;
  for(int i = 0; i < n - 2; i++){
    cin >> a[i];
  }
  all = a[0];
  bool ok = false;
  for(int i = 1; i < n - 2; i++){
    if(all[all.size() - 1] == a[i][0]){
     // cout << all[all.size() - 1] << ' ' << a[i][0] << endl;
      all += a[i][1];
    }
    else{
      all += a[i];
      ok = true;
    }
  }
  if(ok){
    // cout << "yes" << endl;
    cout << all << endl;
  }
  else{
    // cout << "no" << endl;
    cout << all + 'a' << endl;
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

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
#define yes 
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  std::vector<int> a(55);
  a[0] = 1;
  for(int i = 0; i < s.size() - 1; i++){
    if(s[i] == 'E'){
      a[i + 1] = a[i];
    }
    else{
      a[i + 1] = -a[i];
    }
  }
  int n = s.size();
  if(s[n - 1] == 'E'){
    if(a[n - 1] < 0){
      if(abs(a[n - 2]) == a[0]){
        
      }
    }
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

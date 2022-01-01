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

double x1, x2;
int p1, p2;
void solve() {
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  while(x1 >= 10){
    x1 /= 10.0;
    p1 += 1;
  }
  while(x2 >= 10){
    x2 /= 10.0;
    p2 += 1;
  }
  if(p1 > p2){
    cout << ">" << endl;
  }
  else if(p1 == p2){
    if(fabs(x1 - x2) <= 1e-6){
      cout << "=" << endl;
    }
    else if(x1 > x2){
      cout << ">" << endl;
    }
    else{
      cout << "<" << endl;
    }
  }
  else{
    cout << "<" << endl;
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

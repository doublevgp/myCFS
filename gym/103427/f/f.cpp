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
string Fs(string s) {
  map<char, int> g;
  for (int i = 0; i < (int)s.size(); i++) {
    g[s[i]] = i;
  }
  vector<char> trans(26);
  for (auto x : g) {
    int cnt = 0;
    map<char, bool> chr;
    for (int i = x.second + 1; i < (int)s.size(); i++) {
      if (!chr[s[i]]) {
        cnt++;
        chr[s[i]] = true;
      }
    }
    trans[x.first - 'a'] = 'a' + cnt;
  }
  for (int i = 0; i < (int)s.size(); i++) {
    s[i] = trans[s[i] - 'a'];
  }
  // cout << "s = " << s << endl;
  return s;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string tmp = "";
  vector<string> v;
  string mx = "";
  for (int i = 0; i < n; i++) {
    tmp += s[i];
    v.pb(tmp);
    mx = max(mx, Fs(tmp));
  }

  cout << mx << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

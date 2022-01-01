// Problem: C. Dominant Character
// Contest: Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#ifdef LOCAL
#define eprintf(...)            \
  fprintf(stderr, __VA_ARGS__); \
  fflush(stderr);
#else
#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) { return (ull)rng() % B; }

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1e6 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s.find("aa") != s.npos) {
    puts("2");
    return;
  }
  if (s.find("aba") != s.npos || s.find("aca") != s.npos) {
    puts("3");
    return;
  }
  if (s.find("abca") != s.npos || s.find("acba") != s.npos) {
    puts("4");
    return;
  }
  if (s.find("abbacca") != s.npos || s.find("abcabca") != s.npos ||
      s.find("abcacba") != s.npos || s.find("acbabca") != s.npos ||
      s.find("acbacba") != s.npos || s.find("accabba") != s.npos) {
    puts("7");
    return;
  }
  puts("-1");
}

int main() {
  startTime = clock();
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  int t;
  // scanf("%d", &t);
  cin >> t;
  while (t--) solve();

  return 0;
}

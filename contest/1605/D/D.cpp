// Problem: D. Treelabeling
// Contest: Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/D
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

const int N = 1e5 + 5;

void solve() {}

int main() {
  startTime = clock();
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while (t--) solve();

  return 0;
}

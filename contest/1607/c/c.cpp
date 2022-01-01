#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
  #define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
  #define eprintf(...) 42
#endif

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 2e5+5;

void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  ll ans = a[1];
  for(int i = 2; i <= n; i++){
    ans = max(ans, 1ll * (a[i] - a[i - 1]));
  }
  cout << ans << endl;
}

int main()
{
  startTime = clock();
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while(t--) solve();

  return 0;
}

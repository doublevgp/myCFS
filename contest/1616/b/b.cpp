// Problem: B. Mirror in the String
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
template <typename T>
#define pair2 pair<T, T>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = 1;
  while (k < n && (s[k] < s[k - 1] || (k > 1 && s[k] == s[k - 1]))) {
    k++;
  }
  for (int i = 0; i < k; i++) {
    cout << s[i];
  }
  for (int i = k - 1; i >= 0; i--) {
    cout << s[i];
  }
  cout << endl;
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

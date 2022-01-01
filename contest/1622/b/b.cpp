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

const int N = 2e5 + 5;
int n;
bool cmp(pii o1, pii o2){
  return o1.second < o2.second;
}
void solve() {
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  string s;
  cin >> s;
  int l = 1, r = n;
  vector<pii> pos, pos2;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '0'){ 
      cnt++;
      pos.pb(mp(i, p[i]));
    }
    else{
      pos2.pb(mp(i, p[i]));
    }
  }
  sort(pos.begin(), pos.end(), cmp);
  sort(pos2.begin(), pos2.end(), cmp);
  vector<int> ans(n);
  for(int i = 0; i < (int)pos.size(); i++){
    ans[pos[i].first] = l++;
  }
  for(int i = 0; i < (int)pos2.size(); i++){
    ans[pos2[i].first] = l++;
  }
  for(int i = 0; i < n; i++){
    cout << ans[i] << ' ';
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

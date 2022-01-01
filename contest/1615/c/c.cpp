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

const int N = 100005;
int n;
string a, b;
void solve() {
  cin >> n;
  cin >> a >> b;
  if(a == b){
    cout << 0 << endl;
    return ;
  }
  bool ok = false;
  for(int i = 0; i < n; i++){
    if(a[i] == '1'){
      ok = true;
      break;
    }
  }
  if(!ok){
    cout << -1 << endl;
    return ;
  }
  vector<int> samePos, diffPos;
  int cnt1, cnt2;
  cnt1 = cnt2 = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == b[i]){
      samePos.pb(i);
      if(a[i] == '1'){
        cnt1++;
      }
    }
    else{
      diffPos.pb(i);
      if(a[i] == '1'){
        cnt2++;
      }
    }
  }
  int mi = 100005;
  if((cnt1 == (int)samePos.size() / 2 + 1) && (int)samePos.size() & 1){
    mi = (int)samePos.size();
  }
  if(cnt2 == (int)diffPos.size() / 2 && (int)diffPos.size() % 2 == 0){
    mi = min(mi, (int)diffPos.size());
  }
  if(mi == 100005){
    cout << -1 << endl;
    return ;
  }
  cout << mi << endl;
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

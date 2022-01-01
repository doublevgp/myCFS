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
int vis[10005];
vector<int> primes;
void init(){
  for(int i = 0; i < 10000; i++)
    vis[i] = true;
  vis[0] = vis[1] = false;
  for(int i = 2; i < 10000; i++){
    if(vis[i] == true){
      primes.pb(i);
      for(int j = 0; j < (int)primes.size(); j++){
        if(i * primes[j] > 10000)
          break;
        vis[i * primes[j]] = false;
        if(i % primes[j] == 0)
          break;
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cout << primes[i] << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

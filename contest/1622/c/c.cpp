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
#include <functional>
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
ll n, k;
ll suff[100005];
int binary(int i, int l, int r, ll tmp){
  while(l <= r){
      //二分找满足条件的最小x
      //把x个大数修改成i
      // 那么 sum = sum - (suff[n - x] - x * i)
      // 如果 sum <= k 更新 ans
      int mid = (l + r) / 2;
      // cout << "mid = " << mid << endl;
      if(tmp + 1ll * mid * i - suff[n - mid] == k){
        return mid;
      }
      else if(tmp + 1ll * mid * i - suff[n - mid] > k){
        l = mid + 1;
        // cout << "aa" << endl;
      }
      else{
        r = mid - 1;
        // cout << "bb" << endl;
      }
  }
  if(tmp + 1ll * r * i - suff[n - r] > k){
    return -1;
  }
  return r;
}
void solve() {
  cin >> n >> k;
  vector<ll> a(n);
  priority_queue<ll> q;
  priority_queue<ll, vector<ll>, greater<ll> > Q;
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    q.push(a[i]);
    Q.push(a[i]);
  }
  if(sum <= k){
    cout << 0 << endl;
    return ;
  }
  sort(a.begin(), a.end());
  
  suff[n] = 0;
  for(int i = n - 1; i >= 0; i--){
    suff[i] = suff[i + 1] + a[i];
  }
  ll ans = sum - k;
  // cout << ans << endl;
  ll tmp = sum;
  // cout << "sum = " << sum << endl;
  // cout << a[0] - sum + k << endl;
  for(int i = a[0]; i >= a[0] - sum + k; i--){
    // cout << "hhhh " << endl;
    tmp = sum;
    ll cnt = a[0] - i;
    // cout << "cnt = " << cnt << endl;
    //把最小值变成i 用i去set 所需要花费a[0] - i步
    tmp -= cnt;
    //此时sum = sum - cnt 因为减了cnt
    // cout << "tmp = " << tmp << endl;
    int l = 0, r = n - 1;
    int x = binary(i, l, r, tmp);
    // cout << "x = " << x << endl;
    // cout << "i = " << i << " l = " << l << " r = " << r << endl;
    if(x != -1){
      cnt += x;
    }
    // cout << "i = " << i << " l = " << l << endl;
    // cout << cnt << endl;
    if(tmp - suff[n - x] + 1ll * x * i <= k){
      ans = min(ans, cnt);
      // break;
    }
    // cout << "cnt = " << cnt << endl;
    
    // tmp = tmp - suff[n - l] + 1ll * l * i;
    // cout << "i = " << i << ' ' << ans << endl;
  }
  cout << ans << endl;

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

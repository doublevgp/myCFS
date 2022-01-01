#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt[105];
    for (int i = 0; i < 105; i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[abs(a)]++;
    }
    int ans = 0;
    for (int i = 0; i < 101; i++) {
      if (i == 0) {
        ans += min(cnt[i], 1);
      } else {
        ans += min(cnt[i], 2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
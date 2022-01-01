#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second


const int N = 1e5+5;

void solve() {
  ll x0, n;
  cin >> x0 >> n;
  ll ans;
  if(x0 % 2 == 0){
    ll x = n % 4;
    switch (x)
    {
      case 0:
        ans = x0;
        break;
      case 1:
        ans = x0 - n;
        break;
      case 2:
        ans = x0 + 1;
        break;
      case 3:
        ans = x0 + 1 + n;
        break;
    }
  }
  else{
    ll x = n % 4;
    switch (x)
    {
      case 0:
        ans = x0;
        break;
      case 1:
        ans = x0 + n;
        break;
      case 2:
        ans = x0 - 1;
        break;
      case 3:
        ans = x0 - 1 - n;
        break;
    }
  }
  cout << ans << endl;
}

int main()
{

//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while(t--) solve();

  return 0;
}

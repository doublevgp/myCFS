/*
* @Author: doublevgp
* @Date:   2021-12-28 00:39:55
* @Last Modified by:   doublevgp
* @Last Modified time: 2021-12-28 01:10:02
* @File_name: c1.cpp
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<ll> pre(n + 1);
		for(int i = 0; i < n; i++){
			pre[i + 1] = pre[i] + a[i];
		}
		ll ans = (ll)9e18;
		for(int t = 0; t <= n - 1; t++){
			ll sum = pre[n - t] + a[0] * t;
			ll cur = t;
			if(sum > k){
				ll dif = sum - k;
				cur += (dif + (t + 1) / 2) / (t + 1);
			}
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}
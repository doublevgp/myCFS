#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
int n;
ll a[N];

int main() {
	cin >> n;
	ll mx = 0;
	int idx = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(mx < a[i]){
			mx = a[i];
			idx = i;
		}
	}
	ll sum = 0;
	for(ll i = 1; i <= n; i++){
		sum += a[(idx - i + n) % n] * (n - i + 1);
	}
	cout << sum << endl;

	return 0;
}
/*
* @Author: doublevgp
* @File_name: b.cpp
*/
#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}

	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch & 15);
		ch = getchar();
	}
	return x * f;
}
#define pii pair<int,int> 
bool cmp(pii x, pii y){
	if(x.first == y.first)
		return x.second > y.second;
	else
		return x.first < y.first;
}
int main() {
	int T = read();
	while(T--){
		int n, k;
		n = read();
		k = read();
		std::vector<int> a(n + 1);
		long long ans = -1e12;
		for(int i = 1; i <= n; i++){
			a[i] = read();
		}

		int l = max(1, n - 2 * k);
		for(int i = l; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, 1ll * i * j - 1ll * k * (a[i] | a[j]));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
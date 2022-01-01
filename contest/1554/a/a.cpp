/*
* @Author: doublevgp
* @File_name: a.cpp
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
int main() {
	int T;
	T=read();
	while(T--){
		int n;
		n = read();
		std::vector<int> a(n + 1);
		long long ans = 0;
		for(int i = 0; i < n; i++){
			a[i] = read();
		}

		for(int i = 0; i < n - 1; i++){
			ans = max(ans, 1ll * a[i] * a[i + 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
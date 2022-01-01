/*
* @Author: doublevgp
* @File_name: f.cpp
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
const int maxn = 1e6 + 5;
int a[maxn], f[maxn];
int main() {
	int n;
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}

	f[n] = a[n];
	for(int i = n - 1; i >= 1; --i){
		f[i] = min(f[i + 1], a[i]);
	}
	int mx = a[1], ans = 1;
	for(int i = 1; i < n; i++){
		mx = max(mx, a[i]);
		if(mx <= f[i + 1]){
			ans++;
			mx = a[i + 1];
		}
	}
	printf("%d\n", ans);
	return 0;
}
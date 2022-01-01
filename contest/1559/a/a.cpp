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
	int t;
	t = read();
	while(t--){
		int n;
		n = read();
		int a[101];
		for(int i = 1; i <= n; i++){
			a[i] = read();
		}
		int ans = a[1];
		for(int i = 2; i <= n; i++){
			ans &= a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
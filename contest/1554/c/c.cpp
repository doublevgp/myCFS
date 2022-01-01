/*
* @Author: doublevgp
* @File_name: c.cpp
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
		int n, m;
		n = read();
		m = read();
		m++;
		int ans = 0;
		for(int j = 30; j >= 0 && n <= m; j--){
			if((n >> j & 1) == (m >> j & 1)) continue;
			if(m >> j & 1){
				ans |= 1 << j;
				n |= 1 << j;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
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
	for(int t = read(); t; t--){
		int n;
		n = read();
		std::vector<int> a(n);
		for(int i = 0; i < n; ++i){
			a[i] = read();
		}
		int ans = 0;
		while(!is_sorted(a.begin(), a.end())){
			for(int i = ans & 1; i + 1 < n; i += 2){
				if(a[i] > a[i + 1]){
					a[i] ^= a[i + 1];
					a[i + 1] ^= a[i];
					a[i] ^= a[i + 1];
				}
			}
			ans += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
* @Author: doublevgp
* @File_name: d1.cpp
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
		int n, q;
		n = read();
		q = read();
		char s[n + 1];
		int a[n + 1], b[n + 1];
		scanf("%s", s);
		for(int i = 0; i < n; i++){
			if(i & 1){
				if(s[i] == '+'){
					b[i + 1] = b[i] - 1;
				}
				else{
					b[i + 1] = b[i] + 1;
				}
				a[i + 1] = a[i];
			}
			else{
				if(s[i] == '+'){
					a[i + 1] = a[i] + 1;
				}
				else{
					a[i + 1] = a[i] - 1;
				}
				b[i + 1] = b[i];
			}
		}
		while(q--){
			int l, r;
			l = read();
			r = read();
			int tmp = a[r] - a[l - 1] + b[r] - b[l - 1];
			if(tmp == 0){
				printf("0\n");
			}
			else if(tmp & 1){
				puts("1");
			}
			else{
				puts("2");
			}
		}
	}
	return 0;
}
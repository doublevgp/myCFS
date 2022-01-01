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
		cin >> n;
		string s[n << 1];
		for(int i = 0; i < n; i++){
			s[i] = "";
			for(int j = 0; j < 2 * n; j++){
				s[i] += '(';
			}
			for(int j = 1; j < 2 * n - 1; j++){
				
			}
		}
	}
	return 0;
}
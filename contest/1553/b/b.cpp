/*
* @Author: doublevgp
* @File_name: b.cpp
*/
#include <bits/stdc++.h>
#include <string>
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
	int q;
	cin >> q;
	while(q--){
		string s, t;
		cin >> s >> t;
		int n = s.length();
		int m = t.length();
		bool tag = false;
		for(int l = 0; l < n; l++){
			for(int r = l; r < n && r - l + 1 <= m; r++){
				if(s[r] != t[r - l]){
					break;
				}
				if(r - l + 1 + r < m){
					continue;
				}
				bool flag = true;
				for(int k = 0; k < m - (r - l + 1); k++){
					if(t[r - l + 1 + k] != s[r - k - 1])
						flag = false;
				}
				if(flag){
					tag = true;
					break;
				}
			}
		}
		if(tag){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
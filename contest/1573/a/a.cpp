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
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != '0'){
			if(i != n - 1){
				ans += 1;
			}
			ans += s[i] - '0';
		}
	}
	cout << ans << endl;
}
int main() {
	for(int t = read(); t; t--){
		solve();
	}
	return 0;
}
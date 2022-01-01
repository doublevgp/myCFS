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
void solve(){
	string s;
	cin >> s;
	int ans = 10;
	{
		int a = 0, b = 0, la = 5, lb = 5;
		int now = 10;
		for(int i = 0; i < 10; i++){
			if(s[i] == '1'){
				if(i % 2 == 0) ++a;
				else ++b;
			}
			else if(s[i] == '?'){
				if(i % 2 == 0) ++a;
			}
			--(i % 2 == 0 ? la : lb);
			if(b + lb < a){
				now = i + 1;
				break;
			}
		}
		ans = min(ans, now);
	}
	{
		int now = 10, a = 0, b = 0, la = 5, lb = 5;
		for(int i = 0; i < 10; i++){
			if(s[i] == '1'){
				if(i % 2 == 0) ++a;
				else ++b;
			}
			else if(s[i] == '?'){
				if(i % 2 == 1){
					++b;
				}
			}
			--(i % 2 == 0 ? la : lb);
			if(a + la < b){
				now = i + 1;
				break;
			}
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
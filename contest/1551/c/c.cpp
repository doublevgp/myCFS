/*
* @Author: studyordie
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
const int N = 2e5 + 1;
string s[N];
int cnt[N];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 'a'; i <= 'e'; i++){
		for(int j = 0; j < n; j++){
			int len = s[j].length();
			int t = 0;
			for(int k = 0; k < len; k++){
				if(s[j][k] == i){
					t++;
				}
			}
			cnt[j] = len - 2 * t;
		}
	}
	sort(cnt, cnt + n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += cnt[i];
		if(sum >= 0){
			cout << i + 1 << endl;
			break;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
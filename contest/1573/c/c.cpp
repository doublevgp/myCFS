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
#define pb push_back
void solve(){
	int n;
	cin >> n;
	std::vector<std::vector<int>> k(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> k[i][0];
		for(int j = 1; j <= k[i][0]; j++){
			int x;
			cin >> x;
			k[i].pb(x);
		}
	}

	int ans = 0;
	set<int> s;
	for(int i = 1; i <= n; i++){
		for()
	}
}
int main() {
	for(int t = read(); t; t--){
		solve();	
	}
	return 0;
}
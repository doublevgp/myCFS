/*
* @Author: doublevgp
* @File_name: b.cpp
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
int main() {
	int t;
	for(cin >> t; t; t--){
		string s;
		cin >> s;
		int n = s.size();
		int ans = 0;
		std::vector<char> v;
		v.pb(s[0]);
		for(int i = 1; i < n; i++){
			if(s[i] == v.back())
				continue;
			v.pb(s[i]);
		}
		for(int i = 0; i < (int)v.size(); i++){
			// cout << q.front() << ' ';
			ans += (v[i] == '1' ? 0 : 1);
		}
		cout << min(ans,2) << endl;
	}
	return 0;
}
/*
* @Author: doublevgp
* @File_name: b.cpp
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
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
		int a, b;
		a = read(); b = read();
		int n = a + b;
		std::vector<int> ans;
		int d = abs(a - b) >> 1;
		if(n & 1){
			for(int k = d; k <= a + b - d; k++){
				ans.push_back(k);
			}
		}
		else{
			for(int k = d; k <= a + b - d; k += 2){
				ans.push_back(k);
			}
		}
		cout << ans.size() << endl;
		for(int k : ans){
			cout << k << ' ';
		}
		cout << endl;
	}
	return 0;
}
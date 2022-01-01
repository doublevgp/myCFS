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
		int n, s;
		n = read();
		s = read();
		int pos = (n + 1) >> 1;
		int cnt = n - pos + 1;
		cout << (s / cnt) << endl;
	}
	return 0;
}
/*
* @Author: studyordie
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
	int t;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if(k > 0 && m < 2 || n == 1){
			cout << "NO\n";
			continue;
		}
		
	}
	return 0;
}
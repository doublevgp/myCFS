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
int main() {
	int t;
	t = read();
	while(t--){
		int n = read();
		char s[101];
		scanf("%s", s+1);
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += (s[i] != '?');
		}
		if(cnt == 0){
			s[1] = 'R';
		}
		for(int i = 2; i <= n; i++){
			if(s[i] == '?' && s[i - 1] != '?'){
				s[i] = s[i - 1] ^ ('B' ^ 'R');
			}
		}
		for(int i = n - 1; i >= 1; i--){
			if(s[i] == '?' && s[i + 1] != '?'){
				s[i] = s[i + 1] ^ ('B' ^ 'R');
			}
		}
		printf("%s\n", s+1);
	}
	return 0;
}
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
int main() {
	for(int t = read(); t; t--){
		int n;
		n = read();
		char s[n + 1];
		scanf("%s", s);
		int cnt_0 = 0, cnt = 0, l1 = 0, r1 = 0, ans_l1 = 0, ans_r1 = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(cnt == 0){
					l1 = i;
				}
				cnt += 1;
				r1 = i;
			}
			else{
				if(cnt_0 < cnt){
					ans_l1 = l1;
					ans_r1 = r1;
					cnt_0 = cnt;
				}
				cnt = 0;
			}
		}
		if(cnt_0 >= (n >> 1)){
			cout << ans_l1 << ' ' << ans_r1 << ' ' << 
		}
	}
	return 0;
}
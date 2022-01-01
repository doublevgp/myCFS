/*
* @Author: studyordie
* @File_name: b1.cpp
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
const int N = 55;
char s[N];
void sol(){
	scanf("%s", s);
	int green = 0, red = 0;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < strlen(s); i++){
		cnt[s[i] - 'a']++;
	}
	int sum = 0;
	for(int i = 0; i < 26; i++){
		if(cnt[i] == 1){
			sum++;
		}
		else if(cnt[i] >= 2){
			green++, red++;
		}
	}
	printf("%d\n", red+sum/2);
}
int main() {
	int t;
	for(t = read(); t; t--){
		sol();
	}
	return 0;
}
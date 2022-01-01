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

void solve(){
	long long n;
	scanf("%lld", &n);
	long long a[3] = {0};
	if(n > 10){
		a[0] = n / 6;
		n %= 6;
		// printf("n = %lld\n", n);
		if(n == 0){
			;
		}
		else if(n <= 2){
			--a[0];
			++a[1];
		}
		else if(n > 2 && n <= 4){
			--a[0];
			++a[2];
		}
		else if(n > 4){
			++a[0];
		}
		// printf("%lld %lld %lld\n", a[0], a[1], a[2]);	
	}
	else{
		if(n <= 6){
			a[0] = 1;
		}
		else if(n > 6 && n <= 8)
			a[1] = 1;
		else
			a[2] = 1;
	}
	printf("%lld\n", a[0] * 15 + a[1] * 20 + a[2] * 25);
}
int main() {
	int t;
	t = read();
	while(t--){
		solve();
	}
	return 0;
}
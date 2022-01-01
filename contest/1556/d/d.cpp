/*
* @Author: doublevgp
* @File_name: d.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x = 0, f = 1;
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
const int N = 1e5 + 5;
ll a[N];
#define fls fflush(stdout)
void f1(int x, int y){
	printf("or %d %d\n", x, y);
	fls;
}
void f2(int x, int y){
	printf("and %d %d\n", x, y);
	fls;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	f1(1,2);
	ll temp[7];
	int z = 1;
	temp[z++] = read();
	f2(1,2);
	temp[z++] = read();
	f1(1,3);
	temp[z++] = read();
	f2(1,3);
	temp[z++] = read();
	f1(2,3);
	temp[z++] = read();
	f2(2,3);
	temp[z++] = read();
	ll sum = 0;
	for(int i = 1; i <= 6; i++){
		sum += temp[i];
	}
	sum = sum / 2ll;
	for(int i = 1; i <= 3; i++){
		a[i] = sum - temp[6 - 2 * i + 1] - temp[6 - 2 * (i - 1)];
	}
	for(int i = 4; i <= n; i++){
		f1(1, i);
		ll x, y;
		x = read();
		f2(1, i);
		y = read();
		a[i] = x + y - a[1];
	}
	sort(a + 1, a + n + 1);
	printf("finish %lld", a[k]);
	fls;
	return 0;
}
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
#define pii pair<int,int>
#define x first
#define y second
int main() {
	int t;
	t = read();
	while(t--){
		int w, h;
		w = read();
		h = read();
		pii l, r;
		l.x = read();
		l.y = read();
		r.x = read();
		r.y = read();
		int mw = r.x - l.x, mh = r.y - l.y;

		int ww, hh;
		ww = read();
		hh = read();
		if(mw + ww > w && mh + hh > h){
			puts("-1");
			continue;
		}
		int ans = 1e9;
		if(mw + ww <= w){
			ans = min(ans, max(0, ww - l.x));
			ans = min(ans, max(0, r.x - (w - ww)));
		}
		if(mh + hh <= h){
			ans = min(ans, max(0, hh - l.y));
			ans = min(ans, max(0, r.y - (h - hh)));
		}
		cout << ans << endl;
	}
	return 0;
}
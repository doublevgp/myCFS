/*
* @Author: doublevgp
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
#define pii pair<int,int>
bool cmp(pii o1, pii o2){
	if(o1.first == o2.first){
		return o1.second > o2.second;
	}
	return o1.first < o2.first;
}
int main() {
	for(int t = read(); t; t--){
		int n, m;
		n = read(); m = read();
		long long sum = 0;
		for(int i = 1; i <= n; i++){
			std::vector<pii> v(m + 1);
			for(int j = 1; j <= m; j++){
				v[j].first = read();
				v[j].second = j;
			}
			sort(v.begin() + 1, v.end(), cmp);
			int sa[m + 1];
			sa[1] = 0;
			for(int j = 2; j <= m; j++){
				sa[j] = 0;
				for(int k = 1; k < j; k++){
					sa[j] += (v[j].second > v[k].second ? 1 : 0);
				}
				sum += sa[j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
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
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	int one_to_one = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1){
			one_to_one = i - 1;
		}
	}
	int n2 = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		if(b[i] == n << 1){
			n2 = i - 1;
		}
	}
	if(a[1] < b[1]){
		cout << "0\n";
		return ;
	}
	cout << min(one_to_one, n2) << endl;

}
int main() {
	for(int t = read(); t; t--){
		solve();
	}
	return 0;
}
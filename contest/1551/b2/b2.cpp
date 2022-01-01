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
	int n, k;
	n = read();
	k = read();
	std::vector<int> a(n), cnt(n);
	std::vector<int> in;
	for(int i = 0; i < n; i++){
		a[i] = read();
		a[i]--;
		cnt[a[i]]++;
		if(cnt[a[i]] <= k){
			in.push_back(i);
		}
	}
	while((int)in.size() % k != 0){
		in.pop_back();
	}
	sort(in.begin(), in.end(), [&](int i, int j) { return a[i] < a[j]; });
	std::vector<int> ans(n);
	for(int i = 0; i < (int)in.size(); i++){
		ans[in[i]] = i % k + 1;
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main() {
	int t;
	t = read();
	while(t--){
		solve();
	}
	return 0;
}
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
bool isprime(int x){
	if(x == 1)
		return false;
	else if(x == 2)
		return true;
	if(x % 2 == 0)
		return false;
	for(int i = 3; i <= x / 2; i += 2){
		if(x % i == 0)
			return false;
	}
	return true;
}
int strtoi(string tmp){
	int sum = 0;
	for(int i = 0; i < tmp.size(); i++){
		sum = sum * 10 + tmp[i] - '0';
	}
	return sum;
}
int main() {
	for(int t = read(); t; t--){
		int k;
		scanf("%d", &k);
		string s;
		cin >> s;
		bool prime[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
		bool tag = false;
		int ans = 0;
		for(int i = 0; i < k; i++){
			if(!prime[s[i] - '0']){
				tag = true;
				ans = s[i] - '0';
				break;
			}
		}
		if(tag){
			cout << "1\n";
			cout << ans << endl;
		}
		//quanshisushu
		else{
			bool flag = false;
			for(int i = 0; i < k; i++){
				for(int j = i + 1; j < k; j++){
					string tmp = "";
					tmp = tmp + s[i] + s[j];
					if(!isprime(strtoi(tmp))){
						cout << "2\n";
						cout << strtoi(tmp) << endl;
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
		}
	}
	return 0;
}
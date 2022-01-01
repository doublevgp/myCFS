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
	int t;
	for(cin >> t; t; t--){
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int sum = 0;
		for(int i = 0; i < n; i++){
			if(s1[i] != s2[i])
				sum += 2;
			else if(s1[i] == '1'){
				if(i < n - 1){
					if(s1[i + 1] != s1[i] || s2[i + 1] != s1[i])
						sum += 2, i++;
				}
			}
			else{
				if(i < n - 1){
					if(s1[i + 1] == '1' && s2[i + 1] == s1[i + 1])
						sum += 1, i++;
				}	
				sum += 1;
				// puts("f");
			}
		}
		cout << sum << endl;
	}
	return 0;
}
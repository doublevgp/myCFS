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
	for(int t = 1; t; t--){
		int n = read();
		std::vector<int> c(n + 1);
		for(int i = 1; i <= n; i++){
			c[i] = read();
		}
		if(n % 2 == 0){

		}
		else{
			
		}
	}
	return 0;
}
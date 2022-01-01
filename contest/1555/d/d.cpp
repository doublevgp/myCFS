/*
* @Author: doublevgp
* @File_name: d.cpp
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
const int N = 2e5 + 5;
char a[N],t[5];
int sum[7][N];

int main() {
	int n,q,now=0;scanf ("%d%d",&n,&q);
	scanf ("%s",a+1);t[1]='a',t[2]='b',t[3]='c';
	do{
		now++;
		for (int i=1,s=1;i<=n;i++){
			sum[now][i]=sum[now][i-1]+(t[s]!=a[i]);
			s=(s+1)%3+1;
		}
	}while (next_permutation(t+1,t+4));
	while (q--){
		int l,r;scanf ("%d%d",&l,&r);
		int ans=n;
		for (int i=1;i<=now;i++) ans=min(ans,sum[i][r]-sum[i][l-1]);
		printf ("%d\n",ans);
	}
	return 0;
}


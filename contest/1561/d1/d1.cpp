#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int f[N];
int main (){
	int n,m,sum=1;scanf ("%d%d",&n,&m);
	f[1]=1;
	for (int i=2;i<=n;i++){
		f[i]=sum;
		for (int l=2,r;l<=i;l=r+1){
			r=i/(i/l);
			f[i]=(f[i]+1ll*f[i/l]*(r-l+1))%m;
		}
		sum=(sum+f[i])%m;
	}
	printf ("%d",f[n]);
	return 0;
}
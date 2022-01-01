/*
* @Author: doublevgp
* @Date:   2021-08-26 23:28:21
* @Last Modified by:   doublevgp
* @Last Modified time: 2021-08-26 23:31:21
* @File_name: c1.cpp
*/
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
char a[N];
int main (){
	int T;scanf ("%d",&T);
	while (T--){
		int n;scanf ("%d",&n);
		scanf ("%s",a+1);bool flag=true;
		for (int i=1;i<=n;i++)
			if (a[i]=='0') flag=false;
		if (flag){
			printf ("1 %d 2 %d\n",n-1,n);
			continue;
		}
		for (int i=1;i<=n/2;i++)
			if (a[i]=='0'){
				printf ("%d %d %d %d\n",i,n,i+1,n);
				flag=true;break;
			}
		if (flag) continue;
		for (int i=n/2+1;i<=n;i++)
			if (a[i]=='0'){
				printf ("%d %d %d %d\n",1,i,1,i-1);
				flag=true;break;
			}
		if (flag) continue;
	}
    return 0;
}
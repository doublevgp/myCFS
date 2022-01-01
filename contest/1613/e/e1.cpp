#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <char> s[N];
int n,m;char a[N];
int id(int i,int j){
	return i*m+j+1;
}
vector <int> e[N];
int deg[N];
void addedge(int u,int v){
	e[u].emplace_back(v),deg[u]++;
}
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
queue <int> Q;
bool vis[N];
int main(){
	int T;scanf ("%d",&T);
	while (T--){
		scanf ("%d%d",&n,&m);
		for (int i=0;i<n;i++) s[i].resize(m);
		for (int i=0;i<n;i++){
			scanf ("%s",a);
			for (int j=0;j<m;j++) s[i][j]=a[j];
		}
		int st=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (s[i][j]!='#'){
					if (s[i][j]=='L') st=id(i,j);
					for (int k=0;k<4;k++){
						int x=i+dx[k],y=j+dy[k];
						if (x<0||y<0||x>=n||y>=m||s[x][y]=='#') continue;
						addedge(id(i,j),id(x,y));
					}
				}
		Q.push(st);
		while (!Q.empty()){
			int x=Q.front();Q.pop();
			vis[x]=true;
			for (int i=0;i<e[x].size();i++)
				if (deg[e[x][i]]<=2&&!vis[e[x][i]]) Q.push(e[x][i]);
				else deg[e[x][i]]--;
		}
		for (int i=0;i<n;i++,puts(""))
			for (int j=0;j<m;j++)
				if (s[i][j]=='.'&&vis[id(i,j)]) putchar('+');
				else putchar(s[i][j]);
		for (int i=0;i<=n*m;i++) deg[i]=0,vis[i]=false,e[i].clear();
	}
	return 0;
}
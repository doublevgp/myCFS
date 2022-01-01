/*
* @Author: doublevgp
* @File_name: f.cpp
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "no-stack-protector", "unroll-loops")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
using namespace std;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
	int f, qr;
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template <class I>
	inline void gi (I &x) {
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x<<1)+(x<<3) + (c & 15);
	}
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0');
		if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	struct Flusher_ {
		~Flusher_() {
			flush();
		}
	} io_flusher_;
}
using io :: gi;
const int N=500005;
int fa[N];
int getrt(int x){
	return fa[x]==x?x:fa[x]=getrt(fa[x]);
}
int Head[N],Next[N<<1],Adj[N<<1],tot=0;
bool ans[N],Weight[N<<1],val[N];
int deep[N],top[N],son[N],size[N],dfn[N],to[N],Time=0;
void addedge(int u,int v,bool w){
	Next[++tot]=Head[u],Head[u]=tot,Adj[tot]=v,Weight[tot]=w;
	Next[++tot]=Head[v],Head[v]=tot,Adj[tot]=u,Weight[tot]=w;
}
void dfs(int x){
	size[x]=1;
	for (int e=Head[x];e;e=Next[e])
		if (Adj[e]!=fa[x]){
			fa[Adj[e]]=x;
			deep[Adj[e]]=deep[x]+1;
			val[Adj[e]]=val[x]^Weight[e];
			dfs(Adj[e]);
			size[x]+=size[Adj[e]];
			son[x]=(size[Adj[e]]>size[son[x]]?Adj[e]:son[x]);
		}
}
void dfs2(int x,int tp){
	top[x]=tp,dfn[x]=++Time;
	if (!son[x]) return;
	dfs2(son[x],tp);
	for (int e=Head[x];e;e=Next[e])
		if (Adj[e]!=fa[x]&&Adj[e]!=son[x])
			dfs2(Adj[e],Adj[e]);
}
int LCA(int u,int v){
	for (;top[u]!=top[v];deep[top[u]]>deep[top[v]]?u=fa[top[u]]:v=fa[top[v]]);
	return deep[u]<deep[v]?u:v;
}
bool tag[N<<2],ban[N<<2];
#define mid ((l+r)>>1)
void pushdown(int root){
	if (tag[root]){
		tag[root<<1]=tag[(root<<1)|1]=1;
		ban[root<<1]=ban[(root<<1)|1]=1;
		tag[root]=0;
	}
}
bool query(int root,int l,int r,int L,int R){
	if (r<L||l>R) return 0;
	if (L<=l&&r<=R) return ban[root];
	pushdown(root);
	return query(root<<1,l,mid,L,R)||query((root<<1)|1,mid+1,r,L,R);
}
void update(int root,int l,int r,int L,int R){
	if (r<L||l>R) return;
	if (L<=l&&r<=R) {
		tag[root]=ban[root]=1;
		return;
	}
	pushdown(root);
	update(root<<1,l,mid,L,R);
	update((root<<1)|1,mid+1,r,L,R);
	ban[root]=(ban[root<<1]||ban[(root<<1)|1]);
}
#undef mid
int n,q;
void Update(int u,int v){
	while (top[u]!=top[v]){
		if (deep[top[u]]<deep[top[v]]) swap(u,v);
		update(1,1,n,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if (dfn[u]>dfn[v]) swap(u,v);
	if (u!=v) update(1,1,n,dfn[u]+1,dfn[v]);
}
bool Query(int u,int v){
	bool t=false;
	while (top[u]!=top[v]){
		if (deep[top[u]]<deep[top[v]]) swap(u,v);
		t|=query(1,1,n,dfn[top[u]],dfn[u]);
		if (t) return false;
		u=fa[top[u]];
	}
	if (dfn[u]>dfn[v]) swap(u,v);
	if (u!=v) t|=query(1,1,n,dfn[u]+1,dfn[v]);
	return (!t);
}
int u[N],v[N],w[N];
int main () {
//	freopen ("a.in","r",stdin);
	gi(n),gi(q);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=q;i++){
		gi(u[i]),gi(v[i]),gi(w[i]);
		if (getrt(u[i])!=getrt(v[i]))
			fa[getrt(u[i])]=getrt(v[i]),addedge(u[i],v[i],w[i]),ans[i]=1;
	}
	memset (fa,0,sizeof(fa));
	for (int i=1;i<=n;i++)
		if (!size[i]) dfs(i),dfs2(i,i);
	for (int i=1;i<=q;i++){
		if (ans[i]) continue;
		if (val[u[i]]^val[v[i]]^w[i]){
			if (Query(u[i],v[i])){
				Update(u[i],v[i]);
				ans[i]=true;
			}
		}
	}
	for (int i=1;i<=q;i++) puts(ans[i]?"YES":"NO");
	return 0;
}


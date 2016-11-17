#include <cstdio>
#include <cstring>

#define N 300005 
struct node {
	int col, lazy; 
} t[4*N];
int n, m, A[N],B[N],C[N];

void build(int l,int r,int p){
	if (l == r) {
		t[p].col= l;
		t[p].lazy= 0; 
		return ;
	}
	int k= l + r >> 1;
	build(l,k,p<<1);
	build(k+1,r,p<<1|1);
}

void downflag(int p){
	t[p].lazy = 0 ;
	t[p<<1].col = t[p].col ;
	t[p<<1|1].col = t[p].col;
	t[p<<1].lazy = t[p<<1|1].lazy = 1 ; 
}

void paint(int x,int y, int l,int r,int p, int col){
	if (x>y) return ;
	if (t[p].lazy && l<r) downflag(p);
	if (x<=l && r<=y){
		t[p].col = col ;
		t[p].lazy = 1 ; 
		return ; 
	}
	int k = l + r >> 1;
	if (y<=k) paint(x,y,l,k,p<<1,col) ;
	else if (x>k) paint(x,y,k+1,r,p<<1|1, col);
	else {
		paint(x,k,l,k,p<<1,col);
		paint(k+1,y,k+1,r,p<<1|1,col);
	}
}

int query(int x, int l,int r, int p){
	if (l==r) return t[p].col;
	int k = l+r >> 1;
	if (t[p].lazy) downflag(p);
	if (x<=k) return query(x,l,k,p<<1);
	return query(x,k+1,r,p<<1|1);
}

int main()
{
	scanf("%d %d",&n, &m);
	build(1,n,1);
	for (int i=1; i<=m; ++i){
		scanf("%d%d%d",A+i,B+i,C+i);
	}
	for (int i=m; i>=1; --i){
		int x=A[i],y=B[i],c=C[i];
		paint(x,c-1,1,n,1,c);
		paint(c+1, y,1,n,1,c);
	}
	for (int i=1; i<=n; ++i) {
		int ci = query(i,1,n,1);
		if (ci == i) ci = 0 ;
		if (i<n) printf("%d ",ci);
		else printf("%d\n", ci);
	}
}


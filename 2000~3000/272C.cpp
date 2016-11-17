#include <iostream>

using namespace std;

#define LL long long 
#define N 200000 

int n,m,a[N];
LL ans[N];
struct node {
	LL lazy; 
	LL max ;
}t[4*N];
inline LL max(LL a,LL b) {return a > b ? a : b;}
void build(int l,int r, int p) {
	if (l==r) {
		t[p].lazy = 0;
		t[p].max = a[l];
		return ; 
	}
	int k = l +r >> 1;
	build(l, k, p<<1);
	build(k+1, r , p<<1|1);
	t[p].max = t[p<<1].max > t[p<<1|1].max ? t[p<<1].max : t[p<<1|1].max ; 
}
void downflag(int p) {
	t[p<<1].lazy = t[p].lazy;
	t[p<<1|1].lazy = t[p].lazy ;
	t[p<<1].max = t[p].lazy ;
	t[p<<1|1].max = t[p].lazy;
	t[p].lazy = 0 ; 
}
LL query(int x,int y,int l,int r, int p){
	if (x<=l && r<=y) {
		return t[p].max ;
	}
	if (t[p].lazy) downflag(p);
	int k = l + r >> 1;
	LL ans ; 
	if (y<=k) ans=  query(x,y,l,k,p<<1);
	else if (x>k) ans= query(x,y,k+1,r,p<<1|1);
	else ans=  max(query(x,k,l,k,p<<1), query(k+1,y,k+1,r,p<<1|1));

	t[p].max = max(t[p<<1].max, t[p<<1|1].max); 
	return ans; 
}
void update(int x,int y,LL newh, int l, int r, int p){
	
	if (x<=l && r<=y) {
		t[p].lazy = newh ;
		t[p].max = newh; 
		return ; 
	}
	if (t[p].lazy) downflag(p);
	int k = l + r >> 1;
	if (y<=k) update(x,y,newh,l,k,p<<1) ;
	else if (x>k) update(x,y,newh,k+1,r,p<<1|1); 
	else {
		update(x,k,newh,l,k,p<<1);
		update(k+1,y,newh,k+1,r,p<<1|1); 
	}
	t[p].max = max(t[p<<1].max , t[p<<1|1].max) ; 
		
} 
int main()
{
	cin>>n;
	for (int i=1; i<=n; ++i) cin>>a[i];
	build(1,n,1); 
	cin>>m;
	for (int i=1; i<=m; ++i) {
		int w,h;
		cin >> w >> h ; 
		ans[i] = query(1,w,1,n,1);
		update(1,w,ans[i]+h,1,n,1); 
	}
	for (int i=1; i<=m; ++i) cout<<ans[i]<<endl;
}

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#define N 200000*4
using namespace std; 

struct node {
	int ch[26];
} t[N];

char s[300000];
int del[N];
int n,m,k; 
/*
 *   1.  1-7
 *  2. 1-4  3. 5-7
 *  1-2 3-4   5-6 7-7 
 * 1 2  3 4   5 6 7    
 */
node sum(node& a,node& b){
	node ans;
	for (int i=0; i<26; ++i) ans.ch[i] = a.ch[i] + b.ch[i];
	return ans ; 
}
void build(int l,int r,int p){
	if (l == r) {
		char c = s[(l-1)%strlen(s)];
		t[p].ch[c-'a']=1; 
		return ; 
	}
	int k = (l+r) >> 1;
	build(l,k,p<<1);
	build(k+1,r,p<<1|1);
	t[p] = sum(t[p<<1],t[p<<1|1]); 
}
int query(int x,int y,int l,int r,int p,char c){
	if (x<=l && r<=y) {
		return t[p].ch[c-'a']; 
	}
	int k = l + r >> 1,ans;
	if (y<=k) ans=query(x,y,l,k,p<<1,c);
	else if (x>k) ans= query(x,y,k+1,r,p<<1|1,c);
	else ans = query(x,k,l,k,p<<1,c) + query(k+1,y,k+1,r,p<<1|1,c);
	
	return ans ; 
}
void update(int x,int l,int r,int p,char c) {
	if (l==r){
		t[p].ch[c-'a'] = 0; 
		return ; 
	}	
	int k = l + r >> 1;
	if (x<=k) update(x,l,k,p<<1,c);
	else update(x,k+1,r,p<<1|1,c);
	
	t[p] = sum(t[p<<1],t[p<<1|1]);
}
int main(){
	scanf("%d",&k);
	scanf("%s",s);
	n = strlen(s) * k ; 
	build(1,n,1); 
	scanf("%d",&m);
	for (int i=1; i<=m; ++i){
		int p; char c; 
		getchar();
		scanf("%d%c%c",&p,&c,&c);
		int l=1, r=n, mid ;
		while (l<r){
			mid = l + r >> 1;
			if (query(1,mid,1,n,1,c)<p) l= mid+1;
			else r=mid; 
		}
		update(l,1,n,1,c); 
		del[l]=1; 
	}		
	string str=""; 
	for (int i=1; i<=n; ++i) {
		if (!del[i]) str += s[(i-1)%strlen(s)]; 	
	}	
	cout<<str<<endl;	
}

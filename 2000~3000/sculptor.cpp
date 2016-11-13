#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#define N 200000
using namespace std;
inline int min(int a,int b) {return a<b? a :b;}
inline void swap(int& a, int& b) {
	int temp =a ;
	a = b;
	b =temp;
}
struct node {
	int b,c;
	node(int _b, int _c): b(_b), c(_c) {} 
	bool operator< (const node &n2) const {
		if (b==n2.b) return c < n2.c;
		return b < n2.b ; 
	}
};
// value save the postion 
map<node , int > Map; 

int A[N],B[N],C[N]; 
int main()
{
	int n,a,b,c;
	int ans=0,l=0,r=0; 
	scanf("%d",&n); 
	for (int i=1; i<=n; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		if (a>b) swap(a,b);
		if (a>c) swap(a,c);
		A[i] = a , B[i] = b, C[i] =c ; 
		if (a > ans) {
			ans = a;
			l = i ; 
			r = -1 ;
		}
		if (b>c) swap(b,c);
		node* others= new node(b,c); 

		if (Map.find(*others) != Map.end()) {
			int pos = Map[*others];
			int a1 = A[pos] +a ; 
			if (min(a1,min(c,b)) > ans) {
				ans = min(a1,min(b,c));
				l = pos ; 
				r = i ;
			}
			if (A[pos] < a) Map[*others] = i ;
		}
		else Map[*others] = i ; 
	}
	if (r==-1) {
		cout<<1<<endl;
		cout<<l<<endl;
	} else {
		cout<<2<<endl;
		cout<<l<<" "<<r<<endl;
	}
}

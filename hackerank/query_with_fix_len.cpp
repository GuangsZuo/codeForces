#include <iostream>
#include <cstring>

#define N 200000
using namespace std;

int q[N],n,m,a[N],d;

int main(){
	cin >> n >> m ;
	for (int i=1; i<=n; ++i) {
		cin >> a[i]; 
	}
	for (int query=1; query<=m; ++query) {
		cin>>d ;
		int ans = 0x3f3f3f3f, head=1, tail=1; 
		for (int i=1; i<=n; ++i) {
			while (head<tail && q[head]<i-d+1) ++head;
			while (head<tail && a[q[tail-1]]<a[i]) --tail ;
			q[tail++] = i;
			if (i>=d) ans = ans >a[q[head]] ? a[q[head]]: ans ; 
		}
		cout<<ans<<endl;
	}
}

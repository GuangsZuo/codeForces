// if f[i] < f[j] + 1 and w[i] > w[j] 
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 800000

using namespace std;


vector<int> a[N];
int n,m,Next[N],weight[N]; 
int q[N]; 
bool vis[N]; 
int f[N];
struct node {
	int i ;
	int w ; 
	bool operator< (const node& a) const {
		return w < a.w ; 
	}
} edges[N]; 

void add_edge(int x,int y,int w,int i)
{
	a[x].push_back(i);
        Next[i] = y ;
	weight[i] = w ; 	
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; ++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w,i); 
		edges[i].i = i ; 
		edges[i].w = w ; 
	}

	sort(edges+1, edges+m+1);

	memset(f,0,sizeof(f));
       	for (int i=1;i<=m; ++i) {
		int nowedge = edges[i].i, nextP = Next[nowedge];
		for (int j=0; j<a[nextP].size(); ++j) {
			int nextedge = a[nextP][j];
			if (weight[nextedge] > weight[nowedge] && f[nextedge] < f[nowedge] + 1) {
				f[nextedge] = f[nowedge] + 1;
			}
		}
	}
	int ans = 0 ;
	for (int i=1; i<=m; ++i) {
		if (ans<f[i]) ans=f[i]; 
	}
	printf("%d\n",ans+1); 
}

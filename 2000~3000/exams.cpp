#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200000
#define M 200000
using namespace std;
struct node {
    int pos,subject; 
};
bool cmp(const node &a, const node &b) {
    return a.pos < b.pos ; 
};
int d[N],a[N];
node rec[M]; 
int n,m;

bool check(int ans){
    for (int i=1; i<=m; ++i ){
        rec[i].pos = 0 ; 
        rec[i].subject = i ; 
    }
    for (int i=1; i<=ans; ++i) {
        if (d[i] != 0) {
            if(rec[d[i]].pos < i) rec[d[i]].pos = i ;
        }
    }

    sort(rec+1,rec+m+1, cmp); 
    int rest = 0 ; 
    rec[0].pos = 0; 
    for (int i=1; i<=m; ++i) {
        if (rec[i].pos == 0) return false ;
        int sub = rec[i].subject ;
        if (a[sub] > rec[i].pos - rec[i-1].pos - 1  + rest) return false ;
        rest = rec[i].pos - rec[i-1].pos - 1 + rest - a[sub] ; 
    }
    return true ;
}
int main(){
    cin >> n >> m ;
    for (int i=1 ; i<=n; ++i) 
        scanf("%d",&d[i]);
    for (int i=1; i<=m; ++i)
        scanf("%d",&a[i]);
    int l=1 , r=n, mid ;
    while (l<r){
        mid = l + r >> 1;
        if (check(mid)) r = mid ;
        else l=mid + 1; 
    }
    if (!check(l)) cout << -1 <<endl ; 
    else cout << l << endl ;
}


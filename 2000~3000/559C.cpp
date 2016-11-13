/*9 4 5 6 7 4 
4 4 5 6 7 9 
2 6 3 4 5 1 
    6 6 6 6 
3 2 1 5 6 4 

4 3 2 5 6 4     
2 3 4 4 5 6 
3 2 1 6 4 5
3 3 3 6 6 6 

3 2 6 1 4 5
3 3 6 6 6 6 

sort must be stable 

1 4 3 2 8 4 7 
9 4 10 11 5 
找最靠右的比他小的数字的位置
1 2 3 4 5 6 
1 2 3 5 4 6 
1 2 3 5 5 6 
*/

#include <iostream>
#include <algorithm>
#define N 200000

using namespace std;

struct node {
    int x;
    int pos;
} a[N];
bool cmp(const node &i, const node&j){
    return i.x < j.x;
}

int n, Next[N];

int main() {
    cin >> n ;

    for (int i=1; i<=n; ++i) {
        cin>>a[i].x;
        a[i].pos = i; 
    }
    stable_sort(a+1, a+n+1, cmp);
    int max = 0; 
    for (int i=1; i<=n; ++i) {
        if (max < a[i].pos) {
            max = a[i].pos;
            Next[a[i].pos] = a[i].pos; 
        } 
        else Next[a[i].pos] = max ; 
    }
    int ans = 0 ; 
    for (int i=1; i<=n; ) {
         int jump = Next[i]+1; 
         for (int j=i+1; j<jump; ++j)
            if (jump < Next[j]+1) jump = Next[j]+1; 
         i = jump;  
         ++ ans ; 
    }
    cout << ans <<endl ;
}

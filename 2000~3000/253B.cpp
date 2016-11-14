#include <iostream>
#include <algorithm>
#include <fstream>
#define N 200005
using namespace std ; 

int a[N],n; 

bool check(int len) {
    for (int i=1; i<=n-len+1 ; ++i) {
        if (a[i]*2 >=  a[i+len-1]) return true ;
    }
    return false ;
}
int main()
{  
    fstream fin,fout;
    fin.open("input.txt",fstream::in);
    fout.open("output.txt",fstream::out);
    fin >> n;

    for (int i=1; i<=n; ++i) {
        fin >> a[i]; 
    }
    sort(a+1,a+n+1);
    
    int l=1, r=n, mid ;
    while (l < r - 1) {
        mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1 ; 
    }
    if (check(r)) fout<<n-r<<endl;
    else fout<<n-l<<endl; 
    fout.close();
    fin.close();
}

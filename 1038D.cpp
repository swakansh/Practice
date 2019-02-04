/* Author - linpaws07 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
ll ar[500002];
int main(){
    FAST
    int n;
    ll sum = 0;
    cin>>n;
    bool ne=0,po=0;
    rp(i,n){
        cin>>ar[i];
        if(ar[i]<0) ne=1;
        if(ar[i]>=0) po=1;
        sum += abs(ar[i]); 
    }
    if(n==1){
        cout<<ar[0]<<endl;
    }
    else if(po&&ne){
        cout<<sum<<endl;
    }
    else{
        ll mx = -inf;
        ll ls = 0, rs = sum;
        rp(i,n-1){
            ll v1 = ls+rs-abs(ar[i])-abs(ar[i+1]);
            v1+=ar[i]-ar[i+1]; 
            if(mx<v1)   mx = v1;
            v1 = ls+rs-abs(ar[i])-abs(ar[i+1]);
            v1 += ar[i+1]-ar[i];
            if(mx<v1)   mx = v1;
            ls+=abs(ar[i]);
            rs-=abs(ar[i]);
        }
        cout<<mx<<endl;
    }
    return 0;
}
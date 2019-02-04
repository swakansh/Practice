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
int ar[2][3];
int multiple(ll a,int ind){
    int o=0,n=0,e=0;
    while(a%2==0){
        a/=2;
        o++;
    }
    while(a%3==0){
        a/=3;
        n++;
    }
    while(a%5==0){
        a/=5;
        e++;
    }
    ar[ind][0]=o;
    ar[ind][1]=n;
    ar[ind][2]=e;
    return a;
}
int main(){
    FAST
    ll a,b;
    cin>>a>>b;
    int a1 = multiple(a,0);
    int a2 = multiple(b,1);
    if(a1!=a2){
        cout<<"-1"<<endl;
        return 0;
    }
    ll ans = 0;
    rp(i,3){
        ans += max(ar[0][i],ar[1][i])-min(ar[0][i],ar[1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
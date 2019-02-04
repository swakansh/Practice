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
#define MOD 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
pair<ll,ll> calculate(ll x1,ll y1,ll x2,ll y2){
    ll bl=0,wt=0;
    ll n = x2-x1+1;
    ll m = y2-y1+1;
    if((n*m)%2==0){
        bl = (n*m)/2;
        wt = bl;
        return {bl,wt};
    }
    if((x1+y1)%2){
        wt = (n*m)/2;
        bl = wt + 1;  
    }
    else{
        bl = (n*m)/2;
        wt = bl + 1;
    }
    return {bl,wt};
}
bool overlaps(ll a,ll b,ll c,ll d){
    if(c-a<0||d-b<0)    return false;
    return true;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        ll n,m,x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        int xl,yl,xr,yr;
        xl=max(x1,x3);
        yl=max(y1,y3);
        xr=min(x2,x4);
        yr=min(y2,y4);
        ll bl=0,wt=0;
        if((n*m)%2){
            bl=(n*m)/2;
            wt=bl+1;
        }
        else{
            bl=wt=(n*m)/2;
        }
        // cout<<"Orig: "<<bl<<" "<<wt<<endl;
        if(overlaps(xl,yl,xr,yr)){
            //cout<<"Overlaps"<<endl;
            pair<ll,ll> w = calculate(x1,y1,x2,y2);
            pair<ll,ll> b = calculate(x3,y3,x4,y4);
            pair<ll,ll> ov = calculate(xl,yl,xr,yr);
            w.f-=ov.f;
            w.s-=ov.s;
            b.f-=ov.f;
            b.s-=ov.s;
            // cout<<w.f<<" "<<w.s<<" "<<b.f<<" "<<b.s<<ov.f<<" "<<ov.s<<endl;
            bl-=w.f+b.f+ov.f;
            wt-=w.s+b.s+ov.s;
            // cout<<bl<<" "<<wt<<endl;
            ll no = xr-xl+1;
            ll mo = yr-yl+1;
            ll n1 = x2-x1+1;
            ll n2 = x4-x3+1;
            ll m1 = y2-y1+1;
            ll m2 = y4-y3+1;
            wt+=n1*m1-no*mo;
            bl+=n2*m2;
        }
        else{
            pair<ll,ll> w = calculate(x1,y1,x2,y2);
            pair<ll,ll> b = calculate(x3,y3,x4,y4);
            bl-=w.f+b.f;
            wt-=w.s+b.s;
            ll n1 = x2-x1+1;
            ll n2 = x4-x3+1;
            ll m1 = y2-y1+1;
            ll m2 = y4-y3+1;
            wt+=n1*m1;
            bl+=n2*m2;
        }
        cout<<wt<<" "<<bl<<endl;
    }
    return 0;
}
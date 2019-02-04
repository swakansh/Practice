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
vector<pair<ll,ll> > points;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.f<b.f||(a.f==b.f&&a.s<b.s);
}
bool cmpy(pair<ll,ll> a,pair<ll,ll> b){
    return a.s<b.s;
}
int main(){
    FAST
    int n;
    cin>>n;
    ll ans = 0;
    rp(i,n){
        ll x,y;
        cin>>x>>y;
        points.pb({x,y});
    }
    sort(points.begin(),points.end(),cmp);
    ll ct=1,sct=1;
    fr(i,1,points.size()){
        if(points[i].f==points[i-1].f){
            ct++;
        }
        else{
            ans += (ct*(ct-1))/2;
            ct=1;
        }
        if(points[i].f==points[i-1].f&&points[i].s==points[i-1].s){
            sct++;
        }
        else{
            ans -= (sct*(sct-1))/2;
            sct=1;
        }
    }
    ans += (ct*(ct-1))/2;
    ans -= (sct*(sct-1))/2;
    sort(points.begin(),points.end(),cmpy);
    ct=1;
    fr(i,1,points.size()){
        if(points[i].s==points[i-1].s){
            ct++;
        }
        else{
            ans += (ct*(ct-1))/2;
            ct=1;
        }
    }
    ans += (ct*(ct-1))/2;
    cout<<ans<<endl;
    return 0;
}
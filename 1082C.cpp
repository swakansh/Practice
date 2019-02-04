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
vector<ll> vi[100002];
vector<ll> poss(100002,0);
vector<ll> cs[100002];
int main(){
    FAST
    int n,m;
    cin>>n>>m;
    REP(i,n){
        ll a,b;
        cin>>a>>b;
        vi[a].pb(b);
    }
    FOR(i,1,m){
        sort(vi[i].rbegin(),vi[i].rend());
    }
    FOR(i,1,m){
        REP(j,vi[i].size()){
            cs[i].pb(0);
        }
    }
    FOR(i,1,m){
        REP(j,vi[i].size()){
            if(j==0){
                cs[i][0]=vi[i][0];
                if(cs[i][0]>0){
                    poss[j]+=cs[i][0];
                }
            }
            else{
                cs[i][j]=cs[i][j-1]+vi[i][j];
                if(cs[i][j]>0){
                    poss[j]+=cs[i][j];
                }
            }
        }
    }
    ll ans = 0;
    FOR(i,0,100001){
        ans = max(ans,poss[i]);
    }
    cout<<ans<<endl;
    return 0;
}
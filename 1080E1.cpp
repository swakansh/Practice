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


int n,m;
int key = 419, ind1, ind2;
ll p[600];
ll hs[600],cnt[600][600],str[600][600],b[600];
ll xmsk[600];


void power_prime(){
    p[0]=1;
    FOR(i,1,550){
        p[i] = ( p[i-1] * key ) % MOD;
    }
}


bool check(ll msk){
    return (msk==0 || (msk & (msk-1))==0);
}


ll solve(int i1,int i2){
    int sz=1;
    memset(b,0,sizeof b);
    FOR(i,i1,i2){
        b[sz] = hs[i];
        sz += 2;
    }
    sz--;
    ll c=-1,r=0,rad,dp[600]={0},res=0;
    FOR(i,1,sz){
        if(i<r)    rad = min(r-i,dp[2*c-i]);
        else    rad = 1;
        while(i-rad >= 0 && i+rad <= sz && b[i-rad] == b[i+rad])    rad++;
        dp[i]=rad;
        if(i+rad>r){
            c=i;
            r=i+rad;
        }
        res += rad/2;
    }
    return res;
}


int main(){
    FAST
    char ch;
    cin>>n>>m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin>>ch;
            str[i][j]=ch-'a';
        }
    }
    power_prime();
    ll res=0;
    FOR(i,1,m){
        FOR(k,1,n){
            hs[k]=0;
            memset(cnt[k],0,sizeof cnt[k]);
            xmsk[k]=0;
        }
        FOR(j,i,m){
            FOR(k,1,n){
                int x = str[k][j];
                if(cnt[k][x]){
                    hs[k] -= ( cnt[k][x] * p[x+1] ) % MOD;
                    if(hs[k]<0)   hs[k] += MOD;
                }
                cnt[k][x]++;
                hs[k] += ( cnt[k][x] * p[x+1] ) % MOD;
                if(hs[k]>MOD) hs[k] -= MOD;
                xmsk[k]^=(1<<x);
            }
            ind1=1;
            while(ind1<=n){
                if(!check(xmsk[ind1])){
                    ind1++;
                    continue;
                }
                ind2=ind1;
                while(ind2<=n && check(xmsk[ind2])){
                    ind2++;
                }
                ind2--;
                res += solve(ind1,ind2);
                ind1=ind2+1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
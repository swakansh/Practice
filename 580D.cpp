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
#define N (1<<19)
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
int n,m,k;
ll dp[N][20],s[20],mtx[20][20],b2[20];
int len(int mask){
    int k=0;
    while(mask){
        if(mask&1)  k++;
        mask>>=1;
    }
    return k;
}
int main(){
    FAST
    b2[0]=1;
    cin>>n>>m>>k;
    fr(i,0,n){
        cin>>s[i];
    }
    fre(i,1,19){
        b2[i]=b2[i-1]*2;
    }
    int a,b,c;
    fre(i,1,k){
        cin>>a>>b>>c;
        mtx[a-1][b-1]=c;
    }
    fr(i,0,n){
        dp[b2[i]][i]=s[i];
    }
    fre(mask,0,b2[n]){
        fr(j,0,n){
            if(mask&b2[j]){
                fr(k,0,n){
                    if((mask&b2[k])==0){
                        dp[mask|b2[k]][k]=max(dp[mask|b2[k]][k],dp[mask][j]+s[k]+mtx[j][k]);
                    }
                }
            }
        }
    }
    ll ans = -1;
    fre(mask,1,b2[n]){
        if(len(mask)==m){
            fr(i,0,n)   ans = max(ans,dp[mask][i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
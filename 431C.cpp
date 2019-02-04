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
ll solve(int n,int k){
    ll dp[102][102]={0};
    FOR(i,1,n){
        if(i<=k){
            dp[1][i]=1;
            continue;
        }
        dp[1][i]=0;
    }
    FOR(i,1,n){
        FOR(j,1,n){
            if(i>j) dp[i][j]=0;
            else{
                FOR(l,1,min(k,j-1)){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-l]) % MOD;
                }
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    ll ans = 0;
    FOR(i,1,n){
        ans = (ans + dp[i][n]) % MOD;
    }
    return ans;
}
int main(){
    int n,k,d;
    cin>>n>>k>>d;
    ll ans1 = solve(n,k);
    // cout<<ans1<<endl;
    ll ans2 = solve(n,d-1);
    // cout<<ans2<<endl;
    cout<<((ans1-ans2) % MOD + MOD) % MOD<<endl;
    return 0;
}
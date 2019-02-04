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
#define N 100002
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
ll dp[2][N];
int main(){
    FAST
    int t,k;
    cin>>t>>k;
    dp[0][0]=1;
    dp[1][0]=0;
    FOR(i,1,N-1){
        dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
        if(i-k<0){
            dp[1][i] = 0;
        }
        else{
            dp[1][i] = (dp[0][i-k] + dp[1][i-k]) % MOD;
        }
    }
    ll ans[N]={0};
    FOR(i,1,N-1){
        ans[i]= ((ans [i-1] +  dp[0][i]) % MOD + dp[1][i] ) % MOD;
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        ll  tans = (((ans[b]-ans[a-1]) % MOD) + MOD ) % MOD;
        cout<<tans<<endl;
    }
    return 0;
}
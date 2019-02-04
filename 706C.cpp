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
#include <limits.h>
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
int ar[100002];     
vector<string> str;
vector<string> rstr;
ll dp[2][100002];
int main(){
    FAST
    ll n;
    cin>>n;
    FOR(i,1,n){
        cin>>ar[i];
    }
    str.pb(" "),rstr.pb(" ");
    REP(i,n){
        string ctr;
        cin>>ctr;
        str.pb(ctr);
        reverse(ctr.begin(),ctr.end());
        rstr.pb(ctr);
    }
    dp[0][1]=0;
    dp[1][1]=ar[1];
    bool f1,f2;
    FOR(i,2,n){
        f1=0,f2=0;
        ll c1,c2;
        if(dp[0][i-1]!=-1&&str[i].compare(str[i-1])>=0){
            c1 = dp[0][i-1];f1=1;
        }
        if(dp[1][i-1]!=-1&&str[i].compare(rstr[i-1])>=0){
            if(f1)  c1=min(c1,dp[1][i-1]);
            else c1=dp[1][i-1];
            f1=1;
        }
        if(f1)  dp[0][i]=c1;
        else    dp[0][i]=-1;
        if(dp[0][i-1]!=-1&&rstr[i].compare(str[i-1])>=0){
            c2 = dp[0][i-1] + ar[i];f2=1;
        }
        if(dp[1][i-1]!=-1&&rstr[i].compare(rstr[i-1])>=0){
            if(f2)  c2=min(c2,dp[1][i-1] + ar[i]);
            else    c2=dp[1][i-1] + ar[i];
            f2=1;
        }
        if(f2)  dp[1][i]=c2;
        else    dp[1][i]=-1;
        if(!f1&&!f2)   break;
    }
    if(!f1&&!f2)   cout<<-1<<endl;
    else if(f1&!f2) cout<<dp[0][n]<<endl;
    else if(!f1&f2) cout<<dp[1][n]<<endl;
    else cout<<min(dp[0][n],dp[1][n])<<endl;
    return 0;
}
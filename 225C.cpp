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
const ll inf = (ll)1<<60;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
int n,m,x,y;
int mtx[1002][1002];
int cnt[2][1002];
ll dp[2][1002];
int main(){
    FAST
    cin>>n>>m>>x>>y;
    char ch;
    fre(i,1,n){
        fre(j,1,m){
            cin>>ch;
            mtx[i][j] = (ch=='.'?0:1);
        }
    }
    fre(i,1,m){
        int c[2]={0};
        fre(j,1,n){
            c[mtx[j][i]]++;
        }
        cnt[0][i]=c[0];
        cnt[1][i]=c[1];
    }
    fre(i,1,m){
        cnt[0][i]+=cnt[0][i-1];
        cnt[1][i]+=cnt[1][i-1];
    }
    fre(i,1,x-1){
        dp[0][i]=inf;
        dp[1][i]=inf;
    }
    fre(i,x,x){
        dp[0][i]=cnt[1][i];
        dp[1][i]=cnt[0][i];
    }
    fre(i,x+1,m){
        ll m0=inf,m1=inf;
        fre(j,x,y){
            if(i-j<0)   break;
            if(i-j>=x){
                m0 = min(m0,cnt[1][i]-cnt[1][i-j]+dp[1][i-j]);
                m1 = min(m1,cnt[0][i]-cnt[0][i-j]+dp[0][i-j]);
            }
            if(i<=y){
                m0 = min(m0,cnt[1][i]-cnt[1][i-j]+dp[0][i-j]);
                m1 = min(m1,cnt[0][i]-cnt[0][i-j]+dp[1][i-j]);
            }
        }
        dp[0][i]=m0;
        dp[1][i]=m1;
    }  
    cout<<min(dp[0][m],dp[1][m])<<endl;
    return 0;
}
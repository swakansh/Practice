//Author - linpaws07
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
pair<string,string> dp[102][902];
int main(){
    int m,s;
    cin>>m>>s;
    REP(i,102){
        string num;
        REP(j,i)    num+="0";
        dp[i][0].f=num;
        dp[i][0].s=num;
    }
    REP(i,902){
        if(i<10){
            dp[1][i].f=to_string(i);
            dp[1][i].s=to_string(i);
        }
        else{
            dp[1][i].f=dp[1][i].s="-1";
        }
    }
    dp[1][0].f='0';
    dp[1][0].s='0';
    if(s==0){
        if(m==1){
            cout<<"0 0"<<endl;
        }
        else{
            cout<<"-1 -1"<<endl;
        }
        return 0;
    }
    FOR(i,2,m){
        FOR(j,1,s){
            string mins;
            string maxs;
            REP(l,m)    mins+="9";
            REP(l,m)    maxs+="0";
            string cnum;
            bool flag=false;
            FOR(k,0,min(9,j)){
                cnum=dp[i-1][j-k].f+to_string(k);
                if(cnum[0]!='0'&&cnum[0]!='-'&&cnum.compare(mins)<0){
                    flag=true;
                    mins=cnum;
                }
                cnum=dp[i-1][j-k].s+to_string(k);
                if(cnum[0]!='0'&&cnum[0]!='-'&&cnum.compare(maxs)>0){
                    flag=true;
                    maxs=cnum;
                }
            }
            if(flag){
                dp[i][j].f=mins;
                dp[i][j].s=maxs;
            }
            else{
                dp[i][j].f="-1";
                dp[i][j].s="-1";
            }
        }
    }
    cout<<dp[m][s].f<<" "<<dp[m][s].s<<endl;
    return 0;
}
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
ll ar[100002],totsum=0;
ll lef[100002];
ll righ[100002];
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        int n;
        totsum=0;
        cin>>n;
        FOR(i,1,n){
            cin>>ar[i];
            totsum += ar[i];
        }
        lef[1]=1;
        righ[n]=1;
        ll mi=0;
        FOR(i,2,n)  lef[i]=min(lef[i-1]+1,ar[i]);
        FORD(i,n-1,1)   righ[i]=min(righ[i+1]+1,ar[i]);
        FOR(i,1,n)  mi=max(mi,min(lef[i],righ[i]));
        cout<<totsum-mi*mi<<endl;
    }
    return 0;
}
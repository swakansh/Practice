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
ll ar[100002],sum[100002];
int n;
bool check(int mid,ll k){
    int ind = lower_bound(ar,ar+n,k)-ar;
    if(mid>=ind)    return true;
    ll def = k*(ind-mid)-(sum[mid]-sum[ind]);
    if(def<=mid)    return true;
    return false;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        ll q;
        cin>>n>>q;
        REP(i,n){
            cin>>ar[i];
        }
        sort(ar,ar+n);
        sum[n-1]=ar[n-1];
        FORD(i,n-2,0){
            sum[i]=ar[i]+sum[i+1];
        }
        sum[n]=0;
        while(q--){
            ll k;
            cin>>k;
            int low=0,high=n-1,ans=-1;
            while(low<=high){
                int mid = (low + high) / 2;
                if(check(mid,k)){
                    ans = mid;
                    high = mid - 1;
                }
                else    low = mid + 1;
            }
            if(ans!=-1)
                cout<<n-ans<<endl;
            else
                cout<<0<<endl;    
        }
    }
    return 0;
}
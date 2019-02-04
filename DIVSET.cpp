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
int n,k,c;
ll ar[300002];
bool check(int mid){
    vector<vector<ll> > vi(mid);
    int ind = 0;
    FOR(i,1,n){
        if(vi[ind].size() == 0 || c*vi[ind].back() <= ar[i]){
            vi[ind].pb(ar[i]);
            ind = (ind + 1) % mid;
        }
    }
    FOR(i,0,mid-1){
        if(vi[i].size() < k)  return false; 
    }
    return true;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        cin >> n >> k >> c;
        FOR(i,1,n){
            cin >> ar[i];
        }
        sort(ar,ar+n+1);
        int low = 1,high = n, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }
            else    high = mid - 1;    
        }
        if(ans == -1){
            cout << 0 << endl;
        }
        else    cout << ans << endl;
    }
    return 0;
}
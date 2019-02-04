/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define pl pair<ll, ll>
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
int prime[1002];
void sieve(){
    rp(i, 1002){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    prime[2] = 1;
    fre(i, 2, sqrt(1001)){
        if(prime[i]){
            for(int j = i; j * i < 1001; j++){
                prime[j * i] = 0;
            }
        }
    }
}
int main(){
    FAST
    int n;
    cin >> n;
    sieve();
    set<int> ans;
    fr(i, 2, n + 1){
        if(prime[i]){
            // cout << i << " ";
            int val = i;
            while(val <= n){
                ans.insert(val);
                val *= i;
            }
        }
    }
    cout << ans.size() << endl;
    for(int a : ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
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
int main(){
    FAST
    int n;
    cin >> n;
    string str;
    cin >> str;
    ll i1 = -1, i2 = -1;
    set<char> st;
    rp(i, n){
        st.insert(str[i]);
        if(st.size() >= 2){
            i1 = i;
            break;
        }
    }
    st.clear();
    frd(i, n-1, 0){
        st.insert(str[i]);
        if(st.size() >= 2){
            i2 = i;
            break;
        }
    }
    if(str[0] == str[n-1]){
        i2 = n - i2 - 1;
        ll ans = (((i1 + 1) % mod) * ((i2 + 1) % mod)) % mod;
        cout << ans << endl; 
    }
    else{
        i2 = n - i2 - 1;
        ll ans = (((((i1 + 1) % mod) + ((i2 + 1) % mod)) % mod - 1) + mod ) % mod;
        cout << ans << endl;
    }
    return 0;
}
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
int main(){
    FAST
    int v;
    cin >> v;
    int ar[10];
    int mi = INT_MAX, dig = 0;
    fr(i, 1, 10){
        cin >> ar[i];
        if(ar[i] < mi){
            mi = ar[i];
            dig = i;
        }
        else if(ar[i] == mi){
            if(dig < i) dig = i;
        }
    }
    string ans =  "";
    rp(i, v / mi){
        ans += char(dig + 48);
    }
    int rem = v - (v / mi) * mi + mi;
    rp(i, ans.length()){
        int mx = -1;
        fr(i, 1, 10){
            if(i >= dig && rem >= ar[i]){
                mx = max(i, mx);
            }
        }
        ans[i] = char(mx + 48);
        rem = rem - ar[mx] + ar[dig];
    }
    if(ans.length() == 0)   cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}
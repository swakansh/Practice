/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 112
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
int g1[N][N], g2[N][N];
bool ga[N][N];
int n, e, h1;
int k, f, h2;
int m;
bool flow(int a, int b) {
    if(a == h1 && b != h2 || a != h1 && b == h2)    return false;
    fre(i, 1, m){
        if(!ga[a][i] && g1[a][i]){
            ga[a][i] = true;
            bool ans = flow(g1[a][i], (g2[b][i] ? g2[b][i] : b));
            if(!ans)    return ans;
        }
    }
    return true;
}
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        rp(i, N){
            rp(j, N){
                g1[i][j] = g2[i][j] = 0;
                ga[i][j] = 0;
            }
        }
        cin >> m;
        cin >> n >> e >> h1;
        rp(i, e){
            int a, b, l;
            cin >> a >> b >> l;
            g1[a][l] = b;
        }
        cin >> k >> f >> h2;
        rp(i, f){
            int a, b, l;
            cin >> a >> b >> l;
            g2[a][l] = b;
        }
        bool stat = flow(1, 1);
        if(stat)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
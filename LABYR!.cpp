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
char lx[1002][1002];
bool flag[1002][1002];
vector<pi> st;
int r, c, ans = -1;
int dfs (int i, int j) {
    if(i < 0 || i >= r || j < 0 || j >= c)  return 0;
    if(lx[i][j] == '#') return 0;
    if(flag[i][j])  return 0;
    flag[i][j] = true;
    int a[4] = {0};
    a[0] = dfs(i - 1, j);
    a[1] = dfs(i + 1, j);
    a[2] = dfs(i, j - 1);
    a[3] = dfs(i, j + 1);
    sort(a, a + 4);
    ans = max(ans, a[3] + a[2]);
    return a[3] + 1;
};      
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        ans = -1;
        st.clear();
        cin >> c >> r;
        rp(i, r){
            rp(j, c){
                cin >> lx[i][j];
                if(lx[i][j] == '.'){
                    st.pb({i, j});
                }
                flag[i][j] = false;
            }
        }
        rp(i, st.size()){
            if(!flag[st[i].f][st[i].s]){
                dfs(st[i].f, st[i].s);
            }
        }
        cout << "Maximum rope length is " << ans << "." << endl;
    }
    return 0;
}
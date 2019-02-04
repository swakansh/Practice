/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();

int mtx[302][302];
int tme[302][302];
bool visited[302][302];
int n, m;
void bfs(int x, int y, int t) {
    queue<pair<int,pii> > q;
    q.push({t, {x,y}});
    memst(visited, 0);
    visited[x][y] = 1;
    cout << "New : " << endl;
    while(!q.empty()) {
        pair<int,pii> pos = q.front();
        q.pop();
        cout << pos.s.f << " " << pos.s.s << endl;
        if(mtx[pos.s.f][pos.s.s]) {
            tme[pos.s.f][pos.s.s] = pos.f + mtx[pos.s.f][pos.s.s];
        }
        if(pos.s.s == 1 || pos.s.s == m) {
            int x = pos.s.f + 1;
            int y = pos.s.s;
            if(x < n && !visited[x][y]) {
                q.push({pos.f + 1, {x, y}});
                visited[x][y] = 1;
            }
        }
        x = pos.s.f;
        y = pos.s.s - 1;
        if(y >= 1 && !visited[x][y]) {
            q.push({pos.f + 1, {x, y}});
            visited[x][y] = 1;
        }    
        y = pos.s.s + 1;
        if(y <= m && !visited[x][y]) {
            q.push({pos.f + 1, {x, y}});
            visited[x][y] = 1;
        }
    }
}
int main(){
    FAST
    //Do awesome things here
    int t;
    cin >> t;
    while(t--){
        memst(mtx, 0);
        memst(visited, 0);
        memst(tme, 0);
        int k;
        cin >> n >> m >> k;
        vector<pii> psst;
        rp(i, k) {
            int a, b, c;
            cin >> a >> b >> c;
            mtx[a][b] = c;
            psst.pb({a, b});
        }
        vector<int> ans;
        int x = 1, y = 1, t = 0;
        while(k--){
            bfs(x, y, t);
            int omin = INT_MAX;
            rp(i, psst.size()) {
                if(mtx[psst[i].f][psst[i].s] && tme[psst[i].f][psst[i].s] < omin) {
                    x = psst[i].f;
                    y = psst[i].s;
                    omin = tme[psst[i].f][psst[i].s];
                }
            }
            cout << x << " " << y << " " << omin << endl;
            mtx[x][y] = 0;
            ans.pb(omin);
            t = omin;
        }
        cout << endl;
        rp(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
        fr(i, 1, ans.size()) {
            ans[i] += ans[i - 1];
        }
        rp(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}
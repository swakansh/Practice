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

char ch[52][52];
int n;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int vis[52][52];
void bfs(int a, int b, vector<pii> & pt){
    queue<pii> q;
    q.push({a, b});
    vis[a][b] = true;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        pt.pb(p);
        int x = p.f, y = p.s;
        rp(i, 4){
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if(x1 > 0 && x1 <= n && y1 > 0 && y1 <= n && !vis[x1][y1] && ch[x1][y1] == '0'){
                vis[x1][y1] = 1;
                q.push({x1, y1});
            }
        }
    }
}
int main(){
    FAST
    //Do awesome things here
    int64 a, b, c, d;
    cin >> n;
    cin >> a >> b >> c >> d;
    rp(i, n){
        rp(j, n){
            cin >> ch[i + 1][j + 1];
        }
    }
    vector<pii> pt1, pt2;
    bfs(a, b, pt1);
    memst(vis, 0);
    bfs(c, d, pt2);
    int64 ans = inf;
    rp(i, pt1.size()){
        rp(j, pt2.size()){
            int64 d1 = pt1[i].f - pt2[j].f;
            int64 d2 = pt1[i].s - pt2[j].s;
            ans = min(ans, d1 * d1 + d2 * d2);
        }
    }
    cout << ans << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}
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

bool grid[1012][1012]; 
bool flag[1012][1012];
int val[1012][1012];
bool paired[1012][1012];
// int checker[1002][1002];
vector<pi> points;

bool cmp(pi a, pi b){
    return (a.f < b.f) || (a.f == b.f && a.s > b.s);
}
void find_path(pi a, pi b, vector<pi> & path){
    int inc = 0;
    if(a.s < b.s) inc = 1;
    else inc = -1;
    paired[a.f][a.s] = 1;
    while(a.s != b.s){
        if(grid[a.f][a.s] == 1){
            a.f++;
            a.s -= inc;
            if(grid[a.f][a.s] == 0 && flag[a.f][a.s] == 1){
                grid[a.f][a.s] = 1;
                path.pb({a.f, a.s});
                paired[a.f][a.s] = 1;
                return;
            }
        }
        else{
            path.pb({a.f, a.s});
        }
        grid[a.f][a.s] = 1;
        a.s += inc;
        if(grid[a.f][a.s] == 0 && flag[a.f][a.s] == 1){
            grid[a.f][a.s] = 1;
            path.pb({a.f, a.s});
            paired[a.f][a.s] = 1;
            return;
        }
    }
    if(grid[a.f][a.s] == 1){
        a.f++;
        a.s -= inc;
        if(grid[a.f][a.s] == 0 && flag[a.f][a.s] == 1){
            grid[a.f][a.s] = 1;
            path.pb({a.f, a.s});
            paired[a.f][a.s] = 1;
            return;
        }
    }
    while(a.f != b.f){
        path.pb({a.f, a.s});
        grid[a.f][a.s] = 1;
        a.f += 1;
        if(grid[a.f][a.s] == 0 && flag[a.f][a.s] == 1){
            grid[a.f][a.s] = 1;
            path.pb({a.f, a.s});
            paired[a.f][a.s] = 1;
            return;
        }
    }
}
vector<pi> path;
int main(){
    FAST
    int n, m;
    cin >> n >> m;
    rp(i,  2 * m){
        int x, y;
        cin >> x >> y;
        flag[x][y] = 1;
        points.pb({x, y});
    }
    fre(i, 1, n){
        fre(j, 1, n){
            cin >> val[i][j];
        }
    }
    sort(points.begin(), points.end(), cmp);
    for(int i = 0, j = 1;i < points.size() && j < points.size();){
        find_path(points[i], points[j], path);
        // cout << points[i].f << " " << points[i].s << " to " << points[j].f << " " << points[j].s << endl;
        cout << path.size() << " ";
        rp(k, path.size()){
            cout << path[k].f << " " << path[k].s << " ";
            assert (path[k].f > 0 && path[k].s <= n);
            // checker[path[k].f][path[k].s] += 1;
            // if(path[k].f < 0 || path[k].s < 0 || path[k].f > n || path[k].s > n || checker[path[k].f][path[k].s] > 1){
            //     cout << "Failed " <<endl;
            //     return 0;
            // }
        }
        path.clear();
        cout << endl;
        while(i < points.size() && paired[points[i].f][points[i].s])    i++;
        j = i + 1;
        while(j < points.size() && paired[points[j].f][points[j].s])    j++;
    }
    return 0;
}
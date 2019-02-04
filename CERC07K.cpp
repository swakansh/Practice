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
#define mod 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
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
char ch[102][102];
ll vis[20][102][102];
int r,c,sx,sy,ox,oy,x,y;
int inc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,pair<int,int> > > q;
ll chg = 0;
ll bfs(){
    ll ans = -1;
    while(!q.empty()){
        auto var = q.front();
        q.pop();
        ox=var.s.f,oy=var.s.s;
        chg = var.f;
        if(ch[ox][oy] == 'X'){
            ans = vis[chg][ox][oy];
            break;
        }
        rp(i,4){
            x = ox + inc[i][0];
            y = oy + inc[i][1];
            if(x<0||x>=r||y<0||y>=c)    continue;
            if(ch[x][y] == '#')   continue;
            ll nchg = chg;
            char cur = ch[x][y];
            if(cur=='r')    nchg |= 1;    
            if(cur=='y')    nchg |= 2;
            if(cur=='g')    nchg |= 4;
            if(cur=='b')    nchg |= 8;
            if(vis[chg][x][y] != -1)  continue;
            if(cur=='R' && !(chg&1))    continue;
            if(cur=='G' && !(chg&4))    continue;
            if(cur=='B' && !(chg&8))    continue;
            if(cur=='Y' && !(chg&2))    continue;
            vis[nchg][x][y] = vis[chg][ox][oy] + 1;
            q.push({nchg,{x,y}});
        }
    }
    return ans;
}
int main(){
    FAST
    cin>>r>>c;
    while(r!=0&&c!=0){
        memset(vis, -1, sizeof(vis));
        rp(i,r){
            rp(j,c){
                cin>>ch[i][j];
                if(ch[i][j]=='*'){
                    sx=i,sy=j;
                    vis[0][sx][sy]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        ll ans = bfs();
        while(!q.empty())   q.pop();
        if(ans == -1){
            cout<<"The poor student is trapped!"<<endl;
        }
        else{
            cout<<"Escape possible in "<<ans<<" steps."<<endl;
        }
        cin>>r>>c;
    }
    return 0;
}
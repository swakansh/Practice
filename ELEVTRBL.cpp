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

int visited[1000002];

int main(){
    FAST
    rp(i, 1000002){
        visited[i] = -1;
    }
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<pair<int,int> > q;
    q.push({s, 0});
    while(!q.empty()){
        pair<int, int> p = q.front();
        if(p.f == g){
            cout << p.s << endl;
            return 0;
        }
        q.pop();
        if(p.f - d >= 1){
            if(visited[p.f - d] == -1){
                visited[p.f - d] = 1;
                q.push({p.f - d, p.s + 1});
            }
        }
        if(p.f + u >= 1){
            if(visited[p.f + u] == -1){
                visited[p.f + u] = 1;
                q.push({p.f + u, p.s + 1});
            }
        }
    }
    cout << "use the stairs" << endl;
    return 0;
}
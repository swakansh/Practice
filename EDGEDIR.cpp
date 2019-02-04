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
vector<pair<int,int> > adj[100002];
int off = 100002,sg;
int flag[200004]={0},degree[100002]={0},odeg[100002];
int fflag[200004];
vector<pair<int,int> > edge;
void dfs(int i,bool visited[100002]){
    visited[i]=true;
    rp(j,adj[i].size()){
        if(!visited[adj[i][j].f]){
            dfs(adj[i][j].f,visited);
        }
    }
    if(degree[i]>=2){
        if(odeg[i]%2){
            bool f=true;
            rp(j,adj[i].size()){
                if(flag[adj[i][j].s]==-1){
                    if(f){
                        f=false;
                        odeg[i]++;
                        if(adj[i][j].s>off) sg=-1;   
                        else sg=1;
                        flag[adj[i][j].s]=1;
                        flag[adj[i][j].s+sg*off]=0;
                    }
                    else{
                        odeg[adj[i][j].f]++;
                        if(adj[i][j].s>off) sg=-1;   
                        else sg=1;
                        flag[adj[i][j].s]=0;
                        flag[adj[i][j].s+sg*off]=1;
                    }
                }
            }
        }
        else{
            rp(j,adj[i].size()){
                if(flag[adj[i][j].s]==-1){
                    odeg[adj[i][j].f]++;
                    if(adj[i][j].s>off) sg=-1;   
                    else sg=1;
                    flag[adj[i][j].s]=0;
                    flag[adj[i][j].s+sg*off]=1;
                }
            }
        }
    }
}
int main(){
    FAST
    int t;
    cin>>t;
    rp(i,t){
        int n,m;
        cin>>n>>m;
        rp(i,m){
            int a,b;
            cin>>a>>b;
            adj[a].pb({b,i+1});
            adj[b].pb({a,i+1+off});
            edge.pb({a,b});
            flag[i+1]=-1;
            flag[i+1+off]=-1;
            degree[a]++;
            degree[b]++;
        }
        if(m&1){
            cout<<"-1"<<endl;
        }
        else{
            bool f=true;
            while(f){
                f=false;
                fre(i,1,n){
                    if(degree[i]==1){
                        if(odeg[i]%2){
                            rp(j,adj[i].size()){
                                if(flag[adj[i][j].s]==-1){
                                    f=true;
                                    odeg[i]++;
                                    degree[i]--;
                                    degree[adj[i][j].f]--;
                                    if(adj[i][j].s>off) sg=-1;   
                                    else sg=1;
                                    flag[adj[i][j].s]=1;
                                    flag[adj[i][j].s+sg*off]=0;
                                }
                            }
                        }
                        else{
                            rp(j,adj[i].size()){
                                if(flag[adj[i][j].s]==-1){
                                    f=true;
                                    odeg[adj[i][j].f]++;
                                    degree[i]--;
                                    degree[adj[i][j].f]--;
                                    if(adj[i][j].s>off) sg=-1;   
                                    else sg=1;
                                    flag[adj[i][j].s]=0;
                                    flag[adj[i][j].s+sg*off]=1;
                                }
                            }
                        }
                    }   
                }
            }
            bool visited[100002]={0};
            dfs(1,visited);
            fre(i,1,m){
                cout<<flag[i]<<" ";
            }
            cout<<endl;
        }
        edge.clear();
        fre(i,1,n){
            adj[i].clear();
            degree[i]=0;
            odeg[i]=0;
        }
    }
    return 0;
}
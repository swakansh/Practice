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
int n,m;
vector<int> adj[1000002];
set<int> adj_check[1000002];
vector<vector<int> > vp(1000002);
int in_degree[1000002];
bool visited[1000002];
vector<int> T;
void topological_sort(){
    queue<int> q;
    fre(i,1,n){
        if(in_degree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        T.pb(i);
        rp(j,adj[i].size()){
                if(!visited[adj[i][j]]){
                    in_degree[adj[i][j]]--;
                    if(in_degree[adj[i][j]]==0){
                        q.push(adj[i][j]);
                        visited[adj[i][j]] = true;
                    }
                }
        }
    }
}
int main(){
    FAST
    cin>>n>>m;
    rp(i,m){
        int a,b;
        cin>>a>>b;
        adj[b].pb(a);
        in_degree[a]++;
        adj_check[a].insert(b);
        adj_check[b].insert(a);
    }
    topological_sort();
    int op=0;
    for(int i=0;i<T.size();){
        vp[op].pb(T[i]);
        if(i<T.size()-1){
            if(adj_check[T[i]].find(T[i+1])==adj_check[T[i]].end()){
                vp[op].pb(T[i+1]);
                i++;    
            }
            i++;
        }
        else    i++;
        op++;
    }    
    cout<<op<<endl; 
    rp(i,op){
        cout<<vp[i].size()<<" ";
        rp(j,vp[i].size()){
            cout<<vp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
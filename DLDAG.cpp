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
vector<int> adj1[1000002];
int od[1000002];
vector<vector<int> > vp(1000002);
int mark[1000002];
int inar[1000002];
class NODE{
    public:
    int ind;
    int pri;
};
NODE ar[1000002];
class HEAP{
    public:
    int N;
    HEAP(){
        N=0;
    }
    void min_heapify(int i){
        int left  = 2*i;
        int right = 2*i+1;
        int smallest;
        if(left <= N and ar[left].pri < ar[i].pri )
            smallest = left;
        else
            smallest = i;
        if(right <= N and ar[right].pri < ar[smallest].pri )
            smallest = right;
        if(smallest != i){
            swap (ar[i], ar[smallest]);
            swap (inar[ar[i].ind], inar[ar[smallest].ind]);
            min_heapify (smallest);
        } 
    }
    void insert(NODE & v){
        N++;
        ar[N] = v;
        inar[v.ind] = N;
        int i = N;
        int parent = i/2;
        while(i!=1 && ar[parent].pri > ar[i].pri){
            swap (inar[ar[parent].ind],inar[ar[i].ind]);
            swap (ar[i],ar[parent]);
            i=i/2;
            parent=i/2;
        }
    }   
    NODE extract_min(){
        NODE dum;
        dum.ind=-1;
        dum.pri=-1;
        if(empty())    return dum;
        dum = ar[1];
        swap (inar[ar[1].ind],inar[ar[N].ind]);
        inar[ar[1].ind] = -1;
        ar[1] = ar[N];
        N--;  
        min_heapify(1);
        return dum;
    }
    void decrease_priority(int i,int val){
        if(ar[i].pri>val)   ar[i].pri=val;
        else   return;
        int parent = i/2;
        while(i!=1 && ar[parent].pri > ar[i].pri){
            swap (inar[ar[parent].ind],inar[ar[i].ind]);
            swap (ar[i],ar[parent]);
            i=i/2;
            parent=i/2;
        }
    }
    bool empty(){
        return N<1;
    }
};
HEAP obj;
void adjust(int i){
    rp(j,adj[i].size()){
        if(mark[adj[i][j]]!=-1&&od[adj[i][j]]>0){    
            od[adj[i][j]]--;
            rp(k,adj1[adj[i][j]].size()){
                if(inar[adj1[adj[i][j]][k]]>0){
                    obj.decrease_priority(inar[adj1[adj[i][j]][k]],od[adj[i][j]]);
                }
            }
            if(od[adj[i][j]]==0){
                int mi=inf;  
                rp(k,adj[adj[i][j]].size()){
                    mi=min(mi,od[adj[adj[i][j]][k]]);
                }
                NODE v;
                v.ind = adj[i][j];
                v.pri = mi;
                obj.insert(v);    
            }    
        }
    }
}
int we_get(int a,int b){
    map<ll,ll> cod;
    int ct=0;
    rp(i,adj[a].size()){
        cod[adj[a][i]]=od[adj[a][i]]-1;
        if(cod[adj[a][i]]==0)   ct++;
    }
    rp(i,adj[b].size()){
        if(cod.find(adj[b][i])!=cod.end()) cod[adj[b][i]]-=1;
        else{
            cod[adj[b][i]]=od[adj[b][i]]-1;    
        }
        if(cod[adj[b][i]]==0)   ct++;
    }
    return ct;
}
int main(){
    FAST
    cin>>n>>m;
    rp(i,m){
        int a,b;
        cin>>a>>b;
        od[a]++;
        adj[b].pb(a);
        adj1[a].pb(b);
    }
    fre(i,1,n){
        if(!od[i]){
            int mi=inf;  
            rp(j,adj[i].size()){
                mi=min(mi,od[adj[i][j]]);
            }
            NODE v;
            v.ind=i;
            v.pri=mi;
            obj.insert(v);
        }
    }
    int op=0;
    while(!obj.empty()){
        NODE ind1,ind2;
        if(obj.N==3){
            NODE i1,i2,i3;
            i1=obj.extract_min();
            i2=obj.extract_min();
            i3=obj.extract_min();
            int a1 = we_get(i1.ind,i2.ind);
            int a2 = we_get(i2.ind,i3.ind);
            int a3 = we_get(i1.ind,i3.ind);
            if(a1>=a2&&a1>=a3){
                vp[op].pb(i1.ind);
                vp[op].pb(i2.ind);
                mark[i1.ind]=-1;
                adjust(i1.ind);
                mark[i2.ind]=-1;
                adjust(i2.ind);
                op++;
                obj.insert(i3);
            }  
            else if(a2>=a1&&a2>=a3){
                vp[op].pb(i2.ind);
                vp[op].pb(i3.ind);
                mark[i2.ind]=-1;
                adjust(i2.ind);
                mark[i3.ind]=-1;
                adjust(i3.ind);
                op++;
                obj.insert(i1);
            }
            else{
                vp[op].pb(i3.ind);
                vp[op].pb(i1.ind);
                mark[i3.ind]=-1;
                adjust(i3.ind);
                mark[i1.ind]=-1;
                adjust(i1.ind);
                op++;
                obj.insert(i2);
            }
            continue;
        }
        ind1 = obj.extract_min(),ind2;
        ind2.ind=-1;
        vp[op].pb(ind1.ind);
        if(!obj.empty()){
            ind2 = obj.extract_min();
            vp[op].pb(ind2.ind);
        }
        mark[ind1.ind]=-1;
        adjust(ind1.ind);
        if(ind2.ind!=-1){
            mark[ind2.ind]=-1;
            adjust(ind2.ind);
        }
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
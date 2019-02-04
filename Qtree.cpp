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

void gi(int &x) {char ch = getchar(); x = 0; while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();}

const int N = 1e4+100;
const int LEV = 14;

// Learning HLD technique
// First problem : SPOJ QTREE

// Class for HLD operations
class HLD;

//Solver Class
class QTREESOLVER;

// Class for adjacency list of the tree
// to - other node
// cost - cost of this edge
// num - edge number
class ADJNODE{
    int to;
    int cost;
    int num;
    public:
    ADJNODE(int t, int c, int n) : to(t), cost(c), num(n){
    }
    friend class HLD;
};

// Class to store information necessary for doing HLD on a tree 
class HLDNODE{
    int depth, heavy, head, pos, cost;
    public:
    HLDNODE(){
        this->heavy = -1;
    }
    HLDNODE(int d, int h, int head, int pos, int cost){
        this->depth = d;
        this->heavy = h;
        this->head = head;
        this->pos = pos;
        this->cost = cost;
    }
    friend class HLD;
    friend class QTREESOLVER;
};

// This stores necessary info for a node with index i like depth, parent, heavy child index of this node
// and what is its position in the segment tree
vector<HLDNODE> hldinfo(N);

// This stores the adjaceny list for the tree
vector<ADJNODE> adj[N];

// The array on which segment tree is going to be built
vector<int> ar(N);

// This stores the other end in dfs order of edge number i
vector<int> other_end(N);

//Sparse table for storing parent information
//i,j entry in this table denotes 2^i parent of node j
vector<vector<int> > pa(LEV, vector<int>(N));

// Heavy light decomposition class, a Class for HLD preprocessing operations
class HLD{
    public:
    int dfs(int u, int p, int cost){
        pa[0][u] = p;
        hldinfo[u].cost = cost;
        int size = 0, mx = -1, heavy = -1;
        if(p == -1) hldinfo[u].depth = 0;
        else hldinfo[u].depth = hldinfo[p].depth + 1;
        for(ADJNODE node : adj[u]){
            int to = node.to;
            int cost = node.cost;
            int egnum = node.num;
            if(to == p) continue;
            int ssize = dfs(to, u, cost);
            if(ssize > mx){
                mx = ssize;
                heavy = to;
            }
            other_end[egnum] = to;
            size += ssize;
        }
        hldinfo[u].heavy = heavy;
        return size + 1;
    }  

    void decompose(int u, int head, int & pos){
        ar[pos] = hldinfo[u].cost;
        hldinfo[u].pos = pos;
        hldinfo[u].head = head;
        pos++;
        if(hldinfo[u].heavy != -1){
            decompose(hldinfo[u].heavy, head, pos);
        }
        for(ADJNODE node : adj[u]){
            int to = node.to;
            int cost = node.cost;
            int egnum = node.num;
            if(to == hldinfo[u].heavy || to == pa[0][u])  continue;
            decompose(to, to, pos);
        }
    }
    
    void lca_preprocess(int n){
        fr(i, 1, LEV){
            fr(j, 1, n + 1){
                if(pa[i - 1][j] != -1){
                    pa[i][j] = pa[i - 1][pa[i - 1][j]];
                }
            }
        }
    }
    
    int calculate_lca(int a, int b){
        if(hldinfo[a].depth < hldinfo[b].depth) swap(a, b);
        int diff = (hldinfo[a].depth - hldinfo[b].depth);
        rp(i, LEV){
            if((diff>>i)&1){
                a = pa[i][a];
            }
        }    
        if(a == b)  return a;
        frd(i, LEV - 1, 0){
            if(pa[i][a] != pa[i][b]){
                a = pa[i][a];
                b = pa[i][b];
            }
        }
        return pa[0][a];
    }
};

// SEGMENT TREE
class SGTREE;

// Segment tree node
// Class for describing structure of information stored at every node
class SGNODE{
    int max;
    public:
        SGNODE(){
            max = INT_MIN;
        }
        friend class SGTREE;
};

//Segment tree class
class SGTREE{
    vector<SGNODE> sgar;
    public:
    SGTREE(){
    }
    SGTREE(int size){
        sgar.resize(6 * size + 12);
    }
    void merge(SGNODE & a, SGNODE & b, SGNODE & c){
        //to merge info of two child nodes a and b into parent node c 
        c.max = (a.max > b.max ? a.max : b.max);
    }
    void shift_update(int ind){
        //to be used when lazy propagation is needed
    }
    void build_tree(int l, int r, int ind, vector<int> & ar){
        if(l == r){
            sgar[ind].max = ar[l];
            return;
        }
        int mid = (l + r) / 2;
        build_tree(l, mid, ind * 2, ar);
        build_tree(mid + 1, r, ind * 2 + 1, ar);
        merge(sgar[ind * 2], sgar[ind * 2 + 1], sgar[ind]);
    }
    int query_tree(int l, int r, int ql, int qr, int ind){
        if(ql > r || qr < l)    return INT_MIN;
        if(ql <= l && qr >= r)  return sgar[ind].max;
        int mid = (l + r) / 2;
        int lf = query_tree(l, mid, ql, qr, ind * 2);
        int rg = query_tree(mid + 1, r, ql, qr, ind * 2 + 1);
        return (lf < rg ? rg : lf);
    }
    void update_tree(int l, int r, int i, int val, int ind){
        if(i < l || i > r)  return;
        if(l == r && l == i){
            sgar[ind].max = val;
            return;
        }
        int mid = (l + r) / 2;
        update_tree(l, mid, i, val, ind * 2);
        update_tree(mid + 1, r, i, val, ind * 2 + 1);
        merge(sgar[ind * 2], sgar[ind * 2 + 1], sgar[ind]);
    }
};

//Class for current solution
class QTREESOLVER{
    public:
    void update_value(int ed, int nv, int sz, SGTREE & tree){
        int pos = hldinfo[other_end[ed]].pos;
        tree.update_tree(0, sz - 1, pos, nv, 1);
    }
    int sub_query(int a, int b, int sz, SGTREE & tree){
        if(a == b)  return 0;
        int res = INT_MIN;
        while(hldinfo[a].head != hldinfo[b].head){
            //they do not belong to same chain
            int ans = tree.query_tree(0, sz - 1, hldinfo[hldinfo[b].head].pos, hldinfo[a].pos, 1);
            if(res < ans)   res = ans;
            a = pa[0][hldinfo[a].head];
        }
        //they belong to same chain
        if(a == b)  return res;
        int ans = tree.query_tree(0, sz - 1, hldinfo[b].pos + 1, hldinfo[a].pos, 1);
        if(res < ans)   res = ans;
        return res;
    }
    int query(int a, int b, int sz, SGTREE & tree, HLD & obj){
        int lca = obj.calculate_lca(a, b);
        int a1 = sub_query(a, lca, sz, tree);
        int a2 = sub_query(b, lca, sz, tree);
        if(a1 < a2) return a2;
        else    return a1;
    }
};

int main(){
    int t;
    gi(t);
    while(t--){
        QTREESOLVER qt;
        HLD obj;
        SGTREE tree(N);
        int n;
        gi(n);

        //reset starts

        // ar.pb(-1);
        rp(i, n + 1){
            adj[i].clear();
            rp(j, LEV){
                pa[j][i] = -1;
            }
        }
        //reset ends
        
        //input for adjacency list
        rp(i, n - 1){
            int a, b, c;
            gi(a);
            gi(b);
            gi(c);
            ADJNODE n1(b, c, i + 1);
            ADJNODE n2(a, c, i + 1);
            adj[a].pb(n1);
            adj[b].pb(n2);
        }
        //adjacency list input ends

        //builds necessary information
        obj.dfs(1, -1, -1);

        int pos = 0;
        //does heavy light decomposition
        obj.decompose(1, 1, pos);

        //does preprocessing for finding lca
        obj.lca_preprocess(n);

        //builds the segment tree
        tree.build_tree(0, pos - 1, 1, ar);
        
        while(1){
            char op[100];
            scanf("%s", op);
            if(op[0] == 'D')    break;
            if(op[0] == 'C'){
                int i, ti;
                gi(i);
                gi(ti);
                qt.update_value(i, ti, pos, tree);
            }
            else{
                int a, b;
                gi(a);
                gi(b);
                cout << qt.query(a, b, pos, tree, obj) << endl;
            }
        }
    }
    return 0;
}
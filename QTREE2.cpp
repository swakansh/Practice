/* 
    Author - linpaws07 
*/ 
#include<stdio.h>
#include<vector>
using namespace std;
#define mod 1000000007
#define pb push_back
#define f first
#define s second
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)

const int N = 10100;
const int LEV = 14;

// Learning HLD technique
// Second problem : SPOJ QTREE2

// to - other node
// cost - cost of this edge
// num - edge number
int cost[N], depth[N], heavy[N], head[N], pos[N];

// This stores the adjaceny list for the tree
vector<int> adj[N], costs[N], idx[N];

// The array on which segment tree is going to be built
int ar[N];

// This stores the other end in dfs order of edge number i
int other_end[N], atidx[N];

//Sparse table for storing parent information
//i, j entry in this table denotes 2 ^ i parent of node j
int pa[LEV][N];

int dfs(int u, int p, int cst){
    pa[0][u] = p;
    cost[u] = cst;
    int size = 0, mx = -1, hvy = -1;
    if(p == -1) depth[u] = 0;
    else depth[u] = depth[p] + 1;
    rp(i, adj[u].size()){
        int to = adj[u][i];
        int cst = costs[u][i];
        int egnum = idx[u][i];
        if(to == p) continue;
        int ssize = dfs(to, u, cst);
        if(ssize > mx){
            mx = ssize;
            hvy = to;
        }
        other_end[egnum] = to;
        size += ssize;
    }
    heavy[u] = hvy;
    return size + 1;
}  

void decompose(int u, int hd, int & ps) {
    ar[ps] = cost[u];
    pos[u] = ps;
    atidx[ps] = u;
    head[u] = hd;
    ps++;
    if(heavy[u] != -1) {
        decompose(heavy[u], hd, ps);
    }
    rp(i, adj[u].size()){
        int to = adj[u][i];
        if(to == heavy[u] || to == pa[0][u])  continue;
        decompose(to, to, ps);
    }
}


int calculate_lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = (depth[a] - depth[b]);
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

int sgar[6 * N], qt[6 * N];

void build_tree(int l, int r, int ind) {
    if(l == r){
        sgar[ind] = ar[l];
        return;
    }
    int lf = (ind << 1);
    int rg = (lf | 1);
    int mid = ((l + r) >> 1);
    build_tree(l, mid, lf);
    build_tree(mid + 1, r, rg);
    sgar[ind] = sgar[lf] + sgar[rg];
}

void query_tree(int l, int r, int ql, int qr, int ind){
    if(ql > r || qr < l){    
        qt[ind] = 0;
        return;
    }
    if(ql <= l && qr >= r) {
        qt[ind] = sgar[ind];
        return;
    }
    int lf = (ind << 1);
    int rg = (lf | 1);
    int mid = ((l + r) >> 1);
    query_tree(l, mid, ql, qr, lf);
    query_tree(mid + 1, r, ql, qr, rg);
    qt[ind] = qt[lf] + qt[rg];
}

int sum_sub_query(int a, int b, int sz){
    if(a == b)  return 0;
    int res = 0;
    while(head[a] != head[b]){
        //they do not belong to same chain
        query_tree(0, sz - 1, pos[head[a]], pos[a], 1);
        res += qt[1];
        a = pa[0][head[a]];
    }
    //they belong to same chain
    if(a == b)  return res;
    query_tree(0, sz - 1, pos[b] + 1, pos[a], 1);
    res += qt[1];
    return res;
}

int sum_query(int a, int b, int sz){
    int lca = calculate_lca(a, b);
    int a1 = sum_sub_query(a, lca, sz);
    int a2 = sum_sub_query(b, lca, sz);
    return a1 + a2;    
}

int calculate_nodes(int a, int b){
    if(a == b)  return 1;
    int num = 0;
    while(head[a] != head[b]){
        //a and its lca do not belong to the same chain
        num += pos[a] - pos[head[a]] + 1;
        a = pa[0][head[a]];
    }    
    //they belong to the same chain
    if(a == b)
        return num + 1;
    return num + pos[a] - pos[b] + 1;
}

int find_kth(int a, int b, int k){
    while(head[a] != head[b]){
        int id = pos[a] - pos[head[a]] + 1;
        if(id >= k){
            //answer lies in this chain only
            return atidx[pos[a] - (k - 1)];
        }
        k -= id;
        a = pa[0][head[a]];
    }
    //they belong to same chain
    return atidx[pos[a] - (k - 1)];
}

int kth_node(int a, int b, int k){
    int lca = calculate_lca(a, b);
    int n1 = calculate_nodes(a, lca);
    int n2 = calculate_nodes(b, lca);
    if(k <= n1){
        //answer is on the path from a to lca
        //find kth node from a to lca
        return find_kth(a, lca, k);
    }
    else{
        //answer is on the path from next(lca) to b
        k -= n1;
        k = n2 - k;
        //find kth node from b to lca
        return find_kth(b, lca, k);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);    
        
        //reset starts
        rp(i, n + 1) {
            adj[i].clear();
            idx[i].clear();
            costs[i].clear();
            heavy[i] = -1;
            rp(j, LEV){
                pa[j][i] = -1;
            }
        }
        //reset ends
        
        //input for adjacency list
        fr(i, 1, n){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].pb(b);
            costs[a].pb(c);
            idx[a].pb(i);
            adj[b].pb(a);
            costs[b].pb(c);
            idx[b].pb(i);
        }
        //adjacency list input ends

        //builds necessary information
        dfs(1, -1, 0);
        int ps = 0;

        //does heavy light decomposition
        decompose(1, 1, ps);
        
        //builds the segment tree
        build_tree(0, ps - 1, 1);
        
        fr(i, 1, LEV){
            fr(j, 1, n + 1){
                if(pa[i - 1][j] != -1){
                    pa[i][j] = pa[i - 1][pa[i - 1][j]];
                }
            }
        }
        while(1){
            char op[100];
            scanf("%s", op);
            if(op[1] == 'O')    break;
            int a, b, k;
            scanf("%d %d", &a, &b);
            if(op[0] == 'D'){
                printf("%d\n", sum_query(a, b, ps));
            }
            else{
                scanf("%d", &k);
                printf("%d\n", kth_node(a, b, k));
            }
        }
    }
    return 0;
}
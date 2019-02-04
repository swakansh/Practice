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

int n;

struct node{
    string label;
    int pri;
    int ind;
    node(){

    }
    node(string l, int p){
        label = l;
        pri = p;
        ind = -1;
    }
};

struct tree_node{
    node data;
    tree_node * left;
    tree_node * right;
    tree_node(){
        left = NULL;
        right = NULL;
    }
    tree_node(node & d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node ar[50002];
node sg[4 * 50002];
node dum("", -inf);

void build(int l, int r, int ind, node * ar){
    if(l == r){
        sg[ind] = ar[l];
        sg[ind].ind = l;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2, ar);
    build(mid + 1, r, ind * 2 + 1, ar);
    if(sg[ind * 2].pri > sg[ind * 2 + 1].pri)
        sg[ind] = sg[ind * 2];
    else
        sg[ind] = sg[ind * 2 + 1];
}

node query(int l, int r, int ql, int qr, int ind){
    if(qr < l || ql > r)
        return dum;
    if(ql <= l && qr >= r)
        return sg[ind];
    node lf = query(l, (l + r) / 2, ql, qr, ind * 2);
    node rg = query((l + r) / 2 + 1, r, ql, qr, ind * 2 + 1);
    if(lf.pri > rg.pri) return lf;
    return rg;
}

tree_node * build_tree(int l, int r){
    if(l > r)   return NULL;
    node cur = query(0, n-1, l, r, 1);
    tree_node * root = new tree_node(cur);
    root -> left = build_tree(l, cur.ind - 1);
    root -> right = build_tree(cur.ind + 1, r);
    return root;
}

void traverse_tree(tree_node * root){
    if(!root)   return;
    cout << "(";
    traverse_tree(root -> left);
    cout << (root -> data).label << "/" << (root -> data).pri;
    traverse_tree(root -> right);
    cout << ")";
}

bool cmp(node a, node b){
    return a.label < b.label;
}

int main(){
    FAST
    cin >> n;
    while(n > 0){
        rp(i, n){
            string str;
            cin >> str;
            int ind = str.find('/');
            ar[i].label = str.substr(0,ind);
            ar[i].pri = stoi(str.substr(ind + 1));
        }
        sort(ar, ar + n, cmp);
        build(0, n - 1, 1, ar);
        tree_node * root;
        root = build_tree(0, n-1);
        traverse_tree(root);
        cout << endl;
        cin >> n;
    }
    return 0;
}
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
#define MAIN_N 1000000000
#define N 600012
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
const ll inf = (ll)1<<34;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

ll q,k,calls=0;
int st=200003,et=200002;
pair<ll,ll> ar[600012];

struct NODE{
    ll low,high;
    ll ans,sum,pref,suf;
    NODE *l,*r;
    bool val;
    NODE(){
        l=r=NULL;
        low=inf;
        high=-inf;
        pref=suf=-inf;
        sum=ans=0;
        val=false;
    }
    NODE(NODE * cp){
        low=cp->low;
        high=cp->high;
        pref=cp->pref;
        suf=cp->suf;
        sum=cp->sum;
        ans=cp->ans;
        val=cp->val;
    }
};
//Dynamic Segment Tree
struct MAIN_NODE{
    MAIN_NODE *l,*r;
    NODE * subr;
    MAIN_NODE(){
        l = r = NULL;
        subr = new NODE();
    }
};

void print(NODE * fa){
    cout<<fa->ans<<" "<<fa->sum<<" "<<fa->low<<" "<<fa->high<<" "<<fa->pref<<" "<<fa->suf<<" val: "<<fa->val<<endl;
}
void merge_nodes(NODE * to, NODE * fa,NODE * fb){
    to->low = min(fa->low,fb->low);
    to->high = max(fa->high,fb->high);

    if(fa->val&&fb->val){
        to->pref = max(fa->sum,max(fa->pref,fa->sum+fb->pref));
        to->suf = max(fb->sum,max(fb->suf,fb->sum+fa->suf));
        to->sum = fa->sum + fb->sum;
        to->ans = max(max(fa->ans,fb->ans),fa->suf+fb->pref);
        to->val=true;
    }
    else if(fa->val){
        to->pref = max(fa->sum,fa->pref);
        to->suf = max(fa->suf,fa->sum);
        to->sum = fa->sum;
        to->ans = fa->ans;
        to->val=true;
    }
    else if(fb->val){
        to->pref = max(fb->sum,fb->pref);
        to->suf = max(fb->suf,fb->sum);
        to->sum = fb->sum;
        to->ans = fb->ans;
        to->val=true;
    }
}
void merge_sub_tree(NODE * a, NODE * b){
    calls++;
    if(b==NULL) return;
    if(a==NULL) return;
    if(b->l&&!(a->l)){
        a->l=new NODE(b->l);
    }
    else
        a->l=new NODE();
    if(b->r&&!(a->r)){
        a->r=new NODE(b->r);
    }
    else    
        a->r=new NODE();
    merge_sub_tree(a->l,b->l);
    merge_sub_tree(a->r,b->r);
    // cout<<"b: "<<endl;
    // print(b);
    // print(a->l);
    // print(a->r);
    // cout<<"a: "<<endl;
    // print(a);
    merge_nodes(a,a->l,a->r); 
}

void add_node(NODE * v, ll l, ll r,ll q_l, ll q_r, ll c_v, int val){
    if (l>r||q_r<l||q_l>r){
        return;
    }
    
    if(l==r){
        v->low = v->high = c_v;
        v->ans = v->pref = v->suf = v->sum = val;
        v->val = true;
        return;
    }

    ll mid = (l+r)>>1;
    if (v->l == NULL)
        v->l = new NODE();
    if (v->r == NULL)
        v->r = new NODE();

    add_node(v->l, l, mid, q_l, q_r, c_v, val);
    add_node(v->r, mid+1, r, q_l, q_r, c_v, val);
    
    merge_nodes(v,v->l,v->r);
}

void main_add_node(MAIN_NODE * v, ll l, ll r,ll q_l, ll q_r, int val,int d){
    //cout<<l<<" "<<r<<endl;
    if (l>r||q_r<l||q_l>r)
        return;
    add_node(v->subr,0,N,val,val,q_l,d);
    if(l==r)    return;
    ll mid = (l+r)>>1;
    if (v->l == NULL)
        v->l = new MAIN_NODE();
    if (v->r == NULL)
        v->r = new MAIN_NODE();
    main_add_node(v->l, l, mid, q_l, q_r, val, d);
    main_add_node(v->r, mid+1, r, q_l, q_r, val, d);
}


void main_query_tree(MAIN_NODE * v,ll l,ll r,ll x,ll y,NODE * nr){
    if(v==NULL || x>y || x>r || y<l){
        return;
    }
    if(x<=l && r<=y){
        merge_sub_tree(nr,v->subr);
        return;
    }

    ll mid = (l + r) >> 1;
    main_query_tree(v->l,l,mid,x,y,nr);
    main_query_tree(v->r,mid+1,r,x,y,nr);
}


NODE * query_tree(NODE * v,ll l,ll r,ll x,ll y){
    if(v==NULL || x>y || x>v->high || y<v->low){    
        NODE * dum = new NODE;
        return dum;
    }
    if(x<=v->low && v->high<=y){
        return v;
    }
    
    ll mid = (l + r) >> 1;
    NODE * lf = query_tree(v->l,l,mid,x,y);
    NODE * rg = query_tree(v->r,mid+1,r,x,y);
    NODE * ans = new NODE;

    merge_nodes(ans,lf,rg);
    return ans;
}

int main(){
    FAST
    cin>>q>>k;
    ll C=0;
    MAIN_NODE * root = new MAIN_NODE;
    rp(i,q){
        ll t,c,d;
        cin>>t;
        if(t==1){
            cin>>c>>d;
            c=(c^C);
            // cout<<1<<" "<<c<<" "<<d<<endl;
            ar[--st].f=c;
            ar[st].s=d;
            main_add_node(root,0,MAIN_N,c,c,st,d);
            // cout<<"r: "<<root->ans<<endl;
        }
        else if(t==2){
            cin>>c>>d;
            c=(c^C);
            // cout<<2<<" "<<c<<" "<<d<<endl;
            ar[++et].f=c;
            ar[et].s=d;
            main_add_node(root,0,MAIN_N,c,c,et,d);
        }
        else{
            ll cb;
            cin>>cb;
            cb=(C^cb);
            // cout<<3<<" "<<cb<<endl;
            NODE * nr = new NODE();    
            calls=0;
            main_query_tree(root,0,MAIN_N,max((ll)1,cb-k),min((ll)MAIN_N,cb+k),nr);    
            ll qans = max((ll)0,nr->ans);
            // cout<<"Calls: "<<calls<<endl;
            delete nr;
            cout<<qans<<endl;
            //cout<<0<<endl;
            C=qans;
        }
    }
    delete root;
    return 0;
}
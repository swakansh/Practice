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

ll q,k;
int mn=0;
ll osum=0;
int st=200003,et=200002;
bool neg=false;
pair<ll,ll> ar[400012];

struct NODE{
    ll low,high;
    ll ans,sum,pref,suf;
    bool val;
    NODE *l,*r;
    NODE(){
        l=r=NULL;
        low=inf;
        high=-inf;
        pref=suf=-inf;
        sum=ans=0;
        val=false;
    }
};

NODE * seg_tree[702]={0};

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
    
    v->low = min(v->l->low,v->r->low);
    v->high = max(v->l->high,v->r->high);

    if(v->l->val&&v->r->val){
        v->pref = max(v->l->sum,max(v->l->pref,v->l->sum+v->r->pref));
        v->suf = max(v->r->sum,max(v->r->suf,v->r->sum+v->l->suf));
        v->sum = v->l->sum + v->r->sum;
        v->ans = max(max(v->l->ans,v->r->ans),v->l->suf+v->r->pref);
        v->val=true;
    }
    else if(v->l->val){
        v->pref = max(v->l->sum,v->l->pref);
        v->suf = max(v->l->suf,v->l->sum);
        v->sum = v->l->sum;
        v->ans = v->l->ans;
        v->val=true;
    }
    else if(v->r->val){
        v->pref = max(v->r->sum,v->r->pref);
        v->suf = max(v->r->suf,v->r->sum);
        v->sum = v->r->sum;
        v->ans = v->r->ans;
        v->val=true;
    }
}

void add_node(NODE * v, ll l, ll r,ll q_l, ll q_r, NODE & cust){
    if (l>r||q_r<l||q_l>r){
        return;
    }
    
    if(l==r){
        v->low = cust.low;
        v->high = cust.high;
        v->ans = cust.ans;
        v->pref = cust.pref;
        v->suf = cust.suf;
        v->sum = cust.sum;
        v->val = cust.val;
        return;
    }

    ll mid = (l+r)>>1;
    if (v->l == NULL)
        v->l = new NODE();
    if (v->r == NULL)
        v->r = new NODE();

    add_node(v->l, l, mid, q_l, q_r, cust);
    add_node(v->r, mid+1, r, q_l, q_r, cust);
    
    v->low = min(v->l->low,v->r->low);
    v->high = max(v->l->high,v->r->high);

    if(v->l->val&&v->r->val){
        v->pref = max(v->l->sum,max(v->l->pref,v->l->sum+v->r->pref));
        v->suf = max(v->r->sum,max(v->r->suf,v->r->sum+v->l->suf));
        v->sum = v->l->sum + v->r->sum;
        v->ans = max(max(v->l->ans,v->r->ans),v->l->suf+v->r->pref);
        v->val=true;
    }
    else if(v->l->val){
        v->pref = max(v->l->sum,v->l->pref);
        v->suf = max(v->l->suf,v->l->sum);
        v->sum = v->l->sum;
        v->ans = v->l->ans;
        v->val=true;
    }
    else if(v->r->val){
        v->pref = max(v->r->sum,v->r->pref);
        v->suf = max(v->r->suf,v->r->sum);
        v->sum = v->r->sum;
        v->ans = v->r->ans;
        v->val=true;
    }
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

    ans->low = min(lf->low,rg->low);
    ans->high = max(lf->high,rg->high);
    
    if(lf->val&&rg->val){
        ans->pref = max(lf->sum,max(lf->pref,lf->sum+rg->pref));
        ans->suf = max(rg->sum,max(rg->suf,rg->sum+lf->suf));
        ans->sum = lf->sum + rg->sum;
        ans->ans = max(max(lf->ans,rg->ans),lf->suf+rg->pref);
        ans->val=true;
    }
    else if(lf->val){
        ans->pref = max(lf->sum,lf->pref);
        ans->suf = max(lf->suf,lf->sum);
        ans->sum = lf->sum;
        ans->ans = lf->ans;
        ans->val=true;
    }
    else if(rg->val){
        ans->pref = max(rg->sum,rg->pref);
        ans->suf = max(rg->suf,rg->sum);
        ans->sum = rg->sum;
        ans->ans = rg->ans;
        ans->val=true;
    }
    return ans;
}

int main(){
    FAST
    cin>>q>>k;
    ll C=0;
    rp(i,700){
        seg_tree[i] = new NODE();
    }
    rp(i,q){
        ll t,c,d;
        cin>>t;
        if(t==1){
            cin>>c>>d;
            c=(c^C);
            // cout<<1<<" "<<c<<" "<<d<<endl;
            ar[--st].f=c;
            ar[st].s=d;
            if(d<0) neg=true;
            int block = st/700;
            add_node(seg_tree[block],0,700,st%700,st%700,c,d);
            // cout<<"r: "<<root->ans<<endl;
        }
        else if(t==2){
            cin>>c>>d;
            c=(c^C);
            // cout<<2<<" "<<c<<" "<<d<<endl;
            ar[++et].f=c;
            ar[et].s=d;
            if(d<0) neg=true;
            int block = et/450;
            add_node(seg_tree[block],0,700,et%700,et%700,c,d);
        }
        else{
            ll cb;
            cin>>cb;
            cb=(C^cb);
            // cout<<3<<" "<<cb<<endl;
            osum = 0;
            NODE seg_ar[700];
            NODE * root = new NODE;
            rp(i,700){
                seg_ar[i] = *(query_tree(seg_tree[i],0,700,max((ll)1,cb-k),min((ll)MAIN_N,cb+k)));
                add_node(root,0,700,i,i,seg_ar[i]);
            }
            ll qans = max(root->ans,(ll)0);
            cout<<qans<<endl;
            // cout<<0<<endl;
            C=qans;
        }
    }
    return 0;
}
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
int index[1000002];
class NODE{
    public:
    int ind;
    int pri;
};
NODE ar[1000002];
class HEAP{
    int N;
    public:
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
            swap (index[ar[i].ind], index[ar[smallest].ind]);
            min_heapify (smallest);
        } 
    }
    void insert(NODE & v){
        N++;
        ar[N] = v;
        index[v.ind] = N;
        int i = N;
        int parent = i/2;
        while(i!=1 && ar[parent].pri > ar[i].pri){
            swap (index[ar[parent].ind],index[ar[i].ind]);
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
        swap (index[ar[1].ind],index[ar[N].ind]);
        index[ar[1].ind] = -1;
        ar[1] = ar[N];
        N--;  
        min_heapify(1);
        return dum;
    }
    void decrease_priority(int i){
        int ind = index[i];
        ar[ind].pri--;
        int parent = i/2;
        while(i!=1 && ar[parent].pri > ar[i].pri){
            swap (index[ar[parent].ind],index[ar[i].ind]);
            swap (ar[i],ar[parent]);
            i=i/2;
        }
    }
    bool empty(){
        return N<1;
    }
};
int main(){
    FAST
    HEAP obj;
    NODE a,b,c,d;
    a.ind=1,a.pri=2;
    b.ind=2,b.pri=1;
    c.ind=3,c.pri=4;
    d.ind=4,d.pri=0;
    obj.insert(a);
    cout<<"Ins"<<endl;
    obj.insert(b);
    cout<<"Ins"<<endl;
    obj.insert(c);
    cout<<"Ins"<<endl;
    obj.insert(d);
    cout<<"Ins"<<endl;
    while(!obj.empty()){
        cout<<"Hey"<<endl;
        NODE e = obj.extract_min();
        cout<<e.ind<<" "<<e.pri<<endl;
    }
    return 0;
}
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
#define sz 5
void print(int mtx[sz][sz]){
    rp(i, sz){
        rp(j, sz){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
}
void doit(int mtx[sz][sz]){
    srand(time(0) * rand());
    int t = 1000;
    while(t){
        int rm = rand() % sz;
        // cout << rm << " ";
        int temp[sz];
        rp(k, sz){
            temp[k] = mtx[rm][k];
        }
        rp(k, sz){
            mtx[rm][k] = mtx[k][rm];
        }
        rp(k, sz){
            mtx[k][rm] = temp[k];
        }
        t--;
        // print();
    }
}
int main(){
    FAST
    srand(time(0));
    int t = 2000;
    while(t--) {
        int a[sz][sz] = {{1,1,2,2,3},{4,6,7,7,8},{1,2,3,3,3},{2,2,2,4,4},{4,5,6,6,6}};
        int b[sz][sz] = {{1,1,2,2,3},{4,6,7,7,8},{1,2,3,3,3},{2,2,2,4,4},{4,5,6,6,6}};
        doit(a);
        // doit(b);
        rp(i, sz){
            rp(j, sz){
                if(b[i][j] != a[i][j]){
                    swap(b[i][j], b[j][i]);
                }
            }
        }
        bool fl = true;
        rp(i, sz){
            rp(j, sz){
                if(a[i][j] != b[i][j]){
                    fl = false;
                }
            }
        }
        if(!fl){
            cout << "NO" << endl;
            print(a);
            cout << endl;
            print(b);
            break;
        }
    }
    return 0;
}
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
int a[1026][1026], b[1026][1026];
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rp(i, n){
            rp(j, n){
                cin >> a[i][j];
            }
        }
        rp(i, n){
            rp(j, n){
                cin >> b[i][j];
            }
        }
        bool flag = true;
        rp(i, n){
            rp(j, n){
                if(a[i][j] != b[i][j]){
                    if(a[i][j] == b[j][i]){
                        rp(k, n){
                            swap(a[j][k], a[k][j]);
                        }
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag)   break;
        }
        rp(i, n){
            rp(j, n){
                if(a[i][j] != b[i][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        if(!flag){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
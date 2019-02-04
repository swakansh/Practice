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
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n >= 3 && m >= 3){
            cout << 4 << endl;
            int ar[2][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}}, flip = 0;
            rp(i, n){
                rp(j, m){
                    cout << ar[flip][j % 4] << " ";
                }
                cout << endl;
                if(i % 2)   flip = 1 - flip;
            }
        }
        else if( n == 2 || m == 2){
            if(n == 2){
                if(m < 3)
                    cout << (m - 1) % 3 + 1 << endl;
                else
                    cout << 3 << endl;
                int ar[3] = {1, 2, 3};
                rp(i, n){
                    rp(j, m){
                        cout << ar[j % 3] << " ";
                    }
                    cout << endl;
                }
            }
            else if(m == 2){
                if(n < 3)
                    cout << (n - 1) % 3 + 1 << endl;
                else
                    cout << 3 << endl;
                rp(i, n){
                    rp(j, m){
                        cout << (i % 3 + 1) << " ";
                    }
                    cout << endl;
                }
            }
        }
        else{
            if(n == 1){
                if(m < 3)
                    cout << 1 << endl;
                else
                    cout << 2 << endl;
            }
            else{
                if(n < 3)
                    cout << 1 << endl;
                else    
                    cout << 2 << endl;
            }
            int val = 0, cnt = 0;
            rp(i, n){
                rp(j, m){
                    cout << val + 1 << " ";
                    cnt ++;
                    if(cnt == 2){
                        cnt = 0;
                        val = 1 - val;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
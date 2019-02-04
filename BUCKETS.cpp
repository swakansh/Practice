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
int m[1002][1002];
int main(){
    FAST
    int n, k;
    cin >> n >> k;
    rp(i, n){
        rp(j, k){
            cin >> m[i][j];
        }
    }
    fr(i, 0, n){
        int sum = 0;
        fre(j, 1, k){
            sum += m[i][j - 1];
        }
        m[i][k] = sum;
    }
    double ans[1002];
    fr(i, 0, k){
        ll num = 1, den = 1;
        double prob;
        fr(j, 0, n){
            if(j == 0){
                prob = (double)m[j][i] / m[j][k]; 
            }
            else{
                double prob1 = (double)(m[j][i] + 1) / (m[j][k] + 1);
                double prob2 = (double)(m[j][i]) / (m[j][k] + 1);
                prob = prob2 + prob * ((double)1 / (m[j][k] + 1));           
            }
        }
        ans[i] = prob;
    }
    rp(i, k){
        cout << fixed << setprecision(6) << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
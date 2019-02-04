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
#define kiki 5
ll a, b, c;
ll md(ll v){
    return (v % mod + mod) % mod;
}
void multiply(ll a[kiki][kiki], ll b[kiki][kiki]) { 
	ll mul[kiki][kiki]; 
	for (int i = 0; i < kiki; i++) { 
		for (int j = 0; j < kiki; j++) { 
			mul[i][j] = 0; 
			for (int k = 0; k < kiki; k++) 
				mul[i][j] = md(mul[i][j] + md(a[i][k]*b[k][j])); 
		} 
	} 
    for (int i = 0; i < kiki; i++) 
		for (int j = 0; j < kiki; j++) 
			a[i][j] = mul[i][j];
} 
ll power(ll F[kiki][kiki], int n) { 
	ll M[kiki][kiki] = {{1, 0, 3, 2, 2},{1, 0, 0, 0, 0},{0, 1, 0, 0, 0},{0, 0, 0, 1, 1},{0, 0, 0, 0, 1}}; 
    if (n==1) 
		return a * F[0][0] + b * F[0][1] + c * F[0][2] + 2 * F[0][3] + F[0][4]; 
	power(F, n/2); 
	multiply(F, F); 
	if (n%2 != 0) 
		multiply(F, M); 
    return a * F[0][0] + b * F[0][1] + c * F[0][2] + 2 * F[0][3] + F[0][4]; 
} 

ll findNthTerm(ll n) { 
	ll F[kiki][kiki] = {{1, 0, 3, 2, 2},{1, 0, 0, 0, 0},{0, 1, 0, 0, 0},{0, 0, 0, 1, 1},{0, 0, 0, 0, 1}}; 
	return power(F, n-2); 
} 

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> a >> b >> c >> n;
        cout << findNthTerm(n) << endl;
    }
    return 0;
}
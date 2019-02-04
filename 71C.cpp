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

void prime_divisors(int n, set<int> & pd){
    int nc = n;
    fre(i, 2, sqrt(nc)){
        while(n % i == 0){
            n /= i;
            pd.insert(i);
        }
    }
    if(n != 1)
        pd.insert(n);
}

int ar[100002];
int n;

bool check(int a){
    for(int i = 0; i < n / a; i++){
        int ct = 0;
        for(int j = i; j < n ; j += n / a){
            if(ar[j] == 1)  ct++;  
        }
        if(ct == a){
            return true;
        }
    }
    return false;
}

int main(){
    FAST
    cin >> n;
    rp(i, n){
        cin >> ar[i];
    }
    set<int> pd;
    prime_divisors(n, pd);
    for(int a: pd){
        // cout << a << endl;
        if(check((a == 2 ? 4 : a))){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
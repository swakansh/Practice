/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();

int a[1002], ind = 1000;
int m[22][22];
int getnext(){
    while(ind > 0){
        // cout << ind << endl;
        if(a[ind] >= 4){
            a[ind] -= 4;
            return ind;
        }
        ind--;
    }
    cout << "NO" << endl;
    return -1;
}
int getnext_e(){
    while(ind > 0){
        if(a[ind] >= 2){
            a[ind] -= 2;
            return ind;
        }
        ind--;
    }
    cout << "NO" << endl;
    return -1;
}
int main(){
    FAST
    //Do awesome things here
    int n;
    cin >> n;
    rp(i, n * n){
        int b;
        cin >> b;
        a[b]++;
    }
    rp(i, n / 2){
        rp(j, n / 2){
            int v = getnext();
            if(v == -1) return 0;
            m[i][j] = v;
        }
    }
    // cout << "1" << endl;
    rp(i, n / 2){
        rp(j, n / 2){
            m[i][n - j - 1] = m[i][j];
            m[n - i - 1][j] = m[i][j];
            m[n - i - 1][n - j - 1] = m[i][j];
        }
    }
    // cout << "2" << endl;
    if(n & 1){
        ind = 1000;
        rp(i, n / 2){
            int v = getnext_e();
            if(v == -1) return 0;
            m[n / 2][i] = m[n / 2][n - i - 1] = v;
        }
        ind = 1000;
        rp(i, n / 2){
            int v = getnext_e();
            if(v == -1) return 0;
            m[i][n / 2] = m[n - i - 1][n / 2] = v;
        }
        rp(i, 1001){
            if(a[i] % 2){
                m[n / 2][n / 2] = i;
                a[i]--;
                break;
            }
        }
    }
    // cout << "3" << endl;
    rp(i, n){
        rp(j, n){
            if(a[m[i][j]] != 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    rp(i, n){
        rp(j, n){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}
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
typedef long int ii;
typedef unsigned long int uii;
typedef long long int ll;
typedef unsigned long long int ull;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline void check(ll & a){ a %= mod; if(a < 0) a += mod; }
auto start = high_resolution_clock::now();
inline void measure();

int ar[27];
char ch[102][102];
int main(){
    FAST
    //Do awesome things here
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n;
    cin >> n;
    rp(i, 102){
        rp(j, 102){
            ch[i][j] = '.';
        }
    }
    rp(i, n){
        cin >> ar[i];
    }
    int sr, sc, dir, k = 0, f, g;
    if(b > d){
        if(d & 1){
            dir = -1;
            sr = 0, sc = a + c - 1;
        }
        else{
            dir = 1;
            sr = 0, sc = 0;
        }
        f = 0;
        g = a - 1;
    }
    else if(d >= b){
        if(b & 1){
            dir = 1;
            sr = 0, sc = 0;
        }
        else{
            dir = -1;
            sr = 0, sc = a + c - 1;
        }
        f = a;
        g = a + c - 1;
    }
    int e = min(b, d);
    while(true){
        if(k < n && ar[k]){    
            // cout << sr << " " << sc << endl;    
            ch[sr][sc] = k + 'a';
            ar[k]--;
        }
        if(ar[k] == 0)  k++;
        if(k >= n)   break;
        //position adjustment
        if(sr < e && (dir == -1 && sc == 0 || dir == 1 && sc == a + c - 1)){
            sr++;
            if(dir == -1)   dir = 1;
            else    dir = -1;
        }
        else if(sr < e && ((dir == 1 && sc >= 0 && sc < a + c - 1) || ((dir == -1 && sc > 0 && sc <= a + c - 1)))){
            sc = sc + dir;
        }
        else if(sr >= e && (dir == -1 && sc == f || dir == 1 && sc == g)){
            sr++;
            if(dir == -1)   dir = 1;
            else    dir = -1;
        }
        else if(sr >= e && ((dir == 1 && sc >= f && sc < g) || ((dir == -1 && sc > f && sc <= g)))){
            sc = sc + dir;
        } 
    }
    cout << "YES" << endl;
    rp(i, max(b, d)){
        rp(j, a + c){
            cout << ch[i][j];
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
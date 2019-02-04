/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
auto start = high_resolution_clock::now();
inline void measure();

int64 mod = 1;
char ch[1002][1002];
int64 dp[1002][1002];
bool visited[1002][1002];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
    FAST
    //Do awesome things here
    int n;
    mod = pow(2, 31) - 1;
    scd(n);
    rp(i, n){
        scanf("%s", ch[i]);
    }
    dp[0][0] = 1;
    fr(i, 1, n){
        if(ch[0][i] != '#')
            dp[0][i] = dp[0][i - 1];
        if(ch[i][0] != '#')
            dp[i][0] = dp[i - 1][0];
    }
    fr(i, 1, n){
        fr(j, 1, n){
            if(ch[i][j] != '#')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    if(dp[n - 1][n - 1] != 0){
        printf("%lld\n", dp[n - 1][n - 1]);
    }
    else{
        // there is no normal path
        bool reach = false;
        queue<pii> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            pii p = q.front();
            q.pop();
            if(p.f == n - 1 && p.s == n - 1){
                reach = true;
                break;
            }
            rp(i, 4){
                int x = p.f + dir[i][0];
                int y = p.s + dir[i][1];
                if(x >=0 && x < n && y >= 0 && y < n && !visited[x][y] && ch[x][y] == '.'){
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        if(reach)
            printf("THE GAME IS A LIE\n");
        else
            printf("INCONCEIVABLE\n");
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}
/* Author - linpaws07 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
char str[512][300];
int ct[512][26];
int p[512];
bool isp(int ind){
    int st=0;
    for(int i=0;i<26;i++){
        st += (ct[ind][i]&1);
    }
    return st<=1;
}
bool iss(int ind1,int ind2){
    for(int i=0;i<26;i++){
        if(ct[ind1][i]!=ct[ind2][i]) 
            return false;
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    n<<=1;
    for(int i=1;i<=n;i+=2){
        scanf("%s",str[i]+1);
    }
    ll ans = 0;
    for(int i=1;i<=m;i++){
        memset(ct,0,sizeof ct);
        for(int j=i;j<=m;j++){
            for(int k=1;k<=n;k+=2){
                ct[k][str[k][j]-'a']++;
            }
            memset(p,0,sizeof p);
            int C=-1,R=0;
            for(int k=1;k<=n;k++){
                if(!isp(k)){
                    p[k]=0;
                    continue;
                }
                if(k<R){
                    p[k]=min(p[2*C-k],R-k);
                }
                else{
                    p[k]=1;
                }
                while(k-p[k]>=0&&k+p[k]<=n&&isp(k-p[k])&&isp(k+p[k])&&iss(k-p[k],k+p[k])){
                    p[k]++;
                }
                if(k+p[k]>R){
                    R=k+p[k];
                    C=i;
                }
                cout<<p[k]<<" ";
                ans+=p[k]/2;
            }
            cout<<endl;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
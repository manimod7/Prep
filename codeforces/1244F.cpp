#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
    return x*f;
}
const int N=2e5+7;
int n,m,L[N],R[N];
char s[N],ans[N];
vector <int> pos;
bool vis[N];
int main()
{
    n=read(),m=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        int l=(i+n-2)%n+1,r=i%n+1;
        if(s[l]==s[i]||s[r]==s[i]) pos.push_back(i),vis[i]=1;
    }
    int len=pos.size();
    if(!len)
    {
        for(int i=1;i<=n;i++)
            ans[i]= (s[i]=='W' ^ (m&1)) ? 'W' : 'B';
        for(int i=1;i<=n;i++) printf("%c",ans[i]); puts("");
        return 0;
    }
    int las=pos[len-1];
    for(int i=1;i<=n;i++)
        if(vis[i]) las=i;
        else L[i]=las;
    las=pos[1];
    for(int i=n;i>=1;i--)
        if(vis[i]) las=i;
        else R[i]=las;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) { ans[i]=s[i]; continue; }
        int Ld=(i-L[i]+n)%n,Rd=(R[i]-i+n)%n;
        if(min(Ld,Rd)>m)
            ans[i]= (s[i]=='W' ^ (m&1)) ? 'W' : 'B';
        else
            ans[i]= (Ld<Rd) ? s[L[i]] : s[R[i]];
    }
    for(int i=1;i<=n;i++) printf("%c",ans[i]); puts("");
    return 0;
}
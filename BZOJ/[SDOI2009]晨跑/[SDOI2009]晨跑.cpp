#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
 
const int MAX_N=2001,MAX_M=50001,INF=1000000000;
int nm,ansc,n,m,S,T,ansk;
int g[MAX_M],next[MAX_M],cost[MAX_M],flow[MAX_M],c[MAX_N];
int Q[MAX_M*20],pre[MAX_N],E[MAX_N],ud[MAX_N],d[MAX_N];
 
void addedge(int x,int y,int f,int ct){
     g[nm]=y;
     next[nm]=c[x];
     c[x]=nm;
     cost[nm]=ct;
     flow[nm]=f;
     nm++;
}
 
void add(int x,int y,int f,int ct){
     addedge(x,y,f,ct);
     addedge(y,x,0,-ct);
}
 
int spfa(){
    memset(ud,0,sizeof ud);
    Q[1]=S;
    for (int i=1;i<=T;i++) if (i==S) d[i]=0; else d[i]=INF;
    for (int l=1,r=1;l<=r;l++){
        int i=Q[l];
        ud[i]=0;
        for (int k=c[i];k!=-1;k=next[k]){
            int j=g[k];
            if (flow[k]>0 && d[i]+cost[k]<d[j]){
               d[j]=d[i]+cost[k];
               pre[j]=i;
               E[j]=k;
               if (!ud[j]) ud[j]=1,Q[++r]=j;
            }
        }
    }
    return d[T]!=INF;
}
 
void aug(){
     int ret=INF;
     for (int i=T;i!=S;i=pre[i])
         ret=min(ret,flow[E[i]]);
     //printf("%d\n",ret);
     ansk+=ret;
     for (int i=T;i!=S;i=pre[i]){
         //printf("%d %d - ",(i>n && i<=n+n)?(i-n):(i),flow[E[i]]);
         flow[E[i]]-=ret;
         flow[E[i]^1]+=ret;
         ansc+=ret*cost[E[i]];
     }
     //printf("\n");
     //system("pause");
}
 
int main(){
    scanf("%d%d",&n,&m);
    S=2*n+1;T=2*n+2;
    memset(c,-1,sizeof c);
    for (int i=1;i<=n;i++){
        add(i,i+n,1,0);
    }
    for (int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        add(x+n,y,1,w);
    }
    add(S,n+1,INF/2,0);
    add(n,T,INF/2,0);
    while (spfa()) aug();
    printf("%d %d\n",ansk,ansc);
}

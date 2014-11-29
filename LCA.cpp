// http://www.spoj.com/problems/LCA/
// LCA O(n) pre-processing, O(sqrt(H)) query

#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

bool visited[1004];
int T[1004], L[1004], P[1004], H, nr;

void dfs(vvi &v, int start)
{
    visited[start]=1;
    H = max(H,L[start]);
    rep(i,v[start].size())
        if(!visited[v[start][i]])
        {
            T[v[start][i]]=start;
            L[v[start][i]]=L[start]+1;
            dfs(v,v[start][i]);
        }
}

void prelca(vvi &v, int start){
    visited[start]=1;
    if(L[start] < nr) P[start]=0;
    else if(L[start]%nr==0) P[start]=T[start];
    else P[start]=P[T[start]];
    rep(i,v[start].size())
        if(!visited[v[start][i]])
            prelca(v,v[start][i]);
}

int findlca(int x,int y){
    while(P[x]!=P[y]){
        if(L[x] > L[y]) x=P[x];
        else y = P[y];
    }
    while(x!=y){
        if(L[x]>L[y]) x=T[x];
        else y=T[y];
    }
    return x;
}

int main(){
    int t,n,m,x,y,q;
    scanf("%d",&t);
    forup(zz,1,t)
    {
        printf("Case %d:\n",zz);
        scanf("%d",&n);
        vvi v(n);
        rep(i,n)
        {
            scanf("%d",&m);
            while(m--){
                scanf("%d",&x);x--;
                v[i].pb(x);v[x].pb(i);
            }
        }

        // first find immediate parent T[i] & level no. L[i] 
        // of every node. Also find tree height H and 
        // its square root nr using simple dfs
        fill(visited,visited+n,0);
        H=0;T[0]=0;L[0]=0;dfs(v,0);nr=sqrt(H+1);

        // now lca pre processing
        // basically just filling parent array P[i]
        fill(visited,visited+n,0);
        prelca(v,0);

        scanf("%d",&q);
        while(q--){
            scanf("%d %d",&x,&y);x--;y--;
            printf("%d\n",findlca(x,y)+1);
        }
    }
}

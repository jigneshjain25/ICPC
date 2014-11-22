//Problem : http://www.spoj.com/problems/SEQ/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define fordn(i,a,b) for(int i=a;i>=b;i--)
#define debug if(printf("JJ "))
typedef long long ll;
typedef vector<vector<ll> > matrix;
const int mod = 1e9;


// multiplies two matrices and returns a new matrix
// assumes no. of columns = no. of rows property
matrix mul(matrix A,matrix B)
{
    int r = A.size(), c = B[0].size(), x = B.size();
    matrix C(r,vector<ll>(c,0));
    rep(i,r) rep(j,c) rep(k,x)
        C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%mod) % mod;
    return C;
}

// returns power of matrix m^n
matrix pow(matrix n, ll m){
    if(m == 1) return n;
    if(m & 1)
        return mul(n,pow(n,m-1));
    matrix C = pow(n,m/2);
    return mul(C,C);
}

void debugMat(matrix B)
{
    puts("DEBUG");
    rep(i,B.size())
    {
        rep(j,B[i].size()) cout<<B[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int t,k,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        matrix B(k,vector<ll>(1));
        rep(i,k)scanf("%lld",&B[k-1-i][0]);

        matrix C(k,vector<ll>(k,0));
        rep(i,k)scanf("%lld",&C[0][i]);
        forup(i,1,k-1) C[i][i-1]=1;

       // debugMat(B);
       // debugMat(C);

        scanf("%d",&n);
        if(n <= k)
            printf("%lld\n",B[k-1-(n-1)][0]);
        else{
            matrix ret = pow(C,n-k);
            //debugMat(ret);

            ret = mul(ret,B);
            printf("%lld\n",ret[0][0]);
        }
    }
}

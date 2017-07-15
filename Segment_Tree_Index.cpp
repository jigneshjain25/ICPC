#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Prof {
    public:
        int sadness;
        int arrival;
        int lecturesWish;
        int lecturesDone;
};

/* example of seg tree: IPCTRAIN codechef */
/* Range minimum query */

/* the following makes a max finding seg tree with values of professor.sadness. The seg tree will return index to the query ans */

// h = ceil(log2(n))+1
// 2^h-1
// keep one extra for human indexing so  2^h
vector<int> initMvector(int n){
    int power = ceil(log2(float(n))) + 1;
    int size = 1<<power;
    vector<int> M(size,-1);
    return M;
}

void initialize(int node, int a, int b, vector<int> &M){
    if(a==b)
        M[node]=a;
    else{
        int mid = (b-a)>>1;
        int lefti = node<<1;
        int righti = lefti+1;
        initialize(lefti,a,a+mid,M);
        initialize(righti,a+mid+1,b,M);
        M[node]=profs[M[lefti]].sadness > profs[M[righti]].sadness ? M[lefti] : M[righti];
    }
}

int query(int node,int a,int b,vector<int> &M,int i,int j){

	if(a > j || b < i || a > b) return -1;

    if(a>=i && b<=j)
        return M[node];

    int mid = (b-a)>>1;
    int lefti = node<<1;
    int righti = lefti+1;
    int p1=query(lefti,a,a+mid,M,i,j);
    int p2=query(righti,a+mid+1,b,M,i,j);
    if (p1 == -1) return p2;
    else if (p2 == -1) return p1;
    else
        return profs[p1].sadness > profs[p2].sadness ? p1 : p2;
}

void update(int node, int a, int b, vector<int> &M,int i,int j) {

    // debug cout<<node<<" "<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
	if(a > j || b < i || a > b) return;

    if(a == b) {
    	return;
	}

    int mid = (b-a)>>1;
    int lefti = node<<1;
    int righti = lefti+1;
	update(lefti, a, a+mid,M,i,j);
	update(righti, a+mid+1, b, M,i,j);
    M[node] = profs[M[lefti]].sadness > profs[M[righti]].sadness ? M[lefti]: M[righti];
}

int main(){
    int arr[]={1,0,1,3,33,4,2,6};
    int n = sizeof(arr)/sizeof(int);

    vector<int> A(arr,arr+n);
    vector<int> M = initMvector(n);

    initialize(1,0,n-1,M,A);
    update(1,0,n-1,M,n-1,n-1,-99);
    update(1,0,n-1,M,n-2,n-2,999);
    cout<<query(1,0,n-1,M,0,n-2)<<endl;
    cout<<query(1,0,n-1,M,0,n-1)<<endl;
}


#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


/* example of seg tree: HORRIBLE spoj */
/* Range minimum query */


// h = ceil(log2(n))+1
// 2^h-1
// keep one extra for human indexing so  2^h
vector<int> initMvector(int n){
    int power = ceil(log2(float(n))) + 1;
    int size = 1<<power;
    vector<int> M(size,-1);
    return M;
}

vector<int> initLazyvector(int n){
    int power = ceil(log2(float(n))) + 1;
    int size = 1<<power;
    vector<int> M(size,0);
    return M;
}

void initialize(int node, int a, int b, vector<int> &M, vector<int> &A){
    if(a==b)
        M[node]=A[a];
    else{
        int mid = (b-a)>>1;
        initialize(node<<1,a,a+mid,M,A);
        initialize((node<<1)+1,a+mid+1,b,M,A);
        M[node]=max(M[node<<1],M[(node<<1)+1]);
    }
}   

int query(int node,int a,int b,vector<int> &M, vector<int> &lazy,int i,int j){

	if(a > j || b < i || a > b) return 0;
    
    if(lazy[node]) {
		M[node] += lazy[node]; 
 
		if(a != b) {
			lazy[node<<1] += lazy[node]; 
			lazy[(node<<1)+1] += lazy[node]; 
        }
 
		lazy[node] = 0; 
	}
    if(a>=i && b<=j)
        return M[node];
    
    int mid = (b-a)>>1;
    int p1=query(node<<1,a,a+mid,M,lazy,i,j);
    int p2=query((node<<1)+1,a+mid+1,b,M,lazy,i,j);

    return max(p1,p2);
}

void update(int node, int a, int b, vector<int> &M,vector<int> &lazy,int i,int j,int value) {
    
    if(lazy[node]) {
		M[node] += lazy[node]; 
 
		if(a != b) {
			lazy[node<<1] += lazy[node]; 
			lazy[(node<<1)+1] += lazy[node]; 
        }
 
		lazy[node] = 0; 
	}

	if(a > j || b < i || a > b) return;
    
  	if(a >=i && b<=j) { 
    	M[node] += value;
 
		if(a != b) { 
			lazy[node<<1] += value;
			lazy[(node<<1)+1] += value;
		}
 
    	return;
	}
 
    int mid = (b-a)>>1;
	update(node<<1, a, a+mid,M,lazy,i,j,value);
	update((node<<1)+1, a+mid+1, b, M,lazy,i,j,value); 
    
    M[node]=max(M[node<<1],M[(node<<1)+1]);
}

int main(){
    int arr[]={1,0,1,3,33,4,2,6};
    int n = sizeof(arr)/sizeof(int);

    vector<int> A(arr,arr+n);
    vector<int> M = initMvector(n);
    vector<int> lazy = initLazyvector(n);

    initialize(1,0,n-1,M,A);
    update(1,0,n-1,M,lazy,n-1,n-1,-99);
    update(1,0,n-1,M,lazy,n-2,n-2,999);
    cout<<query(1,0,n-1,M,lazy,0,n-2)<<endl;
    cout<<query(1,0,n-1,M,lazy,0,n-1)<<endl;
}


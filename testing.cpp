#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
#include"Segment_Tree.h"

int main(){
    int arr[]={1,2,3};
    int size = sizeof(arr)/sizeof(int);
    vector<int> A(arr,arr+size);
    vector<int> M = initMvector(size);
    initialize(1,0,size-1,M,A);
  //  cout<<A[query(1,0,size-1,M,A,0,7)]<<endl;
    //cout<<A[query(1,0,size-1,M,A,6,size-1)]<<endl;
    //cout<<A[query(1,0,size-1,M,A,2,9)]<<endl;
    //cout<<A[query(1,0,size-1,M,A,0,11)]<<endl;
    //update(A,M,111111,0);
    //cout<<A[query(1,0,size-1,M,A,0,1)]<<endl;
    //cout<<A[query(1,0,size-1,M,A,size-1,size-1)]<<endl;
    for(int i=0;i<M.size();i++)
        cout<<M[i]<<" ";
    //update(A,M,-123,size-1);
    //cout<<A[query(1,0,size-1,M,A,size-1,size-1)]<<endl;


}


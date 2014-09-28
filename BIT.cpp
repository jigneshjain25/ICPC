/******************** Normal BIT ********************************/

//sets A[idx]
void update(int tree[], int idx,int elem,int n){
    while(idx <= n)
    {
        tree[idx]+=elem;
        idx += (idx & (-idx));
    }
}

//returns cummulative sum A[1]..A[idx]
int query(int tree[],int idx,int n){
    int ans = 0;
    while(idx > 0)
    {
        ans += tree[idx];
        idx -= (idx & -idx);
    }
    return ans;
}


/*****************************************************************/


/******************Range update, point query**********************/

// do not call this function directly
void _update(int tree[], int idx,int elem,int n){
    while(idx <= n)
    {
        tree[idx]+=elem;
        idx += (idx & (-idx));
    }
}

// range update A[a]....A[b]
void update(int tree[],int a,int b,int elem,int n){
    _update(tree,a,elem,n);
    _update(tree,b+1,-elem,n);
}

//returns element A[idx]
int query(int tree[],int idx,int n){
    int ans = 0;
    while(idx > 0)
    {
        ans += tree[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

/*******************************************************************/

/* Quick Sort (Non random version)
 */
int Partition(int a[], int beg, int end)        
{
    int p=beg, pivot=a[beg], loc;
    for(loc=beg+1;loc<=end;loc++)
    {
        if(pivot>a[loc])
        {
            a[p]=a[loc];
            a[loc]=a[p+1];
            a[p+1]=pivot;
            p=p+1;
        }
    }
    return p;
}

void QuickSort(int a[], int beg, int end)
{
    if(beg<end)
    {
        int p=Partition(a,beg,end);                       
        QuickSort(a,beg,p-1);                             
        QuickSort(a,p+1,end);
    }
}

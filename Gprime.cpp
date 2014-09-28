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
namespace sieve{
    #define MAX 10000
    #define set(i) (arr[i>>5]|=(1<<(i&31)))
    #define is_composite(i) (arr[i>>5]&(1<<(i&31)))
 
    vector<int> arr((MAX>>5)+5),primes;
 
    void sieve_of_erath()
    {
      int cnt=1;      
      int i,j,sq=sqrt(MAX);
      for(i=3;i<=sq;i+=2)
      {
        if(is_composite(i)==0)
        {
          int k=2*i;          
          for(j=(i*i);j<=MAX;j+=k)
          {            
            set(j);
          }          
        }
      }
            
      primes.push_back(2);
      for(i=3;i<=MAX;i+=2)
      {
        if(is_composite(i)==0)
        {
            primes.push_back(i);
            //cout<<i<<" ";
        }
       }
      //cout<<endl;
    }
}
int main(){
    using namespace sieve;
    
    sieve_of_erath();
    for(int i=0;i<primes.size();i++){
        cout<<primes[i]<<" ";
    }
}







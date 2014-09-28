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
vector<int> primes;
void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      isComposite[0]=isComposite[1]=true;
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (int m = 2; m <= upperBound; m++)
            if (!isComposite[m])
                  primes.push_back(m);
      delete [] isComposite;
}

int main(){
    runEratosthenesSieve(900000000);
    //cout<<primes.size()<<endl;
    for(int i=0;i<primes.size();i++)
        cout<<primes[i];
}


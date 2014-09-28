/* Simple ncr function
 * fails for big nos, search for a better function
 */
long long ncr(int n,int r){
    r = min(r,n-r);
    long long ans=1;
    for(int i=0;i<r;i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}


/*  
 *  Calcualates a^b % c, using fast exponentiation
 *  This same function is used for finding modular inverse as: modulo(a,P-2,P) 
 *  .. where P is the no mod which we want inverse
 */
int modulo(int a,int b,int c){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; 
        b /= 2;
    }
    return x%c;
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
unsigned long long mulmod(unsigned long long a,unsigned long long b,unsigned long long c){
    unsigned long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

/*
 * Sieve of Eratosthenes for finding prime nos
 */

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

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}

//u can also use std::to_string(no)

//integer to string
string tostring ( int Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }


/* 
 * Notes : while solving problems which involve big numbers,
 * always add (long long) at the beginning of every calculation,
 * because otherwise calculations are done taking int storage,
 * but multiplication of two large ints can overflow
 */

//floating pt arithmetic gotchas

double EPS = 1e-9;  // EPS is short for "epsilon", the funky Greek letter Mathematicians use to formally define continuity in analysis (etc.)

//test for equality: DON'T use "a==b"
abs(a-b) < EPS;    // or
abs(a/b - 1) < EPS;   // make sure b != 0, or even anywhere near it

//test for >=: Don't use "a >= b"
a > b-EPS;

//test for >: Don't use "a > b"
a >= b+EPS;

// and similar tests for < and <=
 

// Picks theorem
// Given a simple polygon with all vertices on integer coordinatesgj
A = i + b/2 -1
// A is area
// i is no. of lattice points inside polygon
// b is no of points on edges including corners


// No of lattice points on a line (x1,y1) (x2,y2) == gcd(dx,dy)+1

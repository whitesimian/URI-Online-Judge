// Problem #1568 - {soma+=i++} até N

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int lli;
typedef lli ll;
 
bitset<30000012> isprime;
lli prime[30000012], prime_cont = 0;
lli lim = 30000011;
 
 
void primo() {
  prime[prime_cont++] = 2;
 
    isprime.set();
    for(lli i=3; i<=lim; i+=2)
    {
        if(isprime[i])
        {
            prime[prime_cont++] = i;
 
            for(lli j = i * i; j <= lim; j+= (i + i))
                isprime.reset(j);
        }
    }
}
inline ll fatora(ll n)
{
    ll i = 0;
    ll ans = 1;
    ll divs;
    while (n > 1 && i < 216815)
    {
        divs = 0;
        while(n > 1 && n % prime[i] == 0)
        {
            n/= prime[i];
            divs++;
        }
        if (i) {
            ans*= (divs + 1);
        }
        i++;
    }
    ans <<=(n > 1);
    return ans;
}
 
int main()
{
    ll n;
    primo();
 
    while(cin >> n)
    {
        if (n > 1) {
            cout << fatora(n) << '\n';
        } else {
            cout << "1\n";
        }
    }
}
#include<iostream>
typedef long long ll;
#define mod 1000000007
#define all(x) x.begin(),x.end()
ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(int a, ll p = mod) {return fpow(a, p - 2, p);}
using namespace std;
int main()
{
	ll t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		ll arr[n],gcd;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i==0)
				gcd=arr[i];
			else
				gcd=__gcd(gcd,arr[i]);
		}

		if(gcd==1)
			cout<<0<<endl;
		else
			cout<<-1<<endl;
	}	
}
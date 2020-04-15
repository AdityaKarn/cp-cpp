#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000


using namespace std;

long long int max(long long int a, long long int b){
    if(a>b) return a;
    else return b;
}

long long int ar[200001];
int main()
{
	lli t , n;
	cin>>t;
 
	while(t--)
	{
		cin>>n;
		lli res = 0;
		lli odd = 0;
 
		vi two , zero;
 
		REP(i , n)
		{
			cin>>ar[i] , ar[i] = abs(ar[i]);
			ar[i] %= 4;
 
			if(ar[i] == 0)
			{
				res += i;
				res += (odd * (odd + 1))/2;
				odd = 0;
				zero.pb(i);
			}
			else
			if(ar[i] == 1)
			{
				odd++;
				int pos = 0;
 
				if(two.size() > 1)
				pos = two[two.size() - 2];
 
				if(zero.size() > 0)
				pos = max(pos , zero.back());
 
				res += pos;
			}
			else
			if(ar[i] == 2)
			{
				res += (odd * (odd + 1))/2;
				odd = 0;
 
				int pos = 0;
				if(two.size() > 0)
				pos = two.back();
 
				if(zero.size() > 0)
				pos = max(pos , zero.back());
 
				res += pos;
				two.pb(i);
			}
			else
			{
				odd++;
				int pos = 0;
 
				if(two.size() > 1)
				pos = two[two.size() - 2];
 
				if(zero.size() > 0)
				pos = max(pos , zero.back());
 
				res += pos;
			}
		}
		res += (odd * (odd + 1))/2;
 
		cout<<res<<endl;
	}
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

#define REP(i,n) for (int i = 1; i <= n; i++)
#define lli long long int
#define mod 998244353
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<lli>
#define vii vector<ii>

#define INF 1000000000



using namespace std;


string st;

lli power(lli a , lli n)
{
	lli res = 1;
	
	while(n)
	{
		if(n & 1)
			res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}


lli add(lli a, lli b){
    return (a+b)%mod;
}


vi applyOperator(vi &a , vi &b , char _operator)
{
	vi res(4 , 0);
	//apply OR Operator
	if(_operator == '|')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[1] = add(res[1] , (a[2] * b[1]) % mod);
		res[1] = add(res[1] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[1] = add(res[1] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[1] = add(res[1] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
	

	//apply XOR operator
	if(_operator == '^')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[0] = add(res[0] , (a[1] * b[1]) % mod);
		res[3] = add(res[3] , (a[2] * b[1]) % mod);
		res[2] = add(res[2] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[3] = add(res[3] , (a[1] * b[2]) % mod);
		res[0] = add(res[0] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[2] = add(res[2] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[0] = add(res[0] , (a[3] * b[3]) % mod);
	}
	
	//apply AND operator
	if(_operator == '&')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[0] = add(res[0] , (a[1] * b[0]) % mod);
		res[0] = add(res[0] , (a[2] * b[0]) % mod);
		res[0] = add(res[0] , (a[3] * b[0]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[2] = add(res[2] , (a[2] * b[1]) % mod);
		res[3] = add(res[3] , (a[3] * b[1]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[2]) % mod);
		res[2] = add(res[2] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[0] = add(res[0] , (a[3] * b[2]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[3]) % mod);
		res[3] = add(res[3] , (a[1] * b[3]) % mod);
		res[0] = add(res[0] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
	
	return res;
}



vi getRes(){

    vi temp(4,1);
    stack<vi> stk;

    stack<char> op_stack, par_stack;

    for(char ch: st){
        if(ch=='(') par_stack.push(ch);

        else if(ch=='|'|| ch=='&'|| ch== '^') op_stack.push(ch);

        else if(ch=='#'){
            stk.push(temp);
        }
        else{
            vi a = stk.top();
            stk.pop();

            vi b = stk.top();
            stk.pop();

            char _operator = op_stack.top();
            op_stack.pop();
            par_stack.pop();

            stk.push(applyOperator(a , b , _operator));
        }

    }

    return stk.top();
}

int getExpressionCount(string &st)
{
	int cnt = 0;
	for(char ch : st)
	cnt += (ch == '#');
	
	return cnt;
}

int main(){

    int t; cin>>t;

    while(t--){
        st.clear();
        cin>>st;

        vi res = getRes();
        int exp_cnt = getExpressionCount(st);
		lli d = power(power(4 , exp_cnt) , mod-2);

		
		cout<<(res[0] * d)%mod<<" ";
		cout<<(res[1] * d)%mod<<" ";
		cout<<(res[2] * d)%mod<<" ";
		cout<<(res[3] * d)%mod<<endl;
    }


    return 0;
}
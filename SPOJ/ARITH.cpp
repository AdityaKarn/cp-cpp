#include<iostream>
#include<string>
#include<stack>

using namespace std;

int maxy(int a, int b){
    if (a>b) return a;
    else return b;
}

int miny(int a, int b){
    if (a>b) return b;
    else return a;
}

string add(string a, string b){
    stack<int> st;
    string res = "";
    int carry = 0, currSum, i = a.length()-1, j = b.length()-1;

    while(i >= 0 && j >= 0){
        currSum = (a[i]-48) + (b[j]-48) + carry;
        
        st.push(currSum%10);
        carry = currSum/10;
        i--;j--;
        
    }
    cout<<'1';

    while(i >=0){
        currSum = (a[i]-48) + carry;

        st.push(currSum%10);
        carry = currSum/10;
        i--; 
    }
    cout<<'2';
    while(j >=0){
        currSum = (b[j]-48) + carry;

        st.push(currSum%10);
        carry = currSum/10;
        j--;
    }
    cout<<'3';
    while(carry){
        st.push(carry%10);
        carry /= 10;
        
    }
    cout<<'4';
    // now appending in result
    while(!st.empty()){
        res.append(1, st.top()+48);
        st.pop();
    }
    cout<<'5';
    return res;
}

int main() 
{
    string s, a, b, op, res;
    cin>>s;
    int n = s.length(), i, lenA, lenB=0;
    i=0;

    for(i = 0; i <n; i++){
        if(s[i]=='+'|| s[i]=='-'|| s[i]=='*'|| s[i]=='/'){
            break;
        }
        else{
            a[i]=s[i];
        }
    }
    lenA=i;
    op = s[i++];

    int j =0;
    while(i< n){
        b[j]=s[i];
        i++; j++;
    }

    lenB = j;

    res = add(a,b);

    for(i = 0; i< res.length(); i++){
        cout<<res[i];
    }

    return 0;

    
}

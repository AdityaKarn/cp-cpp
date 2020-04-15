#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<map>
using namespace std;
char func(map<char,char> m, string s)
{
    stack<char> o;
    stack<char> op;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            o.push('(');
            //cout<<"pushing ("<<endl;
        }
        else if(s[i]==')')
        {
           char operation=o.top();
           o.pop();
           o.pop();
           if(operation == '&')
           {
               char operand1=op.top();
               op.pop();
               char operand2=op.top();
               if(operand1!='0' && operand1!='1')
               {
                   operand1=m[operand1];
               }
               if(operand2!='0' && operand2!='1')
                    operand2=m[operand2];
                if(operand1=='1' && operand2=='1')
                    op.push('1');
                else
                    op.push('0');
                //cout<<operand1<<" and "<<operand2<<endl;
            }
            else if(operation=='+')
            {
                char operand1=op.top();
               op.pop();
               char operand2=op.top();
               if(operand1!='0' && operand1!='1')
               {
                   operand1=m[operand1];
               }
               if(operand2!='0' && operand2!='1')
                    operand2=m[operand2];
                if(operand1=='0' && operand2=='0')
                    op.push('0');
                else
                    op.push('1');
                //cout<<operand1<<" or "<<operand2<<endl;
            }
            else if(operation=='>')
            {
                char operand1=op.top();
               op.pop();
               char operand2=op.top();
               if(operand1!='0' && operand1!='1')
               {
                   operand1=m[operand1];
               }
               if(operand2!='0' && operand2!='1')
                    operand2=m[operand2];
                if(operand2=='1' && operand1=='0')
                    op.push('0');
                else
                    op.push('1');
            }
            else if(operation=='-')
            {
                char operand=op.top();
                op.pop();
                if(operand!='0' && operand!='1')
                    operand=m[operand];
                if(operand=='1')
                    op.push('0');
                else
                    op.push('1');
            }
        }
        else if(isalpha(s[i])){
            //cout<<"pushing "<<s[i]<<endl;
            op.push(s[i]);
        }
        else
        {//cout<<"pushing "<<s[i]<<endl;
            o.push(s[i]);
        }
    }
    return op.top();
}
int main()
{
    cout<<"enter the string ";
    string s;
    cin>>s;
    int len=s.length();
    map< char , char> m;
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(isalpha(s[i]))
        {
         if(m.find(s[i])==m.end())
         {
             m[s[i]]='1';
             count++;
         }

        }
    }

    int i=0;
    int max=(1<<count);
    for(map<char ,char> :: iterator it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" ";
    }
    cout<<"Output"<<endl;
    char output[max];
    while(i<max)
    {
        int cur=i;
        map<char , char> :: iterator it=m.end();
        it--;

        while(1)
        {
            if(it==m.begin())
            {
                 int input=cur&1;
            if(input==1)
                it->second='1';
            else
                it->second='0';
                break;
            }

            int input=cur&1;
            if(input==1)
                it->second='1';
            else
                it->second='0';
            cur>>=1;
            it--;

        }
        it=m.begin();
        for(int j=0;j<count;j++)
        {
            cout<<it->second<<" ";
            it++;
        }
        output[i]=func(m,s);
        cout<<output[i]<<endl;
        i++;

    }
    i=0;
    int c=0;
    for(;i<max;i++)
    {
        if(output[i]=='1')
            c++;
    }
    if(c==max)
        cout<<"Tautology";
    else if(c==0)
        cout<<"Contradiction";
    else
        cout<<"Contigency";
    return 0;

}
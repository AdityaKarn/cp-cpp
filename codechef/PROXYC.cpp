#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

    int t;
    cin>>t;
    int n ,count  ,present ,i;
    present = 0;
    string s;
    float per;
    while(t-->0)
    {
        cin>>n;
        cin>>s;
        
        for(int k=0; k<n; k++){
            if(s[k]=='P'){
                present++;
            }
        }
        per=(float) present/n;



        //now checking given conditions
         i=2;
        count=0;
        if(n>=4)
        {
        while(i<n-2 && per<0.75)
        {
            if(s[i]=='A')
            {
            if((s[i-1]=='P' || s[i-2]=='P') && (s[i+1]=='P' || s[i+2]=='P'))
            {
                count++;
                present++;
               per=(float) present/n;
                if(per>=0.75)
                {
                    break;
                }
            }
            }
            i++;
        }
        }
        if(per>=0.75)
        {
            cout<<count<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        s.clear();
    }
}
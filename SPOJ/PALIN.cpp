#include<iostream>
#include<string.h>

using namespace std;


   int all_nine(string str)  //check if all digits are '9' 
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!='9')
                return 0;
        }
        return 1;
    }

/*
string palin(string s){
    
}
*/

int main(){ 
    string s;
    cin>>s;

    //all 9
    if(all_nine(s)){
        int n = s.length();
        char ans[n+1];
        ans[0]='1';
        for(int i=1; i<n; i++){
            ans[i]='0';
        }
        ans[n]='1';
        ans[n+1]='\0';
        cout<<ans;
    }
    else{
        
    }
    

}

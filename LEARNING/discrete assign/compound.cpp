/* works only for three variable p,q,r

((p->q)vr) 
(0->0) v 0

*/

#include<iostream>
#include<string>
#include<stack>



using namespace std;



/* 
not : ~
OR : v
and : ^
implies : ->
equivalence : <->
*/


int parser(string exp){
char temp1, temp2;
 stack<int> values;
 stack<char> ops;

    //changing implies
    for(int i = 0; i< exp.length(); i++){
        if(exp[i]=='-'){
            //will be like p->q we will change that to `pvq
            temp1 = exp[i-1];

            // changing the expression 
            exp[i-1] = '`';
            exp[i] = temp1;
            exp[i+1] = 'v';

        }
        
    }

    //changing equivalence
    for(int i = 0; i< exp.length(); i++){
            if(exp[i]=='<'){
                //will be like p<->q we will change that to `pvq
                temp1 = exp[i-1];
                temp2 = exp[i+3];
                // changing the expression 
                exp[i-1] = '`';
                exp[i] = temp1;
                exp[i+1] = 'v';

            }
            
        }

    return 0;
}




int main(){

    string expression;
    cin>>expression;

    int temp = parser(expression);

    if(temp == 0){
        cout<<"contradiction";

    }
    else if(temp == 1){
        cout<<"tautology";
    }
    else{
        cout<<"contigency";
    }



    return 0;
}
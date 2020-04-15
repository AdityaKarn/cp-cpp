

#include<iostream>
#include<string>
#include<stack>

// here implies means I, equivalence means E, not is `, and is A, or is V


using namespace std;


int precedence(char op){ 
    if(op == 'I'||op == 'E') 
    return 1; 
    else if(op == 'V'||op == 'A') 
    return 2; 

    else return 0; 
} 
  

// Function to perform arithmetic operations. 
int applyOp(int a, int b, char op){ 

    if(op == 'E') {
        int c = (!a)||b;
        int d = (!b)||a;
        return c&&d;
    }
    else if(op == 'I'){
        int t = (!a)||b;
        return t;
    }
    else if(op == 'V'){
        cout<<"idhar pahochi a ki value "<<a<<" and b ki vlue "<<b<<endl;
        cout<<" to result return karra "<< a || b;
        return a || b; 
    } 
    else if(op == 'A') return a && b;
    else return 0;
}
  
// Function that returns value of 
// expression after evaluation. 
int evaluate(string tokens){ 

    int i; 
      
    // stack to store integer values. 
    stack <int> values; 
      
    // stack to store operators. 
    stack <char> ops; 
      
    for(i = 0; i < tokens.length(); i++){ 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i] == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i] == '('){ 
            ops.push(tokens[i]); 
        } 
          
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(isdigit(tokens[i])){ 

              
            values.push(tokens[i]); 
        } 
          
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i] == ')') 
        { 
            while(!ops.empty() && ops.top() != '(') 
            { 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // pop opening brace. 
            if(!ops.empty()) 
               ops.pop(); 
        } 
          
        
        // Current token is an operator. 
        
        else
        { 
            // While top of 'ops' has same or greater  
            // precedence to current token, which 
            // is an operator. Apply operator on top  
            // of 'ops' to top two elements in values stack. 
            while(!ops.empty() && precedence(ops.top()) 
                                >= precedence(tokens[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // Push current token to 'ops'. 
            ops.push(tokens[i]); 
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    // Top of 'values' contains result, return it. 
    return values.top(); 
 
} 


int parse(string exp){

    int trues = 0;
    for(int i =0; i< exp.length(); i++){

        // using all possibilities of p, q , r
        if(exp[i]=='p') exp[i]='0';
        else if(exp[i]=='q') exp[i]='0';
        else if(exp[i]=='r')exp[i]='0';

    }
    int rem = evaluate(exp);
    cout<<rem;
    if(rem == 1) trues++;

    for(int i =0; i<exp.length(); i++){
        cout<<exp[i];
    }

    if(trues==8) return 2;
    else if(trues == 0) return 0;
    else return 1;

        


    
}

int main() { 
    cout << parse("((pVq)Vr)") << "\n"; 
    
    return 0; 
} 
  
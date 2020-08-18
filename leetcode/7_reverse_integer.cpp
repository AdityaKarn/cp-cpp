class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        
        
        int temp = x;
        int res = 0;
        while(temp){
            int last_digit = temp%10;
            
            if(res > INT_MAX/10 || res> 0 && res <= INT_MAX/10 && INT_MAX - 10*res < last_digit) return 0;
            if(res < INT_MIN/10 || res< 0 && res >= INT_MIN/10 && INT_MIN - 10*res > last_digit) return 0;
            res *= 10;
            res += last_digit;
            temp /= 10;
        }
        
        return res;
    }
};
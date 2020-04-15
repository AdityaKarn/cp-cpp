#include <iostream>
#include <vector>

using namespace std;

int main() {
    int maxA[] = {0,0,0,0,0,0,0,0,0,0,0};
    int T, p, s;
    int sum = 0;
    unsigned int n;
    cin>>T;
    for(int i = 0; i<T; i++){
        cin>>n;
        sum = 0;
        for(int j = 0; j< n; j++){
            cin>>p;
            cin>>s;
            if(s> maxA[p-1] && p<9){
                sum= sum - maxA[p-1] + s;
                maxA[p-1]=s;
            }
            
        }
        cout<<sum<<"\n";
    }

	return 0;
    

}

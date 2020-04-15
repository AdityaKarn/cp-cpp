#include<iostream>
#include<list>
#include<set>
#include<map>
#include<iterator>


using namespace std;

int main(){


    // SETS
    /*
    set <int> ss;              //ascending
    set <int, greater <int>> ss2;           //descending
    set <int> :: iterator it;
    set <int, greater <int>> :: iterator it2;

    for (int i = 0; i < 6; i++){
        ss.insert(i*10);
        ss2.insert(i*10);
    }


    for(it = ss.begin(); it != ss.end(); it++){
       cout << *it<< "  "; 
    }

    for(it2 = ss2.begin(); it2 != ss2.end(); it2++){
       cout << *it2<< "  "; 
    }
    */

    // MAPS

    map <char, int> mappu;

    mappu.insert(pair<)

    map <char, int> :: iterator anp;
    
    for(anp= mappu.begin(); anp != mappu.end(); anp++){
        cout<< anp->first<< "  "<< anp->second << "\n";

    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector <bool> a(100000000); //this will store no. that are presents for checking condition 
    vector <string> yes{'Y','E','S'};
    vector <string> no{'N','O'};
    int variableCount = 1;
    char previous = '1';
    for(int i = 0; i< s.size(); i++){
        int weight = s[i] - 'a' + 1;

        if(s[i]==prev){
            variableCount++;
            weight += weight;
        }

        else{
            variableCount = 1;
            previous = s[i];
            a[weight] = true;
        }
    }
    
    for(int j = 0; j< queries.size(); j++){
        int temp;
        temp = queries[j];
        if(a[temp]){
            
            return yes;
        }
        else{
            return no;
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

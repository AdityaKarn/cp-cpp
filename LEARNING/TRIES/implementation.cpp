#include<iostream>
#include<string>

using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode **children;
        bool isTerminal;
    
    TrieNode(char data){
        this->data=data;
        children = new TrieNode*[26];

        for(int i =0; i<26; i++) children[i] = NULL;

        isTerminal = false;
    }
};

class Trie{
    TrieNode *root;
    public:
        

    Trie(){
        root = new TrieNode('\0');
    }

    void Insert(TrieNode *root, string st){
        
        if(st.size()==0){
            root->isTerminal =true; 
        }
        int index = st[0]-'a';
        
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(st[0]);
            root->children[index]= child;
        }

        Insert(child, st.substr(1));
    }

    void Insert(string st){
        Insert(root, st);
    }

    bool Search(TrieNode *root, string st){
        if(st.size()==0){
            
            if(root->isTerminal == true){
                return true;
            } 
            else return false;
        }
        
        int index = st[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        Search(child, st.substr(1));   
    }
    
    bool Search(string st){
        return Search(root, st);
    }

    void removeWord(TrieNode *root, string st){
        
        if(st.size()==0){
            root->isTerminal= false;
            return;
        }

        int index = st[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        removeWord(child, st.substr(1));

        if(child->isTerminal= false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL) return; 
            }
        }
        delete child;

        root->children[index] = NULL;
    }

    void removeWord(string st){
        removeWord(root, st);
    }
};





int main(){
    Trie t;

    t.Insert("are");
    t.Insert("and");
    t.Insert("sae");

    // cout<<t.Search("are");



    return 0;
}
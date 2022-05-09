class Trie{
    private:
    Trie *next[26];
    vector <int> allStrings;
    
    public:
    Trie(){
        for(int i = 0; i < 26; ++i){
            next[i] = NULL;
        }
    }
    
    void insert(Trie *root, string &s, int pos){
        Trie *currentPointer = root;
        for(char c : s){
            if(currentPointer -> next[c - 'a'] != NULL){
                currentPointer = currentPointer -> next[c - 'a'];
            }
            else{
                currentPointer -> next[c - 'a'] = new Trie();
                currentPointer = currentPointer -> next[c - 'a'];
            }
            currentPointer -> allStrings.push_back(pos);
        }
    }
    
    void search(Trie *root, string s, string contact[], vector <vector <string> > &distinctContacts){
        for(int i = 0; i < (int) s.size(); ++i){
            char &c = s[i];
            if(root != NULL and root -> next[c - 'a'] != NULL){
                root = root -> next[c - 'a'];
            }
            else{
                root = NULL;
            }
            if(root){
                for(int &x : root -> allStrings){
                    distinctContacts[i].push_back(contact[x]);
                }
            }
            else{
                distinctContacts[i].push_back(to_string(0));
            }
        }
    }
    
};

class Solution{
    public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        Trie *root = new Trie();
        sort(contact, contact + n);
        for(int i = 0; i < n; ++i){
            if(i == 0 or contact[i] != contact[i - 1]){
                root -> insert(root, contact[i], i);
            }
        }
        vector <vector <string> > distinctContacts((int) s.size(), vector <string> {});
        root -> search(root, s, contact, distinctContacts);
        return distinctContacts;
    }
};

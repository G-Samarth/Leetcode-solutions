class TrieNode {
public:
    bool isWord;
    TrieNode *children[26];

    TrieNode(){
        isWord = false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* curr = root;

        for(int i=0;i<n;i++){
            if(!curr->children[word[i] - 'a']){
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            
            curr = curr->children[word[i] - 'a'];
        }

        curr->isWord = true;
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* curr = root;

        for(int i=0;i<n;i++){
            if(!curr->children[word[i] - 'a']){
                return false;
            }
            
            curr = curr->children[word[i] - 'a'];
        }

        if(curr->isWord)
            return true;
        else
            return false;
    }
    
    bool startsWith(string word) {
        int n = word.length();
        TrieNode* curr = root;

        for(int i=0;i<n;i++){
            if(!curr->children[word[i] - 'a']){
                return false;
            }
            
            curr = curr->children[word[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
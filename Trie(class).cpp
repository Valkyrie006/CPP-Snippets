// https://github.com/yash30201/snippets#Tries
class Trie {
    Trie *children[26];
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isLeaf = false;
    }
    /** Inserts a word into the trie. */
    void insert(string &word) {
        Trie *root = this;
        for(char ch: word) {
            if(root->children[ch - 'a'] == NULL)
                root->children[ch - 'a'] = new Trie();
            root = root->children[ch - 'a'];
        }
        root->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string &word) {
        Trie *root = this;
        for(char ch: word) {
            if(root->children[ch - 'a'] == NULL)
                return false;
            root = root->children[ch - 'a'];
        }
        return root->isLeaf;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
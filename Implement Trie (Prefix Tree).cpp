class Trie {
public:
    struct Trie_node{
        unordered_map<char, Trie_node*> edge;
    };
    Trie_node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Trie_node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie_node *node = root;
        
        for(char ch: word){
            if(node->edge.find(ch) == node->edge.end()){
                Trie_node* newnode = new Trie_node;
                node->edge[ch] = newnode;
            }
            node = node->edge[ch];
        }
        node->edge['*'] = NULL;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie_node *node = root;
        
        for(char ch: word){
            if(node->edge.find(ch) != node->edge.end()){
                node = node->edge[ch];
            }
            else{
                return false;
            }
            
        }
        return node->edge.find('*') != node->edge.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie_node *node = root;
        
        for(char ch: prefix){
            if(node->edge.find(ch) != node->edge.end()){
                node = node->edge[ch];
            }
            else{
                return false;
            }
            
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

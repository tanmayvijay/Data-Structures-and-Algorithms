class Trie {
    char data;
    unordered_map<char, Trie* > children;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->data = '\0';
    }
    Trie(char data) {
        this->data = data;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i=0, len = word.length();
        // if (i < len && this->data == '\0'){
        //     this->data = word[i];
        //     i++;
        // }
        Trie* t = this;
        
        while(i<len){
            if (t->children.find(word[i]) != t->children.end()){
                t = t->children.find(word[i])->second;
            }
            else{
                Trie* temp = new Trie(word[i]);
                t->children.insert({word[i], temp});
                // t = t->children.find(word[i])->second;
                t = temp;
            }
            
            i++;
        }
        // Trie* temp = new Trie('\0')
        t->children.insert({'\0', NULL});
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i=0, len = word.length();
        Trie* t = this;
        while(i<len){
            if (t->children.find(word[i]) != t->children.end()){
                t = t->children.find(word[i])->second;
                // cout << "here" << endl;
            }
            else return false;
            i++;
        }
        if (t->children.find('\0') != t->children.end())
            return true;
        
        return false;
        // if (i==len)
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i=0, len = prefix.length();
        Trie* t = this;
        while(i<len){
            if (t->children.find(prefix[i]) != t->children.end()){
                t = t->children.find(prefix[i])->second;
                // cout << "here" << endl;
            }
            else return false;
            i++;
        }
        // if (t->children.find('\0') != t->children.end())
        return true;
        
        // return false;
    }
};
class Node{
    public:
    Node* links[26];
    bool flag=false;
    bool contains(char c){
        return links[c-'a']!=NULL;
    }
    Node* put(char c){
        return links[c-'a']=new Node();
    }
    Node* get(char c){
        return links[c-'a'];
    }
};

class Trie {
private:
Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->contains(word[i])){
                node=node->get(word[i]);
            }
            else{
                node=node->put(word[i]);
            }
        }
        node->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->flag){
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

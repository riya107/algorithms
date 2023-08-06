class Node{
    public:
    Node* links[26];
    int sw;
    int ew;
    bool contains(char c){
        return links[c-'a']!=NULL;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    Node* put(char c){
        links[c-'a']=new Node();
        return links[c-'a'];
    }
};

class Trie{
    private:
    Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->contains(word[i])){
                node=node->get(word[i]);
                node->sw++;
            }
            else{
                node=node->put(word[i]);
                node->sw++;
            }
        }
        node->ew++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->ew;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->sw;
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            node=node->get(word[i]);
            node->sw--;
        }
        node->ew--;
    }
};

class Node{
    public:
    Node* links[2];
    bool contains(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    Node* put(int bit){
        links[bit]=new Node();
        return links[bit];
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->contains(bit)){
                node=node->get(bit);
            }
            else{
                node=node->put(bit);
            }
        }
    }
    int getMaxXor(int x){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i) & 1;
            if(node->contains(1-bit)){
                maxNum = maxNum | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};

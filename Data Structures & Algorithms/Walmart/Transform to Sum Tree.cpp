class Solution {
    public:
    int transformToSumTree(Node *node){
        if(node == NULL){
            return 0;
        }
        
        int originalNodeValue = node -> data, leftSubtree = transformToSumTree(node -> left), rightSubtree = transformToSumTree(node -> right);
        node -> data = leftSubtree + rightSubtree;
        
        return originalNodeValue + node -> data;
    }
    
    void toSumTree(Node *node){
        transformToSumTree(node);
    }
};

int traverse(Node* root, int x, int &subtreesWithSumX){
    if(root == NULL){
        return 0;
    }
    int leftSubtreeSum = traverse(root -> left, x, subtreesWithSumX), rightSubtreeSum = traverse(root -> right, x, subtreesWithSumX);
    subtreesWithSumX += leftSubtreeSum + rightSubtreeSum + root -> data == x;
    return leftSubtreeSum + rightSubtreeSum + root -> data;
}

int countSubtreesWithSumX(Node* root, int x){
    int subtreesWithSumX = 0;
    traverse(root, x, subtreesWithSumX);
    return subtreesWithSumX;
}

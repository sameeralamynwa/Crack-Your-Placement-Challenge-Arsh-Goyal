class Solution{
    public:
    void linkdelete(struct Node  *head, int m, int n){
        Node *previousNode = NULL;
        do{
            for(int i = 0; i < m and head; ++i){
                previousNode = head;
                head = head -> next;
            }
            for(int i = 0; i < n and head; ++i){
                head = head -> next;
            }
            if(previousNode){
                previousNode -> next = head;
            }
        }while(head);
    }
};

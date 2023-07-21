void insertNode(DoublyLinkedListNode* &prev, DoublyLinkedListNode* &curr, int data){
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);    
    newNode->next = curr;
    if(curr!=NULL){
        curr->prev = newNode;
    }
    prev->next = newNode;
    newNode->prev = prev;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    DoublyLinkedListNode *curr = head;
    DoublyLinkedListNode *prev = NULL;
    
    // first Node
     if(data < curr->data){    
            DoublyLinkedListNode *nullNode = NULL;
            insertNode(nullNode, curr, data);
            return newNode;
        }
    
    while(curr!=NULL){
        if(data>curr->data){
            prev = curr;
            curr = curr->next;
        }else{
            insertNode(prev, curr, data);
            return head;
        }
    }

    DoublyLinkedListNode *nullNode = NULL;
    insertNode(prev, nullNode, data);
    
    return head;
}

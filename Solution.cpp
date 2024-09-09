struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};  

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node* mid(Node* head){
        if (head == NULL || head->next == NULL) return head;
        
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL &&  fast->next!=NULL ){
            fast=fast->next->next;
            if(fast!=NULL){
                slow=slow->next;
            }
        }
        
        return slow;
    }
    
    bool isPalindrome(Node *head) {
        if(head==NULL) return true;
        
        Node* midNode= mid(head);
        
        Node* midList= reverseList(midNode);
        
        Node* s=head;
        while(midList->next!=NULL){
            if(midList->data!=s->data){
                return false;
            }
            s=s->next;
            midList=midList->next;
        }
        return true;
    }
};

// GeeksforGeeks - Check if Linked List is Palindrome
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

bool isPalindrome(Node *head)
{
    Node* ptr = head;
    stack<int> st;
    int count = 0;
    while(ptr != NULL){
        st.push(ptr->data);
        ptr = ptr->next;
        count++;
    }
    ptr = head;
    if(count&1 == 1) count = count/2 + 1;
    else count = count/2;
    while(count != 0){
        if(ptr->data != st.top()){
            return false;
        }
        ptr = ptr->next;
        st.pop();
        count--;
    }
    return true;
}


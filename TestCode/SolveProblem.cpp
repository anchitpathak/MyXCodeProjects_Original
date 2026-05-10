#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* tempNode = head->next;
        int count = 2;
        while(tempNode->next != nullptr)
        {
            count++;
            tempNode = tempNode->next;
        }
        int realRotation = k % count;
        int iteration = count - realRotation;
        ListNode* tempNode1 = head;
        while(--iteration)
        {
            tempNode1 = tempNode1->next;
        }
        tempNode->next = head;
        head = tempNode1->next;
        tempNode1->next = nullptr;
        
        return head;
    }
//int main()
//{
//    ListNode* node = new ListNode(1);
//    node->next = new ListNode(2);
//    node->next->next = new ListNode(3);
//    node->next->next->next = new ListNode(4);
//    node->next->next->next->next = new ListNode(5);
//    ListNode* TempNode = rotateRight(node, 2);
//    cout<<TempNode->val;
//    return 1;
//}

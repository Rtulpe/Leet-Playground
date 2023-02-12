#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void printNode(struct ListNode* node);

int main() {
    struct ListNode node1 = {.val= 5};
    struct ListNode node2 = {.val= 5, .next = &node1};
    struct ListNode node3 = {.val= 6, .next = &node2};
    struct ListNode node4 = {.val= 7, .next = &node3};

    struct ListNode node5 = {.val= 5};
    struct ListNode node6 = {.val= 8, .next = &node5};
    struct ListNode node7 = {.val= 9, .next = &node6};
    struct ListNode node8 = {.val= 1, .next = &node7};
    printNode(&node4);
    printNode(&node8);
    printNode(addTwoNumbers(&node4,&node8));
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *ptr = head;
    int sum = 0;

    while(l1 || l2 || sum){
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        ptr->val = sum % 10;
        sum = sum / 10;

        if(l1 || l2 || sum){
            ptr->next = malloc(sizeof(struct ListNode));
            ptr = ptr->next;
            ptr->val = 0;
            ptr->next = NULL;
        }
    }
    return head;
}

void printNode(struct ListNode* node){
    while(node != NULL){
        printf("%d : ",node->val);
        node = node->next;
    }
    printf("\n");
}
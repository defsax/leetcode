#include <iostream>

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNums(ListNode* l1, ListNode* l2){
  ListNode *temp = new ListNode;
  ListNode *firstNode = temp;
  temp->val = 0;
  
  //while we haven't reached the last node
  while(l1 != nullptr){
    //if there's a l2 value still, add l1 + l2 + temp val(carried)
    if(l2 != nullptr){
      temp->val = temp->val + l1->val + l2->val;
      //advance l2
      l2 = l2->next;
    }
    else //if there's no l2 value, set temp node value to l1 value
      temp->val += l1->val;
    
    
    //if the added amount is greater than 10
    if(temp->val >= 10){
      //divide the value up
      int tens = (temp->val / 10) % 10;
      int ones = temp->val % 10;
      
      //create next node to carry tens value into
      temp->next = new ListNode(tens);
      //set current node's value to single digit
      temp->val = ones;
    }
    else if(temp->val < 10 && l1->next != nullptr)
      temp->next = new ListNode(0);
    
    //advance temp node and l1
    temp = temp->next;
    l1 = l1->next;
  }
  
  return firstNode;
};

void outputSingleList(ListNode* x){
  while(x != nullptr){
    std::cout << x->val << " ";
    
    //advance pointer along list
    x = x->next;
  }
  std::cout << std::endl << std::endl;
}

ListNode *createList(int x[], size_t l)
{
  ListNode *list = new ListNode;
  ListNode *firstNode = list;
  
  //std::cout << l << std::endl << std::endl;
  for(size_t i = 0; i < l; i++){
    list->val = x[i];
    
    //only make a new node if i is less than length - 1
    if(i < l - 1)
      list->next = new ListNode();
    
    //iterate list
    list = list->next;
  }
  return firstNode;
}

int main(){
  //Example 1
  int list1a[] = {2, 4, 3};
  size_t s = sizeof(list1a) / sizeof(list1a[0]);
  ListNode *l1 = createList(list1a, s);
  
  int list1b[] = {5, 6, 4};
  s = sizeof(list1b) / sizeof(list1b[0]);
  ListNode *l2 = createList(list1b, s);
  
  ListNode* x = addTwoNums(l1, l2);
  outputSingleList(x);
  
  
  //Example 2
  int list2a[] = {0};
  s = sizeof(list2a) / sizeof(list2a[0]);
  ListNode *l3 = createList(list2a, s);
  
  int list2b[] = {0};
  s = sizeof(list2b) / sizeof(list2b[0]);
  ListNode *l4 = createList(list2b, s);
  
  ListNode* y = addTwoNums(l3, l4);
  outputSingleList(y);
  
  
  //Example 3
  int list3a[] = {9, 9, 9, 9, 9, 9, 9};
  s = sizeof(list3a) / sizeof(list3a[0]);
  ListNode *l5 = createList(list3a, s);
  
  int list3b[] = {9, 9, 9, 9};
  s = sizeof(list3b) / sizeof(list3b[0]);
  ListNode *l6 = createList(list3b, s);
  
  ListNode* z = addTwoNums(l5, l6);
  outputSingleList(z);
  
  return 0;
}

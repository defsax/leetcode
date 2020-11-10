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
  ListNode *r = temp;
  temp->val = 0;
  int value = 0;
  
  //std::cout << l1->val << std::endl;
  //std::cout << l2->val << std::endl << std::endl;
  
  while(l1 != nullptr){
    if(l2 != nullptr){
      temp->val = temp->val + l1->val + l2->val;
      l2 = l2->next;
    }
    else
      temp->val += l1->val;
    
    if(temp->val >= 10){
      int tens = (temp->val / 10) % 10;
      int ones = temp->val % 10;
      std::cout << "temp->value = " << temp->val << "\ntens: " << tens << "\nones: " << ones << std::endl;
      value = 0;
      
      temp->next = new ListNode(tens);
      //temp->next->val += tens;
      temp->val = ones;
      
      std::cout << "temp->value = " << temp->val << "\ntemp->next->val: " << temp->next->val << std::endl << std::endl;
      
//       //make sure the next node is available, otherwise make one
//       if(l1->next != nullptr){
//         l1->next->val += tens;
//         //l1->val = value % 10;
//         //temp->val = tens;
//       }
//       else{
//         ListNode temp2(tens);
//         l1->next = &temp2;
//         l1->next->val += tens;
//       }
//       l1->val = value % 10;
//       //std::cout << "value = " << value << std::endl;
//       value = 0;
    }
    
    //std::cout << "l1->val = " << l1->val << std::endl;
    temp = temp->next;
    l1 = l1->next;
  }
  
  
  return r;
};

int main(){
//   ListNode l1d(8);
//   ListNode l1c(3, &l1d);
//   ListNode l1b(4, &l1c);  
//   ListNode l1a(2, &l1b);
//   
//   ListNode l2c(4);
//   ListNode l2b(6, &l2c);  
//   ListNode l2a(5, &l2b);
  
  ListNode l1g(9);
  ListNode l1f(9, &l1g);
  ListNode l1e(9, &l1f);
  ListNode l1d(9, &l1e);
  ListNode l1c(9, &l1d);
  ListNode l1b(9, &l1c);  
  ListNode l1a(9, &l1b);
  
  ListNode l2d(9);
  ListNode l2c(9, &l2d);
  ListNode l2b(9, &l2c);  
  ListNode l2a(9, &l2b);
  
  
  //temporary listnode for traversal
  ListNode* temp = &l1a;
  
  
  while(temp != nullptr){
    std::cout << temp->val << std::endl;
    
    //advance pointer along list
    temp = temp->next;
  }
  
  ListNode* x = addTwoNums(&l1a, &l2a);
  while(x != nullptr){
    std::cout << x->val << " ";
    
    //advance pointer along list
    x = x->next;
  }
  std::cout << std::endl;
  return 0;
}

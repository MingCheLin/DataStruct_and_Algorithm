#include <iostream>

using namespace std;

class ListNode{
public:
      int val;
      ListNode *next = NULL, *pre = NULL;
      ListNode(){
            this->val = 0;
      }
      ListNode(int val){
            this->val = val;
      }
};

class LinkedList{
private:
      void createLL(int val){
            size++;
            ListNode* temp = new ListNode(val);
            head = temp;
            tail = temp;
      }
public:
      int size;
      ListNode *head, *tail;
      LinkedList(){
            size = 0;
      };
      LinkedList(int val){
            createLL(val);
      };
      void pushFront(int val);
      void pushBack(int val);
      int getFront();
      int getBack();
      int popLeft();
      int popRight();
};

void LinkedList::pushFront(int val){
      if (size == 0){
            createLL(val);
            return;
      }
      size++;
      ListNode *newNode = new ListNode(val);
      newNode->next = head;
      head->pre = newNode;
      head = newNode;
}

void LinkedList::pushBack(int val){
      if (size == 0){
            createLL(val);
            return;
      }
      size++;
      ListNode *newNode = new ListNode(val);
      tail->next = newNode;
      newNode->pre = tail;
      tail = newNode;
}

int LinkedList::getFront(){
      if (size == 0){
            return -1;
      }
      return head->val;
}

int LinkedList::getBack(){
      if (size == 0){
            return -1;
      };
      return tail->val;
}

int LinkedList::popLeft(){
      if (size == 0){
            return -1;
      };
      int res = head->val;
      head = head->next;
      delete head->pre;
      head->pre = NULL;
      return res;
}

int LinkedList::popRight(){
      if (size == 0){
            return -1;
      }
      int res = tail->val;
      tail = tail->pre;
      delete tail->next;
      tail->next = NULL;
      return res;
}

int main()
{
    LinkedList x = LinkedList();
    x.pushBack(5);
    x.pushBack(6);
    x.pushBack(7);
    x.pushFront(4);
    x.pushFront(3);
    x.pushFront(2);
    x.pushFront(1);
    std::cout << x.popLeft() << std::endl;
    std::cout << x.popLeft() << std::endl;
    std::cout << x.popLeft() << std::endl;
    std::cout << x.popRight() << std::endl;
    std::cout << x.popRight() << std::endl;
    std::cout << x.popRight() << std::endl;
    std::cout << x.getBack() << std::endl;
    std::cout << x.getFront() << std::endl;
    x.pushBack(7);
    x.pushFront(1);
    std::cout << x.getBack() << std::endl;
    std::cout << x.getFront() << std::endl;
    return 0;
}

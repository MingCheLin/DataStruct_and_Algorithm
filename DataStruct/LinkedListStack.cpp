#include <iostream>

using namespace std;
class LinkedList;

class ListNode{
private:
      ListNode* next;
      int val;
public:
    ListNode(){
        next = NULL;
        this->val = val;
    }
    ListNode(int val){
        next = NULL;
        this->val = val;
    }

      friend class LinkedList;
};

class LinkedList{
private:
      int size=0;
      ListNode *head, *tail;
public:
      LinkedList(){
            head = NULL;
            tail = NULL;
      }
      int pop();
      void push(int val);
};

int LinkedList::pop(){
      if (size == 0){
            return 0;
      }
      else{
            int temp = head->val;
            ListNode* next = head->next;
            delete head;
            head = next;
            size--;
            return temp;
      }
}
//  與queue最大不同在於queue push是將新資料置於最後，但stack將新資料置於首端，以此達成FILO
void LinkedList::push(int val){
      ListNode* newNode = new ListNode(val);
      if (size == 0){
            head = newNode;
            tail = newNode;
      }
      else{
            newNode->next = head;
            head = newNode;
      }
      size++;
};

int main()
{
    LinkedList x = LinkedList();
    cout<<x.pop()<<endl;
    x.push(10);
    x.push(11);
    x.push(100);
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
    x.push(101);
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
}

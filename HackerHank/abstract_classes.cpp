#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
   private:
      void sort(Node* n){
         if(head == NULL){ //When list is empty
            head = n;
            tail = n;
            return;
         }
         if(head->next == NULL){ //Just one item on the list
            head = n;
            head->next = tail;
            tail->prev = head;
            return;
         }
         if(n == head){ //n is first item on the list
            return;
         }
         if(head->next == tail && (n==head || n==tail) ){ //Modifying list that has just two items
            Node* temp = head;
            head = tail;
            tail = temp;
            head->next = tail->next;
            tail->next = NULL;
            tail->prev = head->prev;
            head->prev = NULL;
            return;
         }
         if(n->next == NULL && n->prev != NULL){ //n is last item on the list
            n->prev->next = NULL;
            tail = n->prev;
            n->next = head;
            n->prev = NULL;
            head->prev = n;
            head = n;
            return;
         }
         if(n->next == NULL && n->prev == NULL){ //adding new item to the list
            n->next = head;
            head->prev = n;
            head = n;
            return;
         }
         n->prev->next = n->next; //Taking item from middle to head of the list
         n->next->prev = n->prev;
         n->prev = NULL;
         n->next = head;
         head->prev = n;
         head = n;
      }
   public:
      LRUCache(int capacity){
         cp = capacity;
         tail = NULL;
         head = NULL;
      }
      void set(int key, int value){
         if(mp.find(key) != mp.end() ){ //If key exists -> update
            mp[key]->value = value;
            sort(mp[key]);
         }else{                         //If key !exist -> create
            if(mp.size() == cp){
               mp.erase(tail->key);
               Node* temp;
               temp = tail->prev;
               delete tail;
               temp->next = NULL;
               tail = temp;
            }
            Node* temp = new Node(key,value);
            mp.insert(make_pair(key,temp) );
            sort(mp[key]);
         }
      }
      int get(int key){
         if(mp.find(key) != mp.end() ){
            sort(mp[key]);
            return mp[key]->value;
         }else{
            return -1;
         }
      }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

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
         if(n->prev == NULL) return;
         n->prev->next = n->next;
         n->next->prev = n->prev;
         n->prev = NULL;
         n->next = head;
         head = n;
      }
   public:
      LRUCache(int capacity){
         cp = capacity;
         tail = new Node(2,0);
         head = new Node(NULL,tail,1,0);
         tail->prev = head;
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
            Node* temp = new Node(head,tail,key,value);
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

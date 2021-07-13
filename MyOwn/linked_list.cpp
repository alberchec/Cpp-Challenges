#include <iostream>

template <class T>
class Node {
	public:
		T data;
		Node* next;
		Node(T &dt, Node* nxt) : data(dt), next(nxt){}
};

class Linked_list {
	public:
		
};

int main(){
	std::string empty_string="";
	std::string fs="First String";
	std::string ss="Second String";
	std::string ts="Third String";

	Node<std::string> start(empty_string,NULL),c(ts,&start),b(ss,&c),a(fs,&b);
	start.next = &a;

	std::cout << a.next->next->next->next->data << std::endl;
}
#include <ostream>

template <typename T> 
class Node {
    public:
        // miembros públicos
  	T data;
      	Node<T>*;
	Node(T data, Node<T>* next=nullptr);
	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node);	
};

Node(T data, Node<T>* next=nullptr){

}

friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
        out << data << "\n";
        }

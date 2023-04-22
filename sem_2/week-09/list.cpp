#include <utility>
#include <cstddef>
#include <iostream>
#include <ostream>

template <class T>
class List {
	struct Node {
		T	  value;
		Node *next;
		Node(const T &value, Node *next) : value(value), next(next) {}
	};

	Node	   *first;
	Node	   *last;
	std::size_t size;

	void copy(const List &other) {
		Node *other_curr = other.first;
		Node *curr		 = nullptr;
		while (other_curr != nullptr) {
			Node *new_node = new Node(other_curr->value, nullptr);
			if (this->first == nullptr) {
				this->first = new_node;
				curr		= this->first;
			} else {
				curr->next = new_node;
				curr	   = new_node;
			}
			other_curr = other_curr->next;
			++size;
		}
	}

	void copyWithPush(const List &other) {
		Node *curr = other->first;
		while(curr != nullptr) {
			this->push_back(curr->value);
			curr = curr->next;
		}
	}

   public:
	List() : first(nullptr), last(nullptr), size(0) {}
	List(const List &other) : List() { copy(other); }
	~List() { clear(); }
	List &operator=(const List &other) {
		clear();
		copy(other);
	}

	List &push_back(const T &elem) {
		Node *new_node = new Node(elem, nullptr);
		if (this->first == nullptr) {
			this->first = new_node;
			return *this;
		} 
		Node *curr = this->first;
		while(curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new_node;
		return *this;
	}

	List &push_front(const T &elem) {
		this->first = new Node(elem, this->first);
		return *this;
	}

	void clear() {
		while(this->first != nullptr) {
			delete std::exchange(this->first, this->first->next);
		}
	}

	void print(std::ostream & os) {
		Node *curr = this->first;
		while(curr != nullptr) {
			os << curr->value << ' ';
			curr = curr->next;
		}
		os << std::endl;
	}
};

int main() {
	List<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.print(std::cout);
	List<int> l2 = list;

	list.clear();
	list.print(std::cout);

	l2.print(std::cout);
}

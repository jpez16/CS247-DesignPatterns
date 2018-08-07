#include <iostream>
#include <vector>
#include <algorithm>


class Node {
private:
	std::string data_;
	Node* next_;

public:

	class iterator {
		friend class Node;
		Node* curr_;
		explicit iterator(Node *p) : curr_(p) {}
	public:
		Node* getCurr() const {
			return curr_;
		}
		iterator& operator++() {
			curr_ = curr_->getNext();
			return *this;
		}
		bool operator==(const iterator& i) {
			return curr_ == i.getCurr();
		}
		bool operator!=(const iterator& i) {
			return curr_ != i.getCurr();
		}
		std::string operator*(){
			return curr_->getData();
		}
	};

	iterator begin() {
		return iterator(this);
	}

	iterator end() {
		return iterator(nullptr);
	}

	Node(std::string data) : data_(data), next_(nullptr) {}
	Node(std::string data, Node* next) : data_(data), next_(next) {}

	std::string getData() const {
		return data_;
	}

	Node* getNext() const {
		return next_;
	}

	void setData(std::string data) {
		data_ = data;
	}

	void setNext(Node* next) {
		next_ = next;
	}
};

std::ostream& operator<<(std::ostream& out, const Node& node) {
	out << node.getData();
	return out;
}



int main(int argc, const char * argv[]) {

	Node* n1 = new Node("n1", new Node("n2", new Node("n3", new Node("n4"))));
	std::cout << *n1 << std::endl;

	for (auto i : *n1) {
		std::cout << i << std::endl;
	}

    return 0;
}
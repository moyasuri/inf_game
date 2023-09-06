
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class Node
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) :_next(nullptr),_prev(nullptr), _data(value)
	{

	}

public:
	Node* _next;
	Node* _prev;
	T     _data;
};


// [1]<->[2]<->[3]<->[header]<->
template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List()
	{
		// TODO
	}

	void push_back(const T& value)
	{
		AddNode(_header, value);

	}
	//   < ->[header] < ->
	// [1]<->[2]<->[before]<->[4]<->[header]<->
	// [1]<->[2]-[value(node)]-[before]<->[4]<->[header]<->
	// 연결해주는 작업을 해야돼

	void AddNode(Node<T>* before, const T& value)
	{
		Node<T>* node = new Node<T>(value);
		
		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;
		
		node->_next = before;
		before->_prev = node
		
		_size++;

	}





public:
	Node<T>* _header;
	int _size;
};



int main(void)
{
	list<int> li;
	list<int>::iterator eraseit;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseit = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}

	}

	li.pop_back();

	li.erase(eraseit);

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << (*it) << endl;
	}


	return 0;

}
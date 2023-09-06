
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node
{

public:
	Node* _next; // 리스트 다음친구에게도 또 다른 노드가 있을테니 (포인터!)
	Node* _prev; // 이중 리스트
	// 처음에 좀 헷갈리면 void*포인터로 생각해보자
	int _data;
};


int main()
{



	return 0;

}
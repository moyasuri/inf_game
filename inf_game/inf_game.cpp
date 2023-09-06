
#include <iostream>
#include <vector>
#include <list>

using namespace std;


// 주제 : list
// vector 동적배열, list 노드방식->tree 등 다른방식의 초석?

// vector [       ] capacity 만큼 데이터를 모아놨다가 더커지면
// vector [                        ] 더커진 capa를만들고 복사 붙여넣기를 해
// 단일 / 이중 / 원형
// list : 연결 리스트 !!!

// list의 특징!
// [1] ->link [2] -> [3] -> [4] -> [5]  // 단일
// [1] <->link [2] <-> [3] <-> [4] <-> [5] // 이중
// [1] <->link [2] <-> [3] <-> [4] <-> [5] <->...[1] // 원형
// 연속된 공간에 배치되어야 된다는 강제성이 없어


// Node2 [ int 4yte, next(data int 4byte , next))......] 이건 문법적으로 말이안돼
class Node2
{

public:
	// Node2 _next; // 봐 이건 통과 안되잖아
	int _Data;
};


// Node[ int 4 byte _next(4 or 8byte)] -> Node [int 4byte _next(4 or 8byte)] -> ....

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
	// list (연결 리스트)
	//	- 리스트의 동작원리
	//	- 중간 삽입 삭제
	//	- 처음 끝 삽입 삭제
	//	- 임의접근

	list<int> li;
	for (int i = 0;i < 100; i ++ )
	{
		li.push_back(i);

	}

	li.push_front(10);
	// vector는 push front를 지원하지 않았어, 굉장히 비효율적이야.

	int size = li.size();
	// li.capacity(); // 용량의 개념이 아니군 , 없어
	
	int fitst = li.front();
	int last = li.back();

	// li[3] = 10; // 없음

	list<int>::iterator itBegin; // iterator는 사용할 수 있어, 근데 동작방식은 vector랑 완전히 다를거야
	itBegin= li.begin();  // 나눠 쓰기


	list<int>::iterator itEnd = li.end(); // 선언+초기화
	
	for (list<int>::iterator it = li.begin();it != li.end(); it++)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	
	li.erase(li.begin()); // 어떤 위치에 있는 애를 삭제할때 쓰는데, 첫번쨋걸 삭제한경우
	
	li.pop_front(); // 첫번째껄 삭제할때는 이걸 더 많이 쓴다.
	 
	li.remove(10); // -> 10이랑 같은 값을 다 삭제해줘, 벡터는 애초에 중간 삭제가 너무 비효율적이야, 그리고 다돌아가면서 체크해줘야하니까
	// 그래서 지원을 안해준듯.









	return 0;

}
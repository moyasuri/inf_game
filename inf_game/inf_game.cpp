
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
// [1] <->link [2] <-> [3] <-> [4] <-> [5] // 이중 근데 사실 [5] <-> 무언가가 더있어 [_MyHead : end()] dummy node인거지 유효범위체크를 하는 노드임
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
	// 
	// 
	// -> vector가 우선순위로 사용한다는건 단점이 있다는건데 임의 접근을보자.
	//	- 임의접근 ->li[10000]? 안돼 하나하나 계속 타고가야되는거니까 굉장히 비효율적이야 그래서 막혀있는거지
	//








	list<int> li;
	for (int i = 0;i < 100; i ++ )
	{
		li.push_back(i);

	}

	// li.push_front(10);
	// vector는 push front를 지원하지 않았어, 굉장히 비효율적이야.

	int size = li.size();
	// li.capacity(); // 용량의 개념이 아니군 , 없어
	
	int fitst = li.front();
	int last = li.back();

	// li[3] = 10; // 없음

	list<int>::iterator itBegin; // iterator는 사용할 수 있어, 근데 동작방식은 vector랑 완전히 다를거야
	itBegin= li.begin();  // 나눠 쓰기
	list<int>::iterator itEnd = li.end(); // 선언+초기화

	// list<int>::iterator it2 = itBegin + 10;
	// ++ 은 가능하지만 +10은 불가능해 다음 노드는 알지만 순차적으로 배열된게아니기 때문이야.



	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	// test를 한번해보자

	// list<int>::iterator itTest1 = --itBegin; // 에러가 나.   [_MyHead : end()] <-> [0] 이게 아니라는이야기야
	list<int>::iterator itTest2 = --itEnd; // [last]<->[_MyHead : end()] 이건 가능해 
	// list<int>::iterator itTest3 = ++itEnd; // crash [_MyHead : end()] <-> [0] 이게 아니라는이야기야

	
	
	for (list<int>::iterator it = li.begin();it != li.end(); it++)
	{
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);
	//
	//li.erase(li.begin()); // 어떤 위치에 있는 애를 삭제할때 쓰는데, 첫번쨋걸 삭제한경우
	//
	//li.pop_front(); // 첫번째껄 삭제할때는 이걸 더 많이 쓴다.
	// 
	//li.remove(10); // -> 10이랑 같은 값을 다 삭제해줘, 벡터는 애초에 중간 삭제가 너무 비효율적이야, 그리고 다돌아가면서 체크해줘야하니까
	// 그래서 지원을 안해준듯.






	// 임의 접근이 안되는데
	// 중간 삽입 삭제는 빠르다?

	// 50번째데이터 삭제해보자.
	
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50;i++)
	{ 
		++it;  // 결국 이과정은 빠르지않아 #1
	}


	// li.erase(li.begin()+50); // 이거 안된다고햇지
	li.erase(it); // #1  벡터에 비해 복사 붙여넣기가 생략되는 단순 이작업이 빠르다는것이지.
	// 근데만약, it 를 미리 알고 있다면, 마킹을 해줄 수 있잖아
	
	
	list<int>::iterator mark;

	li.erase(mark);
	//for (int i = 0;i < 100; i++)
	//{
	//	if (i == 50)
	//	{
	//		// insert 자체가 iterator를 반환해주는구나 
	//		mark = li.insert(li.end(), i); // 50번째에 =(li.end) , 50을 넣고 그때의 iterator를 반환

	//	}
	//	else
	//	{
	//		li.push_back(i);
	//	}

	//}




	return 0;

}

#include <iostream>
#include <vector>

using namespace std;


// 주제 : vector
int main() {

	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘드릉ㄹ
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체(자료구조) = data Structure 자료를 어떤식으로 저장할 것인가?
	
	// vector (동적 배열) (C# 같은경우 list, C++에는 vector ... 언어마다있음)
	// - vector의 동작 원리 (size / capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 배열
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };
	
	// 사용자가 늘어나거나 줄어드는걸 일일히 관리를 못해주는 문제점.

	for (int i = 0; i < MAX_SIZE; i++)
		arr[i] = i;
	for (int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << endl;


	// 동적 배열! 사용하기 위해서는 vector 또 std 안해놧다면 std::vector
	vector<int> v; // 사이즈가 변경이 가능해.
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v[3] = 3; // 배열문법 사용가능함
	const int size = v.size();
	for (int i = 0; i < v.size();i++)
	{
		cout << v[i] << endl;
	}

	// 동적배열은 어떤 원리로 동작하는가?

	// 1) 여유분을 두고 메모리를 할당한다.
	// 2) 여유분도 꽉찼다면 메모리를 증설한다.
	// [ 필요분  ]        여유분       ]  처럼 만드는데.. 밑에 배열도 비슷하잖아? ---1.

	int arr0[100] = {}; // stack
	 
	int *arr2 = new int[100]; // heap
	delete arr2;
	int *arr3 = new int[1000]; // 이런식으로 증설한다.
	delete arr3;

	// Q1. 여유분은 얼마나 적당한가?
	// -> 현재 capacity의 비례한(ex 1.5배, 2배)만큼 !
	// Q2. 증설은 얼마나 해야하는가?
	// Q3. 기존에 있던 메모리를 삭제하고 덮어씌우고 증설하는지? 아니면 기존의 메모리는 놔두고 덧붙여서 증설하는지?
	//		-> 기존 데이터처리방법에 관한 질문.
	//		-> 기존 데이터를 더 큰 용량에 완전히 복사한다.(복사비용 발생)

	vector<int> v2;
	v2.capacity();
	
	// size는 실제 사용 데이터 개수
	// capacity (여유분을 포함한 용량 개수)
	
	for (int i = 0;i < 1000;i++)
	{
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;

	}


	// 만약 처음부터 어느정도 용량을 안다고치면.
	// v2.reserve(1000); 처음부터 1000개부터시작해.
	// 더넣어주기 시작한다면 다시 1500으로 늘어나.

	// 단, 사이즈가 늘어나는건 아냐, 걍 여유분이 1000개라는것이지.
	
	
	vector<int> v3;
	v3.resize(1000); // v3를 만들고 1000개로 재정의 해주세요. -> 이건 실제 사이즈가 1000이라는 이야기
	// 당연하게도 캐퍼도 같이 늘어나겠지? 얼마나 늘어나느냐는... 1.5배일려나? 확인해보자.

	cout << v3.capacity() << endl;
	// -> 캐퍼 1000이네, (reserve 하지 않았음, 또한 1000이상으로 늘어나지않았음) push back 해보자.


	// 근데 만들고 리사이즈 하는게아니라, 생성부터 초기화 할 수 있어.
	// vector<int> v3(1000);
	// vector<int> v3(1000,0); 1000개의 사이즈 다 0을 집어넣도록
	// vector<int> v4=v3; 복사




	for (int i = 0;i < 1000;i++)
	{
		// v3.push_back(100); // 이미 할당 받은 영역을 사용하려면, 이제 뒤에 붙이는게 아니고
		v3[i] = 100;  // 배열의 느낌처럼 써줘야된다.
 		cout << v3.size() << " " << v3.capacity() << endl;

	}

	// 면접 질문 왜, reserve로 많은 데이터 영역을 잡아놓는가?
	// -> 본래 존재했었던 capacity보다 많은 데이터가 들어오게되면 그때마다 capacity를 늘리기 위하여 복사프로세스가 진행이되는데
	// 이때 자원이 아까우니, 미리 어느정도의 데이터가 들어올지 알고 있다면 여유분을 포함하여 reserve해놓는게 좋다.
	
	// 그런데, 데이터가 필요가 없어져서 데이터를 지워도, capacity가 역으로 줄어드는 일은 없다.

	v3.clear(); // 모든 데이터를 사용안하겠다.

	cout << v3.size() << " " << v3.capacity() << endl;
	
	// 그렇다면 capacity를 줄일려면 어찌해야하는가?
	vector<int>().swap(v3); // vector<int>() 아무것도 갖고 있지 않은애를, v3랑 모든 요소를 바꿔보자.
	// -> 또한 사용하고 나서 임시벡터였던 vector<int>()는 소멸이되어
	// -> 그런데 실무에서도 이런식으로 메모리를 초기화시킬일이 별로 없어, 왜냐하면 캐퍼가 늘어났다는 이야기는
	// 언제든지 다시 그러한 일이 발생할 수도 있다는 이야기기때문에.
	
	
	v3.front();

	v3.back();

	v3.pop_back();
	



	return 0;
}
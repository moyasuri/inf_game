
#include <iostream>
#include <vector>

using namespace std;



//typedef int ab;
//using test = int;

class MyIterator
{
public:
	

};

class MyVector
{
public:
	typedef MyIterator iterator;
	// c++11 using 문법을 쓰고 있다.
};

// 주제 : vector
int main() {


	// container 데이터를 저장하는 객체
	// 
	// 각 컨테이너마다 반복자라는걸 하나씩 들고 있다.
	// 
	// 반복자(iterator) -> 포인터와 유사한개념, 컨테이너의 원소(데이터)를 가리키고 , 다음 /이전 원소로 이동 가능

	vector<int> v(10);
	for (int i = 0;i < static_cast<unsigned int>(v.size());i++) // 혹은 vector<int>::size_type i=0;
	{
		
		v[i] = i;
	}

	vector<int>::iterator it;
	// list, map.. 등등 container들이 각각 똑같은 이름으로 iterator로 되어있다.

	MyVector::iterator it2; // 대강 이렇게 되어있을거라는 예쩨

	
	int* ptr;
	ptr = &v[0];
	it = v.begin(); 
	
	cout << (*it) << endl;
	cout << (*ptr) << endl;

	// 조사식에서 ptr의값을 받고, 그값을 메모리에서 확인해보면 0~9까지 들어가있는걸 확인할수있어.
	// 조사식에서 it의 값을보면, ptr의 값은 당연히 있고 그외에 여러가지 myproxy 등등.. 추가적인값이 들어가 있다.
	// 따지고보면 왜 굳이 포인터 쓰면 되지 iterator라는걸 쓰는 걸까?
	// iterator는 포인터가아닌데 어떻게 포인터처럼 쓸 수 있는건가?
	// operator overloading
	// iterator자체는 클래스이지만 *를 붙여줌으로써 같은 역할을 하게끔 만든거야


	// _Tptr _Ptr; // pointer to element in vector
};


	return 0;
}
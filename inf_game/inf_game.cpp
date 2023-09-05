
#include <iostream>
#include <vector>

using namespace std;


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



	return 0;
}
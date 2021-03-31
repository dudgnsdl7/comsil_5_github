#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
//LinkedList 함수에서 사용한 템플릿을 다시 정의해 주어야 LinkedList class를 상속받을 수 있다.
class Stack : public LinkedList<T> {
	public:
		bool Delete (int &element){
			//class 변수에 저장된 node가 없을 경우 false를 반환
			if(this -> first == 0) {
				return false;
			}
			//입력받은 주소에 처음 노드에 저장된 값을 반환
			element = this -> first -> data;
			//새로운 노드 next를 정의하고 그곳에 처음 노드에 저장되어 있는 다음 노드의  주소를 저장
			Node<T> *next = this -> first -> link;
			//처음 노드를 해제
		        delete this -> first;
			//next에 저장되어 있는 주소값을 first에 저장하여 초기 노드로 설정
			this -> first = next;
			//총 노드의 수를 수정
			this -> current_size--;
			return true;
			}
};

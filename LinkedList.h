#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;
//세로운 데이터형인 T를 정의
template <typename T>
//노드를 정의하는 class
class Node{
	public:
		//저장되는 변수의 데이터형을 T로 설정
		T data;
		//다음 노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

//새로운 데이터형인 T를 정의
template <typename T>
class LinkedList{
	protected:
		//템플릿에 의해 선언된 T가 사용될 것을 표시
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
//새로운 데이터형인 T를 정의
template <class T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해
//새로운 데이터형인 T를 정의
template <class T>
bool LinkedList<T>::Delete(T &element) {

	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
//새로운 대이터형인 T를 정의
template <class T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif

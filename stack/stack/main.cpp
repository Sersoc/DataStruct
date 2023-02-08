//
//  main.cpp
//  stack
//
//  Created by 이재익 on 2023/02/08.
//

#include <iostream>
using namespace std;
/*
 자료구조 stack 구현 LIFO의 성격을 가지고 있다.
 */


/*
 stack 구조체 선언
 */
template<typename T>
class stack{
private:
    T data;
    
public:
    stack<T>* previous = NULL;
    stack<T>* next = NULL;
    stack<T>* top = NULL;
    
    T pop();
    void push(T item);
    T peek();
    bool isEmpty();
    static stack<T>* create(T data);
};
/*
 stack을 생성하는 create 함수
 */
template<typename T>
stack<T>* stack<T>::create(T data){
    stack<T>* st = new stack<T>;
    st->data = data;
    st->next = NULL;
    return st;
}
/*
 top의 data값을 반환하고 top을 제거하는 pop함수
 */
template<typename T>
T stack<T>::pop(){
    if(top==NULL) return 0;
    T data = top->data;
    top = top->next;
    return data;
}
/*
 stack에 data값을 집어넣는 push함수
 top에 아무값도 없으면 top에 값을 집어넣고
 top에 값이 있다면 앞에 데이터 값을 집어넣고 top의 위치를 previous로 바꿔준다
 */
template<typename T>
void stack<T>::push(T item){
    if(top==NULL)
        top = stack<T>::create(item);
    else{
        stack<T>* current = top->previous;
        current = stack<T>::create(item);
        current->next = top;
        top = current;
    }
        
}
/*
 top의 값을 반환하는 peek함수
 */
template<typename T>
T stack<T>::peek(){
    return top->data;
}
/*
 stack이 비어있는지 확인하는 함수 isEmpty
 */
template<typename T>
bool stack<T>::isEmpty(){
    if(top==NULL)
        return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    stack<int> st;
    stack<int> st2;
    cout << st.isEmpty()<< endl;
    st.push(1);
    st.push(2);
    st.push(5);
    cout << st2.isEmpty()<<endl;
    cout << st.pop() << st.peek();
    return 0;
}

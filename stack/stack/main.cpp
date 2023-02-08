//
//  main.cpp
//  stack
//
//  Created by 이재익 on 2023/02/08.
//

#include <iostream>
using namespace std;
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
template<typename T>
stack<T>* stack<T>::create(T data){
    stack<T>* st = new stack<T>;
    st->data = data;
    st->next = NULL;
    return st;
}
template<typename T>
T stack<T>::pop(){
    if(top==NULL) return 0;
    T data = top->data;
    top = top->next;
    return data;
}
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
template<typename T>
T stack<T>::peek(){
    return top->data;
}
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


#ifndef stack_h
#define stack_h



using namespace std;
template <class T>
class Stack {        
public:
    Stack();
    Stack(const Stack & rhs);
    ~Stack();
    
    bool isEmpty() const;
    bool isFull() const;
    void makeEmpty();
    
    
    void pop();
    void push(const T & x);
    T topAndPop();
    const T & top() const;
    
    const Stack & operator=( const Stack & rhs );
    
private:
    
   

    struct Node{
        T data;
        Node *next;
        
        
        Node(const T & _data, Node * _next = NULL):data(_data),next(_next){}
    };
    
    
    Node *topOfStack;

};




template <class T>
Stack<T>::Stack() : topOfStack(nullptr) {} // constructor

template <class T>
bool Stack<T>::isFull() const {

    return false;
}


template <class T>
bool Stack<T>::isEmpty() const {             // if top of the stack is empty returns false
    return topOfStack == nullptr;
}

template <class T>
const T& Stack<T>::top() const {
    if (isEmpty()) {
        throw runtime_error("Underflow");
    }
    return topOfStack->data;
}


template <class T>
void Stack<T>::pop() {
    if (isEmpty())
        throw runtime_error("Underflow");
    Node* oldTop = topOfStack;
    topOfStack = topOfStack->next;
    delete oldTop;
    
}


template <class T>
void Stack<T>::push(const T& x) {
    topOfStack = new Node( x, topOfStack );
}

template <class T>
T Stack<T>::topAndPop() {
    T topData = top();
    pop();
    return topData;
}

template <class T>
void Stack<T>::makeEmpty() {
    while (!isEmpty()) {
        pop();
    }
}

template <class T>
const Stack<T> & Stack<T>::operator=( const Stack<T> & rhs )
{
      if ( this != &rhs )
      {
           makeEmpty( );
           if ( rhs.isEmpty( ) )
                return *this;

           Node *rptr = rhs.topOfStack;
           Node *ptr  = new Node( rptr->data );
           topOfStack = ptr;

           for ( rptr = rptr->next; rptr != NULL; rptr = rptr->next )
                 ptr = ptr->next = new Node( rptr->data );
    }
    return *this;
}
template <class Object>
Stack<Object>::~Stack( )
{
 makeEmpty( );
        }

#endif /* stack_h */

// Alecz0
#ifndef LIST
#define LIST
#include <memory>
#include <iostream>
#include <string>
#include <iterator>

template <typename T> class List;




template <typename T> class Node{
private:
    T value;
    std::shared_ptr<Node<T>> next;

    friend class List<T>;
};


template <typename T> class List{
public:
    // constructors

    List();
    List(std::initializer_list<T> L);


    //destructor

    ~List();


    // ____________________________________________________________________

    bool Empty(void) const noexcept;
    uint32_t Size(void) const noexcept;

    const T& Front() const;

    void PushFront(const T element);
    void PopFront(void);
    void Clear(void) noexcept;

    bool Find(T element) const;

    void DisplayList(void) const;


    //______________________________________________________________________

    //friend List<T> opeartor=(List&& Other){

   //}

    friend bool operator==(const List& A, const List&B){
        auto tempIteratorA = A.head,
             tempIteratorB = B.head;

        while(true) {
            if(tempIteratorA == nullptr && tempIteratorB != nullptr) return false;
            if(tempIteratorA != nullptr && tempIteratorB == nullptr) return false;
            if(tempIteratorA == nullptr && tempIteratorB == nullptr) return true;
            if(tempIteratorA->value != tempIteratorB->value) return false;
            
            tempIteratorA = tempIteratorA->next;
            tempIteratorB = tempIteratorB->next;
        }
    }
    
    
    struct Iterator: public std::iterator<std::input_iterator_tag, Node<T>> {
    public:
        Iterator(std::shared_ptr<Node<T>> ptr): ptr(ptr) {}

        T& operator*() {return ptr->value; }
        std::shared_ptr<Node<T>> operator->() { return ptr; }

        Iterator& operator++() { ptr = ptr->next; return *this; }
        Iterator operator++(T){ Iterator temp = *this; (*this)->next; return temp; }
        
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; }; 

    private:
        std::shared_ptr<Node<T>> ptr;
    };


    
    Iterator begin() {return Iterator(head); };
    Iterator end() {return Iterator(nullptr); };
    

private:
    std::shared_ptr<Node<T>> head;
    uint32_t size{0};

};




//______________________________________________________________________


template <typename T> List<T>::List(void) {
    head = nullptr;
}

template <typename T> List<T>::List(std::initializer_list<T> L) {
    for(auto Iterator: L)
        PushFront(Iterator);
}


template <typename T> List<T>::~List(){
    Clear();
}


// ______________________________________________________________________


template <typename T> bool List<T>::Empty(void) const noexcept{
    return head == nullptr;
}

template <typename T> uint32_t List<T>::Size(void) const noexcept{
    return size;
}


// ______________________________________________________________________


template <typename T> const T& List<T>::Front(void) const{
    return head->value;
}


// ______________________________________________________________________


template <typename T> void List<T>::PushFront(const T element){
    std::shared_ptr<Node<T>> v = std::make_shared<Node<T>>(); 
    v->value = element;
    v->next = head;
    head = v;
    size++;
} 


template <typename T> void List<T>::PopFront(void){
    if(Empty()){
        std::cerr << "Error: can't pop element from empty list\n";
        exit(1);
    }

    std::shared_ptr<Node<T>> old = head; 
    head = old->next;
    old.reset();
    size--;
}


template <typename T> void List<T>::Clear(void) noexcept {
    while(!Empty())
        PopFront();
}


// ______________________________________________________________________


template<typename T> void List<T>::DisplayList(void) const{
    auto Iterator = head;
    while(Iterator != nullptr){
        std::cout << Iterator->value << ' ';
        Iterator = Iterator->next;
    }
    std::cout << std::endl;
}


// ______________________________________________________________________


#endif

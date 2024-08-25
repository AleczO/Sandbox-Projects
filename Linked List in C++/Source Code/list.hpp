// Alecz0
#ifndef LIST
#define LIST
#include <memory>
#include <iostream>
#include <string>

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

    void DisplayList(void) const;

    //______________________________________________________________________

    friend bool operator==(const List& A, const List&B){
        auto IteratorA = A.head,
             IteratorB = B.head;

        while(true) {
            
            if(IteratorA == nullptr && IteratorB != nullptr)
                return false;

            if(IteratorA != nullptr && IteratorB == nullptr)
                return false;

            if(IteratorA == nullptr && IteratorB == nullptr)
                return true;
            

            if(IteratorA->value != IteratorB->value)
                return false;
            
            IteratorA = IteratorA->next;
            IteratorB = IteratorB->next;
        }

    }


private:
    std::shared_ptr<Node<T>> head;
    uint32_t size{0};

};




//______________________________________________________________________


template <typename T> List<T>::List() {
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

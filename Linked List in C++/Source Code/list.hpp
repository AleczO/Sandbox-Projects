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

    List(void);
    List(std::initializer_list<T> L);

    ~List();

    //List<T>& operator=(List<T>&& other);


    // ____________________________________________________________________

    const T& Front() const;

    // ____________________________________________________________________


    bool Empty(void) const noexcept;
    uint32_t Size(void) const noexcept;

    // ____________________________________________________________________

    void PushFront(const T element);
    void PopFront(void);
    void Clear(void) noexcept;

    // ____________________________________________________________________

    bool Find(T element) const;
    void Display(void) const;

    //______________________________________________________________________
    
    
    iterator begin() {return iterator(head); }
    iterator end() {return iterator(nullptr); }

    const_iterator cbegin() const {return const_iterator(head); }
    const_iterator cend() const {return const_iterator(nullptr); }


    class iterator {
    public:
        iterator(std::shared_ptr<Node<T>> ptr): ptr(ptr) {}

        T& operator*() {return ptr->value; }
        std::shared_ptr<Node<T>> operator->() { return ptr; }

        iterator& operator++() { ptr = ptr->next; return *this; }
        iterator operator++(T){ iterator temp = *this; ptr = ptr->next; return temp; }
        
        friend bool operator== (const iterator& a, const iterator& b) { return a.ptr == b.ptr; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a.ptr != b.ptr; }; 

    private:
        std::shared_ptr<Node<T>> ptr;
    };
    


    class const_iterator {
    public:
        const_iterator(std::shared_ptr<Node<T>> ptr): ptr(ptr) {}
        
        const_iterator operator++() { ptr = ptr->next; return (*this); }
        const_iterator operator++(T) { const_iterator temp = *this; ptr = ptr->next ; return temp; }
        const T& operator*() const{ return ptr->value; }
        
        bool operator==(const_iterator rhs) {return this->ptr == rhs.ptr; }
        bool operator!=(const_iterator rhs) {return this->ptr != rhs.ptr; }

    private:
        std::shared_ptr<Node<T>> ptr;
    };

    // _____________________________________________________________________________

    

private:
    std::shared_ptr<Node<T>> head;
    uint32_t size{0};
};




//______________________________________________________________________


template <typename T> List<T>::List(void) {
    head = nullptr;
}

template <typename T> List<T>::List(std::initializer_list<T> L) {
    for(auto iter = std::rbegin(L); iter != std::rend(L); ++iter )
        PushFront(*iter);
}

template <typename T> List<T>::~List(){
    Clear();
}

// ______________________________________________________________________

template <typename T> const T& List<T>::Front(void) const{
    return head->value;
}


// ______________________________________________________________________


template <typename T> bool List<T>::Empty(void) const noexcept{
    return head == nullptr;
}

template <typename T> uint32_t List<T>::Size(void) const noexcept{
    return size;
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


template<typename T> void List<T>::Display(void) const{
    auto iter = head;
    while(iter != nullptr){
        std::cout << iter->value << ' ';
        iter = iter->next;
    }
    std::cout << std::endl;
}


// ______________________________________________________________________


template<typename T> bool operator==(const List<T>& lhs,const List<T>& rhs) {
    auto    lhsIter = lhs.cbegin(),
            rhsIter = rhs.cbegin();
    
    while(true) {
        if(lhsIter == lhs.cend() && rhsIter != rhs.cend()) return false;
        if(lhsIter != lhs.cend() && rhsIter == rhs.cend()) return false;
        if(lhsIter == lhs.cend() && rhsIter == rhs.cend()) return true;

        if(*lhsIter != *rhsIter) return false;

        lhsIter++;
        rhsIter++;
    }
    
    //return 0;
}


#endif

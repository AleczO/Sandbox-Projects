# Linked List in C++

## Description



## Documentation



### Member functions

[(constructor)](#constructor)

[(destructor)](#destructor)


#### Element Access

[Front](#front)

#### Iterators

[begin - cbegin](#begin---cbegin--iterator)


#### Capacity

[Empty](#empty)


[Size](#size)

#### Modifiers

[Clear](#clear)

[PushFront](#pushfront)

[PopFront](#popfront)


### Non-Member Function




<br><br><br>

---
<!--- ____________________________________________________________ --->

<br><br><br>

### constructor

<details> 
<summary>  </summary>

 
```C++
1. List();
```

```C++
2. List(std::initializer_list<T> L);
```


##### Example

```c++
#include <iostream>
#include <string>
#include "List.hpp"

int main(){
    // Default constructor
    List<int> L1;

    // Initializer list constructor
    List<std::string> L2 = {"Hello", "There", "General"};
    
    cout << "L2: ";
    L2.Display();
}
```

##### Output

```
    L2: Hello There General
```


<br>
</details>

### destructor


<details>
<summary> </summary>

<br>

```c++
~List()
```

List destructor. Clears the list elements and deallocates memory used by it.

</details>


### Front

<details>
<summary>  </summary>

```c++
const T& Front() const;
```

##### Example

```c++
#include "list.hpp"

int main(){
    List<int> L{1,2,3,4,5};

    cout << List.Front() << '\n';
}
```

##### Output 

```c++
1
```

</details>

### begin - cbegin  Iterator

<details>
<summary>  </summary>

```c++
1. iterator begin();
```

```c++
2. const_iterator cbegin() const;
```

Returns an iterator to the first element of the list;

##### Retrn value
Iterator to the first element.

##### Example

```c++
#include <iostream>
#include "list.hpp"

int main() {
    List<int> Example{1,2,3,6};
    
    for(auto it: Example)
        std::cout << it << ' ';
    std::cout << '\n';

    std::cout << std::accumulate(Example.begin(), Example.end(), 0) << '\n';
}
```

##### Output
```
1 2 3 6
12
```

</details>

### end - cend Iterator

<details>
<summary> </summary>

```c++
1. iterator end();
```

```c++
2. const_iterator cend() const;
```

Returns an iterator to the element following the last element of the container

##### Return value

Iterator to the element after the last element

##### Example



```c++
#include <iostream>
#include "list.hpp"

int main() {
    List<int> Example{1,2,3,6};
    
    for(auto it: Example)
        std::cout << it << ' ';
    std::cout << '\n';

    std::cout << std::accumulate(Example.begin(), Example.end(), 0) << '\n';
}
```

##### Output
```
1 2 3 6
12
```

</details>

### Empty

<details>
<summary> </summary>

```c++
bool Empty() const noexcept;
```

Checks if the container is empty, `head = nullptr`

##### Return value

`true` if contanier empty, `false` otherwise.
<br>


##### Example

```c++
#include <iostream>
#include "list.hpp"

int main(){
    List<int> Example;

    std::cout << "List is initially empty thus, Example.Empty() returns " << Example.Empty() << '\n';

    Example.PushFront(10);

    std::cout << "Now list has element, thus returns " << Example.Empty() << '\n';

    return 0;
}
```

##### Output

```
List is initially empty thus, Example.Empty() returns 1
Now list has element, thus returns 0
```
</details>

### Size

<details>
<summary> </summary>

```c++
uint32_t Size(void) const noexcept;
```

Returns the count of element in the container

##### Return value

number of elements in container
<br>


##### Example

```c++
#include <iostream>
#include "list.hpp"

int main(){
    List<int> Example;

    std::cout << Example.Size() << '\n';

    Example.PushFront(10);
    Example.PushFront(20);
    Example.PushFront(30);

    std::cout << Example.Size() << '\n';

    Example.PopFront();

    std::cout << Example.Size() << '\n';
}
```

##### Output

```
0
3
2
```
</details>

### Clear

<details>
<summary> </summary>

```c++
void Clear(void) noexcept;
```

Erases all elemetns from the container, sets `Size()` to `0`

##### Example
```c++
#include <iostream>
#include "list.hpp"

int main() {
    List<int> Example{1,2,3};

    Example.Display();

    Example.Clear();
    Example.Display();

    std::cout << Example.Size() << '\n';
}

```
##### Answer

```
1 2 3 

0
```

</details>

### PushFront

<details>

<summary> </summary>

```c++
void PushFront(const T element);
```

inserts an element to the beginning

##### Parameters

value - the value of the element to add

##### Example



```c++
#include <iostream>
#include "list.hpp"

int main() {
    List<int> Example{1,2,3};

    Example.Display();

    Example.PushFront(1);

    Example.Display();

}
```

</details>

### PopFront

<details>
<summary> </summary>

```c++
void PopFront(void);
```

Removes the first element of the container. If there are no elements throws error.

##### Example

```c++
#include <iostream>
#include "list.hpp"


int main() {
    List<int> Example{1,2,3};

    Example.Display();

    Example.PopFront();

    Example.Display();
}
```

##### Output

```
1 2 3 
2 3
```



</details>



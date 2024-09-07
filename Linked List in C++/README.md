# Linked List in C++

## Description



## Documentation



### Member functions

[(constructor)](#constructor)

[(destructor)](#destructor)


### Element Access

[Front](#front)


### Capacity

[Empty](#empty)


[Size](#size)

### Modifiers

Clear

PushFront

PopFront


<br>

---
<!--- ____________________________________________________________ --->

#### constructor

<details> 
<summary>  </summary>

 
```c++
1. List();
```

```c++
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
    L2.DisplayList();
}
```

##### Output

```
    L2: Hello There General
```


<br>
</details>

#### desturctor


<details>
<summary> </summary>

<br>

```c++
~List()
```

List destructor. Clears the list elements and deallocates memory used by it.

</details>


#### Front

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

#### Empty

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

#### Size

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

#### Temp

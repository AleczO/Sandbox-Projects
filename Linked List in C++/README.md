# Linked List in C++

## Description


## Documentation


### Member functions

<details> 
<summary> (constructor) </summary>
<br>

 
```c++
1. List();
```

```c++
2. List(std::initializer_list<T> L);
```


#### Example

```c++
#include <iostream>
#include <string>
#include "List.hpp"

int main(){
    // Default constructor
    List<int> L1;

    // Initializer list constructor
    List<std::string> L2 = {"Hello", "There", "General"};
    
    std::cout << "L2 - " 
    L2.DisplayList();
}
```

#### Output

```
    L2
```



<br>
</details>
<br>

<details>
<summary> (destructor) </summary>

<br>

```c++
~List()
```

List destructor. Clears the list elements and deallocates memory used by it.

</details>

<br>

### Element Access



<details>
<summary> Front </summary>

```c++
const T& Front() const;
```


</details>

### Capacity

Empty

Size

### Modifiers

Clear

PushFront

PopFront



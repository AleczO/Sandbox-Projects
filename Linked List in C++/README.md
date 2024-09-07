# Linked List in C++

## Description


## Documentation


### Member functions

<details> 
<summary> (constructor) </summary>

 
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
    
    L2.DisplayList();
}
```

#### Output

```

```



<br>
</details>

(destructor)


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



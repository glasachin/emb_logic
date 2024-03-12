# Tuples in C++
It can store several different values of different data types.

## Syntax
```tuple <type_1, type_2,...> tuple_name```

``` 
using namespace std;
tuple <int, double, char> tp(4, 0.5, 'z');

or

tuple <char, int, int> tp1;
tp1 = make_tuple('a', 10, 20);

or

tuple<int , int> tp3 = make_tuple(1,20);

```

## Getting Elements from Tuple
we use `get()` to access tuple elements. We have `0` based indexing in tuples.

```
using namespace std;

int main () {
    // Declare and initialise tuple.
    tuple <int, double, char> tp(4, 0.6, 'z');
    // Print elements.
    cout << get<0>(tp) << "  " << get<1>(tp) << "  " << get<2>(tp);
    return 0;
}

```

**modifying the value**
```
// Modify the second element.
    get<1>(tp) = 0.1;
```

## Return type function

```
tuple<int, int> getValue() {
    tuple<int , int> tp4 = make_tuple(1,20);
    return tp4;
}
```

## Dynamic indexing
we can only use `constants` for refering to indexes, else it will result in a compilation error.

```
int index = 3; 
tuple <int, string, char, double> tp(6, "abc", 'a', 0.6);
string element = get<index>(tp);
cout << element;
```

The above code will give error. Correct way of doing the same is as follows:

```
tuple <int, char> tp(133, 'y');
const int idx = 1;
cout << get<idx>(tp);

```

## Other Functions

### tuple_size

```
#include <bits/stdc++.h>
using namespace std;

int main () {
    // Declare and initialise tuple.
    tuple <int, string, char, double> tp(6, "abc", 'a', 0.6);

    // tuple_size() called.
    cout << "The size of the tuple is = " << tuple_size<decltype(tp)>::value;

    return 0;
}

```

### Swap

```
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <int, char, double> tp1(1, 'a', 0.1); // First tuple
    tuple <int, char, double> tp2(2, 'b', 0.2); // Second tuple

    cout << "First tuple originally: " << get<0>(tp1) << ", " << get<1>(tp1) << ", " << get<2>(tp1) << endl;  
    cout << "Second tuple originally: " << get<0>(tp2) << ", " << get<1>(tp2) << ", " << get<2>(tp2) << endl;  
    cout << endl;
    
    // Swapping elements.
    tp1.swap(tp2);

    cout << "First tuple currently: " << get<0>(tp1) << ", " << get<1>(tp1) << ", " << get<2>(tp1) << endl;  
    cout << "Second tuple currently: " << get<0>(tp2) << ", " << get<1>(tp2) << ", " << get<2>(tp2) << endl;  

    return 0;
}

```

### tie()
enables a set of objects to act as a tuple. This is useful in unpacking tuple values into different variables.
```
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <string, int, bool> tp("sample", 56, false);

    string var1;
    int var2;
    bool var3;

    // tie() is used below for unpacking tuple values.
    tie(var1, var2, var3) = tp;

    cout << "The unpacked values of the tuple elements are:  ";
    cout << var1 << ",  " << var2 << ",  " << var3;

    return 0;
}

```

We may want to prevent some values from getting unpacked. To do this, we use `ignore` instead of the particular variable as an argument to tie().
```
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <string, int, bool> tp("sample", 56, false);

    string var1;
    bool var2;

    // tie() is used below for unpacking tuple values, with ignore being used to prevent unpacking of the 2nd element.
    tie(var1, ignore, var2) = tp;

    cout << "The unpacked values of the tuple elements are:  ";
    cout << var1 << ",  " << var2;

    return 0;
}

```

### tuple_cat()
tuple_cat() is used for concatenating two tuples into a single tuple.

```
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <int, char> tp1(1, 'a'); // First tuple
    tuple <int, int> tp2(2, 3); // Second tuple

    // Concatenating the two tuples.
    auto tp_combined1 = tuple_cat(tp1, tp2);

    Alternatively, we could also write the above code like this.
    tuple <int, char, int, int> tp_combined2 = tuple_cat(tp1, tp2);

    // Print elements.
    cout << "The concatenated tuple is = " << get<0>(tp_combined1) << ", " << get<1>(tp_combined1) << ", ";
    cout << get<2>(tp_combined1) << ", " << get<3>(tp_combined1);

    return 0;
}

```
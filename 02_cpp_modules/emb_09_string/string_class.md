# String Class

C++ doesn't support build in string type. ANSI standard C++ provides a new class called `string`

## Creating string

`string s1;`

`string s2("xyz")`

## Accessing characters

```c++
s1[0];             // Access character at index 0
s1.at(1);          // Safer access with bounds checking
s1.front();        // First character
s1.back();         // Last character
```

## Modifications

```c++
s1 += " World";            // Append string
s1.append("!");            // Append string
s1.insert(5, ",");         // Insert at position
s1.erase(5, 1);            // Erase 1 char from position 5
s1.replace(0, 5, "Hi");    // Replace "Hello" with "Hi"
s1.clear();                // Remove all characters
```

## Size and Capacity
```c++
 s1.length();     // or s1.size()
s1.capacity();   // Capacity before reallocation
s1.resize(10);   // Resize to length 10
s1.empty();      // Check if empty
```

## Searching
```c++
s1.find("lo");        // First occurrence
s1.rfind("l");        // Last occurrence
s1.find_first_of("aeiou");
s1.find_last_of("aeiou");
s1.find_first_not_of("H"); 
```

## Comparison
```c++
s1 == s2;
s1 != s2;
s1.compare(s2);  // Returns 0 if equal, <0 or >0 otherwise
```

## Substring and conversion
```c++
s1.substr(0, 5);  // Substring from index 0 of length 5
std::stoi("123");         // String to int
std::to_string(456);      // Int to string
```

## C-style Conversion
```c++
const char* cstr = s1.c_str();  // Convert to C-string
```




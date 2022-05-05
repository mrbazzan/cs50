
# CS50
`CS50 labs and problem set`


# C is a very very fascinating language

- Macros
 `makefile01/misc.c` contains some quick information about Macros.
  - Object-like macros
    - 
        `#define PI 3.142`
  - Function-like macros
    -
      ```
      #define f(a, b) a##b
      #define g(a) #a
      #define h(a) g(a)
      Find h(f(1,2))?
      ```
    **Order of expansion


- Structs
  - 


- Goto
  - 
  - `goto` contains example of 'goto' statement use case.


- Pointers
  - 
      - Pointer variables are used to hold the memory location(address) of a variable.
      - Pointers are 64bits addresses.
  
      - `->` and `.`?
        ```
        e.g 
        struct food{
                char *name;
                int amount;
        };
    
        struct food n = {"Ade", 1};
        n.name gives "Ade".
    
        struct food *n = {"Sayo", 2};
        n->name gives "Sayo".
        (*n).name gives "Sayo". // The dereferencing operator(*) has a lower precdence
                                // than the (.) operator.
        ```
    
- Memory
  - 
  - Dynamic memory allocation is done using functions such as malloc, calloc. Dynamically created memory is stored on the `heap` not `stack` as opposed to 
    local variables which is stored on the `stack`.


  `makefile001` introduces make and Makefile


- Structure Padding & Packing
  - Structure Packing
    - ```
      #pragma pack(1)
      ```
  - Structure Padding
    - Memory is not read 1 byte at a time from memory. It is read in word. 
    In a x-bit processor, the amount of memory read in a CPU cycle is x/8.
    - 
    - For this reason, the way `struct` is defined really matters. This is
    in order to prevent number of CPU cycles being run or reduce memory wastage.
    


- Extern
  - 
  - `extern` keyword in C is used to force declaration of a
     keyword that was defined elsewhere. It should be used in the
     header file and not the source files.
  
  - `extern/` directory gives an example of how it is used.

- Static
  - 
  - `static` keyword in C is a storage class specifier. Its meaning is
  dependent on context.
    - `Inside a Function`: Make variables retain its value
    between multiple function calls.
    
    - `Outside a Function`: Restrains the visibility of the function or
    variable to the current file.


- Function Pointers
  - 
  - What is a function? It's a block of code with a name. It
  exists somewhere in memory.
  - A pointer to a function is just the address of where
  the instruction starts. Therefore, `name of function` == `address of the function`
      

- Data Type
  -
  - 
    unsigned int a;
  - 
    unsigned b;
    
    sizeof(a) == sizeof(b)

- NB: The format specifier used for `unsigned` is `%u`.


- NOTE
  - 
  
  ```python
    unsigned uc;
    sscanf("F0FD","%02x",&uc);
  ```
    It converts "FOFD" to format(%2x) and saves in memory location **uc**.
    `sscanf` is only concerned with the number between the format specifier.
    Since it's 2, it only converts "FO" to hexadecimal.


###NB
- `gcc -E "file_ending_with_dot_c"`: to check the preprocessed content of a .c file


- To read the content of a `.o` file; use `objdump -D "file_name_ending_with_dot_o_extension" `


- To read the content of an executable file: use `hexdump "executable_file"`


- To debug code; pass `-g`option to the `gcc` command. Then use `gdb "filename" core` to debug.
- `bt` to backtrace.


# MATERIALS USED
- CS50
- PROF. BARRY BROWN
- WIKIPEDIA

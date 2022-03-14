
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
  - Dynamic memory allocation is done using functions such as malloc, calloc


  `makefile001` introduces make and Makefile

- Extern
  - 
  - `extern` keyword in C is used to force declaration of a
     keyword that was defined elsewhere. It should be used in the
     header file and not the source files.
  
  - `extern/` directory gives an example of how it is used.

- Function Pointers
  - 
  - What is a function? It's a block of code with a name. It
  exists somewhere in memory.
  - A pointer to a function is just the address of where
  the instruction starts. Therefore, `name of function` == `address of the function`
      


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

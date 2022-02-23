
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


- Pointers

  - 
      - Pointer variables are used to hold the memory location(address) of a variable.
      - Pointers are 64bits addresses.
    
- Memory
  - 
  - Dynamic memory allocation is done using functions such as malloc, calloc


  `makefile001` introduces make and Makefile


###NB
- `gcc -E "file_ending_with_dot_c"`: to check the preprocessed content of a .c file


- To read the content of a `.o` file; use `objdump -D "file_name_ending_with_dot_o_extension" `


- To read the content of an executable file: use `hexdump "executable_file"`


- To debug code; pass `-g` to the `gcc` command. Then use `gdb "filename" core` to debug.
- Then, `bt` to backtrace.

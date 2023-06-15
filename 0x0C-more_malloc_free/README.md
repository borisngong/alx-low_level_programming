0x0C. C - More malloc, free
* Calloc() method
“calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. 
It is very much similar to malloc() but has two different points and these are:
-It initializes each block with a default value ‘0’.
-It has two parameters or arguments as compare to malloc().
* Realloc() method
“Realloc” or “re-allocation” method is used to dynamically change the memory allocation of a previously allocated memory. 
In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory. 
Re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.

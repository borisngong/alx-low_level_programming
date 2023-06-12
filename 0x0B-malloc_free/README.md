0x0B. C - malloc, free
The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size
It returns a pointer of type void which can be cast into a pointer of any form.
It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially.
“free” method in C is used to dynamically de-allocate the memory.
The memory allocated using functions malloc() and calloc() is not de-allocated on their own.
Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

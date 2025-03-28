# Seminar 3
The code here is written solely to expose the basic idea behind how we're approaching undo. An interface and specifications should be written, and more testing should be done. 

# Seminar 1 demos
A non-exhaustive set of examples for the first seminar.
## Structs and typedefs

```c
// structs are a C mechanism to group related variables coherently, think of them as ancient classes, or at least their precursors
struct Person {
    int age;
    char name[20];
};

// typedef <existing type> <alias> where now existing type is `struct Person` and alias is `Person1`,
// so we'll be able to refer by `Person1` to the original type that has to spell `struct Person`;
typedef struct Person Person1;
typedef my_fancy_int int;
// analogously we can write this, where now `existing type` is `struct { ... }` and alias is `Person2`
typedef struct {
    int age;
    char name[20];
} Person2;

int main() {
    struct Person p; // 
    my_fancy_int k;
    Person1 p1; // but no `Person p`;
    return 0;
}
```

## Sizes of different types
What is even a type after all anyway?

Ps: also take care of formatters I use here, like `%lu`, `%d`, `%x`, etc. More on format specifiers [here](https://www.geeksforgeeks.org/format-specifiers-in-c/).
```c
#include <stdio.h>

typedef struct {
    int age;
    char name[20];
} Person;

int main() {
    Person p;
    Person people[100];
    printf("One p takes: %lu bytes\n", sizeof p);
    printf("%lu ps take: %lu bytes\n", sizeof people / sizeof p, sizeof people);
    printf("One address takes: sizeof &p = %lu, sizeof &people=%lu. No matter the type, an address is an address\n",
           sizeof &p, sizeof &people); // although clang tidy will complain

    int i;
    char c;
    long l;
    float f;
    double d;
    printf("These all take: int %lu, char %lu, long %lu, float %lu, double %lu\n", sizeof i, sizeof c, sizeof l,
           sizeof f, sizeof d);
    return 0;
}
```

## Basic function parameter passing
Parameters are passed by value. Alyways. Never ever is the same variable that was passed, and the one inside the function, the same. 
The trick is, however, that they can have the same value, which can be an address, which by means of being the same and thus pointing to the
very same location in memory, allows us to mutate variables even within function calls.
```c
#include <stdio.h>

int f(int a) {
    // a different address from the original argument's address, the same value
    printf("Address of a: %x, value of a: %d\n", &a, a);
    a += 1;//no effect on original
    return a;
}

void f_that_can_modify(int *a) {
    // all arguments are passed by value, we can mutate values from outside the original scope of the function
    // by passing an address - still by value.
    printf("Address of a: %x, value of a: %x\n", &a, a);
    *a += 1; // dereference
}


int main() {
    int k = 9;
    printf("Address of k: %x, value of k: %d\n", &k, k);
    int from_f = f(k);
    // yet another address, same value
    printf("Address of from_f: %x, value of from_f: %d\n", &from_f, from_f);
    printf("Address of k after calling f: %x, value of k: %d\n", &k, k);

    f_that_can_modify(&k);
    printf("Address of k after calling f that can modify: %x, value of k: %d\n", &k, k);
    return 0;
}
```

## Further on pointers to static and dynamic arrays:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[100];
    // a static array has the same value as its address
    printf("Address of numbers: %x and value of numbers: %x is the same\n", numbers, &numbers);

    int *numbers_on_heap = malloc(sizeof(int) * 100);
    // a dynamically allocated array has a different value from the variable's address
    printf("Address of numbers on heap: %x and value of numbers on heap: %x is not the same\n", numbers_on_heap,
           &numbers_on_heap);

    int *numbers_address = &numbers;
    // the variable `numbers_address` has a different address from the value it points to, which is `numbers`
    printf("Just like address of numbers_address: %x and value of numbers: %x are different\n", &numbers_address,
           numbers);
    return 0;
}
```


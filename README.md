# FunArrayStack

### Interactive terminal app demonstrating array stack computations

FunArrayStack was developed in c language to demonstrate how a stack can be created using arrays.

- Enter your own elements to create a magically-numbered array stack.
- 7 fun fun menu options to manipulate the stack
- Menu options let you decide when, where, and how often to manipulate the stack. You're in control!
- Repeat menu the same options to continually change the stack

# Features!

Menu options include display, check if full, check if empty, pop, push, peek at top, and peek under the stack! Still not enough for you? Well, you might be expecting too much for a simple pop and push array stack. Check out my linked list stack to double your pleasure.

### Tech

Tech uses the very very very advanced terminal shell and gcc compiler.

### Installation

The program comes with a swanky Makefile for you to automagically compile the .c extensions into .o binaries. Exciting? Make the file and run the file in bash.

```sh
$ make
$ ./funfunarraystack
```

Don't have all that time to type in "make"? Well, I have another solution for you...

```sh
$ gcc -I./ -o funfunarraystack funfunarraystack.c menufunc.c func.c
```

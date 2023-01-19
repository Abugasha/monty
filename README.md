# Monty Project - Interpreter of ByteCodes files

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. This program is an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
user@ubuntu:~/monty$ cat -e bytecodefile.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
user@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
user@ubuntu:~/monty$ cat -e bytecodefile.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
user@ubuntu:~/monty$
```

## General Project Requirements:

* All your files will be compiled on `Ubuntu 14.04 LTS`
* Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called `monty.h`
* All your header files should be include guarded

## Usage

### Download:

Clone the repository with the command line interface

`git clone https://github.com/nathsotomayor/monty.git`

### Compilation:

Compile all `.c` files with:

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

### Execution:

`user@ubuntu:~/monty$ ./monty bytecodefile.m`

### Example:
Structure of a Monty bytecode file:
```
user@ubuntu:~/monty$ cat -e bytecodefile.m
push 1
push 2
push 3
pall
user@ubuntu:~/monty$
```
Output after execution:
```
user@ubuntu:~/monty$ ./monty bytecodefile.m
3
2
1
user@ubuntu:~/monty$
```

## Extra information

### Monty Bytecode Opcodes

|Opcode                         |Function                     |
|-------------------------------|-----------------------------|
|`push <int>`                   |Pushes an integer onto the top of the stack           |
|`pop`              |Removes the top element of the stack            |
|`pall` | Prints all values on the stack|
|`pint` | Prints the value at the top of the stack|
|`swap`|Swaps the top two elements of the stack|
|`nop` | Does nothing|
|`pchar` | Prints the char at the top of the stack|
|`pstr` | Prints the string starting at the top of the stack|
|`add` | Adds the top two elements of the stack|
|`sub` | Subtracts the top element of the stack from the second element of the stack|
|`mul` | Multiplies the top two elements of the stack|
|`div` | Divides the second element of the stack by the top element of the stack|
|`mod` | Returns the remainder of dividing the second element of the stack by the top element of the stack|

### Brainfuck scripts usage:
Install the `bf` interpreter to test your code with:

`sudo apt-get install bf`

Run your code like this:

```
user@ubuntu:~/monty/bf$ bf brainfuckfile.bf 
Monty is awesome
user@ubuntu:~/monty/bf$
```

Read more about [brainfuck](https://en.wikipedia.org/wiki/Brainfuck)


## Authors

David Orejuela - [GitHub](https://github.com/daorejuela1) | [Twitter](https://twitter.com/DavidOrejuela14)

Nathaly Sotomayor Ampudia - [GitHub](https://github.com/nathsotomayor) | [Twitter](https://twitter.com/nathsotomayor)



`Made with 💛 in Holberton School`

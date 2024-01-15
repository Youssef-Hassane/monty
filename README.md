
## The monty program

- Usage: monty f-he
	- where f11e is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message usAGE : monty -£11e , followed by a new
line, and exit with the statUS EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file ‹I-11e› , followed by a new line, and exit with the statUS EXIT_FAI LURE
	- where ‹I-he› is the name of the file
- If the file contains an invalid instruction, print the error message L‹11ne_number›: unknown 1nstruct1on ‹opcode› , followed by a new line, and exit withthe status EXIT FAILURE
	- where is the line number where the instruction appears.
	- Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured
- If you can’t malloc anymore, print the error message Error: mal1oc failed , followed by a new line, and exit with StatUS EXIT_FAI LURE .
- You have to use ma1loc and free and are not allowed to use any other function from «ian ma1Ioc (realloc, calloc, ...)

## Task 0 (push, pall)

### Implement the push and pall opcodes.
### The push opcode
### The opcode push pushes an element to the stack.

- Usage: push ‹1nt›
	- where ‹1nt› is an integer
- if ‹int› isnot an integer or if there is no argument given to push , print the error message L‹1ine_number›: usage: push :tnteger , followedby a new line, and exit with the status EXIT FAILURE
	- where is the line number in the file
- You won’t have to deal with overflows. Use the ato1 function

### The pall opcode
### The opcode paI1 prints all the values on the stack, starting from the top of the stack.

- Usage pall
- Format: see example
- If the stack is empty, don’t print anything














## Developer:

| **Youssef Hassane** | **AKA Almasy** |
|---|---|
| ![Youssef Hassane](https://github.com/Youssef-Hassane/Screenshot/blob/main/img.png) | Youssef Hassane is a software engineer with a passion for building innovative and user-friendly web applications. He is currently a freelancer working on Upwork, where he is involved in a variety of projects. Youssef's goal is to become a world-class software engineer and make a positive impact on the world through his work. He is passionate about using technology to solve real-world problems and is always looking for new ways to use his skills to make a difference. |

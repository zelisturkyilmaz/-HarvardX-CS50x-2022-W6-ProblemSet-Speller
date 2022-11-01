# CS50's Introduction to Computer Science
## HarvardX - CS50x
### Week 6 Problem Set - Speller
<hr>


### Assignment and Requirements:
Implementation ```load, hash, size, check, and unload``` functions in ```dictionary.c``` as efficiently as possible using a hash table that spell-checks a file, as seen as the below. *Other files in the project are provided by CS50 team*

```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```

#### Compiling And Execution:

Before execution of the program, it must be compiled with a compiler, translating it from source code into machine code.\
Execute the command below in the Command Line to do that:

```
make speller
```

Execute the program by executing the below:
```
./speller TXTFILE
```
where ```TXTFILE``` is a ```.txt``` file of choice

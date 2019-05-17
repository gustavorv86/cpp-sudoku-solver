# cpp-sudoku-solver
Efficient sudoku solver algorithm

What you need
-------------

Install the next software.

`sudo apt-get install git g++ gdb make`

Build
-----

Clone this repository.

`git clone https://github.com/gustavorv86/cpp-sudoku-solver`

Go to repository folder and run make command.

```
cd cpp-sudoku-solver
make
```

Run examples
------------

Go to **dist** directory and run the examples into the **sudoku_tests** folder.
**Note**: the command interprets the dot character '.' as a empty cell.

```
cd dist
./sudoku-solver -f ../sudoku_tests/example_001.txt
```

Show help command.

`./sudoku-solver -h`

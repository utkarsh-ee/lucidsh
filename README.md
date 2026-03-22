# Lucid Shell (lucidsh)

A minimal Unix-like shell implemented in C. This project demonstrates core operating system concepts such as process creation, execution, and command parsing.

---

## Features

- Execute system commands (e.g., `ls`, `pwd`, `echo`)
- Built-in commands:
  - `cd`
  - `exit`
- Argument parsing using `strtok_r`
- Process creation using `fork()`
- Program execution using `execvp()`
- Parent-child synchronization using `waitpid()`
- Dynamic prompt showing current working directory

---

## Concepts Demonstrated

- Unix process model (`fork` + `exec`)
- Process synchronization (`waitpid`)
- File system navigation (`chdir`)
- Environment variables (`HOME`)
- Command parsing (`argv`)
- System calls and error handling

---

## Compilation

```bash
make

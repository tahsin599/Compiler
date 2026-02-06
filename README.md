# Compiler

A simple C compiler using Bison and Flex that tokenizes input, parses a C-like grammar, builds an AST, and generates correct assembly code.

---


---

## Overview

This project implements a simplified C compiler pipeline using Flex (lexer) and Bison (parser). It demonstrates the core compilation stages: lexical analysis, parsing, AST creation, semantic checks, and assembly generation. The generated assembly can be assembled and linked with standard toolchains (e.g., `gcc`) to produce executable programs.

---

## Features

- Lexical analysis with Flex
- Grammar parsing with Bison
- Construction of a simple AST
- Semantic checks for basic constructs
- Assembly code generation for compiled programs
- Example programs to validate the pipeline

---

## Supported language subset

This compiler implements a practical subset of C typically used for educational compilers, including:

- Primitive integer type(s) (`int`)
- Variable declarations and assignments
- Arithmetic expressions (`+`, `-`, `*`, `/`, `%`)
- Relational and logical operators (`<`, `>`, `<=`, `>=`, `==`, `!=`, `&&`, `||`, `!`)
- Control flow: `if`, `if-else`, `while`, (possibly `for`)
- Function definitions and calls (including `main`)
- `return` statements
- Basic integer literals and identifiers

Note: If your repo implements more features (arrays, pointers, structs, I/O), add them to the list above.

---

Install on Debian/Ubuntu:
```sh
sudo apt update
sudo apt install build-essential bison flex
```

---

## Quickstart — Build & Run



If there is no `Makefile`, you can run the usual Flex/Bison sequence manually. Adjust the filenames to match your repo (common names: `lexer.l`, `parser.y`):

```sh
bison -d -o parser.tab.c parser.y        # generates parser.tab.c and parser.tab.h
flex -o lex.yy.c lexer.l                 # generates lex.yy.c
gcc -o compiler parser.tab.c lex.yy.c -lfl -g   # link with libfl (or -lfl)
```




## How it works (high level)

1. Flex (lexer) tokenizes input into tokens (identifiers, numbers, keywords, operators).
2. Bison (parser) parses tokens according to grammar rules and builds an AST.
3. Semantic analysis resolves symbols, checks types, and validates constructs.
4. Code generator walks the AST and emits assembly (for example, x86_64 GAS syntax).
5. Output assembly is fed to `gcc`/assembler to produce an executable.

---





- "Compilers: Principles, Techniques, and Tools" (a.k.a. the Dragon Book)
- GNU assembler and x86_64 calling conventions (System V AMD64 ABI)

<div align="right">
  <img src="https://private-user-images.githubusercontent.com/197754999/434705190-5f8d33ce-fed8-438a-935c-a9916afef26e.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDk5NTQxNjgsIm5iZiI6MTc0OTk1Mzg2OCwicGF0aCI6Ii8xOTc3NTQ5OTkvNDM0NzA1MTkwLTVmOGQzM2NlLWZlZDgtNDM4YS05MzVjLWE5OTE2YWZlZjI2ZS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjE1JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYxNVQwMjE3NDhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT01YjMxZjc1MjA5MWZlZjUwMzQ5YmY0MzEwY2Q2YzhjMjFjMGE2MjYyN2EyMGE2N2VkYzcwZmM0Zjg2NzA3NDQwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.scT5Z-IvAbM2qpUeAAujRNrZjPEWjrxlUaxEHn5l9h0" alt="Holberton Logo" width="80">
</div>

# <a><img src="https://upload.wikimedia.org/wikipedia/commons/3/35/The_C_Programming_Language_logo.svg" width=3% height=3%></img></a> _printf

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?center=true&size=28&duration=3000&pause=1000&color=FF69B4&width=435&lines=printf+—+by+Najwa+and+Haifa" alt="Typing SVG" />
</p>

---

## Printf Manual
## Overview

The `_printf` project is a thoughtful re-creation of the standard C `printf` function. Engineered by Najwa & Haifa at Holberton School, it emphasizes both correctness and design clarity.

**Key Features:**

* Supports variadic arguments via `<stdarg.h>`
* Low-level output using `write()`
* Efficient custom parsing logic

**Supported Format Specifiers:** `%c` (char), `%s` (string), `%d` / `%i` (integers), `%%` (percent)

---

## Prototype

```c
int _printf(const char *format, ...);
```

---

## Requirements

- All code is written in C and compiled on Ubuntu 22.04 LTS using:
  gcc version 11.4.0 with the flags: -Wall -Werror -Wextra -pedantic

- The project was developed and tested in the Holberton School Sandbox environment.

- The code follows the Betty style guide for C programming:
  - Proper indentation and formatting
  - Clear function descriptions
  - Consistent naming conventions

- No use of global variables.

- All function prototypes are located in the main.h header file.

- Memory management is handled properly; no memory leaks allowed.

- Each function is tested using provided main files and standard test cases.

---

## Project Files

```text
📁 _printf.c       → Main logic that interprets and routes format strings
📁 helpers.c       → Implements helper functions like print_char, print_string, etc.
📁 main.h          → Header file with prototypes and macros
📁 test/main.c     → Sample test driver (currently local)
📁 man_3_printf    → Manual page for terminal usage
```

---
## Installation

To clone the repository locally, use the following commands:

git clone https://github.com/Haifahasher/holbertonschool-printf.git
cd holbertonschool-printf
---
## Usage

Include the header file in your source code to use the custom _printf function:

#include "main.h"

You can now call _printf just like the standard printf function.
---
## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

---

## Usage Examples

```c
_printf("Hello, %s!", "Najwa");      // Output: Hello, Najwa!
_printf("Value: %d%%", 100);         // Output: Value: 100%
_printf("Char: %c\n", 'A');         // Output: Char: A
```

---



## Testing

Compare with the standard printf for validation:

```c
_printf("Character: %c\n", 'N');
printf("Character: %c\n", 'N');

_printf("String: %s\n", "Najwa");
printf("String: %s\n", "Najwa");

_printf("Integer: %d\n", 42);
printf("Integer: %d\n", 42);
```

---

## Authors

* [Najwa Aljunaidel](https://github.com/NajwaAljunaidel)
* [Haifa Hasher](https://github.com/Haifahasher)

---

## Connect With Us

Built with 💗 at [Holberton School](https://www.holbertonschool.com/) – June 2025

* [NajwaAljunaidel GitHub](https://github.com/NajwaAljunaidel)
* [Haifahasher GitHub](https://github.com/Haifahasher)

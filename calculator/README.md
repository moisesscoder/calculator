# Calculator Example Project

## Prerequisites
- GNU C++17 Compiler
- Gtest Unit Test Library
- Clang-tidy
- Clang-format


## Building

To build de program
```
make
```

> Output will be placed at 'src/bin'

# Checking code

To scan the code for possible issues:
```
make lint
```

To scan the code for format issues:
```
make format-check
```

To scan the code for possible issues (lint+format):
```
make check
```

## Testing

To compile tests
```
make unittest
```

> Output will be placed at 'tests/bin'
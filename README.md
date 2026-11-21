# todo-cli

A simple command-line to-do list application written in C++.

## Features

- Add, list, complete and delete tasks
- Interactive menu in the console
- Tasks are saved to a text file, so they are still there the next time you run the program
- Input validation: empty titles, invalid numbers and unknown task IDs are handled without crashing

## Example

The interface of the program is in Turkish.

```
=== To-Do CLI ===
1) Görev ekle
2) Görevleri listele
3) Görevi bitir
4) Görevi sil
5) Çıkış
Seçimin: 2
1. [x] Ödevi bitir
2. [ ] Git öğren
```

## Build and run

You need a C++ compiler (for example `clang++` or `g++`).

```
clang++ -std=c++17 src/main.cpp -o todo
./todo
```

## Project structure

```
src/
├── main.cpp          # menu and user input
├── task.h            # Task struct (id, title, done)
└── task_manager.h    # TaskManager class: add, list, mark done, remove, save, load
```

## How it works

- Tasks are kept in a `std::vector<Task>` inside the `TaskManager` class.
- Every change is written to `tasks.txt` immediately, one task per line in the format `id|done|title`.
- Task IDs are not renumbered when a task is deleted, so an ID always points to the same task.

## Possible improvements

- Unit tests with GoogleTest
- CMake build
- Split `TaskManager` into `.h` and `.cpp` files
- Task priorities and due dates
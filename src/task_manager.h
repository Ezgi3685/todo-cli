#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "task.h"

class TaskManager {
public:
    void add(const std::string& title) {
        Task t;
        t.id = nextId;
        t.title = title;
        tasks.push_back(t);
        nextId++;
    }

    bool markDone(int id) {
        for (Task& t : tasks) {
            if (t.id == id) {
                t.done = true;
                return true;
            }
        }
        return false;
    }

    bool remove(int id) {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].id == id) {
                tasks.erase(tasks.begin() + i);
                return true;
            }
        }
        return false;
    }

    void list() const {
        if (tasks.empty()) {
            std::cout << "Hiç görev yok." << std::endl;
            return;
        }
        for (const Task& t : tasks) {
            std::cout << t.id << ". ["
                      << (t.done ? "x" : " ") << "] "
                      << t.title << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
    int nextId = 1;
};
#pragma once

#include <fstream>
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

    void save(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out) {
            std::cout << "Dosya yazılamadı: " << filename << std::endl;
            return;
        }
        for (const Task& t : tasks) {
            out << t.id << '|' << (t.done ? 1 : 0) << '|'
                << t.title << '\n';
        }
    }

    void load(const std::string& filename) {
        std::ifstream in(filename);
        if (!in) {
            return;  // dosya henüz yok, sorun değil
        }

        tasks.clear();
        nextId = 1;

        std::string line;
        while (std::getline(in, line)) {
            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            if (p1 == std::string::npos || p2 == std::string::npos) {
                continue;  // bozuk satırı atla
            }

            try {
                Task t;
                t.id = std::stoi(line.substr(0, p1));
                t.done = (line.substr(p1 + 1, p2 - p1 - 1) == "1");
                t.title = line.substr(p2 + 1);
                tasks.push_back(t);
                if (t.id >= nextId) {
                    nextId = t.id + 1;
                }
            } catch (...) {
                continue;  // numara okunamadıysa satırı atla
            }
        }
    }

private:
    std::vector<Task> tasks;
    int nextId = 1;
};
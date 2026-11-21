#include <iostream>
#include "task_manager.h"

int main() {
    TaskManager manager;
    manager.load("tasks.txt");

    std::cout << "--- Açılışta yüklenen görevler ---" << std::endl;
    manager.list();

    manager.add("Yeni görev");
    manager.save("tasks.txt");

    std::cout << "--- Kaydedildi ---" << std::endl;
    return 0;
}
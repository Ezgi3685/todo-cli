#include <iostream>
#include "task_manager.h"

int main() {
    TaskManager manager;

    manager.add("Ödevi bitir");
    manager.add("Git öğren");
    manager.add("Markete git");

    manager.markDone(2);
    manager.list();

    std::cout << "--- 1 numaralı görev siliniyor ---" << std::endl;
    manager.remove(1);
    manager.list();

    std::cout << "--- olmayan görev siliniyor ---" << std::endl;
    if (!manager.remove(99)) {
        std::cout << "99 numaralı görev bulunamadı." << std::endl;
    }

    return 0;
}
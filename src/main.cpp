#include <iostream>
#include "task.h"

int main() {
    Task t;
    t.id = 1;
    t.title = "Ödevi bitir";

    std::cout << t.id << " - " << t.title
              << " - bitti mi: " << t.done << std::endl;
    return 0;
}
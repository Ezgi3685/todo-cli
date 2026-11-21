#include "task_manager.h"

int main() {
    TaskManager manager;

    manager.add("Ödevi bitir");
    manager.add("Git öğren");
    manager.add("Markete git");

    manager.list();
    return 0;
}
#include <iostream>
#include <limits>
#include <string>
#include "task_manager.h"

bool readInt(const std::string& prompt, int& value) {
    std::cout << prompt;
    if (std::cin >> value) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    if (std::cin.eof()) {
        return false;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

void printMenu() {
    std::cout << "\n=== To-Do CLI ===" << std::endl;
    std::cout << "1) Görev ekle" << std::endl;
    std::cout << "2) Görevleri listele" << std::endl;
    std::cout << "3) Görevi bitir" << std::endl;
    std::cout << "4) Görevi sil" << std::endl;
    std::cout << "5) Çıkış" << std::endl;
}

int main() {
    TaskManager manager;
    const std::string file = "tasks.txt";
    manager.load(file);

    while (std::cin) {
        printMenu();

        int choice;
        if (!readInt("Seçimin: ", choice)) {
            std::cout << "Lütfen bir sayı gir." << std::endl;
            continue;
        }

        if (choice == 1) {
            std::cout << "Görev başlığı: ";
            std::string title;
            std::getline(std::cin, title);
            if (title.empty()) {
                std::cout << "Başlık boş olamaz." << std::endl;
            } else {
                manager.add(title);
                manager.save(file);
                std::cout << "Görev eklendi." << std::endl;
            }
        } else if (choice == 2) {
            manager.list();
        } else if (choice == 3) {
            int id;
            if (readInt("Bitirilecek görevin numarası: ", id)) {
                if (manager.markDone(id)) {
                    manager.save(file);
                    std::cout << "Görev bitti olarak işaretlendi." << std::endl;
                } else {
                    std::cout << id << " numaralı görev bulunamadı." << std::endl;
                }
            } else {
                std::cout << "Lütfen bir sayı gir." << std::endl;
            }
        } else if (choice == 4) {
            int id;
            if (readInt("Silinecek görevin numarası: ", id)) {
                if (manager.remove(id)) {
                    manager.save(file);
                    std::cout << "Görev silindi." << std::endl;
                } else {
                    std::cout << id << " numaralı görev bulunamadı." << std::endl;
                }
            } else {
                std::cout << "Lütfen bir sayı gir." << std::endl;
            }
        } else if (choice == 5) {
            std::cout << "Görüşürüz!" << std::endl;
            break;
        } else {
            std::cout << "Geçersiz seçim." << std::endl;
        }
    }

    return 0;
}
/*
 *  АиСД-2, 2023, КДЗ-2
 *  ФИО: Шиндяпкин Илья Дмитриевич
 *  ГРУППА: БПИ219
 *  Среда разработки: CLion, 2021.3.4
 *  Сделано: реализованы различные алгоритмы поиска шаблона в строке с подсчетом времени и усреднением,
 *  есть возможность запустить лубой алгоритм или все сразу,
 *  произведены вычисления, результаты записаны в csv файлы, построены графики, написан отчет.
 *  Не сделано: Нету, все сделано.
 * */

#include <iostream>
#include "Utils/StringAlgorithmUtils/AlgorithmExecutor.cpp"
#include "Utils/InterfaceUtils/ConsoleInputReader.cpp"

int main() {
    std::string loop;
    do {
        // Generate strings and templates.
        generateText();
        printAlgorithms();
        // Choose finding algorithm.
        int choice = readConsoleInput();
        chooseAlgorithm(choice);
        // Program loop.
        do {
            std::cout << "\nContinue? (y/n):";
            std::getline(std::cin, loop);
        } while (loop != "y" && loop != "n");
        std::cout << '\n';
    } while (loop == "y");
    // Delete arrays from heap.
    clearMemory();
}

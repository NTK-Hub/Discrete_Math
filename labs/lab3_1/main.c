#include "../../libs/alg/alg.h"

bool conditionA(int x, int y) {
    // Условие A: (x, y) | x ∈ N и y ∈ N и x < 11 и y < 11 и (x > y или y > 7)
    return x < 11 && y < 11 && (x > y || y > 7);
}

bool conditionB(int x, int y) {
    // Условие B: (x, y) | x ∈ N и y ∈ N и x < 11 и y < 11 и 10x + y кратно 3
    return x < 11 && y < 11 && (10 * x + y) % 3 == 0;
}

bool conditionC(int x, int y) {
    // Условие C: (x, y) | x ∈ N и y ∈ N и x < 11 и y < 11 и x - чётное и y - нечётное
    return x < 11 && y < 11 && x % 2 == 0 && y % 2 != 0;
}

int main() {
    // Устанавливаем кодировку вывода в UTF-8 для корректного отображения
    SetConsoleOutputCP(CP_UTF8);

    int departureAreaSize = 10;
    int arrivalAreaSize = 10;

    // Создаем отношения A, B и C на основе новых условий
    bool **A = getRelationByCondition(conditionA, departureAreaSize, arrivalAreaSize);
    bool **B = getRelationByCondition(conditionB, departureAreaSize, arrivalAreaSize);
    bool **C = getRelationByCondition(conditionC, departureAreaSize, arrivalAreaSize);

    //1.3
    // Выводим отношения на экран
    printf("Отношение A:\n");
    printRelation(A, departureAreaSize, arrivalAreaSize);

    printf("Отношение B:\n");
    printRelation(B, departureAreaSize, arrivalAreaSize);

    printf("Отношение C:\n");
    printRelation(C, departureAreaSize, arrivalAreaSize);

    //1.5
    // Выполняем операции над отношениями и выводим результат
    printf("Вывод:\n");
    printRelation(unionOperation(inversionOperation(differenceOperation( A, B, departureAreaSize, arrivalAreaSize),departureAreaSize, arrivalAreaSize),intersectionOperation(C, complementOperation(A, departureAreaSize, arrivalAreaSize), departureAreaSize, arrivalAreaSize), departureAreaSize, arrivalAreaSize), departureAreaSize, arrivalAreaSize);

    //2.3
    printf("А:\nРефлексивность: %d\nАнтирефлексивность: %d\nСимметричность: %d\n"
           "Антисимметричность: %d\nТранзитивность: %d\nАнтитранзитивность: %d\n"
           "Толерантность: %d\nЭквивалентность: %d\nПолнота: %d\n",
           reflexivityOperation(A, departureAreaSize, arrivalAreaSize),
           antiReflexivityOperation(A, departureAreaSize, arrivalAreaSize),
           symmetryOperation(A, departureAreaSize, arrivalAreaSize),
           antiSymmetryOperation(A, departureAreaSize, arrivalAreaSize),
           transitivityOperation(A, departureAreaSize, arrivalAreaSize),
           antiTransitivityOperation(A, departureAreaSize, arrivalAreaSize),
           toleranceOperation(A, departureAreaSize, arrivalAreaSize),
           equivalenceOperation(A, departureAreaSize, arrivalAreaSize),
           fullyOperation(A, departureAreaSize, arrivalAreaSize));
    printf("B:\nРефлексивность: %d\nАнтирефлексивность: %d\nСимметричность: %d\n"
           "Антисимметричность: %d\nТранзитивность: %d\nАнтитранзитивность: %d\n"
           "Толерантность: %d\nЭквивалентность: %d\nПолнота: %d\n",
           reflexivityOperation(B, departureAreaSize, arrivalAreaSize),
           antiReflexivityOperation(B, departureAreaSize, arrivalAreaSize),
           symmetryOperation(B, departureAreaSize, arrivalAreaSize),
           antiSymmetryOperation(B, departureAreaSize, arrivalAreaSize),
           transitivityOperation(B, departureAreaSize, arrivalAreaSize),
           antiTransitivityOperation(B, departureAreaSize, arrivalAreaSize),
           toleranceOperation(B, departureAreaSize, arrivalAreaSize),
           equivalenceOperation(B, departureAreaSize, arrivalAreaSize),
           fullyOperation(B, departureAreaSize, arrivalAreaSize));
    printf("C:\nРефлексивность: %d\nАнтирефлексивность: %d\nСимметричность: %d\n"
           "Антисимметричность: %d\nТранзитивность: %d\nАнтитранзитивность: %d\n"
           "Толерантность: %d\nЭквивалентность: %d\nПолнота: %d\n",
           reflexivityOperation(C, departureAreaSize, arrivalAreaSize),
           antiReflexivityOperation(C, departureAreaSize, arrivalAreaSize),
           symmetryOperation(C, departureAreaSize, arrivalAreaSize),
           antiSymmetryOperation(C, departureAreaSize, arrivalAreaSize),
           transitivityOperation(C, departureAreaSize, arrivalAreaSize),
           antiTransitivityOperation(C, departureAreaSize, arrivalAreaSize),
           toleranceOperation(C, departureAreaSize, arrivalAreaSize),
           equivalenceOperation(C, departureAreaSize, arrivalAreaSize),
           fullyOperation(C, departureAreaSize, arrivalAreaSize));

    // Освобождаем выделенную память для массивов
    for (int i = 0; i < departureAreaSize; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
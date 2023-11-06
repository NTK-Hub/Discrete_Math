//
// Created by NTK on 06.11.2023.
//

#ifndef DISCRETE_MATH_LAB3_1_H
#define DISCRETE_MATH_LAB3_1_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

// Функция для определения условия A
bool conditionA(int x, int y);

// Функция для определения условия B
bool conditionB(int x, int y);

// Функция для определения условия C
bool conditionC(int x, int y);

// Функция для печати отношения
void printRelation(const bool **relation, int departureAreaSize, int arrivalAreaSize);

// Функция для создания отношения на основе заданного условия
bool **getRelationByCondition(bool (*func)(int, int), int departureAreaSize, int arrivalAreaSize);

// Функция для обновления размеров матрицы A и B до одинаковых размеров
void updateBetween(bool **A, bool **B, int maxRows, int maxCols);

// Функция для обновления матрицы A до квадратной формы и возврата максимального размера
int updateToSquare(bool **A, int maxRows, int maxCols);

// Функция для операции включения (inclusion)
bool inclusionOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции равенства (equality)
bool equalityOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции строгого включения (strict inclusion)
bool strictInclusionOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции объединения (union)
bool **unionOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции пересечения (intersection)
bool **intersectionOperation(bool **A, bool **B, int maxRows, int maxCols) ;

// Функция для операции разности (difference)
bool **differenceOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции симметричной разности (symmetric difference)
bool **symmetricDifferenceOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция для операции дополнения (complement)
bool **complementOperation(bool **A, int maxRows, int maxCols);

// Функция для операции инверсии (inversion)
bool **inversionOperation(bool **A, int maxRows, int maxCols);

// Функция для операции композиции (composition)
bool **compositionOperation(bool **A, bool **B, int maxRows, int maxCols);

// Функция проверки рефлексивности
bool reflexivityOperation(bool **A, int maxRows, int maxCols);

// Функция проверки антирефлексивности
bool antiReflexivityOperation(bool **A, int maxRows, int maxCols);

// Функция проверки симметрии
bool symmetryOperation(bool **A, int maxRows, int maxCols);

// Функция проверки антисимметрии
bool antiSymmetryOperation(bool **A, int maxRows, int maxCols);

// Функция проверки транзитивности
bool transitivityOperation(bool **A, int maxRows, int maxCols);

// Функция проверки антитранзитивности
bool antiTransitivityOperation(bool **A, int maxRows, int maxCols);

// Функция проверки толерантности
bool toleranceOperation(bool **A, int maxRows, int maxCols);

// Функция проверки эквивалентности
bool equivalenceOperation(bool **A, int maxRows, int maxCols);

// Функция проверки полного порядка
bool fullyOperation(bool **A, int maxRows, int maxCols);

// Функция проверки порядка
bool orderOperation(bool **A, int maxRows, int maxCols);

// Функция проверки слабого порядка
bool looseOrderOperation(bool **A, int maxRows, int maxCols);

// Функция проверки строгого порядка
bool strictOrderOperation(bool **A, int maxRows, int maxCols);

// Функция проверки линейного порядка
bool linearOrderOperation(bool **A, int maxRows, int maxCols);

// Функция проверки нестрогого линейного порядка
bool nonStrictLinearOrderOperation(bool **A, int maxRows, int maxCols);

// Функция проверки строгого линейного порядка
bool strictLinearOrderOperation(bool **A, int maxRows, int maxCols);

#endif //DISCRETE_MATH_LAB3_1_H

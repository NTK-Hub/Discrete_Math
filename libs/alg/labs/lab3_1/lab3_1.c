#include "lab3_1.h"

void printRelation(const bool **relation, int departureAreaSize, int arrivalAreaSize) {
    for (int x = 0; x < departureAreaSize; x++) {
        for (int y = 0; y < arrivalAreaSize; y++) {
            if (relation[x][y]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

bool **getRelationByCondition(bool (*func)(int, int), int departureAreaSize, int arrivalAreaSize) {
    // Выделяем память для двумерного массива
    bool **res = (bool **) malloc(departureAreaSize * sizeof(bool *));

    for (int i = 0; i < departureAreaSize; i++) {
        res[i] = (bool *) malloc(arrivalAreaSize * sizeof(bool));
    }

    // Заполняем массив в соответствии с заданным условием
    for (int x = 1; x <= departureAreaSize; x++) {
        for (int y = 1; y <= arrivalAreaSize; y++) {
            res[x - 1][y - 1] = func(x, y);
        }
    }

    return res;
}

void updateBetween(bool **A, int maxRows, int maxCols) {
    // Изменяем размеры матрицы A до maxRows x maxCols
    for (int i = 0; i < maxRows; i++) {
        A[i] = (bool *) realloc(A[i], maxCols * sizeof(bool));
        for (int j = 0; j < maxCols; j++) {
            if (j >= maxCols) {
                A[i][j] = 0; // Заполняем новые элементы нулями
            }
        }
    }

    // Освобождаем лишние строки в матрице A
    for (int i = maxRows; i < maxRows; i++) {
        free(A[i]);
    }

    // Добавляем новые строки к матрице A, если необходимо
    A = (bool **) realloc(A, maxRows * sizeof(bool *));
    for (int i = maxRows; i < maxRows; i++) {
        A[i] = (bool *) malloc(maxCols * sizeof(bool));
        for (int j = 0; j < maxCols; j++) {
            A[i][j] = 0; // Заполняем новые строки нулями
        }
    }
}

int updateToSquare(bool **A, int maxRows, int maxCols) {
    // Вычисляем максимум из maxRows и maxCols
    int maxMetric = maxRows > maxCols ? maxRows : maxCols;

    // Изменяем размеры матрицы A до maxMetric x maxMetric
    for (int i = 0; i < maxMetric; i++) {
        A[i] = (bool *) realloc(A[i], maxMetric * sizeof(bool));
        for (int j = maxCols; j < maxMetric; j++) {
            A[i][j] = 0; // Заполняем новые элементы нулями
        }
    }

    // Добавляем новые строки к матрице A, если необходимо
    for (int i = maxRows; i < maxMetric; ++i) {
        A = (bool **) realloc(A, (maxMetric + 1) * sizeof(bool *));
        A[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            A[i][j] = 0; // Заполняем новые строки нулями
        }
    }

    return maxMetric;
}

bool inclusionOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Проверяем, что каждый элемент A равен 1, если соответствующий элемент B равен 0
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false; // Найден элемент, который не соответствует условию
        }
    }
    return true; // Все элементы A удовлетворяют условию inclusion
}

bool equalityOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Проверяем, что каждый элемент A равен соответствующему элементу B
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            if (A[i][j] != B[i][j])
                return false; // Найден элемент, который не соответствует условию
        }
    }
    return true; // Все элементы A равны соответствующим элементам B
}

bool strictInclusionOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);
    bool flag = false;

    // Проверяем, что каждый элемент A равен 1, если соответствующий элемент B равен 0,
    // и проверяем, есть ли хотя бы один различный элемент
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false; // Найден элемент, который не соответствует условию
            if (A[i][j] != B[i][j])
                flag = true;
        }
    }
    return flag; // Все элементы A удовлетворяют условию strict inclusion
}

bool **unionOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Создаем новую матрицу C
    int maxMetric = maxRows > maxCols ? maxRows : maxCols;
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = A[i][j] || B[i][j]; // Выполняем операцию объединения
        }
    }
    return C;
}

bool **intersectionOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Создаем новую матрицу C
    int maxMetric = maxRows > maxCols ? maxRows : maxCols;
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = A[i][j] && B[i][j]; // Выполняем операцию пересечения
        }
    }
    return C;
}

bool **differenceOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Создаем новую матрицу C
    int maxMetric = maxRows > maxCols ? maxRows : maxCols;
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = A[i][j] && !B[i][j]; // Выполняем операцию разности
        }
    }
    return C;
}

bool **symmetricDifferenceOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Создаем новую матрицу C
    int maxMetric = maxRows > maxCols ? maxRows : maxCols;
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = (A[i][j] && !B[i][j]) || (!A[i][j] && B[i][j]); // Выполняем операцию симметричной разности
        }
    }
    return C;
}

bool **complementOperation(bool **A, int maxRows, int maxCols) {
    // Обновляем размеры матрицы A до квадратной формы и получаем maxMetric
    int maxMetric = updateToSquare(A, maxRows, maxCols);

    // Создаем новую матрицу C
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = !A[i][j]; // Выполняем операцию дополнения
        }
    }
    return C;
}

bool **inversionOperation(bool **A, int maxRows, int maxCols) {
    // Обновляем размеры матрицы A до квадратной формы и получаем maxMetric
    int maxMetric = updateToSquare(A, maxRows, maxCols);

    // Создаем новую матрицу C
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = A[j][i]; // Выполняем операцию инверсии
        }
    }
    return C;
}

bool **compositionOperation(bool **A, bool **B, int maxRows, int maxCols) {
    // Обновляем размеры матриц A и B до одинаковых
    updateBetween(A, maxRows, maxCols);
    updateBetween(B, maxRows, maxCols);

    // Получаем максимальный размер матрицы
    int maxMetric1 = updateToSquare(A, maxRows, maxCols);
    int maxMetric2 = updateToSquare(B, maxRows, maxCols);
    int maxMetric = maxMetric1 > maxMetric2 ? maxMetric1 : maxMetric2;

    // Создаем новую матрицу C
    bool **C = (bool **) malloc(maxMetric * sizeof(bool *));

    for (int i = 0; i < maxMetric; i++) {
        C[i] = (bool *) malloc(maxMetric * sizeof(bool));
        for (int j = 0; j < maxMetric; j++) {
            C[i][j] = 0; // Инициализируем матрицу C нулями
            for (int k = 0; k < maxMetric; k++) {
                C[i][j] = C[i][j] || (A[i][k] && B[k][j]); // Выполняем операцию композиции
            }
        }
    }
    return C;
}

bool reflexivityOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что все диагональные элементы равны 1 (рефлексивность)
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        if (!A[i][i])
            return false;
    }

    return true;
}

bool antiReflexivityOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что все диагональные элементы равны 0 (антирефлексивность)
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        if (A[i][i])
            return false;
    }

    return true;
}

bool symmetryOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что матрица симметрична относительно главной диагонали
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        for (int j = 0; j < ((maxRows + maxCols) / 2); j++) {
            if (A[i][j] != A[j][i])
                return false;
        }
    }

    return true;
}

bool antiSymmetryOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что матрица антисимметрична (A[i][j] и A[j][i] не могут быть оба равны 1)
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        for (int j = 0; j < ((maxRows + maxCols) / 2); j++) {
            if (A[i][j] == A[j][i])
                return false;
        }
    }

    return true;
}

bool transitivityOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что матрица удовлетворяет транзитивному свойству
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        for (int j = 0; j < ((maxRows + maxCols) / 2); j++) {
            for (int k = 0; k < ((maxRows + maxCols) / 2); k++) {
                if (A[i][j] && A[j][k] && !A[i][k]) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool antiTransitivityOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что матрица не удовлетворяет транзитивному свойству
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        for (int j = 0; j < ((maxRows + maxCols) / 2); j++) {
            for (int k = 0; k < ((maxRows + maxCols) / 2); k++) {
                if (A[i][j] && A[j][k] && A[i][k])
                    return false;
            }
        }
    }

    return true;
}

bool toleranceOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам рефлексивности и симметрии
    return reflexivityOperation(A, maxRows, maxCols) && symmetryOperation(A, maxRows, maxCols);
}

bool equivalenceOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам рефлексивности, симметрии и транзитивности
    return reflexivityOperation(A, maxRows, maxCols) && symmetryOperation(A, maxRows, maxCols) &&
           transitivityOperation(A, maxRows, maxCols);
}

bool fullyOperation(bool **A, int maxRows, int maxCols) {
    // Приводим матрицу A к квадратной форме
    updateToSquare(A, maxRows, maxCols);

    // Проверяем, что матрица удовлетворяет свойствам полного порядка
    for (int i = 0; i < ((maxRows + maxCols) / 2); i++) {
        for (int j = 0; j < ((maxRows + maxCols) / 2); j++) {
            if (!(A[i][j] && !A[j][i] || !A[i][j] && A[j][i]))
                return false;
        }
    }

    return true;
}

bool orderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам антисимметрии и транзитивности
    return antiSymmetryOperation(A, maxRows, maxCols) && transitivityOperation(A, maxRows, maxCols);
}

bool looseOrderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам порядка и рефлексивности
    return orderOperation(A, maxRows, maxCols) && reflexivityOperation(A, maxRows, maxCols);
}

bool strictOrderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам порядка и антирефлексивности
    return orderOperation(A, maxRows, maxCols) && antiReflexivityOperation(A, maxRows, maxCols);
}

bool linearOrderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам порядка и полного порядка
    return orderOperation(A, maxRows, maxCols) && fullyOperation(A, maxRows, maxCols);
}

bool nonStrictLinearOrderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам слабого порядка и полного порядка
    return looseOrderOperation(A, maxRows, maxCols) && fullyOperation(A, maxRows, maxCols);
}

bool strictLinearOrderOperation(bool **A, int maxRows, int maxCols) {
    // Проверяем, что матрица удовлетворяет свойствам строгого порядка и полного порядка
    return strictOrderOperation(A, maxRows, maxCols) && fullyOperation(A, maxRows, maxCols);
}
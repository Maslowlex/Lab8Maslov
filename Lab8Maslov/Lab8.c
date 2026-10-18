#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
int zad1() {
        int count;
        char symbol;
        printf("Введите количество символов: ");
        scanf("%d", &count);
        printf("Введите символ для печати: ");
        scanf(" %c", &symbol); 
        printf("\nБазовый вывод:\n");
        for (int start = 1; start <= count; start++) {
            putchar(symbol);
        }
        printf("\n");
        printf("\nС символом '+' в начале и конце:\n");
        putchar('+');
        for (int start = 1; start <= count; start++) {
            putchar(symbol);
        }
        putchar('+');
        printf("\n");
        printf("\nПоловина символов '%c', половина символов '*':\n", symbol);
        for (int start = 1; start <= count; start++) {
            if (start <= count / 2) {
                putchar(symbol);
            }
            else {
                putchar('*');
            }
        }
        printf("\n");
        printf("\nС восклицательным знаком после каждого символа:\n");
        for (int start = 1; start <= count; start++) {
            putchar(symbol);
            putchar('!');
        }
        printf("\n");
        printf("\nСоздание рамочки с 3 сторон\n");
        for (int row = 1; row <= 4; row++) {
            for (int col = 1; col <= 8; col++) {
                if (row == 1 || row == 4) {
                    putchar('-');
                }
                else if (col == 1) {
                    putchar('|');    
                }
                else {
                    putchar(' ');
                }
            }
            printf("\n"); 
        }
        return 0;
}
int zad2() {
    int n, m;
    int s = 0;
    int k = 0;
    int even = 0;
    int odd = 0;
    printf("Введите значение n (начало):");
    scanf("%d", &n);
    printf("Введите значение m (конец):");
    scanf("%d", &m);
    printf("\nНачало цикла\n");
    for (int i = m; i >= n; i--) {
        s += i;
        if (i % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
        printf(" выполнено %d раз", k++);
    }
    double average = (double)s / k;
    printf("\n\nКоличество чисел: %d\n", k);
    printf("Сумма: %d\n", s);
    printf("Среднее арифметическое: %.1f\n", average);
    printf("\nКоличество чётных чисел: %d\n", even);
    printf("Количество нечётных чисел: %d\n", odd);
    return 0;
}

int zad4() {
    double a = 0.0;     
    double b = 2.0;     
    double h;
    double x = a;
    double y;
    double min_y = 0.0;
    double max_y =0.0;
    double min_x =0.0;
    double max_x = 0.0;
    printf("Функция: y = x^2 + 3x - 1\n");
    printf("Введите шаг h: ");
    scanf("%lf", &h);
    int first = 1;
    printf("\n-----------------------\n");
    printf("|    x    |     y     |\n");
    printf("-----------------------\n");
    for (x = a; x <= b+1e-9; x += h) {
        y = x * x + 3 * x - 1;
        printf("| %7.2lf | %9.4lf |\n", x, y);
        if (first) {
            min_y = max_y = y;
            min_x = max_x = x;
            first = 0;
        }
        else {
            if (y > max_y) {
                max_y = y;
                max_x = x;
            }
            if (y < min_y) {
                min_y = y;
                min_x = x;
            }
        }
    }
    printf("-----------------------\n");
    printf("Максимум: y = %.4lf при x = %.2lf\n", max_y, max_x);
    printf("Минимум:  y = %.4lf при x = %.2lf\n", min_y, min_x);

    return 0;
}
int zad3() {
    int n;
    int type;

    printf("Исследование переполнения типов данных\n");
    printf("Введите степень n (до которой считать 2^n): ");
    scanf("%d", &n);

    printf("\nВыберите тип данных для хранения результата:\n");
    printf("1 - int\n");
    printf("2 - unsigned int\n");
    printf("3 - long long\n");
    printf("Ваш выбор: ");
    scanf("%d", &type);

    printf("\n--- Результаты (2^n) ---\n");
    if (type == 1) {
        int result = 1;
        for (int i = 0; i <= n; i++) {
            printf("2^%d = %d\n", i, result);
            result *= 2; 
        }
    }
    else if (type == 2) {
        unsigned int result = 1;
        for (int i = 0; i <= n; i++) {
            printf("2^%d = %u\n", i, result); 
            result *= 2;
        }
    }
    else if (type == 3) {
        long long result = 1;
        for (int i = 0; i <= n; i++) {
            printf("2^%d = %lld\n", i, result); 
            result *= 2;
        }
    }
    else {
        printf("Неверный выбор типа!\n");
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "Тип", "Последняя корректная степень", "Результат", "Что происходит дальше");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "int", "2^30", "1073741824", "Переполнение -> отриц.");
    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "", "(следующий 2^31)", "-2147483648", "число, затем 0");

    printf("---------------------------------------------------------------------------------------------------------------\n");

    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "unsigned int", "2^31", "2147483648", "Переполнение -> 0");
    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "", "(следующий 2^32)", "0", "сброс всех битов");

    printf("----------------------------------------------------------------------------------------------------------------\n");

    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "long long", "2^62", "4611686018427387904", "Переполнение -> отриц.");
    printf("| %-13s | %-30s | %-21s | %-25s |\n",
        "", "(следующий 2^63)", "-9223372036854775808", "число, затем 0");

    printf("---------------------------------------------------------------------------------------------------------------- \n\n");

    return 0;
}

int main() {
    (setlocale(LC_ALL, "RUS"));
    puts("Введите номер задания из лабораторной");
    int choise = 0;
    scanf("%d", &choise);
    switch (choise) {
    case 1:
        zad1();
        break;
    case 2:
        zad2();
        break;
    case 3:
        zad3();
        break;
    case 4:
        zad4();
        break;
    }
    getchar();
}
#include <cmath>
#include <iomanip>
#include <iostream>


void check_cin_int() {
    if (std::cin.good())
        return;
    std::cin.clear();
    std::string ignore;
    std::cin >> ignore;
}

double read_double(const char* prompt) {
    double result;
    while(true) {
        printf(prompt);
        std::cin >> result;
        if (std::cin.good())
            return result;
        check_cin_int();
    }
}

void task_1() {
    double d;
    printf("1. Enter double number: ");
    std::cin >> d;
    printf("1. Your double with two decimal places: %.2f\n", d);
}

void task_2() {
    const double c = read_double("2.1. c: ");  // 5.1
    const double z = cos(c);
    double x;
    if(z < 0)
        x = pow(z, 3) - 3 * pow(z, 2);
    else if (z > 0 && z < 8)
        x = z * log10(z);
    else
        x = exp(z) - exp(-z);
    const double y = pow(x, 2) + 8 * x + 6;
    printf("2.1. Result: %.4f\n", y);
}

int read_int(const char* prompt) {
    int result;
    while(true) {
        printf(prompt);
        std::cin >> result;
        if (std::cin.good())
            return result;
        check_cin_int();
    }
}

void task_3() {
    int day = 0;
    while(true) {
        printf("2.2. Enter day (between 1 and 7): ");
        std::cin >> day;
        check_cin_int();
        if(day >= 1 && day <= 7)
            break;
        printf("     Day must be between 1 and 7!\n");
    }

    switch(day) {
        case 1: {printf("     4 lessons"); break;}
        case 2: {printf("     1 lessons"); break;}
        case 3: {printf("     4 lessons"); break;}
        case 4: {printf("     2 lessons"); break;}
        case 5: {printf("     2 lessons"); break;}

        case 6:
        case 7:
        default:
        printf("     0 lessons");
    }
    printf("\n");
}

void task_4() {
    int len = 0;
    while(true) {
        printf("3.1. Enter array length (greater than 1): ");
        std::cin >> len;
        check_cin_int();
        if(len >= 1)
            break;
        printf("     Number must be greater than 1!\n");
    }

    int sum = 0;
    int i = 0;
    int tmp;
    do {
        printf("     Enter integer: ");
        std::cin >> tmp;
        if (!std::cin.good()) {
            check_cin_int();
            continue;
        }
        sum += tmp;
        i++;
    } while (i < len);

    double result = (double)sum / len;
    printf("     Result (do-while): %.3f\n", result);

    sum = 0;
    for(i = 0; i < len; i++) {
        printf("     Enter integer: ");
        std::cin >> tmp;
        if (std::cin.good())
            sum += tmp;
    }

    result = (double)sum / len;
    printf("     Result (for): %.3f\n", result);
}

void task_5() {
    printf("3.2\n");
    const int a = read_int("   a: "); // 3
    const int b = read_int("   b: "); // 5
    const double c = read_double("   c: "); // 0.5
    printf("   +---------------+\n");
    for(double x = a; x <= b; x += c) {
        const double y = x - sin(x);
        printf("   | %.3f | %.3f |\n", x, y);
    }
    printf("   +---------------+\n");
}

int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();

    return 0;
}

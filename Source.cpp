#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double generator(int&); // прототип функции генерации псевдослучайных чисел
double matozhidanie(double[]); // прототип функции вычисления мат.ожидания
double dispersia(double[], double M); // прототип функции вычисления дисперсии
double srednekvotkl(double D);
void viborka(double array[]);

const int NUMBER = 2500; // количество псевдослучайных чисел
double NumbersArray[NUMBER]; // массив псевдослучайных чисел

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "rus");

    int x0 = 2; // начальное значение (выбирается случайно 0 <= x0 < m)
    cout << "Псевдослучайные числа:\n";
    for (int i = 0; i < ::NUMBER; i++)
    {
        NumbersArray[i] = generator(x0); // генерация i-го числа
        cout << NumbersArray[i] << "\n";
    };

    double M = 0; // переменная для матожидания
    M = matozhidanie(NumbersArray);
    cout << "\nМат.ожидание: " << M;

    double D = 0; // переменная для дисперсии
    D = dispersia(NumbersArray, M);
    cout << "\nДисперсия:" << D;

    cout << "\nСреднеквадратичное отклонение: " << srednekvotkl(D) << "\n\n";

    viborka(NumbersArray);

    return 0;
}

double generator(int& x) // функция генерации псевдослучайных чисел
{
    const int m = 187976, // генерация псевдослучайных чисел в диапазоне значений от 0 до 148 (выбирается случайно m > 0)
        a = 9, // множитель (выбирается случайно 0 <= a <= m)
        c = 13; // инкрементирующее значение (выбирается случайно 0 <= c <= m)
    x = ((a * x) + c) % m; // формула линейного конгруэнтного метода генерации псевдослучайных чисел x=(ax+c)mod m
    return (x / double(m));
}

double matozhidanie(double array[]) // функция вычисления мат.ожидания
{
    double M = 0; 
    for (int k = 0; k < ::NUMBER; k++)
        M = M + array[k];
    return(M / double(::NUMBER));
}

double dispersia(double array[], double M) // функция вычисления дисперсии
{
    double D = 0;
    double rasschetArray[NUMBER];
    for (int k = 0; k < ::NUMBER; k++)
    {
        for (int i = 0; i < ::NUMBER; i++)
            rasschetArray[i] = (array[i] - M) * (array[i] - M);
        D = D + rasschetArray[k];
    }
    return(D / double(::NUMBER));
}

double srednekvotkl(double D)
{
    double sko = sqrt(D);
    return(sko);
}

void viborka(double array[])
{
    const int k = 10;
    double intervali[k] = { 0 };
    double sum[k] = { 0 };
    for (int i = 0; i < ::NUMBER; i++)
    {
        if ((array[i] >= 0) && (array[i] <= 0.1))
        {
            intervali[0]++;
            sum[0] = sum[0] + array[i];
        }
        else
        {
            if ((array[i] > 0.1) && (array[i] <= 0.2))
            {
                intervali[1]++;
                sum[1] = sum[1] + array[i];
            }
            else
            {
                if ((array[i] > 0.2) && (array[i] <= 0.3))
                {
                    intervali[2]++;
                    sum[2] = sum[2] + array[i];
                }
                else
                {
                    if ((array[i] > 0.3) && (array[i] <= 0.4))
                    {
                        intervali[3]++;
                        sum[3] = sum[3] + array[i];
                    }
                    else
                    {
                        if ((array[i] > 0.4) && (array[i] <= 0.5))
                        {
                            intervali[4]++;
                            sum[4] = sum[4] + array[i];
                        }
                        else
                        {
                            if ((array[i] > 0.5) && (array[i] <= 0.6))
                            {
                                intervali[5]++;
                                sum[5] = sum[5] + array[i];
                            }
                            else
                            {
                                if ((array[i] > 0.6) && (array[i] <= 0.7))
                                {
                                    intervali[6]++;
                                    sum[6] = sum[6] + array[i];
                                }
                                else
                                {
                                    if ((array[i] > 0.7) && (array[i] <= 0.8))
                                    {
                                        intervali[7]++;
                                        sum[7] = sum[7] + array[i];
                                    }
                                    else
                                    {
                                        if ((array[i] > 0.8) && (array[i] <= 0.9))
                                        {
                                            intervali[8]++;
                                            sum[8] = sum[8] + array[i];
                                        }
                                        else
                                        {
                                            if ((array[i] > 0.9) && (array[i] <= 1.0))
                                            {
                                                intervali[9]++;
                                                sum[9] = sum[9] + array[i];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int l = 0; l < k; l++)
    {
        cout << l + 1 << " столбец гистограммы включает " << intervali[l] << " значений\n";
        cout << sum[l] << " - сумма этих значений\n\n";
    }

    double hi2 = 0;
    for (int h = 0; h < k; h++)
    {
        hi2 = hi2 + (((intervali[h] - 250) * (intervali[h] - 250)) / 250);
    }
    cout << "Хи-квадрат Пирсона: " << hi2 << endl;
}
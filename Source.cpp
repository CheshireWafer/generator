#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double generator(int&); // �������� ������� ��������� ��������������� �����
double matozhidanie(double[]); // �������� ������� ���������� ���.��������
double dispersia(double[], double M); // �������� ������� ���������� ���������
double srednekvotkl(double D);
void viborka(double array[]);

const int NUMBER = 2500; // ���������� ��������������� �����
double NumbersArray[NUMBER]; // ������ ��������������� �����

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "rus");

    int x0 = 2; // ��������� �������� (���������� �������� 0 <= x0 < m)
    cout << "��������������� �����:\n";
    for (int i = 0; i < ::NUMBER; i++)
    {
        NumbersArray[i] = generator(x0); // ��������� i-�� �����
        cout << NumbersArray[i] << "\n";
    };

    double M = 0; // ���������� ��� �����������
    M = matozhidanie(NumbersArray);
    cout << "\n���.��������: " << M;

    double D = 0; // ���������� ��� ���������
    D = dispersia(NumbersArray, M);
    cout << "\n���������:" << D;

    cout << "\n������������������ ����������: " << srednekvotkl(D) << "\n\n";

    viborka(NumbersArray);

    return 0;
}

double generator(int& x) // ������� ��������� ��������������� �����
{
    const int m = 187976, // ��������� ��������������� ����� � ��������� �������� �� 0 �� 148 (���������� �������� m > 0)
        a = 9, // ��������� (���������� �������� 0 <= a <= m)
        c = 13; // ���������������� �������� (���������� �������� 0 <= c <= m)
    x = ((a * x) + c) % m; // ������� ��������� ������������� ������ ��������� ��������������� ����� x=(ax+c)mod m
    return (x / double(m));
}

double matozhidanie(double array[]) // ������� ���������� ���.��������
{
    double M = 0; 
    for (int k = 0; k < ::NUMBER; k++)
        M = M + array[k];
    return(M / double(::NUMBER));
}

double dispersia(double array[], double M) // ������� ���������� ���������
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
        cout << l + 1 << " ������� ����������� �������� " << intervali[l] << " ��������\n";
        cout << sum[l] << " - ����� ���� ��������\n\n";
    }

    double hi2 = 0;
    for (int h = 0; h < k; h++)
    {
        hi2 = hi2 + (((intervali[h] - 250) * (intervali[h] - 250)) / 250);
    }
    cout << "��-������� �������: " << hi2 << endl;
}
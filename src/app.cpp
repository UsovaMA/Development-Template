#include "app.h"

bool  BullAndCow::similarNum(char Mass[], int number)
{
    int count = 0;
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
        {
            if (Mass[i] == Mass[j])
                count++;
        }

    return (count != 0);
}


void  BullAndCow::bullCow() {
    int k = 1;
    int a = 0;
    do {
        if (count == 0) {
            srand(time(NULL));
            for (int i = 1; i < 6; i++)
                rand();
            int i = -1;
            cout << "������� ���� ����� � �����?" << endl;
            while (i < 2 || i > 5) {
                cout << "�� 2 �� 5" << endl;
                cin >> i;
            }
            count = i;
            do {
                PCrand(pc_num, count);
            } while (similarNum(pc_num, count));
        }

        cout << "������� ����� �� " << count << " ���� " << endl;
        cin >> number;
        if (number > (pow(10, count) - 1))
        {
            cout << "������� ����� ������, ���� ������ ���� " << count << endl ;
            continue;
        }
        if (number < pow(10, count - 1))
        {
            cout << "������� ����� ������, ���� ������ ���� " << count << endl;
            continue;
        }
        MassNum(number, me, count);

        if (similarNum(me, count))
        {
            cout << "�������� ���� ���������� ����";
            continue;
        }

         Bull = 0; 
        Cow = 0;  
        for (int i = 0; i < count; i++)
        {
            if (pc_num[i] == me[i])
                 Bull++;
            for (int j = 0; j < count; j++)
                if (pc_num[i] == me[j])
                    Cow++;
        }
        Cow -=  Bull;
        cout << "����� " <<  Bull << "  ###  ����� " << Cow << endl;
    } while ( Bull != count);
    do {
        cout << "������" << endl;
        cout << "1) ����������" << endl;
        cout << "2) �����" << endl;
        cin >> a;
    } while (a < 1 || a > 2);
        if (a == 1) {
            bullCow();
        }
        if (a == 2) {
            exit;
        }
}

void  BullAndCow::PCrand(char Mass[], int number)
{
    MassNum(rand() % 9999, Mass, count);
}

void  BullAndCow::MassNum(int value, char Mass[], int number)
{
    for (int i = count - 1; i >= 0; i--)
    {
        Mass[i] = '0' + value % 10;
        value = value / 10;
    }
}

 BullAndCow:: BullAndCow(int number) {
    if (number < 1 && number > 9999) throw std::logic_error("Input error:wrong number!");
    int k = number;
    for (; number > 0; count++) {
        number /= 10;
    }
    MassNum(k, pc_num, count);

}
#include "..\include\add.h"
#include "..\include\add.h"
#include "add.h"

Date::Date() {
    YMD = new int[4];
    for (int i = 0; i < 4; i++) {
        YMD[i] = 0;
    }
    T = 0;
}

Date::Date(int* _YMD, int _T) {
    YMD = new int[4];
    for (int i = 0; i < 4; i++) {
        YMD[i] = _YMD[i];
    }
    T = _T;
}

Date::Date(const Date& c) {
    YMD = new int[4];
    for (int i = 0; i < 4; i++) {
        YMD[i] = c.YMD[i];
    }
    T = c.T;
}

Date::~Date() {
    delete[] YMD;

    T = 0;
}

Term::Term() {
    count = 0;
}

Term::Term(int* _YMD, int _T) {
    num = new Date[1];
    for (int i = 0; i < 4; i++) {
        num[0].YMD[i] = _YMD[i];
    }
    num[0].T = _T;
}

Term::Term(const Term& c) {
    count = c.count;
    num = new Date[count];
    for (int j = 0; j < c.count; ++j) {
        for (int i = 0; i < 4; i++) {
            num[j].YMD[i] = c.num[j].YMD[i];
        }
        num[j].T = c.num[j].T;
    }
}

Date Date::operator=(Date& c) {
    for (int i = 0; i < 4; i++) {
        YMD[i] = c.YMD[i];
    }
    T = c.T;
    return *this;
}

Term::~Term() {
    if (count != 0) {
        count = 0;
        delete[] num;
    }
}

Term Term::operator=(Term& c) {
    if (count != c.count) {
        if (count != 0) delete[] num;
        num = new Date[count];
        count = c.count;
    }

    for (int i = 0; i < count; i++) {
        num[i] = c.num[i];
    }
    for (int i = 0; i < count; i++) {
        num[i].T = c.num[i].T;
        for (int j = 0; j < 4; j++)
            num[i].YMD[j] = c.num[i].YMD[j];
    }
    return *this;
}

void Term::menu() {
    int month;
    int all;
    int w = 0;
    Date a;
    Term b;

    while (w != 6) {
        do {
            system("CLS");
            cout << "���� ���������� ������������ ����������:" << endl;
            cout << "1) �������� ����� ����������" << endl;
            cout << "2) ������� ���������� �� �����" << endl;
            cout << "3) ����: ������� �����������." << endl;
            cout << "4) ���������� � ������ ����������" << endl;
            cout << "5) ���������� � ����������� �� ��������� ����" << endl;
            cout << "6) �����" << endl;
            cout << "�����: ";
            cin >> w;
            if (w < 1 || w>6) {
                cout << endl << "�� ����� ������������ ����� ��������. ���������:" << endl << endl;
            }
        } while (w < 1 || w>8);
        if (w == 1) {
            system("CLS");
            a.getdate();
            (*this).setdate(a);
            cout << "���������� ���������..." << endl;
            int vid3 = 0;
            while (vid3 != 2) {
                do {
                    cout << "��������� � ����?" << endl;
                    cout << "1)�� " << endl;
                    cout << "1)��� " << endl;
                    cin >> vid3;
                } while (vid3 < 1 || vid3 > 2);
                if (vid3 == 1) {
                    infile();
                    vid3 = 2;
                }
                if (vid3 == 2) {
                    cout << "����� � ����" << endl;
                }
            }
        }
        if (w == 2) {
            outfile();
        }
        if (w == 3) {
            system("CLS");
            int vid2 = 0;
            while (vid2 != 3) {
                do {
                    cout << "1) ������� ����������� �� ������������ �����" << endl;
                    cout << "2) ������� ����������� �� ��� �����" << endl;
                    cout << "3) ����� � ������� ����" << endl;
                    cout << "�����: ";
                    cin >> vid2;
                } while (vid2 < 1 || vid2 > 4);
                if (vid2 == 3) {
                    cout << "����� � ����" << endl;
                }
                if (vid2 == 1) {
                    month = inpmonth();
                    show_sredm(month);
                }
                if (vid2 == 2) {
                    showsredall(0);
                }
            }
        }
        if (w == 4) {
            firstdata();
        }
        if (w == 5) {
            info();
        }
        if (w == 6) {
            exit;
        }
    }
}

void Term::firstdata() {
    if (num[0].YMD[0] < 10) {
        cout << "0" << num[0].YMD[0];
    }
    else {
        cout << num[0].YMD[0];
    }
    if (num[0].YMD[1] < 10) {
        cout << ":" << "0" << num[0].YMD[1];
    }
    else {
        cout << ":" << num[0].YMD[1];
    }
    cout << ":" << num[0].YMD[2] << endl;
    cout << "����� � �����: " << num[0].YMD[3] << endl;
    cout << "����������� �� ���� ������: " << num[0].T << endl << endl;
}

void Term::infile() {
    ofstream in;
    in.open("C:\\iiiip\\Development-Template\\app\\Term.txt");
    for (int i = 0; i < count; i++) {
        if (count == 1) {
            in << endl << "������ ����������: ";
        }
        else {
            in << endl;
            in << "���������� ��: ";
        }
        if (num[i].YMD[0] < 10) {
            in << "0" << num[i].YMD[0];
        }
        else {
            in << num[i].YMD[0];
        }
        if (num[i].YMD[1] < 10) {
            in << ":" << "0" << num[i].YMD[1];
        }
        else {
            in << ":" << num[i].YMD[1];
        }
        in << ":" << num[i].YMD[2] << endl;
        in << "����� � �����: " << num[i].YMD[3] << endl;
        in << "�����������: " << num[i].T << endl << endl;
    }
    in.close();
}

void Term::outfile() {
    string str;
    ifstream out("C:\\iiiip\\Development-Template\\app\\Term.txt");
    if (!out.is_open()) {
        throw logic_error("not find file");
        cout << "�� ������� ������� ����" << endl;
    }
    else {
        while (!out.eof()) {
            str = "";
            getline(out, str);
            cout << str << endl;
        }
    }
    out.close();
}

int Term::inpmonth() {
    Date mon;
    do {
        cout << endl << "������� ����������� �� ������������ ����� " << endl;
        cout << "�����: ";
        cin >> mon.YMD[1];
        if (mon.YMD[1] < 1 || mon.YMD[1] > 12) {
            cout << "������ ����� ������" << endl;
        }
    } while (mon.YMD[1] < 1 || mon.YMD[1] > 12);
    cout << endl;
    return mon.YMD[1];
}

void Term::showsredall(int tr) {
    int ress = sredall(tr);
    if (ress != 0) {
        cout << "������� ����������� �� ��� �����" << ress << endl << endl;
    }
    else {
        cout << "��� ���������� ���" << endl << endl;
    }
}

int Term::sredall(int tr) {
    if (count == 0) {
        count++;
    }
    int k = 0;
    int res = 0;
    int result = 0;
    int f;
    int* temp = new int;
    for (int i = 0; i < count; i++) {
        temp[k] = num[i].T;
        k++;
        f = i;
    }
    if (count >= 2) {
        for (int i = 0; i < k; i++) {
            res = res + temp[i];
        }
        if (k > 1) {
            res = res / k;
            result = res;
        }
        else {
            for (int i = 0; i < count; i++) {
                result = num[i].T;
            }
        }
    }
    else {
        for (int i = 0; i < count; i++) {
            result = num[i].T;
        }
    }
    return result;
}

int Term::sredm(int month) {
    if (count == 0) {
        count++;
    }
    int k = 0;
    int res = 0;
    int result = 0;
    int f;
    int* temp = new int;
    for (int i = 0; i < count; i++) {
        if (month == num[i].YMD[1]) {
            temp[k] = num[i].T;
            k++;
            f = i;
        }
    }
    if (count >= 2) {
        for (int i = 0; i < k; i++) {
            res = res + temp[i];
        }
        if (k > 1) {
            res = res / k;
            result = res;
        }
        else {
            for (int i = 0; i < count; i++) {
                if (month == num[i].YMD[1]) {
                    result = num[i].T;
                }
            }
        }
    }
    else {
        for (int i = 0; i < count; i++) {
            if (month == num[i].YMD[1]) {
                result = num[i].T;
            }
        }
    }
    return result;
}

void Term::show_sredm(int month) {
    int ress = sredm(month);
    if (ress != 0) {
        cout << "������� ����������� �� �����: " << ress << endl << endl;
    }
    else {
        cout << "��� ���������� �� ���� �����" << endl << endl;
    }
}

int Term::returnday() {
    Date get;
    cout << "������� ����, ����� �������� ���������� � ���������. ����,�����,���:" << endl;
    do {
        cout << "������� ����: ";
        cin >> get.YMD[0];
        cout << endl;
        if (get.YMD[0] < 1 || get.YMD[0] > 31) {
            cout << "�������� ���� ���" << endl;
        }
    } while (get.YMD[0] < 1 || get.YMD[0] > 31);
    return get.YMD[0];
}

int Term::returnmonth() {
    Date get;
    do {
        cout << "������� �����: ";
        cin >> get.YMD[1];
        cout << endl;
        if (get.YMD[1] < 1 || get.YMD[1] > 12) {
            cout << "�������� ���� ������" << endl;
        }
    } while (get.YMD[1] < 1 || get.YMD[1] > 12);
    return get.YMD[1];
}

int Term::returnyear() {
    Date get;
    do {
        cout << "������� ���: ";
        cin >> get.YMD[2];
        cout << endl;
        if (get.YMD[2] < 0) {
            cout << "�������� ���� ����" << endl;
        }
    } while (get.YMD[2] < 0);
    return get.YMD[2];
}

int Term::returnhour() {
    Date get;
    do {
        cout << "������� ����� � �����: ";
        cin >> get.YMD[3];
        if (get.YMD[3] < 0 || get.YMD[3] > 23) {
            cout << "�������� ���� �������" << endl;
        }
    } while (get.YMD[3] < 0 || get.YMD[3] > 23);
    return get.YMD[3];
}

int Term::info() {

    cout << endl;
    int* arr = new int[count];
    int day = returnday();
    int month = returnmonth();
    int year = returnyear();
    int hour = returnhour();
    cout << endl;
    for (int i = 0, j = 1; i < count; i++) {
        if (day == num[i].YMD[0] && month == num[i].YMD[1] && year == num[i].YMD[2] && hour == num[i].YMD[3]) {
            cout << j << " ������ " << endl;
            cout << " ����������� �� ��� ����: " << num[i].T << endl << endl;
        }
        else {
            cout << endl << "���������� ���" << endl;
        }
    }
    return true;
}


void Term::setdate(Date new_YMD) {
    Term copy(*this);
    if (count != 0) {
        delete[] num;
    }
    num = new Date[count + 1];
    count = count + 1;
    for (int i = 0; i < count - 1; ++i) {
        num[i] = copy.num[i];
    }
    num[count - 1] = new_YMD;
}
void Date::getdate() {
    cout << "����� ������" << endl;
    do {
        cout << "������� ���: ";
        cin >> YMD[2];
        cout << endl;
        if (YMD[2] < 0) {
            cout << "�������� ���� ����" << endl;
        }
    } while (YMD[2] < 0);
    do {
        cout << "������� �����: ";
        cin >> YMD[1];
        cout << endl;
        if (YMD[1] < 1 || YMD[1] > 12) {
            cout << "�������� ���� ������" << endl;
        }
    } while (YMD[1] < 1 || YMD[1] > 12);
    do {
        cout << "������� ����: ";
        cin >> YMD[0];
        cout << endl;
        if (YMD[0] < 1 || YMD[0] > 31) {
            cout << "�������� ���� ���" << endl;
        }
    } while (YMD[0] < 1 || YMD[0] > 31);
    do {
        cout << "������� ����� � �����: ";
        cin >> YMD[3];
        cout << endl;
        if (YMD[3] < 0 || YMD[3] > 23) {
            cout << "�������� ���� �������" << endl;
        }
    } while (YMD[3] < 0 || YMD[3] > 23);

    cout << "������� ����������� �� ��� ����: ";
    cin >> T;
    system("CLS");
}
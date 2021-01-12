#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { ME, MF, TN, IT, KN };

string strSpecialty[] = { "ME", "MF", "TN", "IT", "KN" };

struct Student
{
    string prizv;
    Specialty specialty;
    short unsigned kurs;
    short unsigned physics;
    short unsigned math;
    union
    {
        short unsigned informatics;
        short unsigned metod;
        short unsigned pedagogika;
    };
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double well_students(Student* s, const int N);
void bestphysics(Student* s, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;


    cout << "Введіть кількість студентів: "; cin >> N;
    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    cout << "| Процент студентів, які вчаться на відмінно " << fixed << setprecision(2) << well_students(s, N) << '%' << setw(29) << "|" << endl;
    cout << "| Прізвища студентів, які отримали з фізики " << char(34) << "5" << char(34) << fixed << setprecision(2) << setw(33) << "|" << endl;
    bestphysics(s, N);
    cout << "================================================================================" << endl;
    delete[] s;
}

void Create(Student* s, const int N)
{
    int kurs, specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - ME, 1 - MF, 2 - TN, 3 - IT, 4 - KN): "; cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "  оцінка з фізики: "; cin >> s[i].physics;
        cout << "  оцінка з математики: "; cin >> s[i].math;
        switch (s[i].specialty)
        {
        case KN:
            cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
            break;
        case IT:
            cout << "  оцінка з чисельних методів: "; cin >> s[i].metod;
            break;
        case ME:
        case MF:
        case TN:
            cout << "  оцінка з з педагогіки: "; cin >> s[i].pedagogika;
            break;
        }
    }
}

void Print(Student* s, const int N)
{
    cout << "==============================================================================================================="
        << endl;
    cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика | Чисельні методи | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(14) << right << strSpecialty[s[i].specialty];
        switch (s[i].specialty)
        {
        case KN:
            cout << "| " << setw(4) << right << s[i].physics << "   "
                << "| " << setw(5) << right << s[i].math << "      ";
            cout << "| " << setw(11) << setprecision(2) << fixed << right
                << s[i].informatics << " |" << setw(18) << right << "|" << setw(13) << right << "|" << endl;
            break;
        case IT:
            cout << "| " << setw(4) << right << s[i].physics << "   "
                << "| " << setw(5) << right << s[i].math << "      ";
            cout << "| " << setw(13) << right << "|" << " " << setw(15) << right
                << s[i].metod << " |" << setw(13) << right << "|" << endl;
            break;
        case ME:
        case MF:
        case TN:
            cout << "| " << setw(4) << right << s[i].physics << "   "
                << "| " << setw(5) << right << s[i].math << "      ";
            cout << "| " << setw(13) << right << " |" << setw(18) << right << "|" << " " << setw(10) << right
                << s[i].pedagogika << " |" << endl;
            break;
        }
    }
    cout << "===============================================================================================================" << endl;
}
double well_students(Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].physics == 5 && s[i].math == 5 && (s[i].informatics == 5 || s[i].metod == 5 || s[i].pedagogika == 5))
            k++;
    return 100.0 * k / N;
}
void bestphysics(Student* s, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5)
            cout << s[i].prizv << endl;
    }
}

#include <iostream>
#include <iomanip>
#include <string>

//3
//Sydorenko 10555
//Petrenko 21545
//Kovalchuk 32555

using namespace std;

enum Spec { KN, INF, ME, FI, TN };
string specStr[] = { "Comp. Science", "Informatics", "Math & Econ.", "Phys. & Inf.", "Labor Educ." };

struct Student
{
    string prizv;
    unsigned kurs;
    Spec spec;
    int fizyka;
    int matematyka;
    int informatyka;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CountExcellentPerSubject(Student* p, const int N, int& cFiz, int& cMat, int& cInf);
int CountExcellentFizAndMat(Student* p, const int N);

int main()
{
    int N;
    cout << "Enter the number of students N: ";
    cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    int cFiz = 0, cMat = 0, cInf = 0;
    CountExcellentPerSubject(p, N, cFiz, cMat, cInf);

    cout << "Number of 'excellent' grades (5):" << endl;
    cout << " - in Physics: " << cFiz << endl;
    cout << " - in Mathematics: " << cMat << endl;
    cout << " - in Informatics: " << cInf << endl << endl;

    int bothExcellent = CountExcellentFizAndMat(p, N);
    cout << "Number of students with '5' in both Physics and Mathematics: "
        << bothExcellent << endl;

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Student # " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " surname: "; getline(cin, p[i].prizv);
        cout << " course: "; cin >> p[i].kurs;
        cout << " specialty (0 - CS, 1 - INF, 2 - ME, 3 - PI, 4 - LE): ";
        cin >> spec;
        p[i].spec = (Spec)spec;

        cout << " Physics grade: "; cin >> p[i].fizyka;
        cout << " Mathematics grade: "; cin >> p[i].matematyka;
        cout << " Informatics grade: "; cin >> p[i].informatyka;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "==================================================================================" << endl;
    cout << "| No |    Surname    |Course|   Specialty   |Physics |Mathematics |Informatics |" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(13) << left << specStr[p[i].spec] << " "
            << "| " << setw(6) << right << p[i].fizyka << " "
            << "| " << setw(10) << right << p[i].matematyka << " "
            << "| " << setw(11) << right << p[i].informatyka << " |" << endl;
    }
    cout << "==================================================================================" << endl << endl;
}

void CountExcellentPerSubject(Student* p, const int N, int& cFiz, int& cMat, int& cInf)
{
    cFiz = 0; cMat = 0; cInf = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5) cFiz++;
        if (p[i].matematyka == 5) cMat++;
        if (p[i].informatyka == 5) cInf++;
    }
}

int CountExcellentFizAndMat(Student* p, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (p[i].fizyka == 5 && p[i].matematyka == 5)
            count++;
    return count;
}
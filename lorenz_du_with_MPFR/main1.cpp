#include "solve_ser.h"

//long double -не берет,пишет -core doumpt

int main()
{
scalar T,x0,y0,z0;

int N = 100; // сто знаков считаем

// Количество бит под мантиссу вещественного числа
int prec = (int) (N / log10(2) );

mpreal::set_default_prec(prec);

system("cp /dev/null output_data.txt");//чистим файл перед прочитыванием

fstream outdata1("output_data.txt");
string str1;
scalar var_R = steps1 * Rad *10.;

cout << "machinnui epsilon = " << machine_epsilon() << endl;
cout << endl;

cout << "введите длину отрезка интегрирования" << endl;
  cin >> var_R;


cout << "введите начальные условия" << endl;

cin >> x0 >> y0 >> z0;

scalar steps_new = var_R/(Rad*10.);

solver_ser1(x0,y0,z0,outdata1,steps_new);



system("./plot_command.gnu ");
cout << "в этой папке создан файлы с графиками X.eps и fasov.eps" <<endl;

outdata1.close();
}

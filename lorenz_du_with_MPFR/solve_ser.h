#ifndef SOLVE_SER_H_INCLUDED
#define SOLVE_SER_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

//библиотека высокоточных вычислений
#include <mpreal.h>
using namespace mpfr;

typedef mpreal scalar;


#define ORDER_SER 60
#define steps1 100  // количество шагов
#define Rad (scalar)0.02

using namespace std;


const scalar r = 28. ,sigma =10. ,b=2.66666666666666666; // точность этого числа очень влияет на общ. точность!!

//-------------------------
bool solver_ser1(scalar &a1,scalar &a2,scalar &a3,std::fstream &file1,scalar &steps);
//-------------------------

//---------------------------
template<typename T1>
inline T1 sum_pr(vector<T1> &SX1,vector<T1> &SX2,int N);
//--------------------------


//---------------------------
template<typename T2>
inline T2 series_create1(vector<T2> &SX,T2 t,int N);
//--------------------------


#endif // SOLVE_SER_H_INCLUDED

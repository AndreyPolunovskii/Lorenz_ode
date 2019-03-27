#include "solve_ser.h"



template<typename T1>
inline T1 sum_pr(vector<T1> &SX1,vector<T1> &SX2,int N)
{

T1 var1=0;

for (int i = 0; i <=N;i++)
  var1 += SX1[i+1]*SX2[N+1-i];

return var1;
}
//-------------------------------------------------

template<typename T2>
inline T2 series_create1(vector<T2> &SX,T2 t,int N)  // сначала пишешь переменные шаблонного типа,а потом конкретного!!!
{
  T2 f1 = 0;

  for (int i = 1 ;i <=N-3;i++)
      f1 += SX[i]*pow(t,i-1);



return f1;

}

//--------------------------------------------------
bool solver_ser1(scalar &a1 ,scalar &a2,scalar &a3,std::fstream &file1,scalar &steps)
{


std::vector<scalar> X(ORDER_SER) , Y(ORDER_SER), Z(ORDER_SER),SXZ;
std::vector<scalar> X_zn,Y_zn,Z_zn,T_zn;
scalar t1_f=0;

for (int k=1 ;k <=10*steps; k++)
  {



     X[1]=a1;
     Y[1]=a2;
     Z[1]=a3;


     
      for (int n=0; n<=ORDER_SER-3; n++)
        {
          X[n+2] = sigma*(Y[n+1]-X[n+1])/((scalar)n+1.);
          Y[n+2] = (r * X[n+1] - sum_pr(X,Z,n)- Y[n+1])/((scalar)n+1.);
          Z[n+2] = (sum_pr(X,Y,n)-b*Z[n+1])/((scalar)n+1.);

        }



     for (int i = 10*(k-1); i <= 10*k;i++)
        {
            t1_f = (i - 10*(k-1))*Rad/10;
            X_zn.push_back(series_create1(X,t1_f,ORDER_SER));
            Y_zn.push_back(series_create1(Y,t1_f,ORDER_SER));
            Z_zn.push_back(series_create1(Z,t1_f,ORDER_SER));
            T_zn.push_back(i*Rad/10);
        }

    a1 = series_create1(X,Rad,ORDER_SER);
    a2 = series_create1(Y,Rad,ORDER_SER);
    a3 = series_create1(Z,Rad,ORDER_SER);
        
 //   X.clear();
 //   Y.clear();
 //   Z.clear();


  }

file1.setf(ios_base::fixed,ios_base::floatfield);//фиксируем плавающую точку
file1.precision(15);//15- количество знаков после запятой,для double 15 - это вроде максимум

 for (int j = 0 ; j < X_zn.size()-2; ++j)
   {
   file1 << T_zn[j] << " " << X_zn[j] << " " << Y_zn[j] << " " << Z_zn[j] << endl;
   }


return 0;
}

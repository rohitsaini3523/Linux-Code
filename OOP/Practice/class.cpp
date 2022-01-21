#include <iostream>
using namespace std;
template<class T>
class calc
{
   public:
      T Add(T, T);
      T Sub(T, T);
      T Mul(T, T);
};
template<class T>
T calc<T>::Add(T x,T y)
{
   T temp = x + y;
   return temp;
}

int main() 
{
   calc c;
   int i = 10, j = 20;
   Add(i,j);
   return 0;
}
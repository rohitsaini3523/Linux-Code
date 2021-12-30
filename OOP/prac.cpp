#include <iostream>
using namespace std;
class a
{
    public:
    virtual void a1()
    {
        cout << "Base" << endl;
    }
};
class b:public a
{
    private:
    virtual void a1()
    {
        cout << "Derived" << endl;
    }
};
main() 
{
    a *x;
    b g;
    x = &g;
    x->a1();

}
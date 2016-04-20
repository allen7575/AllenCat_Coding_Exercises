#include <string>

using namespace std;

class Vector2D{
    public:
        Vector2D(const Vector2D& inputVec);
        Vector2D(string VecName, double X, double Y);
        Vector2D();
        ~Vector2D();
        Vector2D operator+(const Vector2D& inputVec);
        void operator=(const Vector2D& inputVec);
        //why add const? because we want to use this function with const 
        //object that can not be modified. using const to insure that 
        //'this' pointer can't be access in this function.
        double getX() const;
        double getY() const;
        string name;
    private:
        double X;
        double Y;
};

#include <iostream>

using namespace std;

class Figura {
    public:
        Figura ( double x = 0, double y = 0): x(x),y(y) {
        }

        virtual void desenha() const { // virtual permite q o método seja sobrescrito pelas classes filhas
            cout << "N implementado - abstrato";
            cout << " Na posição (" << x << ", " << y << ")" << endl;
        }

        virtual ~Figura() {}

    public:
        double x, y;
};

class Quadrado : public Figura {
    public:
        Quadrado ( double x, double y, double lado): Figura(x, y), lado(lado) {
        }
        Quadrado ( double lado ): Figura(), lado(lado) {}




        virtual void desenha() {
            cout << "Lado do quadrado é " << lado;
            cout << " e a posição é (" << x << ", " << y << ")" << endl;
        }

        ~Quadrado() {
            cout << "Destruindo quadrado" << endl;
        }


    private:
        double lado;
};

void foo( const Figura& f ) {
    f.desenha();
}


int main() {
    Quadrado a(0, 0, 1);
    Figura b(0, 1);

    foo(a);
    foo(b);

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;

    return 0;
}



// g++ 2026_03_24_class5_code.cpp -o executavel
// ./executavel
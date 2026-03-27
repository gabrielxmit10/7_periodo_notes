#include <iostream>

using namespace std;

void foo( int& v ){
    cout << "v: " << v << endl;
    v = 9;
}


int main() {
    
    int  h = 10;
    foo( 34 );
    
    return 0;
}

// g++ 2026_03_26_class6_code.cpp -o executavel
// ./executavel
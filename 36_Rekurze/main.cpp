#include <iostream>

using namespace std;

int faktorial_I(int x){
    int result = 1;
    for(int i = x; i >=1; i--){
        result *=i;
    }
    return result;
}

int faktorial_R(int n){
    if(n <= 1) return 1;
    return n * faktorial_R(n -1);
}

int fibonacci_I(int n){
    int fibnMinus2 = 1;
    int fibnMinus1 = 1;
    int fibN = 1;
    for(int i = 2; i<=n; i++){
        fibnMinus2 = fibnMinus1;
        fibnMinus1 = fibN;
        fibN = fibnMinus1 + fibnMinus2;
    }
    return fibN;
}

int fibonacci_R(int x){
    if(x == 0 || x == 1){
        return 1;
    } else {
        return fibonacci_R(x-1) + fibonacci_R(x-2);
    }
}

int main()
{
    int x = 45;
    /*
    int y = faktorial_I(x);
    int z = faktorial_R(x);

    cout << y << endl;
    cout << z << endl;
    */

    int r2 = fibonacci_I(x);
    cout << "Iterativne Fib_" << x << " = " << r2 << endl;
    int r1 = fibonacci_R(x);
    cout << "Rekurzivne Fib_" << x << " = " << r1 << endl;
    return 0;
}

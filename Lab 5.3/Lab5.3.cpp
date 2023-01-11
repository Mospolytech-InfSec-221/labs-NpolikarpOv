#include <iostream>
#include "Matrix_op_reloadr.h"
int main()
{
    setlocale(LC_ALL, "RUS");
    Matrix A, B;
    Matrix C;
    std::cin >> A;
    std::cin >> B;
    //A + B;
    //std::cout << "\n";
    //std::cout << A;
    // - A;
    //std::cout << "\n";
    //std::cout << A;
    //A * 5;
    //std::cout << A;
    //A* B;
    //std::cout << A;
    // C = A + B;
    //std::cout << C;
    //std::cout << C.get_elem(0, 0);
    //A += B;
    //std::cout << A;
    //-A;
    A += B;
    std::cout << A;
    
    return 0;
}
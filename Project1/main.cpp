//Project 1
//Main.cpp
//Sam Disharoon
#include"matrix.h"
#include<iostream>

int main(int argc, char** argv){
	long unsigned int r,c;

        std::cout<<"How many rows?\n";
        std::cin>>r;
        std::cout<<"How many columns?\n";
        std::cin>>c;
        Matrix A1(r,c);
	A1.fill();
	A1.print();
        std::cout<<"====\nAfter Padding:\n====\n";
        A1.pad();
	A1.print();
	Matrix A2;
        A2=A1;//Shows off assignment operator
        A2.print();
        std::cout<<"====\n";
        Matrix A3=A1;//Shows off copy ctor
        std::cout<<"Adding 2 matricies\n";
        A3=(A1+A2);
        A3.print();
        Matrix A4;
        std::cout<<"Multiplying 2 matricies\n";
        A4.mul(A1,A2);
        A4.print();
        Matrix A5;
        std::cout<<"Subtracting 2 matricies\n";
        A5 =(A3-A2);
       	A5.print();
	std::cout<<"Transpose of A1 is:\n";
	Matrix A6;
	A6=A1.trans();
	A6.print();
//	A1.inv();
//	A1.print();
	std::cout<<"===========================\n";


return 0;
}

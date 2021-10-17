#include <iostream>
#include "node.h"
#include "quadTree.h"

int main()
{
    Point p1 = {4, 5};
    Point p2 = {1, 2};    
    Point p3 = {7, 7};
    Point p4 = {3, 8};

    QuadTree qt;

    qt.insert(p1);
    qt.insert(p2);
    qt.insert(p3);
    qt.insert(p4);
    

    // qt.print();
    std::cout << qt.query(Point{0, 0}, Point{5, 5}) << std::endl;


    std::cout<< qt.getRoot()->toString() << std::endl;

    return 0;
}
    
    
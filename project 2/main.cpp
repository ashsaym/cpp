#include <iostream>
#include <cmath>

struct Points{
    int x{},y{};
    double Distance_origin{};
    std::string point_name;
};

double calculateOrigin(struct Points *ptr){
    int fx, fy;
    double dxy;
    fx = (*ptr).x - 0;
    fy = (*ptr).y - 0;
    (*ptr).Distance_origin = std::sqrt((fx*fx) + (fy*fy));
    dxy = (*ptr).Distance_origin;
    return dxy;
}

int main() {
    Points *ptr,d;
    ptr = &d;
    std::cout<<"Enter points name :";
    std::cin>>(*ptr).point_name;
    std::cout<<std::endl;
    std::cout<<"Enter x ";
    std::cin>> (*ptr).x;
    std::cout<<std::endl;
    std::cout<<"Enter y :";
    std::cin>>(*ptr).y;
    std::cout<<std::endl;
    std::cout<<"Distance from origin :"<<calculateOrigin(ptr);
    std::cout<<std::endl;
    return 0;
}
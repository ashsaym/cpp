#include <iostream>
#include <cmath>

struct Points{
    int x,y;
    double Distance_origin;
    std::string point_name;
};

double calculateOrigin(struct Points *ptr){
    double fx, fy , dxy;
    fx = (*ptr).x - 0;
    fy = (*ptr).y - 0;
    (*ptr).Distance_origin = std::sqrt(((fx*fx) + (fy*fy))* 1.0);
    dxy = (*ptr).Distance_origin;
    return dxy;
}


int main() {
    Points *ptr,d[10];
    ptr = d;
    for (int i = 0; i < 3; ++i) {
        std::cout<<"Enter points name :";
        std::cin>>ptr[i].point_name;
        std::cout<<std::endl;
        std::cout<<"Enter x ";
        std::cin>> ptr[i].x;
        std::cout<<std::endl;
        std::cout<<"Enter y :";
        std::cin>>ptr[i].y;
        std::cout<<std::endl;
        ptr[i].Distance_origin = calculateOrigin(&ptr[i]);
        std::cout<<"Distance from origin :"<<ptr[i].Distance_origin;
        std::cout<<std::endl;
    }
    std::cout<<"Point\t"<<"x\t"<<"y\t"<<"distance"<<std::endl;
    for (int j = 0; j < 3; ++j) {
        std::cout<<ptr[j].point_name<<"\t"<<ptr[j].x<<"\t"<<ptr[j].y<<"\t"<<ptr[j].Distance_origin<<std::endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    std::string name;
    double x,y, Distances;
    struct Point *next;
};

struct Point* Start;

double calculateOrigin(struct Point*);
double Euclidian_distance(Point*, Point*);
Point* Get_New_Point(std::string);
void Add_Point(std::string);
void Delete_Point(Point **, std::string);
void deleteList(Point**);
void Print();
void Print_Points();
Point *Sort();
string Nearest(Point*);


int main()
{
    Start = nullptr;
    std::string x;
    std::cout<<"string describing obstacle (\"end\" for end of input):";
    std::cin>>x;

    while (x != "end"){
        Add_Point(x);
        std::cout<<"string describing obstacle (\"end\" for end of input):";
        std::cin>>x;
    }
    Start = Sort();
    while (Start != nullptr){
        Print();
        Print_Points();
        std::cout<<std::endl<<"delete (\"Point\" or \"all\") : ";
        std::cin>>x;
        if (x != "all"){
            Delete_Point(&Start,x);
        } else{
            deleteList(&Start);
        }
    }
    delete(Start);
    std::cout<<"Exiting the program...";
    return EXIT_SUCCESS;
}


double calculateOrigin(struct Point *ptr){
    double fx, fy , dxy;
    fx = (*ptr).x - 0;
    fy = (*ptr).y - 0;
    (*ptr).Distances = sqrt(((fx*fx) + (fy*fy))* 1.0);
    dxy = (*ptr).Distances;
    return dxy;
};


double Euclidian_distance(Point * p1 , Point * p2){
    int x1,x2,y1,y2;
    double fx,fy,d;
    x1 = p1->x;
    x2 = p2->x;
    y1 = p1->y;
    y2 = p2->y;
    fx = pow(((x1)-(x2)), 2);
    fy = pow(((y1)-(y2)),2);
    d = sqrt(fx+fy);
    return d;
}

Point* Get_New_Point(std::string N) {
    Point *newNode;
    newNode = new Point;
    newNode->name = N;

    std::cout<<endl<<"Enter X : ";
    std::cin>>newNode->x;

    std::cout<<"Y : ";
    std::cin>>newNode->y;
    newNode->Distances = calculateOrigin(newNode);
    std::cout<<std::endl;

    newNode->next = nullptr;
    return newNode;
}

void Add_Point(std::string N) {
    Point* newNode = Get_New_Point(N);
    if(Start == nullptr) {
        Start = newNode;
        return;
    }
    newNode->next = Start;
    Start = newNode;
}

Point *Sort()
{
    Point * list_end = nullptr;
    while(list_end != Start)
    {
        Point *temp, *swap1;
        swap1 = Start;
        while( swap1->next != list_end )
        {
            if(swap1->Distances > swap1->next->Distances)
            {
                Point *swap2 = swap1->next;
                swap1->next = swap2->next;
                swap2->next = swap1;
                if(swap1 == Start)
                {
                    Start = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->next = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->next;
        }
        list_end = swap1;
    }
    return  list_end;
}

string Nearest(Point* Near){
    int min = INT_MAX;
    string sm;
    double d;
    Point* temp = Start;
    while (temp!= nullptr){
        if (temp == Near){
            temp = temp->next;
        } else{
            d = Euclidian_distance(Near,temp);
            if (min > d){
                min = d;
                sm = temp->name;
            }
            temp = temp->next;
        }
    }
    return  sm;
}

void Delete_Point(Point **List, std::string value)
{
    Point *current, *previous;
    previous = nullptr;
    for (current = *List;current != nullptr;previous = current, current = current->next) {
        if (current->name == value) {
            if (previous == nullptr) {
                *List = current->next;
            } else {
                previous->next = current->next;
            }
            cout << "Deleting : " << current->name << "\n";
            if (*List == nullptr){
                std::cout<<"No Points are in the list. The list is empty.."<<std::endl;
            }
            delete(current);
            return;
        } else{
            cout << "Value " << current->name << " does not match " << value << ".\n";
        }
    }
}
void deleteList(Point** Start)
{
    Point* current = *Start;
    Point* next;

    while (current != nullptr)
    {
        next = current->next;
        delete(current);
        current = next;
    }
    *Start = nullptr;
}
void Print() {
    struct Point* temp = Start;
    std::cout<<std::endl;
    while(temp != nullptr) {
        std::cout<<"obstacle "<<temp->name <<" : ("<<temp->x<<","<<temp->y<<")\tdistance : "<< temp->Distances<<"m\t"<<"nearest\t"<<Nearest(temp)<<std::endl;
        temp = temp->next;
    }
}
void Print_Points() {
    struct Point* temp = Start;
    std::cout<<std::endl;
    std::cout<<"Points : ";
    while(temp != nullptr) {
        std::cout<<temp->name<<" ";
        temp = temp->next;
    }
}

#include <iostream>
enum  timeZones : unsigned int {
    ACT,CET,CST,EST,GMT,MSK,PST,UTC
};
enum arrivalDeparture {
    arrival,departure
};

class LocalTime;
void set_time (int , int );
int get_hour ();
int get_minute();
bool is_valid ();


int main() {
    int temp = 0 ;
    temp = timeZones::MSK;
    std::cout << temp << std::endl;
    return 0;
}

class LocalTime{
private:
    int minutes;
    timeZones TimeZone;
public:
    LocalTime(){
        minutes = -1;
        TimeZone = CET;
    }
    LocalTime(int hour, int minute, timeZones TimeZone){
        TimeZone = CET;
        set_time(hour,minute);
        get_hour();
        get_minute();
        is_valid ();
    }
};

void set_time (int hour , int minute){
    int maxHours = 24;
    int maxMinutes = 24*60;
    int minValues = 0;
    bool validHours,validMinutes;
    validHours = hour >= minValues && hour <= maxHours;
    validMinutes= minute >= minValues && hour <= maxMinutes;
    if (!validHours || !validMinutes){
        std::cout<<std::endl<<"Please enter valid time"<<std::endl;
    }
};

int get_hour (){
    int hours;
    return hours;
};

int get_minute(){
    int minutes;
    return minutes;
};
bool is_valid (){
    bool valid;
    return valid;
};

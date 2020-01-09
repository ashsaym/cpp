#include <iostream>
enum  timeZones : unsigned int {
    ACT,CET,CST,EST,GMT,MSK,PST,UTC
};
enum arrivalDeparture {
    arrival,departure
};

class LocalTime;
class Flight;
class Airport;

std::ostream& operator<<(std::ostream& , LocalTime&);


int main() {
    int temp , hours,minute;
    std::cin>> temp;
    hours = temp / 60;
    minute = temp % 60;
    std::cout << temp<<"\t" << hours<<"\t"  << minute<<std::endl;
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
    LocalTime(int , int , timeZones);
    void set_time (int , int );
    int get_hour ();
    int get_minute();
    bool is_valid ();
};

LocalTime::LocalTime(int hour, int minute, timeZones TimeZone = CET) {
    set_time(hour,minute);
    get_hour();
    get_minute();
    is_valid ();
}

void LocalTime::set_time(int hour, int minute) {
    bool validHours,validMinutes;
    validHours = hour >= 0 && hour <= 24;
    validMinutes= minute >= 0 && hour <= 60;
    if (!validHours){
        hour = -1;
        std::cout<<std::endl<<"Please enter valid hours"<<std::endl;
    }
    if (!validMinutes){
        minute = -1;
        std::cout<<std::endl<<"Please enter valid minutes"<<std::endl;
    }
}

int LocalTime::get_hour() {
    int hours;
    hours = minutes / 60;
    return hours;
}

int LocalTime::get_minute() {
    int temp_minutes;
    temp_minutes = minutes % 60;
    return temp_minutes;
}

bool LocalTime::is_valid() {
    bool valid = false;
    if (minutes<= 24*60 && minutes<=0){
        valid = true;
    } else{
        std::cout<<std::endl<<"Please enter valid time";
    }
    return valid;
}

std::ostream& operator<<(std::ostream& output, LocalTime& localTime){
    output<<localTime.get_hour()<<":"<<localTime.get_minute();
    return output;
}

class Flight{
private:
    arrivalDeparture arrivalOrDeparture;
    std::string code, destination,gate,checkIn,comment;
    LocalTime expected;
public:
    Flight(std::string, std::string, std::string, std::string ,std::string);
    ~Flight();
    std::string get_code();
    std::string get_destination();
    std::string get_gate();
    std::string get_checkIn();
    std::string get_comment();
    LocalTime get_scheduled();
    void set_expected(LocalTime);
    void set_comment(std::string );
    bool is_arrival();
    bool is_departure();
    void print(LocalTime);
};

Flight::Flight(std::string code, std::string destination, std::string gate,
               std::string checkIn , std::string comment = "") {
    code = code;
    destination = destination;
    gate = gate;
    checkIn = checkIn;
    comment = comment;
}

Flight::~Flight() {
    std::cout<<code<<std::endl;
}

std::string Flight::get_code() {
    return std::__cxx11::string();
}

std::string Flight::get_destination() {
    return std::__cxx11::string();
}

std::string Flight::get_gate() {
    return std::__cxx11::string();
}

std::string Flight::get_checkIn() {
    return std::__cxx11::string();
}

std::string Flight::get_comment() {
    return std::__cxx11::string();
}

LocalTime Flight::get_scheduled() {
    return LocalTime();
}

void Flight::set_expected(LocalTime) {

}

void Flight::set_comment(std::string) {

}

bool Flight::is_arrival() {
    return false;
}

bool Flight::is_departure() {
    return false;
}

void Flight::print(LocalTime) {

}


class Airport{
private:
    std::string name;
    Flight * slot [24][60] = {nullptr} ;
public:
    Airport(std::string);
    ~Airport();
    void schedule(LocalTime , Flight *);
    void comment(LocalTime , std::string );
    void delay(LocalTime,LocalTime);
    void print(arrivalDeparture);

};

Airport::Airport(std::string name) {

}

Airport::~Airport() {
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; ++j) {
            delete slot[i][j];
        }
    }
}

void Airport::schedule(LocalTime localTime, Flight * slot) {
    slot = slot;
}

void Airport::comment(LocalTime localTime, std::string comment) {
    comment = comment;
}

void Airport::delay(LocalTime localTime_1, LocalTime localTime_2) {
    LocalTime temp = localTime_1;
    localTime_1=localTime_2;
}

void Airport::print(arrivalDeparture status) {

}





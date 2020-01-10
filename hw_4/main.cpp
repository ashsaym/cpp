#include <iostream>
#include <utility>
enum  timeZones : unsigned int {
    ACT,CET,CST,EST,GMT,MSK,PST,UTC
};
enum arrivalDeparture {
    arrival,departure
};

class LocalTime{
private:
    int LT_minutes;
    timeZones LT_timeZones;
public:
    LocalTime(){
        LT_minutes = -1;
        LT_timeZones = CET;
    }

    LocalTime(int,int,timeZones);
    void set_time (int , int );
    int get_hour ();
    int get_minute();
    bool is_valid ();
};

LocalTime:: LocalTime(int hour,int minute,timeZones TZ=CET) {
    set_time(hour,minute);
    LT_timeZones=TZ;
}

void LocalTime::set_time(int hour, int minute) {
    bool validHours,validMinutes;
    validHours = hour >= 0 && hour < 24;
    validMinutes= minute >= 0 && hour < 60;
    if (!validHours){
        hour = -1;
        std::cout<<std::endl<<"Please enter valid hours"<<std::endl;
    }
    if (!validMinutes){
        minute = -1;
        std::cout<<std::endl<<"Please enter valid minutes"<<std::endl;
    }
    if (validHours && validMinutes){
        LT_minutes = (hour*60)+minute;
    }
}

int LocalTime::get_hour() {
    int temp_hours;
    temp_hours = LT_minutes / 60;
    return temp_hours;
}

int LocalTime::get_minute() {
    int temp_minutes;
    temp_minutes = LT_minutes % 60;
    return temp_minutes;
}

bool LocalTime::is_valid() {
    return LT_minutes <= 24 * 60 && LT_minutes >= 0;
}

std::ostream& operator<<(std::ostream& output, LocalTime& localTime){
    if(localTime.is_valid()){
        output<<localTime.get_hour()<<":"<<localTime.get_minute();
    }
    return output;
}

class Flight{
private:
    arrivalDeparture arrivalOrDeparture;
    std::string code, destination,gate,checkIn,comment;
    LocalTime expected;
public:
    Flight(arrivalDeparture,std::string, std::string, std::string, std::string ,std::string);
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

Flight::Flight(arrivalDeparture F_status,std::string F_code, std::string F_destination, std::string F_gate,
               std::string F_checkIn , std::string F_comment = "") {
    arrivalOrDeparture = F_status;
    code = F_code;
    destination = F_destination;
    gate = F_gate;
    checkIn = F_checkIn;
    comment = F_comment;
}

Flight::~Flight() {
    std::cout<<std::endl<<code<<"\tdeleted";
}

std::string Flight::get_code() {
    return code;
}

std::string Flight::get_destination() {
    return destination;
}

std::string Flight::get_gate() {
    return gate;
}

std::string Flight::get_checkIn() {
    return checkIn;
}

std::string Flight::get_comment() {
    return comment;
}

LocalTime Flight::get_scheduled() {
    return expected;
}

void Flight::set_expected(LocalTime F_expected) {
    expected = F_expected;
}

void Flight::set_comment(std::string F_comment) {
    comment=F_comment;
}

bool Flight::is_arrival() {
    return arrivalOrDeparture == arrival;
}

bool Flight::is_departure() {
    return arrivalOrDeparture == departure;
}

void Flight::print(LocalTime F_scheduled) {
    std::cout<<code<<"\t"<<destination<<"\t\t"<<F_scheduled<<"\t\t"<<expected<<"\t\t"<<gate<<"\t"<<checkIn<<"\t"<<comment;
}


class Airport{
private:
    std::string name;
    Flight * slot[24][60];
public:
    Airport(std::string);
    ~Airport();
    void schedule(LocalTime , Flight *);
    void comment(LocalTime , std::string );
    void delay(LocalTime,LocalTime);
    void print(arrivalDeparture);

};

Airport::Airport(std::string airportName) {
    name = airportName;
    for (int i = 0; i <= 24; i++)
    {
        for (int j = 0; j <= 60; ++j) {
            slot[i][j] = nullptr;
        }
    }
}

Airport::~Airport() {
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; ++j) {
            delete slot[i][j];
        }
    }
}

void Airport::schedule(LocalTime A_LocalTime, Flight * A_slot) {
    int hour = A_LocalTime.get_hour();
    int  minute = A_LocalTime.get_minute();
    slot[hour][minute] = A_slot;
}

void Airport::comment(LocalTime A_LocalTime, std::string A_comment) {
    int hour = A_LocalTime.get_hour();
    int  minute = A_LocalTime.get_minute();
    slot[hour][minute] -> Flight::set_comment(A_comment);
}

void Airport::delay(LocalTime A_LocalTime_1, LocalTime A_LocalTime_2) {
    int hour , minute;
    hour= A_LocalTime_1.get_hour();
    minute = A_LocalTime_1.get_minute();
    slot[hour][minute] -> set_expected(A_LocalTime_2);
}

void Airport::print(arrivalDeparture status) {
    if(status==arrival)
    {
        std::cout<<name<<" arrival"<<std::endl;
        std::cout<<"==========================="<<std::endl;
        std::cout<<"Flight"<<"\t"<<"From"<<"\t\t\t"<<"Scheduled"<<"\t"<<"Expected"<<"\t"<<"Gate"<<"\t"<<"Check-in"<<"\t"<<"Comments"<<std::endl;
    }
    if(status==departure)
    {
        std::cout<<std::endl<<name<<" departure"<< std::endl;
        std::cout<<"==========================="<<std::endl;
        std::cout<<"Flight"<<"\t"<<"From"<<"\t\t\t"<<"Scheduled"<<"\t"<<"Expected"<<"\t"<<"Gate"<<"\t"<<"Check-in"<<"\t"<<"Comments"<<std::endl;
    }
    int m,n;
    for(m=0;m<24;m++){
        for(n=0;n<64;n++){
            if(slot[m][n]!=nullptr){
                LocalTime localTime(m,n);
                if(status==arrival)
                {
                    if(slot[m][n]->is_arrival()){
                        slot[m][n]->print(localTime);
                        std::cout<<std::endl;
                    }
                }else
                {
                    if(slot[m][n]->is_departure()){
                        slot[m][n]->print(localTime);
                        std::cout<<std::endl;
                    }
                }
            }
        }
    }
}

int main() {
    Airport airport_name("Dusseldorf Airport");

    Flight* name_1=new Flight(arrival,"LH 2010","Munich\t","A04 ","");
    Flight* name_2=new Flight(arrival,"EW 9347","Manchester","B04 ","");
    Flight* name_3=new Flight(departure,"AF 1307","Paris\t","B51 ","192-194 ");
    Flight* name_4=new Flight(departure,"SU 2637","Moscow\t","C31 ","252-255 ");
    Flight* name_5=new Flight(departure,"EW 9466","London-Heathrow","B35 ","151-170 ");
    Flight* name_6=new Flight(departure,"LH 2011","Munich\t","A40 ","115-120 ");
    Flight* name_7=new Flight(departure,"XQ 959", "Izmir\t","C45 ","240-242 ");

    LocalTime schedule_1(12,40);
    LocalTime schedule_2(14,50);
    LocalTime schedule_3(9,10);
    LocalTime schedule_4(10,40);
    LocalTime schedule_5(11,15);
    LocalTime schedule_6(13,25);
    LocalTime schedule_7(14,55);

    LocalTime deley_1(13,5);
    LocalTime deley_2(15,20);

    airport_name.schedule(schedule_1,name_1);
    airport_name.schedule(schedule_2,name_2);
    airport_name.schedule(schedule_3,name_3);
    airport_name.schedule(schedule_4,name_4);
    airport_name.schedule(schedule_5,name_5);
    airport_name.schedule(schedule_6,name_6);
    airport_name.schedule(schedule_7,name_7);

    airport_name.delay(schedule_1,deley_1);
    airport_name.delay(schedule_7,deley_2);

    airport_name.comment(schedule_3,"departed");
    airport_name.comment(schedule_4,"boarding");
    airport_name.comment(schedule_6,"Code Sharing");

    airport_name.print(arrival);
    airport_name.print(departure);

    return 0;
}




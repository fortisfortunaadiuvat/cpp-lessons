#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

class  Time{
private:
    int hour;
    int minute;
    int second;
public:
    float  calculate_second();
    void set_value_of_time(int hour,int minute,int second){
        this->hour   = hour;
        this->minute = minute;
        this->second = second;
    }
    int get_value_of_time_hour(){
        return  this->hour ;
    }
    int get_value_of_time_minute(){
        return  this->minute ;
    }
    int get_value_of_time_second(){
        return  this->second ;
    }
};

float  Time::calculate_second() {
    return  (360*hour) + (60*minute) + second ;
}

int main() {

    Time time1[10];

    srand (time(nullptr));

    for (int i = 0; i < sizeof(time1) / sizeof(time1[0]); i++) {
        time1[i].set_value_of_time(rand() %24,rand() %24,rand() %24);
    }

    for (int i = 0; i < sizeof(time1) / sizeof(time1[0]); i++) {
        std::string text = "time ";
        text += std::to_string(i);
        std::cout << text << std::endl;
        std::cout << time1[i].get_value_of_time_hour() << std::endl;
        std::cout << time1[i].get_value_of_time_minute() << std::endl;
        std::cout << time1[i].get_value_of_time_second() << std::endl;
        std::cout << time1[i].calculate_second() << std::endl;
        std::cout << "" << std::endl;
    }

    return 0;
}

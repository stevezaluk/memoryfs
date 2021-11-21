#include <iostream>
#include <ctime>

using namespace std;

string getCurrentDateTime() {
    time_t now = time(0);
    char *datetime = ctime(&now);
    return string(datetime);   
}
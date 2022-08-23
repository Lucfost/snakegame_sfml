#include <iostream>
#include "Application.hpp"
#include <string>
using namespace std;

int main()
{
    Application application;
    application.build(900, 900); // It is determined to what extent the application will work.
    application.run(60); // You can run the application at any fps you want.
}
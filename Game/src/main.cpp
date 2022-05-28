#include "epch.h"

#include "Game/App.h"


int main()
{

    App::App* application = new App::App();

    application->Run();
    
    delete application;
    return 0;
}

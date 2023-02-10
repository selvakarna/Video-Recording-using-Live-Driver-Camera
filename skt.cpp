unter after each frame update. Dividing the frame counter by the program's uptime gives you the FPS.

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;

steady_clock::time_point first_tp;
unsigned long frame_count = 0;

duration<double> uptime()
{
    if (first_tp == steady_clock::time_point{})
        return duration<double>{ 0 };

    return steady_clock::now() - first_tp;
}

double fps()
{
    const double uptime_sec = uptime().count();

    if (uptime_sec == 0)
        return 0;

    return frame_count / uptime_sec;
}

void time_consuming_function()
{
    std::this_thread::sleep_for(milliseconds{ 100 });
}

void run_forever()
{
    std::cout << "fps at first: " << fps() << '\n';

    first_tp = std::chrono::steady_clock::now();

    while (true)
    {
        std::cout << "fps: " << fps() << '\n';
        
        time_consuming_function();

        frame_count++;
    }
}

int main()
{
    run_forever();
}


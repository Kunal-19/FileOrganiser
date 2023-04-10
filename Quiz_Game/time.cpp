#include<iostream>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

class generate_clock{
    public:
    int hr,min,sec;

    generate_clock(int hr,int min,int sec){
        this->hr = hr;
        this->min = min;
        this->sec = sec;
    }

    void clk(){
        for(int i= hr; i>=0; i--){
            for(int j = min; j>=0; j--){
                for(int k = sec; k>0;k--){
                    showTime();
                    sleep(1);
                    sec--;
                }
                min--;
                sec = 60;
            }
            hr--;
            min = 59;
        }
    }

    void showTime(){
        printf("\033[%d;%dH", 9, 120);
        cout << "\033[31;1m" <<hr << ":" << min << ":" << sec<< "\033[31;1m" << "\r" << flush; //The color code "\033[32m" specifies the ANSI escape code for the color green in the terminal.

        // \r: takes the cursor back to the original position
        // flush : flushes the output stream to avoid unexpected behaviour
    }
};

int main(){
    generate_clock clk(3,0,0);
    clk.clk();
    return 0;
}
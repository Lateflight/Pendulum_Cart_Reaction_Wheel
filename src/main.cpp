#include "../inc/simulator.hpp"

int main(void){
    sim::Pendulum P;
    sim::Cart C;
    sim::simulate(P,C,40000);
    return 0;
}
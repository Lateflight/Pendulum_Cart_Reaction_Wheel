#include <array>
#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <array>
#include "../inc/simulator.hpp"
#include "../inc/logger.hpp"
#define DT 0.002
#define STATE_COUNT 9


void sim::simulate(sim::Pendulum& P, sim::Cart& C, const int SIM_LENGTH){
        float theta_dot = 0.0f;
        float dt = DT;
        float t = 0;
        std::cout << "\n";
        std::array<std::string,STATE_COUNT> title = {"Time (s)","Theta","Theta dot","Omega","Omega dot","X","Y","dX/dt","dY/dt"};
        logger::make_csv_columns(title);
        for (int i = 0; i < SIM_LENGTH; i++){

            std::array<float,RW_STATE_PARAM> current_state = P.getRWstate();
            
            float theta = (current_state)[0];
            float length = P.getLength();
            float moment = P.getMoment();
            //TEMP: Euler here is just to check that it even works
            logger::log_nums(t, current_state);
            t = static_cast<float>(i)*dt;
            theta_dot += STANDARD_GRAVITY*std::sin(theta)*length*P.getMass()/(moment)*dt;
            theta += theta_dot*dt;
            (current_state) = {theta,theta_dot,0,0};
             

        }
        logger::console_log();


    }

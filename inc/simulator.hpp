#pragma once

#include <array>

constexpr int RW_STATE_PARAM = 4;
constexpr float STANDARD_GRAVITY = 9.81f;


namespace sim {

    class Pendulum {
    private:
        const float length = 2.0f;
        float theta = 0.1f;
        const float mass = 1.0f;
        const float radius_wheel = 1.0f;
        const float moment_of_inertia = 0.5f * mass * radius_wheel * radius_wheel + mass * length * length;

        std::array<float, 2> pivot_location = {0.0f, 0.0f};

        // theta, theta_dot, wheel_angle, wheel_angular_velocity
        std::array<float, RW_STATE_PARAM> rw_state_vector =
            {theta, 0.0f, 0.0f, 0.0f};

    public:
        std::array<float, 2> pivot() const {
            return pivot_location;
        }
        
        void pivot_update(std::array<float,2> pivot_pos){
            pivot_location = pivot_pos;
        }

        std::array<float, RW_STATE_PARAM>& getRWstate() {
            return rw_state_vector;
        }

        float getLength() const {
            return length;
        }

        float getMass() const {
            return mass;
        }

        float getMoment() const {
            return moment_of_inertia;
        }
    };

    
    
    class Cart{

        private:

            const float mass = 1.0f;
            std::array<float, RW_STATE_PARAM> cart_state_vector = {0.0f, 0.0f, 0.0f, 0.0f};

        public:

            std::array<float, RW_STATE_PARAM>& getCartstate() {
            return cart_state_vector;
        }
    };
    
    
    
    
    
    void simulate(Pendulum& P, Cart& C,const int SIM_LENGTH);
    








}
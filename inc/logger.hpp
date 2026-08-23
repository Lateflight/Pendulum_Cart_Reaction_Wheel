#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include <string>
namespace logger{



    inline std::ofstream output("output.csv");

    template <size_t Num>

    void make_csv_columns(std::array<std::string,Num> title){

        for (size_t i = 0; i< title.size(); i++){
            output << title[i] << "," << " ";
        }

        output << "\n";
        }

    template <size_t Num>
    void log_nums(float t, std::array<float,Num> state_array){

        output << t << ",";
        for (size_t j = 0; j<(state_array).size(); j++){
            output << (state_array)[j] << "," << " ";
        }
        output << "\n";
    }
        
    void console_log(){
        
        std::ifstream file("output.csv");
        if (!file.is_open()){
            std::cerr << "exitcode 2";
            return;
        } 
        std::string line;
        while (std::getline(file,line)){
            std::cout << line << std::endl;
        }
    }


}
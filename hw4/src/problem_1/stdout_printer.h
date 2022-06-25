#include "printer.h"
#include <iostream>

class StdoutPrinter : public Printer {
public:
    void print(std::string val) override {
        /*
         * TODO: homework
         */
        std::cout << val << std::endl;
    }
};
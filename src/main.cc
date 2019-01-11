#include <iostream>
#include <tuple>
#include <boost/program_options.hpp>

#include "include.h"

namespace po = boost::program_options;

int main(int argc, char** argv) { 
    po::options_description desc("Allowed Options");
    desc.add_options()
        ("day", po::value<int>(), "Day of AOC")
        ("part", po::value<int>(), "Part of Day")
        ("input-file", po::value<std::string>(), "input file")
    ;

    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(
            po::command_line_parser(argc, argv).
            options(desc).positional(p).run(), vm);
    po::notify(vm);

    int day = vm["day"].as<int>();
    int part = vm["part"].as<int>();
    std::string input_file = vm["input-file"].as<std::string>();

    // TODO: definitely a better way of doing this.
    if (day == 1) {
        if (part == 1) {
            std::cout << day1::part1::solution(input_file) << std::endl;
        } else {
            std::cout << day1::part2::solution(input_file) << std::endl;
        }
    } else {
        std::cout << "Unimplemented" << std::endl;
        return 1;
    }
    return 0;
}

#include <fstream>

namespace day1 
{
    namespace part1
    {
        int solution(std::string filename) {
            std::ifstream input (filename);

            int running_sum = 0;
            int n = 0;
            while (input >> n) {
                running_sum += n;
            }

            return running_sum;
        }
    }
}

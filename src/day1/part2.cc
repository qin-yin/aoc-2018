#include <fstream>
#include <set>

namespace day1
{
    namespace part2
    {
        int solution(std::string filename) {
            std::ifstream input(filename);

            int running_sum = 0;
            int n = 0;
            std::set <int> memo;
            memo.insert(running_sum);

            while (true) {
                while (input >> n) {
                    running_sum += n;

                    if (memo.find(running_sum) == memo.end()) {
                        memo.insert(running_sum);
                    } else {
                        return running_sum;
                    }
                }

                input.clear();
                input.seekg(0);
            }
        }
    }
}

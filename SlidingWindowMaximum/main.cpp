
#include "Solution.hpp"
using namespace std;
int main()
{
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    
    Solution solution;
    solution.maxSlidingWindow(input,3);
    return 0;
}
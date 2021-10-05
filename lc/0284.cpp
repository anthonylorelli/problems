// 0284. Peeking Iterator
// Problem definition: https://leetcode.com/problems/peeking-iterator/
// Accepted 2021-01-30
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
public:
	struct Data;
	Data* data;
	Iterator(const std::vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums) { }
	
	int peek() {
		return Iterator{*this}.next();
	}
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<int,int,int>> input {
//         {3,7,28},
//         {3,2,3},
//         {7,3,28},
//         {3,3,6}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [m, n, expected] = p;
//                 REQUIRE(s.uniquePaths(m, n) == expected);
//             });
//     }
// }

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

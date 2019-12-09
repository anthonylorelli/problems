// 1233. Remove Sub-Folders from the Filesystem
// Problem definition: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Remove Sub-Folders from the Filesystem]") {
    std::vector<std::pair<std::vector<std::string>,std::vector<std::string>>> input {
        {{"/a","/a/b","/c/d","/c/d/e","/c/f"},{"/a","/c/d","/c/f"}},
        {{"/a","/a/b/c","/a/b/d"},{"/a"}},{{"/a/b/c","/a/b/ca","/a/b/d"},{"/a/b/c","/a/b/ca","/a/b/d"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.removeSubfolders(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

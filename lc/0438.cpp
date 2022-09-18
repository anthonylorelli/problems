// 0438. Find All Anagrams in a String
// Problem definition: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Accepted 2022-09-18
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <queue>
#include <vector>

struct Record
{
    int32_t count {0};
    int32_t total {0};
    int32_t round {0};
};

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        size_t len {p.size()};
        std::vector<int> result;
        if (len > s.size()) {
            return result;
        }
        Record table[26]{};
        for (auto c : p) {
            table[c - 'a'].total++;
        }
        for (size_t i {0}, round {1}; i <= s.size() - len; ++i, ++round) {
            bool found {true};
            for (size_t j {i}; j < i + len; ++j) {
                if (table[s[j] - 'a'].total == 0) {
                    found = false;
                    break;
                }
                if (table[s[j] - 'a'].round < round) {
                    table[s[j] - 'a'].count = 0;
                    table[s[j] - 'a'].round = round;
                }
                table[s[j] - 'a'].count++;
                if (table[s[j] - 'a'].count > table[s[j] - 'a'].total) {
                    found = false;
                    break;
                }
            }
            if (found) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> result;
//         if(s.size() < p.size()) {
//             return result;
//         }
        
//         int arr[26] = {0, };
        
//         //init
//         int windowSize = p.size();
//         for(int i = 0; i < windowSize ; ++i) {
//             ++arr[s[i] - 97];
//         }
        
//         for(int i = 0; i < windowSize ; ++i) {
//             --arr[p[i] - 97];
//         }
       
//         if(isAllZero(arr)) {
//             result.push_back(0);
//         } 
        
        
//         for(int i = 0; i < s.size() - windowSize; ++i) {
//             --arr[s[i]-97];
//             ++arr[s[i+windowSize]-97];
//             if(isAllZero(arr)) {
//                 result.push_back(i+1);
//             }
//         }
        
//         return result;
        
//     }
// private:
//     bool isAllZero(int arr[]) {
//         for(int i = 0; i < 26; ++i) {
//             if(arr[i] != 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string,std::vector<int>>> input {
        {"cbaebabacd","abc",{0,6}},
        {"abab","ab",{0,1,2}},
        {"abc","def",{}},
        {"abc","abc",{0}},
        {"aaabaaa","aab",{1,2,3}},
        {"aaa","aaaaa",{}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [str1, str2, expected] = p;
                REQUIRE(s.findAnagrams(str1, str2) == expected);
            });
    }
}

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

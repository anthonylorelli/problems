// 1233. Remove Sub-Folders from the Filesystem
// Problem definition: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <tuple>

struct Directory
{
    std::unordered_map<std::string_view,std::unique_ptr<Directory>> children;
    template <typename T>
    void addChildren(const std::string& path, const T& begin) {
        const auto& [name, it] = next(path, begin);
        if (it != path.end()) {
            if (!children.count(name)) {
                children[name] = std::make_unique<Directory>();
            }
            children[name]->addChildren(path, it);
        }
    }

    bool isLeaf() {
        return children.size() == 0;
    }

    void removeLeaves() {
        for (auto it {children.begin()}; it != children.end();) {
            if (it->second->isLeaf()) {
                it = children.erase(it);
            } else {
                it->second->removeLeaves();
                it++;
            }
        }
    }

    template <typename T>
    static std::pair<std::string_view,T> next(const std::string& s, const T& it) {
        auto begin {*it == '/' ? it + 1 : it};
        auto child {std::find_if(begin, s.end(), [](const auto& c) { return c == '/'; })};
        size_t length = child - begin;
        return {std::string_view(&(*begin), length), child};
    }
};

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        for (const auto& path : folder) {
            add(path);
        }

        for (auto& paths : m_top) {
            auto& [name, dir] = paths;
            dir.removeLeaves();
        }

        std::vector<std::string> result;
        return result;
    }

    void add(const std::string& path) {
        const auto& [name, it] = Directory::next(path, path.begin());
        if (!m_top.count(name)) {
            m_top.emplace(name,Directory{});
        }
        m_top[name].addChildren(path, it);
    }

    std::unordered_map<std::string_view,Directory> m_top;
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

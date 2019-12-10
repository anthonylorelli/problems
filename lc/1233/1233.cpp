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
    bool terminal {false};
    std::string* m_path {nullptr};

    template <typename T>
    void addChildren(std::string& path, const T& begin) {
        if (begin != path.end()) {
            const auto& [name, it] = next(path, begin);
            if (!children.count(name)) {
                children[name] = std::make_unique<Directory>();
            }
            children[name]->addChildren(path, it);
        } else {
            terminal = true;
            m_path = &path;
        }
    }

    void collectPaths(std::vector<std::string>& paths) const {
        if (terminal) {
            paths.push_back(std::move(*m_path));
        } else {
            for (auto& [name, dir] : children) {
                dir->collectPaths(paths);
            }
        }
    }

    template <typename T>
    static std::pair<std::string_view,T> next(std::string& s, const T& it) {
        auto begin {*it == '/' ? it + 1 : it};
        auto child {std::find_if(begin, s.end(), [](const auto& c) { return c == '/'; })};
        size_t length = child - begin;
        return {std::string_view(&(*begin), length), child};
    }
};

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        for (auto& path : folder) {
            add(path);
        }

        return getPaths();
    }

    std::vector<std::string> getPaths() {
        std::vector<std::string> result;
        for (auto& [name, dir] : m_top) {
            dir.collectPaths(result);
        }
        return result;
    }

    void add(std::string& path) {
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

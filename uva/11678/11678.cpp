// Exchanging cards
// Problem definition: https://uva.onlinejudge.org/external/116/11678.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

class Trade
{
public:
    Trade(int alice, int betty, std::istream& i) {
        auto extract{[&i]() -> int { int c; i >> c; return c; }};
        std::generate_n(std::inserter(m_alice, m_alice.end()), alice, extract);
        std::generate_n(std::inserter(m_betty, m_betty.end()), betty, extract);
    }

    const size_t alice() const { return m_alice.size(); }
    const size_t betty() const { return m_betty.size(); }

private:
    std::set<int> m_alice;
    std::set<int> m_betty;
};

int execute(std::istream& in, std::ostream& out) {

    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Size", "[Exchanging cards]") {
    SECTION("No repeats") {
        std::istringstream i{"1\n1 2 3 4 5 10 100 1000 10000 100000\n"};
        Trade t{1, 10, i};
        REQUIRE(t.alice() == 1);
        REQUIRE(t.betty() == 10);
    }
    SECTION("Alice repeats") {
        std::istringstream i{"1 1 1 1 1 1 2 3\n1 2 3 4 5 10 100 1000 10000 100000\n"};
        Trade t{8, 10, i};
        REQUIRE(t.alice() == 3);
        REQUIRE(t.betty() == 10);
    }
    SECTION("Betty repeats") {
        std::istringstream i{"1 2 3\n1 1 2 2 3 3 4 4 5 5 10 10 100 100 1000 1000 10000 10000 100000 100000\n"};
        Trade t{3, 20, i};
        REQUIRE(t.alice() == 3);
        REQUIRE(t.betty() == 10);
    }
}

TEST_CASE("Execute unit tests", "[Exchanging cards]") {
    std::istringstream i{""};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
}

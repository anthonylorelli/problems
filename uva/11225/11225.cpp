// Tarot scores
// Problem definition: https://uva.onlinejudge.org/external/112/11225.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <iostream>
#include <string>

class TarotHand
{
public:
    TarotHand(std::istream& i, int n) : m_threshold{0}, m_score{0.0} {
        int oudlers{0};
        for (int j{0}; j < n; ++j) {
            std::string rank, conj, suit;
            i >> rank;
            if (rank == "fool") {
                oudlers++;
                m_score += 4.5;
            } else {
                i >> conj >> suit;
                oudlers += parse(rank, suit);
            }
        }

        m_threshold = oudlers == 3 ? 36 : oudlers == 2 ? 41 : oudlers == 1 ? 51 : 56;
    }

    int parse(const std::string& r, const std::string& s) {
        bool isOudler{false};
        if (s == "trumps") {
            if (r == "one" || r == "twenty-one") {
                isOudler = true;
                m_score += 4.5;
            }
        } else if (r == "king") {
            m_score += 4.5;
        } else if (r == "queen") {
            m_score += 3.5;
        } else if (r == "knight") {
            m_score += 2.5;
        } else if (r == "jack") {
            m_score += 1.5;
        } else {
            m_score += 0.5;
        }

        return isOudler ? 1 : 0;
    }

    double compare() {
        return m_score - m_threshold;
    }

private:
    int m_threshold;
    double m_score;
};

int execute(std::istream& in, std::ostream& out) {
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Execute unit tests", "[Tarot scores]"){
    std::istringstream i{""};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == "");
}

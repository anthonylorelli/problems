// Tarot scores
// Problem definition: https://uva.onlinejudge.org/external/112/11225.pdf
// Accepted 2019-06-11

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <iostream>
#include <string>
#include <cmath>

class TarotHand
{
public:
    TarotHand(std::istream& i, const int n) : m_threshold{0}, m_score{0.0} {
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

    const int parse(const std::string& r, const std::string& s) {
        bool isOudler{false};
        if (s == "trumps") {
            if (r == "one" || r == "twenty-one") {
                isOudler = true;
                m_score += 4.5;
            } else {
                m_score += 0.5;
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

    const double compare() const {
        return m_score - m_threshold;
    }

    const double score() const { return m_score; }
    const int threshold() const { return m_threshold; }

private:
    int m_threshold;
    double m_score;
};

int execute(std::istream& in, std::ostream& out) {
    int cases{0};
    in >> cases;

    for (int i{1}; i <= cases; ++i) {
        int cards{0};
        in >> cards;
        TarotHand hand{in, cards};
        double delta{hand.compare()};
        if (i > 1) { out << "\n"; }
        out << "Hand #" << i << "\n" << "Game " << ((delta >= 0) ? "won" : "lost") << 
            " by " << std::abs(delta) << " point(s).\n";
    }

    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Tarot hand tests", "[Tarot scores]") {
    SECTION("Three oudlers") {
        std::istringstream i{"fool\n"
            "two of clubs\nthree of hearts\n"
            "one of trumps\ntwenty-one of trumps\n"};
        TarotHand hand{i, 5};

        REQUIRE(hand.threshold() == 36);
        REQUIRE(hand.score() == 14.5);
    }
    SECTION("Two oudlers") {
        std::istringstream i{"fool\n"
            "two of clubs\nthree of hearts\none of trumps"};
        TarotHand hand{i, 4};

        REQUIRE(hand.threshold() == 41);
        REQUIRE(hand.score() == 10);
    }
    SECTION("One oudler") {
        std::istringstream i{"fool\n"
            "two of clubs\nthree of hearts\n"};
        TarotHand hand{i, 3};

        REQUIRE(hand.threshold() == 51);
        REQUIRE(hand.score() == 5.5);
    }
    SECTION("No oudlers") {
        std::istringstream i{"two of clubs\nthree of hearts\n"};
        TarotHand hand{i, 2};

        REQUIRE(hand.threshold() == 56);
        REQUIRE(hand.score() == 1.0);
    }
    SECTION("Only trumps") {
        std::istringstream i("one of trumps\ntwo of trumps\nthree of trumps\n");
        TarotHand hand{i, 3};

        REQUIRE(hand.threshold() == 51);
        REQUIRE(hand.score() == 5.5);
    }
    SECTION("Large hand") {
        std::istringstream i{"ace of diamonds\n"
            "ace of hearts\n"
            "eight of clubs\n"
            "eight of diamonds\n"
            "eight of spades\n"
            "eight of trumps\n"
            "eleven of trumps\n"
            "five of clubs\n"
            "five of diamonds\n"
            "four of clubs\n"
            "four of spades\n"
            "four of trumps\n"
            "fourteen of trumps\n"
            "jack of clubs\n"
            "jack of hearts\n"
            "jack of spades\n"
            "king of clubs\n"
            "king of hearts\n"
            "knight of clubs\n"
            "knight of diamonds\n"
            "knight of hearts\n"
            "nine of diamonds\n"
            "nineteen of trumps\n"
            "one of trumps\n"
            "queen of clubs\n"
            "queen of diamonds\n"
            "queen of spades\n"
            "seven of spades\n"
            "seven of trumps\n"
            "six of clubs\n"
            "six of hearts\n"
            "six of trumps\n"
            "sixteen of trumps\n"
            "ten of clubs\n"
            "ten of diamonds\n"
            "three of clubs\n"
            "three of diamonds\n"
            "three of hearts\n"
            "three of spades\n"
            "three of trumps\n"
            "two of diamonds\n"
            "two of spades\n"};
        TarotHand hand{i, 42};

        REQUIRE(hand.threshold() == 51);
        REQUIRE(hand.score() == 51);
    }
}

TEST_CASE("Execute unit tests", "[Tarot scores]") {
    std::istringstream i{"2\n"
        "4\n"
        "ace of spades\n"
        "eight of diamonds\n"
        "fool\n"
        "twenty-one of trumps\n"
        "42\n"
        "ace of diamonds\n"
        "ace of hearts\n"
        "eight of clubs\n"
        "eight of diamonds\n"
        "eight of spades\n"
        "eight of trumps\n"
        "eleven of trumps\n"
        "five of clubs\n"
        "five of diamonds\n"
        "four of clubs\n"
        "four of spades\n"
        "four of trumps\n"
        "fourteen of trumps\n"
        "jack of clubs\n"
        "jack of hearts\n"
        "jack of spades\n"
        "king of clubs\n"
        "king of hearts\n"
        "knight of clubs\n"
        "knight of diamonds\n"
        "knight of hearts\n"
        "nine of diamonds\n"
        "nineteen of trumps\n"
        "one of trumps\n"
        "queen of clubs\n"
        "queen of diamonds\n"
        "queen of spades\n"
        "seven of spades\n"
        "seven of trumps\n"
        "six of clubs\n"
        "six of hearts\n"
        "six of trumps\n"
        "sixteen of trumps\n"
        "ten of clubs\n"
        "ten of diamonds\n"
        "three of clubs\n"
        "three of diamonds\n"
        "three of hearts\n"
        "three of spades\n"
        "three of trumps\n"
        "two of diamonds\n"
        "two of spades\n"};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == "Hand #1\n"
        "Game lost by 31 point(s).\n\n"
        "Hand #2\n"
        "Game won by 0 point(s).\n");
}

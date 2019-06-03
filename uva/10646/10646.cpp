// Problem definition: https://uva.onlinejudge.org/external/106/10646.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <iostream>

int execute(std::istream& in, std::ostream& out)
{
    return 0;
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Execute unit tests", "[What is the Card?]")
{
    REQUIRE(execute(std::cin, std::cout) == 0);

    SECTION("Stream interfaces")
    {
        std::istringstream i{""};
        std::ostringstream o{""};
        REQUIRE(execute(i, o) == 0);
        REQUIRE(i.str() == "");
        REQUIRE(o.str() == "");
    }
}

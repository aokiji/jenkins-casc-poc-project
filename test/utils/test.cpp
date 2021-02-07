#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "utils/greetings.h"

struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer )
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};

BOOST_AUTO_TEST_CASE( test_hello_output  ) {

  boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );

        utils::greet(utils::GreetingType::Hello);
    }

    BOOST_CHECK( output.is_equal( "Hello World!\n" ) );
}

BOOST_AUTO_TEST_CASE( test_goodbye_output  ) {

  boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );

        utils::greet(utils::GreetingType::GoodBye);
    }

    BOOST_CHECK( output.is_equal( "Good Bye!\n" ) );
}

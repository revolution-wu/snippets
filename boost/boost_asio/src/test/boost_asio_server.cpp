#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace boost::asio::ip;
std::string getString()
{
    time_t seconds = time(NULL);
    char buf[32] = { 0 };
    ctime_r(&seconds, buf);
    return buf;
}


int main()
{
    try
    {
        boost::asio::io_service ioServer;
        tcp::acceptor acceptor(ioServer, tcp::endpoint(tcp::v4(), 8888));

        std::cout << "start server " << std::endl;

        while (1)
        {
            tcp::socket socket(ioServer);

            acceptor.accept(socket);

            auto message = getString();
            boost::system::error_code ignored_error;

            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "bye" << std::endl;
    return 0;
}
























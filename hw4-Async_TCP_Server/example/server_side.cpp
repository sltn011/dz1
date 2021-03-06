#include <iostream>
#include "tcp.hpp"
#include <errno.h>

int main(int argc, char *argv[]) {
    HW::Server server("127.1.1.1", 8888);
    server.open();
    server.listen(5);
    std::cout << "accepting:\n";
    HW::Connection connection = server.accept();
    std::cout << "Connection: " << std::boolalpha << connection.isOpened() << std::endl;
    auto[dst_ip, dst_port] = connection.getDstAddr();
    auto[src_ip, src_port] = connection.getSrcAddr();
    std::cout << "Dst: " << dst_ip << ' ' << dst_port << std::endl;
    std::cout << "Src: " << src_ip << ' ' << src_port << std::endl;
    server.close();
    return 0;
}
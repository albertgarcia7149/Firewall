#include "Firewall.h"
#include "Firewall.cpp"
#include <iostream>

using namespace std;

int main(){
    //Create Rules via csv file (assumed to be properly formated)
    Firewall f("firewall2.csv");

    //Print rules
    f.printRules();

    //Test Cases
    f.acceptPacket("inbound", "tcp", 80, "192.168.1.2");
    f.acceptPacket("inbound", "udp", 53, "192.168.2.1");
    f.acceptPacket("outbound", "tcp", 10234, "192.168.10.11");
    f.acceptPacket("inbound", "tcp", 81, "192.168.1.2");
    f.acceptPacket("inbound", "udp", 24, "52.12.48.92");

    return 0;
}

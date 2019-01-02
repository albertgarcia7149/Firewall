#ifndef FIREWALL_H
#define FIREWALL_H

#include <string>
#include <vector>


#include <iostream>
using std::cout;
using std::endl;

using std::string;
using std::vector;


class Firewall{
    //Structure to hold rules
    private:
        struct Rule{
            string direction;
            string protocol;
            int portmin;
            int portmax;
            string ipmin;
            string ipmax;
        };

        vector<Rule> rules;

    public:
        Firewall(string path);
        printRules();
        acceptPacket(string direction,string protocol,int port,string ip);

};
#endif // FIREWALL_H

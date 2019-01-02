#ifndef FIREWALL_CPP
#define FIREWALL_CPP

#include <fstream>
#include <sstream>
#include <string>
#include "Firewall.h"

using std::ifstream;
using std::stringstream;

Firewall::Firewall(string path){
    cout<<"FILE PATH: "<<path<<endl;

    //Create temporary rule
    Rule temp;

    //Attempt to open .csv File
    ifstream infile;
    infile.open(path);
    if (infile){
        string str;
        stringstream ss;
        // Get information from file line by line
        while(getline(infile,str)){
            string t;
            int count=0;

            //Assign file information to rule
            for(char c: str){
                if (c==','){
                    if(count==0){
                        temp.direction=t;
                    }else if(count==1){
                        temp.protocol=t;
                    }else if(count==2){
                        bool dash=false;
                        // Handle possible dash in ports
                        for(int i =0;i<t.size();i++){
                            if(t[i]=='-'){
                                stringstream(t.substr(0,i))>>temp.portmin;
                                stringstream(t.substr(i+1,t.size()))>>temp.portmax;
                                dash=true;
                                break;
                            }
                        }
                        if (!dash){
                            stringstream(t)>>temp.portmin;
                            temp.portmax=temp.portmin;
                        }

                    }else{

                    }
                    count++;
                    t="";
                }else{
                    t+=c;
                }
            }
            bool dash=false;
            // Handle possible dash in ips
            for(int i =0;i<t.size();i++){
                if(t[i]=='-'){
                    stringstream(t.substr(0,i))>>temp.ipmin;
                    stringstream(t.substr(i+1,t.size()))>>temp.ipmax;
                    dash=true;
                    break;
                }
            }
            if (!dash){
                stringstream(t)>>temp.ipmin;
                temp.ipmax=temp.ipmin;
            }

            // Add new rule to vector of rules
            rules.push_back(temp);
        }

    //If file couldn't be opened
    }else{
        cout<<"File Not Found"<<endl;
    }
}
Firewall::printRules(){
    cout<<"RULES:"<<endl;
    for (Rule r : rules){
        cout<<r.direction<<" "<<r.protocol<<" "<<r.portmin<<"-"<<r.portmax<<" "<<r.ipmin<<"-"<<r.ipmax<<endl;
    }
}
Firewall::acceptPacket(string direction,string protocol,int port,string ip){
    bool status = false;
    string statusstr="";
    //Check if Packet should be accepted
    for(Rule r : rules){
       if(direction==r.direction){
            if(protocol==r.protocol){
                if(port>=r.portmin && port<=r.portmax){
                    //Insert Ip check here
                    status=true;
                }
            }
       }
    }
    statusstr = status ? "True" : "False";
    //Print the result
    cout<<"Accepted: "<< statusstr<<endl;
}

#endif // FIREWALL_CPP

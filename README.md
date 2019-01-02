# Firewall
Firewall Class made for Illumio Coding Challenge

This program was written in CodeBlocks using their environment.
The included files are:

  -*Firewall.cpp* - Implementation file for Firewall.h
  
  -*Firewall.h* - Definition of Firewall Class
  
  -*main.cpp* - The testing file for this class
  
  -*firewall2.csv* - the .csv file used in defining the firewall rules
  
Currently there is no check for whether or not the ip is in a rule's range. My thoughts on the implementation for this would be to either make 2 vectors which contain the integers for the min and max ip so simple integer comparision can be used later.

Another improvement I would like to make would be to replace the string search via for loop I implemented in the class with the string find function. I wasn't confident enough to implement find functions within the time constraints.

Finally, after implementing the above improvements I would more thoroughly test edge cases.

Thank you for your consideration.

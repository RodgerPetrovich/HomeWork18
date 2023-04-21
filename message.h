#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Message
{
    string from;
    string to;
    string text;
    public:
    Message(string from, string to, string text):from(from),to(to),text(text){}
    friend fstream& operator >> (fstream& is, Message& obj)
    {
        is>> obj.from;
        is>>obj.to;
        is>>obj.text;
        return is;
    }
    friend ostream& operator << (ostream& os, const Message& obj)
    {
        os<<obj.from;
        os<<' ';
        os<<obj.to;
        os<<' ';
        os<<obj.text;
        os<<'\n';
        return os;
    }

};
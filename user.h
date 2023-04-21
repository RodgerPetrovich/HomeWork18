#include <string>
#include <fstream>

using namespace std;

class User
{
    string login;
    string name;
    string pass;
    public:
    User(string login, string name, string pass):login(login),name(name), pass(pass){}
    friend fstream& operator >> (fstream& is, User& obj)
    {
        is>> obj.login;
        is>> obj.name;
        is>>obj.pass;
        return is;
    }
    friend ostream& operator << (ostream& os, const User& obj)
    {
        os<<obj.login;
        os<<' ';
        os<<obj.name;
        os<<' ';
        os<<obj.pass;
        os<<'\n';
        return os;
    }
    void showUser()
    {
        cout<< login<<" "<<name<<endl;
    }

};
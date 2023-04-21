#include <iostream>
#include <fstream>
#include <filesystem>
#include "user.h"
#include "message.h"

using namespace std;
namespace fs = std::filesystem;


int main()
{

    fstream userFile("users.txt", ios::in|ios::out);
    fstream messageFile("messages.txt",ios::in|ios::out);
    if(!userFile) 
    {
        userFile = fstream("users.txt",ios::in|ios::out|ios::trunc);
        fs::permissions("users.txt", fs::perms::group_all|fs::perms::others_all,fs::perm_options::remove);
    }
    if(!messageFile)
    {
        messageFile = fstream("messages.txt", ios::in|ios::out|ios::trunc);
        fs::permissions("messages.txt", fs::perms::group_all|fs::perms::others_all,fs::perm_options::remove);
    }
    if(userFile)
    {
       User userObj("Vicror","victor","qwerty");
       userFile<<userObj<<endl;
       userFile.seekg(0,ios_base::beg);
       userFile>>userObj;
       cout<< "User\n"<< userObj<<endl;
    }
    if(messageFile)
    {
        Message messageObj ("Andrey", "Victor", "Hello_VIctor!");
        messageFile<<messageObj<<endl;
        messageFile.seekg(0,ios_base::beg);
        messageFile>>messageObj;
        cout<< "Message \n" <<messageObj<<endl;
    }

    

    return 0;
}
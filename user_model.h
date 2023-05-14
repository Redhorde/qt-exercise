#ifndef USER_MODEL_H
#define USER_MODEL_H
#include <string>


class User_model
{
private:
    std::string Name;
    std::string Surname;
    std::string Role;
public:
    User_model(std::string name, std::string surname, std::string role);
    std::string getUserName();
    std::string getUserSurname();
    std::string getUserRole();
};

class Admin_model:User_model
{
private:
    int Key;
public:
    Admin_model(std::string name, std::string surname, std::string role, int key):User_model(name, surname, role){
        Key = key;
    };
    bool valid_key(int key);
};

#endif // USER_MODEL_H

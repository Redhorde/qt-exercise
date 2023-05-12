#include "user_model.h"

User_model::User_model(std::string name, std::string surname, std::string role)
{
    Name = name;
    Surname = surname;
    Role = role;
}

std::string User_model::getUserName(){
    return Name;
};
std::string User_model::getUserSurname(){
    return Surname;
};
std::string User_model::getUserRole(){
    return Role;
};

bool Admin_model::valid_key(int key){
    if (key == Key)
    {
        return true;
    }
    else
    {
        return false;
    }
}



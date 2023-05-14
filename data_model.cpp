#include "data_model.h"
#include <string>
#include <algorithm>
#include <stdexcept>


Data_model::Data_model()
{
}

// Useless with public user_list
int Data_model::Size()
{
    return user_list.size();
}

// Check if role is on the role list before adding user
void Data_model::push_back(User_model user)
{
    if (std::count(Roles.begin(), Roles.end(), user.getUserRole()))
    {
        user_list.push_back(user);
    }
    else
        throw std::invalid_argument(user.getUserRole() + " not found in roles list");
}

void Data_model::addRole(std::string role)
{
    Roles.push_back(role);
}

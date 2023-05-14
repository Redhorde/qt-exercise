#ifndef DATA_MODEL_H
#define DATA_MODEL_H
#import"user_model.h"
#include <vector>


class Data_model
{
private:
    std::vector<std::string> Roles = {"role1", "role2", "role3"};
public:
    std::vector<User_model> user_list;
    Data_model();
    int Size();
    void push_back(User_model user);
    void addRole(std::string role);
};

#endif // DATA_MODEL_H

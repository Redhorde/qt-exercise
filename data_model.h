#ifndef DATA_MODEL_H
#define DATA_MODEL_H
#import"user_model.h"
#include <list>


class Data_model
{
private:
    std::list<Admin_model> User_list;
public:
    Data_model(std::list<Admin_model> user_list);
};

#endif // DATA_MODEL_H

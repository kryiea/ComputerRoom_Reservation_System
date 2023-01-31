//
// Created by 86195 on 2023/1/29.
//

#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class Teacher : public Identity{
public:
    //无参构造
    Teacher();
    //有参构造
    Teacher(int empId, string name, string pwd);
    //菜单
    virtual void openMenu();
    //查看所有预约
    void showAllOrder();
    //审核预约
    void validOrder();

    //职工号
    int m_empId;


};
//
// Created by 86195 on 2023/1/29.
//
#pragma once
#include <iostream>

using namespace std;

//身份抽象基类
class Identity{
public:
    //操作菜单 纯虚函数
    virtual void openMenu() = 0;

    //用户名
    string m_Name;
    //密码
    string m_Pwd;

};

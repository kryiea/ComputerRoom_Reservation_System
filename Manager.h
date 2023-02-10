//
// Created by 86195 on 2023/1/29.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

class Manager : public Identity{
public:
    //无参构造
    Manager();
    //有参构造
    Manager(string name, string pwd);
    //菜单界面
    virtual void openMenu();
    //添加账号
    void addPerson();
    // 查看账号
    void showPerson();
    //查看机房信息
    void showComputer();
    // 清空预约记录
    void cleanFile();

    //初始化容器
    void initVector();

    //检查重复 参数1 检测学号、职工号， 参数2 人员类型
    bool checkRepeat(int id, int type);

    //学生容器
    vector<Student>vStu;

    //教师容器
    vector<Teacher>vTea;




};
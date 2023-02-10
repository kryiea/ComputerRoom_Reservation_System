//
// Created by 86195 on 2023/1/29.
//

#include <fstream>
#include <algorithm>
#include "Manager.h"
#include "globalFile.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    //初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化容器 获取文件所有的 学生 老师信息
    this->initVector();

}

void Manager::openMenu() {
    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t------------------\n";
    cout << "\t\t    1. 添加账号    \n";
    cout << "\t\t    2. 查看账号    \n";
    cout << "\t\t    3. 查看机房    \n";
    cout << "\t\t    4. 清空预约    \n";
    cout << "\t\t    0. 注销登录    \n";
    cout << "\t\t------------------\n";
    cout << "请选择你的操作：" << endl;

}

void Manager::addPerson() {
    cout << "请输入添加账号类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;//操作文件名
    string tip; //提示ID号
    string errorTip;//错误信息

    ofstream  ofs; //文件 操作对象

    int select = 0;
    cin >> select;

    if(select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    }
    else{
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工编号重复，请重新输入";
    }

    //利用追加的方式写文件
    ofs.open(fileName,ios::out | ios::app);

    if(!ofs.is_open()){
        cout << "文件不存在" << endl;
    }else{
        cout << "文件存在" << endl;
    }

    int id; // 学号、职工号
    string name;//姓名
    string pwd;//密码

    cout << tip <<endl;
    while(true){
        cin >> id;
        bool ret = checkRepeat(id, select);
        if(ret){
            cout << errorTip << endl;
        }
        else{
            break;
        }
    }

    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    ofs.close();
    cout << "添加成功" << endl;
    system("pause");
    system("cls");

    this->initVector();
}

void printStudent(Student & s){
    cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码:" << s.m_Pwd << endl;
}

void printTeacher(Teacher & t){
    cout << "职工编号：" << t.m_empId << " 姓名：" << t.m_Name << " 密码:" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson() {
    cout << "请选择查看内容" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;
    cin >> select;

    if(select == 1){
        cout << "学生所有信息如下： " << endl;
        for_each(vStu.begin(),vStu.end(),printStudent);
    }
    else{
        //查看老师
        cout << "老师所有信息如下： " << endl;
        for_each(vTea.begin(),vTea.end(),printTeacher);
    }
    system("pause");
    system("cls");

}

void Manager::showComputer() {

}

void Manager::cleanFile() {

}

//初始化容器
void Manager::initVector() {
    //确保容器清空
    vStu.clear();
    vTea.clear();

    //读取信息 学生、老师
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open()){
        cout << "文件读取失败" << endl;
        return;
    }

    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close();

    //读取老师信息
    ifs.open(TEACHER_FILE,ios::in);
    if(!ifs.is_open()){
        cout << "文件读取失败" << endl;
        return;
    }
    Teacher t;
    while(ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd){
        vTea.push_back(t);
    }
    cout << "当前老师数量为：" << vTea.size() << endl;
    ifs.close();

}

bool Manager::checkRepeat(int id, int type) {
    if(type == 1){
        //检测学生
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
                if (id == it->m_Id){
                return true;
            }
        }

    }
    else{
        //检测老师
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if (id == it->m_Id){
                return true;
            }
        }
    }
    return false;
}
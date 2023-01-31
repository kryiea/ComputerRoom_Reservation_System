#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity * &manager){

    while (true){
        //调用管理员子菜单
        manager->openMenu();

        //父类指针 转为子类指针，调用子类里其他接口
        Manager * man = (Manager*)manager;

        //接受用户选择
        int  select = 0;
        cin >> select;

        if(select == 1){
            //添加账号
            cout << "添加账号" << endl;
            man->addPerson();


        }
        else if(select == 2){
            //查看账号
            cout << "查看账号" << endl;
            man->showPerson();

        }
        else if(select == 3){
            //查看机房
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if(select == 4){
            //清空预约
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else{
            //销毁
            delete manager; //销毁堆区对象
            cout << "注销成功" << endl;
            system("pause");
            system("cls");

        }

    }

}

//登录功能 参数1：操作文件名  参数2：操作身份类型
void LoginIN(string fileName, int type){
    //父类指针，指向子类对象
    Identity * person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName,ios::in);

    //判断文件存在
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    //准备接受用户信息
    int id = 0;
    string name;
    string pwd;

    //判断身份
    if(type == 1) {
        //学生身份
        cout<< "请输入你的学号：" << endl;
        cin >> id;
    }
    else if(type == 2){
        cout<< "请输入你的职工号：" << endl;
        cin >> id;
    }

    cout<< "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    if(type == 1){
        //学生身份验证
        int fId;    //从文件中读取的ID
        string fName;//从文件中读取的姓名
        string fPwd;//从文件中读取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            if(fId == id && fName == name && fPwd == pwd){
                cout << "学生登录认证成功！" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                //进入学生身份子菜单

                return;

            }
        }
    }
    else if(type == 2){
        //老师身份验证
        int fId;    //从文件中读取的ID
        string fName;//从文件中读取的姓名
        string fPwd;//从文件中读取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            if(fId == id && fName == name && fPwd == pwd){
                cout << "老师登录认证成功！" << endl;
                system("pause");
                system("cls");
                //person = new Teacher(id, name, pwd);
                //进入老师身份子菜单
                return;

            }
        }
    }
    else if(type == 3){
        //管理员身份验证
        string fName;//从文件中读取的姓名
        string fPwd;//从文件中读取的密码
        while (ifs >> fName && ifs >> fPwd){
            if( fName == name && fPwd == pwd){
                cout << "管理员登录认证成功！" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                //进入股管理员身份子菜单
                return;

            }
        }

    }

    cout << "验证登录失败！" << endl;
    system("pause");
    system("cls");
    return;
}

int main() {
    int select = 0; // 接受用户选择
    while(true){
        cout << "==== 机房预约系统 ====" << endl;
        cout << endl << "请输入你的身份" << endl;
        cout << "\t\t ------------------\n";
        cout << "\t\t|      1.学生代表    |\n";
        cout << "\t\t|      2.老    师    |\n";
        cout << "\t\t|      3.管 理 员    |\n";
        cout << "\t\t|      0.退    出   |\n";
        cout << "\t\t ------------------\n";
        cout << "请输入你的选择:";

        cin >> select;//接受用户选择

        switch (select) {
            case 1: //学生
                LoginIN(STUDENT_FILE,1);
                break;
            case 2: //老师
                LoginIN(TEACHER_FILE,2);
                break;
            case 3: //管理员
                LoginIN(ADMIN_FILE,3);
                break;
            case 0: //退出
                cout << "欢迎下一次使用" << endl;
                system("pause");
                return 0;
            default:
                cout << "输入有误，请重新选择！" << endl;
                system("pause");
                system("cls");
                break;
        }
    }


    return 0;

}

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
    //��ʼ������Ա��Ϣ
    this->m_Name = name;
    this->m_Pwd = pwd;

    //��ʼ������ ��ȡ�ļ����е� ѧ�� ��ʦ��Ϣ
    this->initVector();

}

void Manager::openMenu() {
    cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
    cout << "\t\t------------------\n";
    cout << "\t\t    1. ����˺�    \n";
    cout << "\t\t    2. �鿴�˺�    \n";
    cout << "\t\t    3. �鿴����    \n";
    cout << "\t\t    4. ���ԤԼ    \n";
    cout << "\t\t    0. ע����¼    \n";
    cout << "\t\t------------------\n";
    cout << "��ѡ����Ĳ�����" << endl;

}

void Manager::addPerson() {
    cout << "����������˺�����" << endl;
    cout << "1�����ѧ��" << endl;
    cout << "2�������ʦ" << endl;

    string fileName;//�����ļ���
    string tip; //��ʾID��
    string errorTip;//������Ϣ

    ofstream  ofs; //�ļ� ��������

    int select = 0;
    cin >> select;

    if(select == 1){
        fileName = STUDENT_FILE;
        tip = "������ѧ�ţ�";
        errorTip = "ѧ���ظ�������������";
    }
    else{
        fileName = TEACHER_FILE;
        tip = "������ְ����ţ�";
        errorTip = "ְ������ظ�������������";
    }

    //����׷�ӵķ�ʽд�ļ�
    ofs.open(fileName,ios::out | ios::app);

    if(!ofs.is_open()){
        cout << "�ļ�������" << endl;
    }else{
        cout << "�ļ�����" << endl;
    }

    int id; // ѧ�š�ְ����
    string name;//����
    string pwd;//����

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

    cout << "������������" << endl;
    cin >> name;

    cout << "���������룺" << endl;
    cin >> pwd;

    //���ļ����������
    ofs << id << " " << name << " " << pwd << " " << endl;
    ofs.close();
    cout << "��ӳɹ�" << endl;
    system("pause");
    system("cls");

    this->initVector();
}

void printStudent(Student & s){
    cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ����:" << s.m_Pwd << endl;
}

void printTeacher(Teacher & t){
    cout << "ְ����ţ�" << t.m_empId << " ������" << t.m_Name << " ����:" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson() {
    cout << "��ѡ��鿴����" << endl;
    cout << "1���鿴����ѧ��" << endl;
    cout << "2���鿴������ʦ" << endl;

    int select = 0;
    cin >> select;

    if(select == 1){
        cout << "ѧ��������Ϣ���£� " << endl;
        for_each(vStu.begin(),vStu.end(),printStudent);
    }
    else{
        //�鿴��ʦ
        cout << "��ʦ������Ϣ���£� " << endl;
        for_each(vTea.begin(),vTea.end(),printTeacher);
    }
    system("pause");
    system("cls");

}

void Manager::showComputer() {

}

void Manager::cleanFile() {

}

//��ʼ������
void Manager::initVector() {
    //ȷ���������
    vStu.clear();
    vTea.clear();

    //��ȡ��Ϣ ѧ������ʦ
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
    ifs.close();

    //��ȡ��ʦ��Ϣ
    ifs.open(TEACHER_FILE,ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }
    Teacher t;
    while(ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd){
        vTea.push_back(t);
    }
    cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
    ifs.close();

}

bool Manager::checkRepeat(int id, int type) {
    if(type == 1){
        //���ѧ��
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
                if (id == it->m_Id){
                return true;
            }
        }

    }
    else{
        //�����ʦ
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if (id == it->m_Id){
                return true;
            }
        }
    }
    return false;
}
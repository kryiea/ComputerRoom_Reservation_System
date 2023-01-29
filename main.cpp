#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"

using namespace std;

//��¼���� ����1�������ļ���  ����2�������������
void LoginIN(string fileName, int type){
    //����ָ�룬ָ���������
    Identity * person = NULL;

    //���ļ�
    ifstream ifs;
    ifs.open(fileName,ios::in);

    //�ж��ļ�����
    if (!ifs.is_open()){
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    //׼�������û���Ϣ
    int id = 0;
    string name;
    string pwd;

    //�ж����
    if(type == 1) {
        //ѧ�����
        cout<< "���������ѧ�ţ�" << endl;
        cin >> id;
    }
    else if(type == 2){
        cout<< "���������ְ���ţ�" << endl;
        cin >> id;
    }

    cout<< "�������û�����" << endl;
    cin >> name;
    cout << "���������룺" << endl;
    cin >> pwd;

    if(type == 1){
        //ѧ�������֤
    }
    else if(type == 2){
        //��ʦ�����֤
    }
    else if(type == 3){
        //����Ա�����֤
    }

    cout << "��֤��¼ʧ�ܣ�" << endl;
    system("pause");
    system("cls");
    return;
}

int main() {
    int select = 0; // �����û�ѡ��
    while(true){
        cout << "==== ����ԤԼϵͳ ====" << endl;
        cout << endl << "������������" << endl;
        cout << "\t\t ------------------\n";
        cout << "\t\t|      1.ѧ������    |\n";
        cout << "\t\t|      2.��    ʦ    |\n";
        cout << "\t\t|      3.�� �� Ա    |\n";
        cout << "\t\t|      0.��    ��   |\n";
        cout << "\t\t ------------------\n";
        cout << "���������ѡ��:";

        cin >> select;//�����û�ѡ��

        switch (select) {
            case 1: //ѧ��
                LoginIN(STUDENT_FILE,1);
                break;
            case 2: //��ʦ
                LoginIN(TEACHER_FILE,2);
                break;
            case 3: //����Ա
                LoginIN(ADMIN_FILE,3);
                break;
            case 0: //�˳�
                cout << "��ӭ��һ��ʹ��" << endl;
                system("pause");
                return 0;
            default:
                cout << "��������������ѡ��" << endl;
                system("pause");
                system("cls");
                break;
        }
    }


    return 0;

}

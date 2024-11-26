#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <locale>

struct ���������� {
    std::string �����;
    std::string ������;
    int ���;
    std::string ����;
    float ����;

    // ����� ��� ����������� ���������� �� ����������
    void ������������������() const {
        std::cout << "�����: " << �����
            << ", ������: " << ������
            << ", ���: " << ���
            << ", ����: " << ����
            << ", ����(� �����): " << ����
            << std::endl;
    }
};

std::vector<����������> ����������;

double balance = 0;
bool isActive = false;

int init() {
    ����������.push_back({"Lada", "Vesta", 2015, "�����", 2500 });
    ����������.push_back({"Honda", "Civic", 2019, "�������", 3500 });
    ����������.push_back({"Ford", "Mustang", 2021, "������", 5000 });
    return 0;
}

int arenda() {
    std::cout << "�������� ����, ������� �� ������ ���������� (������� �����):" << std::endl;
    for (size_t i = 0; i < ����������.size(); ++i) {
        const auto& ���� = ����������[i];
        std::cout << i << " - " << ����.����� << " " << ����.������ << " (����: " << ����.���� << ")" << std::endl;
    }

    int �����1;
    std::cout << "������� ����� ����������: ";
    std::cin >> �����1;

    // �������� �� ������������ �����
    if (�����1 < 0 || �����1 >= ����������.size()) {
        std::cout << "�������� ����� ����������. ���������� ��� ���." << std::endl;
        return -1; // ���������� ������
    }

    // ����� ���������� � ��������� ����������
    const auto& ������������� = ����������[�����1];
    if (balance >= �������������.����) {
        std::cout << "�� �������: " << �������������.����� << " " << �������������.������
            << ". ���� ������: " << �������������.���� << std::endl;
        balance -= �������������.����;
    }
    else {
        std::cout << "� ��� ������������ �������! ��������� ���� ����� ���������� ����!" << std::endl;
    }
    

    return 0;
}

int info() {
    std::cout << "�������� ����, ������� �� ������ ����������� (������� �����):" << std::endl;
    for (size_t i = 0; i < ����������.size(); ++i) {
        const auto& ���� = ����������[i];
        std::cout << i << " - " << ����.����� << " " << ����.������ << std::endl;
    }

    int �����2;
    std::cout << "������� ����� ����������: ";
    std::cin >> �����2;

    // �������� �� ������������ �����
    if (�����2 < 0 || �����2 >= ����������.size()) {
        std::cout << "�������� ����� ����������. ���������� ��� ���." << std::endl;
        return -1; // ���������� ������
    }

    // ����� ���������� � ��������� ����������
    const auto& ������������� = ����������[�����2];
    �������������.������������������();
    return 0;
}

int plusMoney() {
    double money;
    std::cout << "������� �����, ������� ������ �������� �� ����: ";

    while (true) {
        std::cin >> money;

        // �������� �� ������������ �����
        if (std::cin.fail() || money < 0) { // ���������, �������� �� ���� ������ � �� �������������
            std::cout << "������: ������� ������������� �����!" << std::endl;
            std::cin.clear(); // ���������� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ������������ ����
            std::cout << "������� �����, ������� ������ �������� �� ����: ";
        }
        else {
            break; // ���� ���������, ������� �� �����
        }
    }

    balance += money; // ��������� ����� � �������
    std::cout << "������ ��������. ������� ������: $" << balance << std::endl;

    system("cls");
    return 0;
}

int main() {
    setlocale(LC_ALL, "RU");

    if (isActive != true) {
        init();
        isActive = true;
    }
    system("cls");
    int command;
    while (true) {
        std::cout << "����� ���������� � Caromobile! ������� ������ ������� ����� ���������� ���� (������: " << balance << " ������)" << std::endl;
        std::cout << "1 - ���������� ����" << std::endl;
        std::cout << "2 - ���������� � ����" << std::endl;
        std::cout << "3 - ��������� ������" << std::endl;
        std::cout << "4 - �����-������" << std::endl;
        std::cout << "5 - �����" << std::endl;
        std::cin >> command;
        switch (command)
        {
            default:
                break;

            case 1:
                arenda();
                break;

            case 2:
                info();
                break;

            case 3:
                plusMoney();
                break;

            case 4:
                std::string password = "cppIsTopChik";
                std::string input;
                std::cout << "����� ������: ";
                std::cin >> input;
                if (input != password) {
                    std::cout << "�������� ������" << std::endl;
                    break;
                }
                else {
                    std::string com;
                    while (true) {
                        std::cout << "�����-������ Caromobile" << std::endl;
                        std::cout << "create - �������� ������" << std::endl;
                        std::cout << "exit - �����" << std::endl;
                        std::cin >> com;
                        if (com == "create") {
                            std::string brandInput;
                            std::string modelInput;
                            int yearInput;
                            std::string colourInput;
                            float sellInput;

                            std::cout << "����� �������� ������: ";
                            std::cin >> brandInput;

                            std::cout << "����� �������� ������: ";
                            std::cin >> modelInput;

                            std::cout << "����� ��� ������������: ";
                            std::cin >> yearInput;

                            std::cout << "����� ���� ����: ";
                            std::cin >> colourInput;

                            std::cout << "����� ����(� �����): ";
                            std::cin >> sellInput;

                            ����������.push_back({ brandInput, modelInput, yearInput, colourInput, sellInput });
                        }
                        else if (com == "exit") {
                            main();
                        }
                        else {
                            std::cout << "����������� �������!" << std::endl;
                        }
                        
                    }
                }

        }
    }

	return 0;
}
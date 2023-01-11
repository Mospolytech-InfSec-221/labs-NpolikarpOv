#include <iostream>
#include <queue>
/*deque - ��� ������ ������ ����������, ������� ��������� ������������ �������.*/

bool primfacs(int n) {
    bool is_235 = true;
    int i = 2;
    // ��� �� �������� ����� �� ++
    while (i * i <= n) {
        while (n % i == 0) {
            if (i != 2 and i != 3 and i != 5)
                is_235 = false;
            n /= i;
        }
        i++;
    }
    if (n > 1 and n != 2 and n != 3 and n != 5)
        is_235 = false;

    return is_235;
}

int main()  // �������
{
    std::queue <int> data;
    int end_num;
    std::cout << "Enter max num: ";
    std::cin >> end_num;

    //��������� ������� 
    for (int i = 2; i <= end_num; i++) {
        if (primfacs(i))
            ///std::cout << i << ' ';
            data.push(i);
    }
    ///std::cout << data.size() << '\n';
    //��������� �������
    int len = data.size();
    for (int i = 0; i < len; i++) {
        std::cout << data.front() << ' ';
        data.pop();
    }
}
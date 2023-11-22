#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>

int main(int argc,char** argv)
{
    std::vector<std::string> people{"연태민","김태형", "이민규", "한정우", "윤혁진", "하헌욱", "박재현", "박민제", "우상무"};
    std::vector<std::string> cleaning{"스낵", "정수기", "박스", "일쓰", "재활용"};

    int num_of_people = 0;

    num_of_people = people.size();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> rnd_number(0, num_of_people - 1);

    std::vector<int> random_index;
    int size = 0;
    size = cleaning.size();
    
    random_index.resize(size);
    
    for(int i = 0; i < size; i++)
    {
        random_index[i] = rnd_number(gen);
    }
    
    bool number_is_set = false;

    while(number_is_set == false)
    {
        std::sort(random_index.begin(), random_index.end());
        random_index.erase(std::unique(random_index.begin(), random_index.end()), random_index.end());
        
        if(random_index.size() == size)
        {
            number_is_set = true;
        }
        else
        {
            random_index.push_back(rnd_number(gen));
        }
    }

    for(int k = 0; k < size; k++)
    {
        std::cout << cleaning[k] << "의 담당자는 " << people[random_index[k]] << "입니다." << std::endl;
    }


    return 0;
}
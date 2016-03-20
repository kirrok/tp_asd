#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct man
{
    int weight;
    int strength;
};

bool special_sort_function(const man &left, const man &right) {
    return left.weight < right.weight ;
}

int build_a_tower (vector<man> &vman) {

    int counter = 1;
    int weight = 0;
    int position = 0;
    int current_index = 0;
    bool flag = false;

//printf("counter = %d   weight = %d   pos = %d   index = %d \n",counter,weight,position,current_index);
    if(vman.size() > 1 ) {
        man current_man = vman[vman.size() - 1];
        current_index = vman.size()-1;
 //printf(" counter = %d   weight = %d   pos = %d   index = %d \n\n\n\n",counter,weight,position,current_index);
        do{

    //    printf(" 1  counter = %d   weight = %d   pos = %d   index = %d \n",counter,weight,position,current_index);
            weight = 0;
            flag = false;
            if(counter != 1) {
                current_index = position -1;
                current_man = vman[position -1];
            }
     //     printf(" 2  counter = %d   weight = %d   pos = %d   index = %d \n",counter,weight,position,current_index);

            position = 0;
        //    printf(" 3  counter = %d   weight = %d   pos = %d   index = %d \n",counter,weight,position,current_index);

            if(weight+vman[position].weight <= current_man.strength && position < current_index)
                flag = true;
//printf("-------------------WHILE---------------------\n");
            while( weight+vman[position].weight <= current_man.strength && position < current_index) {



               // printf("weight[position] = %d ",vman[position].weight);
±
                weight+=vman[position].weight;

             //   printf(" while : counter = %d   weight = %d   pos = %d   index = %d \n",counter,weight,position,current_index);
position++;
            }

            //printf("----------------------WHILE ------------------------\n");

            if(flag)
                counter++;
//printf(" 4  counter = %d   weight = %d   pos = %d   index = %d \n\n\n",counter,weight,position,current_index);

    } while(current_index > position && position - 1 >= 0 &&  flag);

    }

    return counter;
}
int main(){

    vector<man> vman;
    man _man;
    while (scanf("%d%d",&_man.weight,&_man.strength) != -1 && _man.strength != 0)
    {
        vman.insert(vman.end(),_man);
    }

    sort (vman.begin(), vman.end(), ptr_fun(special_sort_function));

    cout << build_a_tower(vman);

    return 0;
}


/* 1. Получаем массив структур.
    2. Сортируем его по Массе.
    3. Первый элемент - самый тяжелый в массиве.
    4. Для текущего элемента i находим количество элементов которое он может выдержать :
    заведем перменную и счетчик и будем увеличивать ее на значения веса элемента массива проходя
    массив с конца ( от меньших весов к большим),
    до тех пор, пока значение переменной <= значения силы предыдущего элемента. подсчитываем итерации. (n).
    5. Когда нашли n. будем рабоать только с первыми n элементами массива (цикл от j до n), первый элемент
    из n т.е j возьмем за i. Повторяем все до тех пор пока не сможем выбрать хотя бы 1 элемент.
*/

#include <iostream>
#include <string>

int main(){
    char* str;
    str = new char [10000000000];
    

    if(str == nullptr){
        std::cout << "Not enough memory. �븷�떦�릺吏� �븡�븯�뒿�땲�떎. \n";
    }
    else{
        std::cout << "硫붾え由щ�� �븷�떦 諛쏆븯�뒿�땲�떎. \n";
        delete [] str;
    }

    long long int *superlongint;
    superlongint = new long long int [10000000000];
    //怨꾩냽 �궎�슦�떎 蹂대㈃ 硫붾え由� 怨듦컙�씠 �뾾�뼱�꽌 �븷�떦�씠 �븞�릺嫄곕굹
    //�븘�땲硫� �븘�궎�뀓爾먮븣臾몄뿉 �븷�떦�씠 �븞�맖

    if(superlongint == nullptr){
        std::cout << "Not enough memory. �븷�떦�릺吏� �븡�븯�뒿�땲�떎.\n";
    }
    else{
        std::cout << "硫붾え由щ�� �븷�떦諛쏆븯�뒿�땲�떎. \n";
        delete [] superlongint;
    }

    int* num;
    num = new int;

    if(num == nullptr){
        std::cout << "Not enough memory. �븷�떦�릺吏� �븡�븯�뒿�땲�떎. \n";
    }
    else{
        std::cout << "硫붾え由щ�� �븷�떦諛쏆븯�뒿�땲�떎. \n";
        delete num;
    }
    return 0;
}
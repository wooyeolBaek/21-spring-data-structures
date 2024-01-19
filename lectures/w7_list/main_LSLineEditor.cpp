#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "LSLineEditor.hpp"

int main(){
    LineEditor editor;
    char command; 
    do{
        std::cout << "[메뉴선택] j-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료=> ";
        command = std::getchar(); //한글자를 받아서 command로 사용
        std::cin.sync(); //버퍼에 남아있는 개행문자 처리해줌

        switch(command){
            case 'd':
                editor.DeleteLine();
                break;
            case 'i':
                editor.InsertLine();
                break;
            case 'r':
                editor.ReplaceLine();
                break;
            case 'l':
                editor.LoadFile("test.txt");
                break;
            case 's':
                editor.SaveFile("test.txt");
                break;
            case 'p':
                editor.Display();
                break;
            case 'q':
                break;
        } //?? 결과 이상함 test.txt는 1st line 2nd line 3rd line 이 세줄임
    } while(command != 'q');
    return 0; 
}
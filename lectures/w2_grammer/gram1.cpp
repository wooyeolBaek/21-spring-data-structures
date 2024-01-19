//
//  main.cpp
//  DS_lecture2_1
//
//  Created by Wooyeol Baek on 3/15/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// you can write in here
/*
 it could be
 different
 lines
 */

using namespace std;

int main()
{

    cout << "Hello World" << endl;
    
    //const가 앞에 붙으면 나중에 변수값 변경 불가 => 이런 경우 보통 변수명 대문자로 씀
    const double PI = 3.1415926535;
    char myGrade = 'A';
    bool isRain = false;
    int myRoomNo = 708;
    float pi = 3.14;
    double e = 2.71828182846;
    // 줄변경을 할때 endl; 보다 "\n"; 방식 선호 이유는 후자는 버퍼를 쌓아놓고 한번에 출력하지 않고 그 줄이 끝날 때 마다 출력하기 때문에 속도가 더 느리다.
    cout << "e = " << e << "\n";
    
    // 변수의 사이즈 측정
    cout << "Size of int " << sizeof(myRoomNo) << "\n";
    cout << "Size of char " << sizeof(myGrade) << "\n";
    cout << "Size of bool " << sizeof(isRain) << "\n";
    cout << "Size of float " << sizeof(pi) << "\n";
    cout << "Size of double " << sizeof(e) << "\n";
    
    /*
     변수가 여러종류가 있음
     int 앞에 short과 long 이라는 키워드를 붙힐 수 있음
     ex)
     short int aa;
     long int aa;
    */
    
    /* short은 최하 16비트 이하 integer를 의미
      long은 최대 32비트 이상의 integer를 의미, long은 한번 더 붙힐 수 있음 => 아주 큰 숫자를 사용할 때 long long int 사용
      long 두번은 최하 64비트 이상의 integer 의미
      비트수가 증가는 표기할 수 있는 수의 범위가 늘어나는 것
      비트수는 컴파일러마다 다르고 시스템마다 다르다 => 그때 그때 테스트 해봐야 알 수 있다.
     ex)
     long long int aa;
      */
    
    /* unsigned integer는 양수+음수+0인 정수에서 음수를 빼고 그 빠진 만큼 양수쪽에서 공간을 더 쓸 수 있음
     주로 자연수를 표현해야하고, 음수 양수를 표기할 필요가 없을 때 용량을 아끼거나 조금 더 넒은 범위의 숫자를 표현하기 위해 사용
     ex)
     unsigned int aa;
     */
    

    /* int 최대값을 활용한 실험, INT_MAX : int의 최대값을 불러오는 함수 */
    cout << "the largest int is " << INT_MAX << endl;
    /* int보다 하나 큰 값을 넣으면
     int TESTINT = 2147483648;
     -2147483648이 나옴
     => overflow, 즉 값이 넘는 현상이 발생하면 반대쪽 끝, 가장 작은 값으로 넘어감
     즉 메모리 계산을 잘못하면 말도 안되는 값이 출력될 수 있음
     따라서 메모리가 넘어갈 것 같으면 long int 나 long long int 사용하기*/
    
    /* 사칙연산 %: 나머지 8 mod 3 느낌 */
    cout << "8 + 3 = " << 8 + 3 << "\n";
    cout << "8 - 3 = " << 8 - 3 << "\n";
    cout << "8 * 3 = " << 8 * 3 << "\n";
    cout << "8 / 3 = " << 8 / 3 << "\n";
    cout << "8 % 3 = " << 8 % 3 << "\n";

    /* 증가연산자(++), 감소연산자(--) : 한개씩 증가, 감소 시킴
     뒤에 붙히면 호출하고 연산: 변수가 먼저 나오고 그 이후에 연산된 값이 나옴
     앞에 붙히면 연산하고 호출: 연산된 값으로 나옴
     */
    int eight = 8;
    cout << "8++ = " << eight++ << " " << eight << "\n";
    cout << "8-- = " << eight-- << " " << eight << "\n";
    cout << "++8 = " << ++eight << " " << eight << "\n";
    cout << "--8 = " << --eight << " " << eight << "\n";
    
    /*
     증가에서 assign 하는 연산자
     한개 이상 씩 증가, 감소 시킬 때 사용
     ex)
     eight에 6을 할당해 더하기
     eight에 6을 할당해 뺴기
     */
    eight = 8;
    eight += 6;
    cout << eight << "\n";
    eight -= 6;
    cout << eight << "\n";
    
    /* 연산의 순서 : 수학이랑 같음
     */
    cout << "1 + 2 - 3 * 4 = " << 1 + 2 - 3 * 4 << "\n";
    cout << "(1 + 2 - 3) * 4 = " << (1 + 2 - 3) * 4 << "\n";
    
    /* 타이퀘스트?
     정수형 자료형이라
     10/11은 소수로 안나오고 0으로 출력됨
     100/11은 뒤에 것을 버린 9가 출력됨
     */
    cout << 10 / 11 << "\n";
    cout << 100 / 11 << "\n";
    
    /* 이 값이 float이라고 정해주면 정확한 소수점 이하 값이 나옴
     */
    cout << (float) 10 / 11 << "\n";
    
    /* 비교 연산자 =>
     같다 ==
     다르다 !=
     크다 >
     작다 <
     크거나 같다 >=
     작거나 같다 <=
     
     and 연산자 &&
     or 연산자 ||
     
     ! not이라는 뜻
     
     ex) 나이별 운전 가능 여부
     */
    int age = 40;
    int ageLastTest = 30;
    bool isNotDrunk = true;
    
    if((age >= 1)&&(age < 20))
    {
        cout << "20세 미만은 운전을 할 수 없습니다." << "\n";
    }
    else if(! isNotDrunk)
    {
        cout << "술을 마시면 운전할 수 없습니다." << "\n";
        
    }
    else if((age >= 80) && ((age > 100) || (age - ageLastTest > 5)))
    {
        cout << "고령자는 테스트 없이 운전할 수 없습니다." << "\n";
    }
    else
    {
        cout << "운전하셔도 됩니다." << "\n";
    }
    
    /* 스위치 정해진 케이스에 대해 작동하는 것
     고객들의 언어를 추정해서 인삿말을 바꾸는 코드
     */
    int guestLang = 3;
    switch (guestLang)
    {
        case 1:
            cout << "Hello" << "\n";
            break;
        case 2:
            cout << "Hola" << "\n";
            break;
        case 3:
            cout << "Ciao" << "\n";
            break;
        default:
            cout << "안녕하세요" << "\n";
            break;
    }
    
    /* 삼항 연산자 => 코드를 짧게 만드는 대신 가독성이 떨어짐
     사용법 : 변수 = 조건 ? 참 : 거짓
     수업에서 명확성 때문에 사용하지 않을 예정
     */
    int largeNum = (10 > 5) ? 10 : 5;
    cout << largeNum << "\n";
    
    /* 배열 ordering이 0부터 시작하는거 알고 있기*/
    
    int myNumbers[5];
    int yourNumbers[5] = {3, 4, 6, 5, 1};
    cout << "your Number 1 : " << yourNumbers[0] << endl;
    
    /* 2차원 배열*/
    int yourNumbers2d[2][5] = {{3, 4, 7, 6, 1},
                                {13, 14, 17, 16, 11}};
    cout << "your Number 2D 0, 2 : " << yourNumbers2d[0][2] << endl;
    /* 2차원 배열에서 처음 초기 [0] 생략 가능 */
    int yourNumbers2d2[][5] = {{3, 4, 7, 6, 1},
                                {13, 14, 17, 16, 11}};
    cout << "your Number 2D 0, 2 : " << yourNumbers2d2[0][2] << endl;
    
    /* 전체를 한번에 표기 가능 */
    int Array2D[3][5] = { 0 };
    cout << "Array2D 2, 4 : " << Array2D[2][4] << endl;
    
    /* 소프트웨어를 짤때 가장 많이 사용하는 루프
     for 루프, while 루프*/
    /* for 루프는 몇번 반복할지 알때 사용 */
    for(int i = 1; i <= 10; i++)
    {
        cout << i << "\n";
    }
    /* for문으로 2d array 만들기
     int yourNumbers2d[2][5] = {{3, 4, 7, 6, 1},
                                 {13, 14, 17, 16, 11}};
     원래 코드에 포함되어야하지만 이중 정의되어 오류떠서 주석에 포함함
     */
    for(int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 5; k++)
        {
            cout << yourNumbers2d[j][k] << " ";
        }
        cout << "\n";
    }
    /* while 루프
     예시) 20이 나오면 멈추는 난수 생성 루프 ? 잘 안되는 듯
     */
    cout << " 난수 " << "\n";
    int randNum = (rand() % 20) + 1;
    while (randNum != 20)
    {
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    cout << "\n";
    
    /* while문을 for문 처럼 쓰기*/
    int idx = 0;
    while (idx < 10)
    {
        cout << idx << " ";
        idx++;
    }
    cout << "\n";
    
    /* do while 문
     사용 목적 일단 루프는 한번 돌리고 싶을 떄
     예시) 20이 나오기 전까지 난수 생성하는데 첫번째로 20이 나오면 바로 끝나니까
     일단 한번은 돌리고 싶을 떄 => 생성하고 20이면 멈추는 방식
     int randNum = (rand() % 20) + 1;
     -> 위에 있어서 중복이라 여기다 씀
     */
    do
    {
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    while(randNum != 20);
    cout << "\n";
    
    /* while문을 사용해서 text input을 받아 사용하기 실습
     stoi 함수 : str을 int로 변환하는 함수*/
   /* 입력값 때문에 일단 주석 처리함
    string yourAnswer;
    int intYourAnswer;
    
    do
    {
        cout << "1부터 10까지의 숫자 중 하나를 맞춰보세요 : \n";
        getline(cin, yourAnswer); //문자열을 받아 yourAnswer에 저장
        intYourAnswer = stoi(yourAnswer);
    }
    while (intYourAnswer !=7 );
    */
    char textArray[6] = "Happy";
    string textString = "Day!";
    cout << textArray + textString << "\n";
    
    /* 입력값 때문에 주석 처리
    string userName;
    cout << "당신의 이름을 알려주세요" << "\n";
    getline(cin, userName); //문자열을 받아 userName에 저장
    cout << "반갑습니다, " << userName << "!" << "\n";
     */
    
    string sPi = "3.14";
   /* double pi = 3.14;
    재정의라 주석처리함*/
    /* stod : string을 double로 바꾸는 함수*/
    if(stod(sPi) == pi)
    {
        cout << "Match!" << "\n";
    }
    
    /* string 내부 함수들 */
    /* string 크기 */
    cout << "string의 크기 = " << sPi.size() << "\n";
    /* string이 비어있으면 1 안비어있으면 0 출력*/
    cout << "string이 비어있나요 = " << sPi.empty() << "\n";
    /* string 뒤에 다른 string을 붙힘*/
    cout << "string을 덧붙입니다 = " << sPi.append("285") << "\n";
    
    /* string끼리 비교함수
     값이 같으면 0이 나오고
     1이나 -1이 나옴*/
    string dogSound = "멍멍";
    string catSound = "야옹";
    
    cout << dogSound.compare(catSound) << "\n";
    cout << catSound.compare(dogSound) << "\n";
    cout << dogSound.compare(dogSound) << "\n";
    cout << catSound.compare(catSound) << "\n";
    
    /* string 복사 */
    string userName = "Yun Jinhyuk";
    string fullName = userName.assign(userName);
    cout << fullName << "\n";
    string lastName = fullName.assign(fullName, 0, 3);
    cout << lastName << "\n";
    
    /*이름 시작 위치 출력*/
    int firstNameIdx = userName.find("Jin");
    cout << "이름은 " << firstNameIdx << "부터 있습니다." << "\n";
    
    /* str 추가 */
    userName.insert(firstNameIdx, "Professor ");
    cout << "새 이름은 " << userName << "\n";
    
    /* str 삭제 */
    userName.erase(firstNameIdx, 10);
    cout << "새 이름은 " << userName << "\n";
    
    /* str 교체 */
    userName.replace(firstNameIdx, 8, "Man");
    cout << "새 이름은 " << userName << "\n";
    
    /* C++의 벡터
     => 변수의 길이를 자유자재로 바꿀 수 있는 배열 */
    vector <int> lottoNumVec(6); //int타입의 벡터를 생성해 6개의 값 0으로 초기화
    int lottoNumArray[6] = {10, 23, 25, 31, 38, 40}; // 벡터값 정의
    /* 벡터안에 array 복사하기
    insert(lottoNumVec.begin():lottoNumVec의 처음부터, lottoNumArray의, lottoNumArray의 3번째까지) */
    lottoNumVec.insert(lottoNumVec.begin(), lottoNumArray, lottoNumArray + 3);
    cout << lottoNumVec[2] << "\n";
    /* cout << lottoNumVec[2] << "\n";과 같은방식인데
     at은 특정 위치의 변수를 리턴 해줌 */
    cout << lottoNumVec.at(2) << "\n";
    /* 같은건데 다른방식
    44를 4번 자리에 추가*/
    lottoNumVec.insert(lottoNumVec.begin() + 4, 44);
    cout << lottoNumVec.at(4) << "\n";
    
    /* 벡터의 사이즈 측정
     string과 같은 메소드를 공유함
     사이즈가 10으로 나오는 것은 처음 insert로 3개 복사해서 추가하고 바로 위에서 하나 새로 정의해서 10임
     => 가변성의 높음 => 벡터는 길이를 유연하게 변형할 수 있는 자료형이다 */
    cout << lottoNumVec.size() << "\n";
    /* 맨 끝의 값을 알고싶을 때 */
    cout << lottoNumVec.back() << "\n";
    /* 맨 처음 값 알고 싶을 때 */
    cout << lottoNumVec.front() << "\n";
    /* 비어있는지 채워져 있는지 검사하는 것, true false로 반환 */
    cout << lottoNumVec.empty() << "\n";
    
    
    /* C++의 함수*/
    /* 숫자 두개 곱하는 함수 만들기 */
    /* main 재정의라고 떠서 주석 처리함
     함수 정의할 때 메인 함수 이전에 정의 하고 메인함수를 시작해서 그 안에서 사용해야함
    int multiplyNumbers(int numOne, int numTwo = 1) // int numTwo = 1 은 변수 하나만 입력된 경우 int numOone으로 대입하고 int numTwo 는 1로 계산
    {
        int resultValue = numOne * numTwo;
        return resultValue;
    }

    int multiplyNumbers(int numOne, int numTwo, int numThree)
    {
        int resultValue = numOne * numTwo * numThree;
        return resultValue;
    }
     
    int main()
    {
        cout << multiplyNumbers(1) << "\n";
     
        cout << multiplyNumbers(1, 3) << "\n";
     
        cout << multiplyNumbers(1, 3, 5) << "\n";
        
        return 0;
    }
    */
    /* C++의 신기한 기능 중 같은 함수라고 안의 변수라던지 변수 타입을 바꿔서 다른 함수 처럼 쓸 수 있음 => 함수 오버로딩이라고 함
     => 프로그램이 커지면 같은 종류의 계산을 하는 경우가 많아짐, 여럿이서 개발할 때 같은 연산에 같은 함수를 사용해서 코드의 일관성 유지하는 것 중요
     */
    
    /* 재귀함수 : 자기자신을 호출해 결과를 내는 함수
     하지만 대부분 루프로고 구현 가능
     효율적인 방법은 그때그때 다르니 잘 해보기
     예시) factorial, n! => 자기자신을 빼면서 계속 곱함
     */
    /*
    int getFactorial(int num)
    {
        int fac;
        if(num -- 1) fac - 1;
        else fac - getFactorial(num - 1) * num;
        
        return fac;
    }
    
    int main()
    {
        cout << "Factorial of 10 is " << getFactorial(10) << "\n";
     }
    */
    
    
    /* 파일 다루는 법
     텍스트나 바이너리 파일 다루는 법 단순함
     만들어지긴하는거 같은데 왼쪽에 파일이 안뜸 나중에 vscode 고쳐서 그걸로 다시해보기
     일단은 주석처리
     */
    
    /* 파일 만들기*/
    /* ofstream outfile을 stream 형식으로 연다는 뜻*/
    
    string datastructure = "자료구조는 다양한 자료구조의 형태와 알고리즘을 배우는 과목입니다.";
    ofstream f_out("ds.txt");
    
    if(!f_out)
    {
        cout << "파일이 열려있지 않습니다." << "\n";
    }
    else
    {
        f_out << datastructure << "\n";
        f_out.close();
    }
    
    /* 만든 파일에 덧붙이기 */
    
    string datastructure2 = "이번 학기 자료구조는 윤진혁 교수가 가르칩니다.";
    ofstream f_out2("ds.txt", ios::app);
    
    if(!f_out2)
    {
        cout << "파일이 열려있지 않습니다." << "\n";
    }
    else
    {
        f_out2 << datastructure2 << "\n";
        f_out2.close();
    }
    
    
    /*  이외에도 아래와 같이 ios::*를 통해 파일을 다룰 수 있습니다.
     ios::binary : 파일을 binary로 다루기
     ios::in : 파일을 읽기만 가능한 형태로 열기
     ios::out : 파일을 쓰기만 가능한 형태로 열기
     ios::ate : 파일을 오픈하면서 파일포인터를 끝부분으로 옮기기
     ios::trunc : 오픈하고자하는 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만들기(기본 설정)
     ios::nocreate : 파일을 열지 않고 파일이 있는지만 확인. 파일이 없으면 에러
     ios::noreplace : 파일이 존재하면 에러를 발생
     */
    
    /* 파일 읽기*/
    char letter;
    
    fstream f_in("ds.txt");
    if(!f_in)
    {
        cout << "파일이 열려있지 않습니다." <<"\n";
    }
    else
    {
        for(int i = 0; !f_in.eof(); i++)
        {
            f_in.get(letter);
            cout << letter;
        }
    }
    
    /* C++에서 exception 다루는 법, 간략하게만 */
    /* 변수 두개를 서로 바꿔주는 함수
     a==b 일때 catch에 a를 보내는 exception
     함수 정의니까 int main이전에 써야함 그래서 주석처리 */
    /*
    void swap(int &a, int &b)
    {
        int tmp;
       
        if(a==b) throw a;
        tmp - a;
        a - b;
        b = tmp;
    }
    */
    /*
    int main()
    {
        try
        {
            int a = 3;
            int b = 3; b 값을 3이나 2로 바꿔보기
            swap(a, b);
        }
        에러 방지를 위해 catch가 있음, throw로 온 변수를 받아서 에러 메세지 표시
        catch(int val)
        {
            cout << "두 값이 모두 " << val << "으로 같습니다. \n";
        }
    }
    // 파이썬에서 try, except 느낌인거 같음
    */
    
    /* 비슷하게 함수를 사용하지 않고 하는 방법 */
    int num = 1; /* 0일 경우 나눌 수 없기 때문에 에러로 에러문구가 뜸*/
    try
    {
        if(num == 0)
        {
            throw num;
        }
        cout << 2/num << "\n";
    }
    catch(int num)
    {
        cout << num << "은 올바르지 않은 분모입니다. \n";
    }

    
    

    /* 3강
    포인터 레퍼런스 참조자 */
    int myAge = 100;
    /*재정의라서 주석처리함
    char myGrade = 'A';
     */
    
    cout << "Size of int " << sizeof(myAge) << "\n";
    cout << "Size of char " << sizeof(myGrade) << "\n";

    
    /* 변수가 메모리의 어디에 있는지 찾기 */
    cout << "변수 myAge는 메모리의 어디에 있나요?  " << &myAge << "\n";
    /* 자료구조의 중요성 => 컴퓨터 메모리의 구조 => 방같은 것들이 여러개 있음, 방마다 주소가 있고 데이터가 들어있음 => 데이터에 access하기위해 주소를 찾아가는 방식 &변수 자리에 나타난 것이 그 방 주소 */
    
    
    /* 포인터
     myAge의 위치를 가리키는 포인터 만들기
     같은 주소를 참조하고 있기 때문에 같은 주소가 나옴 */
    int* agePointer = &myAge;
    cout << "agePointer는 메모리의 어디를 참조하나요? " << agePointer << "\n";
    
    /* 참조자 추가 예시 1
    포인터를 받아서 그 포인터 위치에 있는 변수의 값을 바꾸는 함수 5 -> 3으로 바뀜 */
    /* 함수정의라 주석처리함
    int change_val(int *p)
    {
        *p = 3;
        return 0;
    }
    int main()
    {
    int number = 5;
    cout << number << "\n";
    change_val(&number);
    cout << number << "\n";
    5, 3 출력
    }
    
     예시 2
     참조자를 받아서 변수값 바꾸는 함수, 5 -> 3으로 바뀜
     int change_val2(int &p)
     {
        p = 3;
        return 0;
     }
     {
         *p = 3;
         return 0;
     }

     number = 5; 앞에서 이미 정의해서 이렇게만 씀
     cout << number << "\n";
     change_val2(number);
     cout << number << "\n";
     5, 3 출력
     */
    
    
    /* 레퍼런스 정의, 레퍼런스는 자기가 값을 가지는 것이 아니라 특정값을 가지는 대상을 얘는 얘에요라고 가리키는 것 => 자신이 값을 가지지 않으므로 비어있는 상태(int ref;)로 정의 불가
     인테그랄 레퍼런스 정의 */
    int number = 10;
    int &ref = number; /* 참조자 선언,number와 값 공유함 int &ref; 는 오류뜸 => 변수와 다르게 이런식으로 정의 안됨 */
    int *p = &number; /* 포인터 선언, number의 주소만 가져옴 */
    
    /* 포인터와, 레퍼런스가 어떻게 다른지 보자*/
    cout << "참조자" << "\n";
    cout << ref << " " << &ref << "\n"; //참조자를 불러옴
    ref++; /* ref라는 참조자를 증가연산할 수 있음 => 증가연산을 할 경우 참조자는 원래 변수를 바꿈 예시) 10 -> 11, 주소는 그대로 */
    cout << ref << " " << &ref << "\n";
    cout << number << " " << &number << "\n";
    
    /* 같은 것 다시한번
     포인터의 증가연산은 주소값을 증가연산해서 바꿔줌 값이 바뀌는 것이 아님
     그래서 바뀐 주소에 있던 값이 참조가 됨 예시)주소 : 0x61fe0c -> 0x61fe10, 값 : 11 -> 6422032 */
    cout << "포인터" << "\n";
    cout << p << " " << *p << "\n"; // p의 주소창은 위 number의 주소와 같고 값도 11
    p++;
    cout << p << " " << *p << "\n"; // 증가연산 이후의 포인터 p는 주소값을 증가 연산함 integer size만큼 증가
    cout << number << " " << &number << "\n";
    /* 즉 포인터는 증가연산을 할 때 주소만 바뀌고 값이 바뀌지 않음 , number라는 변수는 변하지 않고 11로 남아있음*/
    
    /* 포인터와 레퍼런스가 다르기 때문에 편한식으로 쓸 수 있는 법 */
    int x;
    int &y = x;
    int &z = y;
    x = 1;
    cout << x << y << z << "\n";
    y = 2;
    cout << x << y << z << "\n";
    z = 5;
    cout << x << y << z << "\n";
    /* x y z 중 어떤 것을 바꿔도 x값이 바뀜
     즉 참조자의 연산이 포인터보다 훨씬 간편 */
    
    /* 참조자를 array에서 어떻게 쓸 수 있을까 */
    /*
    int a, b;
    int &arr[2] = {a, b}; //이런식으로 참조자의 array를 만드는 것은 할 수 없음
     */
    
    /* 이미 있는 array에 대해서 참조자를 만드는 것은 가능 */
    cout << "array를 참조자로 만들기" << "\n";
    int arr[3] = {1, 2, 3};
    int (&ref2)[3] = arr;
    cout << ref2[0] << ", " << ref2[1] << ", " << ref2[2] << "\n";
    /* 포인터는 더 편하게 정의 할 수 있음 int *p 로 모든 일차 배열을 가질 수 있음  -> 이런 경우 포인터가 편함 */
    ref2[0] = 4;
    ref2[1] = 2;
    ref2[2] = 7;
    cout << ref2[0] << ", " << ref2[1] << ", " << ref2[2] << "\n";
    cout << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";
    
    /* 2차원 배열
     예시) 2X3 배열 */
    int arr3[2][3] = {1, 2, 3, 4, 5, 6}; // {{1, 2}, {3, 4}, {5, 6}} 이렇게 굳이 안써도 됨
    int(&ref3)[2][3] = arr3;
    
    cout << ref3[0][0] << ", " << ref3[0][1] << ", " << ref3[0][2] << "\n";
    cout << ref3[1][0] << ", " << ref3[1][1] << ", " << ref3[1][2] << "\n";
    
    /* 참조자를 return하는 함수 만들기
    int &return_ref2(int &a){return a;}
    여기부턴 메인함수에 들어가야함
    int x = 1;
    cout << return_ref2(x)++ << "\n";
    cout << x << "\n";
     */
    
    /* 끝! */
    return 0;
}












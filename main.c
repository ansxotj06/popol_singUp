#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<unistd.h>

void print_menu(void);  //print_menu 함수원형
int choice_menu(void);  //choice_menu 함수원형
int loginp(void);  //login 함수원형
int fine_menu(void);  //회원정보 찾기 함수원형
void SignUp(void);  //임시 회원가입 함수원형
void login_delay(void);  //로그인 지연 함수원형
int End(void);  //종료 함수원형
int page(void);  //페이지 함수원형


#define success 1
#define fail 0

int count_login = 0, count_member = 1;  //로그인 시도횟수, 회원수 - (전역변수)


struct login_data {
    char ID[13], PW[13], Name[10], Email[40];
    int Age, CallNumber;
};  //회원정보를 저장하는 데이터구조체

struct login_data p[5];


int main(void)
{
    int choice, result;

    strcpy(p[0].ID, "moontaeseo");
    strcpy(p[0].PW, "moontaeseo");
    strcpy(p[0].Name, "문태서");
    strcpy(p[0].Email, "22sunrin073");
    p[0].Age = 17;
    p[0].CallNumber = 33181668;


    while (1)
    {
        if (count_login > 5)  //로그인 시도횟수가 5초과일 경우
        {
            login_delay();  //로그인 지연 함수실행
        }

        
        print_menu();  //메뉴출력 함수실행
        choice = choice_menu();  //메뉴선택 함수실행 - 입력값 반환

//        system("cls");

        if (choice == 1)  //메뉴 = 1. 로그인
        {
            result = loginp();  //로그인 함수실행 - 결과값 반환

            if (result == 0)  //로그인 실패
            {
                count_login++;  //로그인횟수 증가
            }
            else if (result == 1)  //로그인 성공
            {
                page();  //페이지 함수실행
            }

        }
        else if (choice == 2)  //메뉴 = 2. 회원정보 찾기
        {
            fine_menu();  //회원정보 찾기 함수실행
        }
        else if (choice == 3)  //메뉴 = 3. 임시 회원가입
        {
            SignUp();  //임시 회원가입 함수실행
        }
        else if (choice == 4)  //메뉴 = 4. 프로그램 종료
        {
            return(End());  //프로그램 종료 함수실행
        }
        else
        {
            printf("\n###올바른 메뉴를 입력하여주세요...\n");

//            Sleep(2400);

            return(End());  //종료 함수실행
        }

//        system("cls");
    }
}



void print_menu(void)  //메뉴출력 함수
{
    printf("    ===============================\n");
    printf("        1. 로그인\n");
    printf("    ===============================\n");
    printf("        2. 회원정보 찾기\n");
    printf("    ===============================\n");
    printf("        3. 임시 회원가입\n");
    printf("    ===============================\n");
    printf("        4.프로그램 종료\n");
    printf("    ===============================\n>>> ");
}


int choice_menu(void)  //메뉴선택 함수
{
    int input;

    scanf("%d", &input);

    return(input);
}


int loginp(void)  //로그인 함수
{
    char input_ID[12] = { '\0' }, input_PW[12] = { '\0' };

    printf("***로그인화면***\n\n");
    printf("ID: ____________\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", input_ID);
    printf("PW: ____________\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", input_PW);

    for (int i = 0; i < count_member; i++)
    {
        if (strcmp(p[i].ID, input_ID) == 0 && strcmp(p[i].PW, input_PW) == 0)
        {
            printf("\n###로그인에 성공하셨습니다.\n");

//            Sleep(2400);

            return success;
        }
        else
        {
            if (i == (count_member - 1))  //마지막 구조체(회원)까지 검사했을 경우
            {
                printf("\n###회원정보가 일치하지 않습니다.\n");

//                Sleep(2400);

                return fail;
            }
            else  //마지막 구조체(회원)까지 검사하지 않았을 경우
            {
                continue;  //i를 증가시켜 다른회원 검사
            }
        }
    }
    
    return 0;
}


int fine_menu(void)  //회원정보 찾기 함수
{
    char input_name[10], input_Email[40];
    int input_age, input_CallNumber, choice;

    printf("###회원정보 찾기를 진행합니다...###\n\n\n\n");
    printf("이름: ___\b\b\b");
    scanf("%s", input_name);

    printf("나이: __\b\b");
    scanf("%d", &input_age);

    printf("핸드폰 번호: 010 ________\b\b\b\b\b\b\b\b");
    scanf("%d", &input_CallNumber);

    printf("이메일 주소: ");
    scanf("%s", input_Email);

//    Sleep(2000);

    for (int i = 0; i < count_member; i++)
    {
        if (strcmp(p[i].Name, input_name) == 0 && (input_age == p[i].Age) && (input_CallNumber == p[i].CallNumber) && strcmp(p[i].Email, input_Email) == 0)
        {        //입력한 회원정보가 저장된 회원정보와 모든 항목이 일치할 경우

            printf("===================================\n");
            printf("%s님의  아이디 및 패스워드\n\n\n", p[i].Name);
            printf("ID: %s\n", p[i].ID);
            printf("PW: %s\n", p[i].PW);

//            Sleep(3000);
            
            do
            {
                printf("\n    메뉴 화면으로 돌아가시려면 1을 입력하세요..\n\n");
                printf("    1. 메뉴 화면으로 돌아가기\n    >>> ");
                scanf("%d", &choice);
                
            } while (choice != 1);
            
            return 0;
            
           

            //Sleep(2000);


        }
        else  //입력한 회원정보가 저장된 회원정보와 일치하지 않을 경우
        {
            if (i != (count_member - 1))  //마지막 회원까지 검사하지 않았을 경우
            {
                continue;  //i를 증가시켜 다른회원 검사
            }

            printf("\n\n일치하는 회원정보가 존재하지 않습니다.\n");

//            Sleep(3000);

            printf("메뉴 화면으로 돌아갑니다...\n");

//            Sleep(1500);

            return 0;
        }

    }
    return 0;
}


void SignUp(void)  //임시 회원가입 함수
{

    printf("###임시 회원가입을 진행합니다...");

//    Sleep(2000);
//    system("cls");

    printf("이용자님의 정보를 입력하여주세요...\n\n\n");
    printf("이름: ");
    scanf("%s", p[count_member].Name);

    printf("나이: ");
    scanf("%d", &p[count_member].Age);

    printf("핸드폰 번호: 010 ________\b\b\b\b\b\b\b\b");
    scanf("%d", &p[count_member].CallNumber);

    printf("이메일 주소: ");
    scanf("%s", p[count_member].Email);

//    Sleep(2000);
//    system("cls");

    printf("사용하실 아이디와 패스워드를 입력하여주세요... **최대 12문자\n\n\n");
    printf("아이디: ____________\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", p[count_member].ID);
    printf("패스워드: ____________\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", p[count_member].PW);

//    Sleep(1500);

    printf("=======================================================\n\n");
    printf("회원가입이 완료되었습니다!!        #회원번호%d\n\n", count_member);
    printf("로그인을하여 회원페이지를 이용하실 수 있습니다.\n");

    count_member++;

//    Sleep(4000);
}


void login_delay(void)  //로그인 지연 함수
{
    printf("###로그인시도 초과로 인해 로그인이 잠시 지연됩니다.###\n\n\n");

//    Sleep(2000);

    for (int i = 5; i > 0; i--)
    {
        printf("%d초 뒤 로그인지연이 해제됩니다...\n", i);

//        Sleep(1000);
    }

    count_login = 0;  //로그인횟수 초기화
}


int End(void)  //프로그램 종료 함수
{
    for (int i = 5; i > 0; i--)
    {
        printf("%d초 후에 프로그램이 종료됩니다...\n", i);

        sleep(1);
    }

    return 0;
}


int page(void)  //페이지 함수
{


//    system("cls");

    
//    Sleep(5000);

    printf("로그인 화면입니다...");    
    
    return 0;
}


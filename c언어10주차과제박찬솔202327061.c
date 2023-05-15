#include <stdio.h>

int title_screen() {
    char gameTitle[13][51] = {
        "################################################",
        "##                                            ##",
        "##                                            ##",
        "##             American sniper                ##",
        "##                    -V0.1-                  ##",
        "##                                            ##",
        "##                                            ##",
        "##                                            ##",
        "##            1.GAME START                    ##",
        "##            2.How TO Play                   ##",
        "##            3.EXIT                          ##",
        "##                                            ##",
        "################################################"
    };

    int i = 0;
    while (i < 13) {
        printf("%s\n", gameTitle[i]);
        i++;
    }

    return 0;
}

int introduce_screen() {
    printf("         -게임설명-        .\n");
    printf("이 게임은 전체 이용가 입니다.\n");
    printf("선택을 하여 게임을 하십시오.\n");
    printf("당신의 선택하나하나가 이야기를 바꿉니다 신중히 선택하세요.\n");
    return 0;
}

int main() {
    int game_state = 0; // 게임 상태 변수, 0 = 메뉴, 1 = 게임 실행 중
    int game_running = 1; 
    int screen = 1; // 화면 상태 변수, 1 = 타이틀 스크린, 0 = 게임 설명 스크린
    char key_input = 0; // 사용자 입력을 저장할 변수

    while (game_running) {
        if (game_state == 0) { // 메뉴 상태일 때
            if (screen == 1) { // 타이틀 스크린 표시
                title_screen(); 
                screen = 0;
            }

            scanf(" %c", &key_input);

            if (key_input == '2') {
                introduce_screen();
            }
            else if(key_input == '3') {
                break;
            }
            else if(key_input == '1') {
                printf("구현안됨");
                break;
            }
        }
    { // 게임 설명 상태일 때
            introduce_screen();
            printf("Return to menu?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            
            scanf(" %c", &key_input);

            if (key_input == '1') {
                game_state = 0;
                screen = 1; // 메뉴 화면 출력
            }
            else if (key_input == '2') {
                introduce_screen();
                printf("Return to menu?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                screen = 0; // 게임 설명 화면 출력
            }
        }
    }

    return 0;
}
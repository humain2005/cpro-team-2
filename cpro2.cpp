//sj.txt 파일에서 값을 읽어 과목 평균 및 개인별 평균을 구해서 화면에 출력하는 코드
#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
    char name[20];                     // 학생의 이름 (최대 20글자)
    int id;                            // 학번
    int cpro;                        // 1과목 성적
    int webpro;                        // 2과목 성적
} Student;
int main() {
    FILE *fp = fopen("sj.txt", "rb");  // 파일을 바이너리 읽기 모드로 열기
    Student students[3];               // 학생 정보를 담을 구조체 배열 선언
    for (int i = 0; i < 3; i++) {
        fread(&students[i], sizeof(Student), 1, fp);   // 파일로부터 학생 정보 읽어오기
    }
    fclose(fp);                        // 파일 닫기
    // 과목 평균 구하기
    float cpro_avg = (students[0].cpro + students[1].cpro + students[2].cpro) / 3.0;
    float webpro_avg = (students[0].webpro + students[1].webpro + students[2].webpro) / 3.0;
    float individual_avg[3];
    for (int i = 0; i < 3; i++) {
        individual_avg[i] = (students[i].cpro + students[i].webpro) / 2.0;  // 개인별 평균 성적 구하기
    }
    // 과목 평균 및 개인별 평균 출력
    printf("c 프로그래밍 평균 성적: %.2f\n", cpro_avg);  //c 프로그래밍 평균 성적 출력
    printf("웹 프로그래밍 평균 성적: %.2f\n", webpro_avg); //웹 프로그래밍 평균 성적 출력
    for (int i = 0; i < 3; i++) {
        printf("%s의 평균 성적: %.2f\n", students[i].name, individual_avg[i]);  //개인별 평균 성적 출력
    }
    return 0;
}                                      //프로그램 종료
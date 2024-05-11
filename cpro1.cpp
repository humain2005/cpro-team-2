//학생의 정보를 저장하는 구조체 정의 후, 이를 파일에 저장
#include <stdio.h>
#include <stdlib.h>                
typedef struct Student {            //구조체 정의
  char name[20];                    //이름 (최대 20글자)
  int id;                           //학번
  int cpro;                       //1과목 성적
  int webpro;                       //2과목 성적
} Student;
int main() {
  Student students[3] = {           //3명의 정보를 담응 배열 선언 및 초기화
    {"권도윤", 20240938, 90, 85},
    {"최태인", 20240960, 85, 90},
    {"박지영", 20230003, 78, 83},
  }; 
  FILE *fp = fopen("sj.txt", "wb"); //파일을 쓰기 모드로 열기
  for (int i = 0; i < 3; i++) {     //3회 반복
    fwrite(&students[i], sizeof(Student), 1, fp); //학생 정보 배열을 하나씩 읽고, sj.txt 파일에 바이너리 데이터 형식으로 출력
  }
  fclose(fp);                       //파일 닫기
  return 0;
}                                   //프로그램 종료
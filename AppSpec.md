APP OVERVIEW
- StudentInfoSystem은 콘솔에서 실행되는 학생 정보 관리 프로그램이다.
- 학생 레코드는 Name, StudentID, AdmissionYear, BirthYear, Department, Tel 필드를 가진다. StudentID는 10자리 숫자이며 앞 4자리는 AdmissionYear로 사용된다.
- 데이터는 실행 시 파일에서 불러오고 종료 시 저장된다. 중복 StudentID가 삽입되면 `Error : Already inserted` 메시지가 출력된다.

MAIN MENU
화면에는 다음과 같이 표시된다.
--- Main Menu ---
1. Insertion
2. Search
3. Sorting Option
4. Exit
5. Agent Mode
> 

MENU DETAIL
1) Insertion
   - 5단계 입력 마법사.
   - 순서와 프롬프트: `--- Add New Student ---`와 함께 Name, 이어서 Student ID, Birth Year, Department, Telephone.
   - 권장 입력 형식: Name은 영문 1~15자, Student ID는 10자리 숫자, Birth Year는 4자리 연도, Department는 영문 1~23자, Telephone은 1~12자리 숫자.
   - 마지막 단계에서 전화번호를 제출하면 학생이 리스트에 추가되고 메인 메뉴로 복귀한다.
   - StudentList가 StudentID 중복을 감지하면 예외가 발생하며 표준 에러에 메시지를 남기고 동일 단계가 다시 표시된다.

2) Search
   - 선택 화면: `--- Search ---`와 함께 1~6 옵션과 `> ` 프롬프트가 출력된다.
     1. Search by Name
     2. Search by Student ID
     3. Search by Admission Year
     4. Search by Birth Year
     5. Search by Department
     6. List All
   - 1~5를 고르면 각각 키워드 입력 프롬프트(`Name Keyword:`, `Student ID Keyword:`, `Admission Year Keyword:` 등)가 나온다.
   - 검색은 부분 문자열 매칭을 사용한다. 결과는 표 형태로 이름, 학번, 학과, 생년, 전화번호가 열 너비를 맞춘 채 출력된다.
   - 결과가 없으면 `NO RESULTS FOUND`가 출력된다.
   - 검색 결과 출력 후에는 다시 Search 메뉴가 표시된다.
   - 6을 고르면 전체 학생 목록을 동일한 표 형식으로 출력한다.

3) Sorting Option
   - 화면: ` --- Sorting Option ---` 뒤에 1~4 선택지와 `> ` 프롬프트가 나온다.
     1. Sort by Name
     2. Sort by StudentID
     3. Sort by BirthYear
     4. Sort by Department
   - 각 정렬은 StudentList 전체를 해당 키로 오름차순 정렬한다.
   - 정렬이 끝나면 `Sorting completed`가 출력되고 메인 메뉴로 돌아간다.

4) Exit
   - 선택 시 `exit program` 메시지를 띄우고 StudentList를 파일에 저장한 뒤 종료한다.

5) Agent Mode
   - 사용자가 수동으로 `5`를 입력하면 `>>> Agent mode on!`이 출력된다.
   - 이때 콘솔에서 추가 질문을 받아 LLM에 전달하는 사용자 입력이 저장된다.
   - 에이전트는 이후 화면 출력에 따라 필요한 값만 입력해야 하며, 메인 메뉴에서 다시 수동 입력으로 돌아가려면 LLM이 `exit`를 반환하거나 플래그가 초기화되어야 한다.

ERROR AND FEEDBACK
- 메뉴에서 허용 범위를 벗어난 값을 입력하면 `Invaild Input` 메시지가 나온다.
- `Error : Already inserted`는 동일한 StudentID 삽입 시 출력된다.
- 기타 재시도 메시지가 출력되면 직전 단계 입력을 다시 요구한다.

SCREEN EXAMPLE
사용자가 Search 메뉴에서 "2024학번 학생들 찾아줘"라고 질문할 경우, 에이전트는 먼저 Search 메뉴에서 적절한 옵션을 선택한 뒤 Admission Year 키워드를 2024로 입력해야 한다.

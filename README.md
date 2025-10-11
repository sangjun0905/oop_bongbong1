# oop_bongbong1
봉봉 과제1 prob2

mkdir build 
cd build
cmake ..
make
./StudentInfoSystem file1.txt


// ninja 설치해서 실행 하는 경우
cmake -S . -B build -G Ninja
cmake --build build
cd build
./StudentInfoSystem.exe

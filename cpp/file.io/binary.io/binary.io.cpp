#include <iostream>
#include <fstream>
#include <iomanip> // hex 출력을 위한 헤더 파일

using namespace std;

int main()
{
    ifstream file("leaf.jpg", ios::binary);


    if (file)
    {
        string line;
        getline(file, line); // 첫 줄만 읽어옴

        cout << "First line in hex format:" << endl;

        // 각 문자를 hex 형식으로 변환하여 출력
        for (char c : line)
        {
            stringstream ss;
            ss << hex << static_cast<int>(static_cast<unsigned char>(c));
            cout << ss.str() << " ";
        }
        cout << endl;
    }
    else cerr << "Failed to open the file." << endl;


    /*
    if (file)
    {
        file.seekg(0, ios::end);    //  파일 포인터를 파일의 끝으로 이동
        streampos file_size = file.tellg(); // streampos: 파일의 크기를 나타내는 정수형 타입, file.tellg(): 현재 파일 포인터의 위치를 반환
        file.seekg(0, ios::beg);    // 파일 포인터를 파일의 시작으로 다시 이동, ios::beg는 파일의 시작을 나타내는 상수

        //  파일 데이터를 저장할 버퍼 생성
        char* buffer = new char[file_size];

        file.read(buffer, file_size);

        cout << "File contents: " << endl;
        // 16진수로 출력
        for (int i = 0; i < file_size; i++)
        {
            cout << hex << setw(2) << setfill('0') << static_cast<unsigned int>(buffer[i]) << " ";
            if ((i + 1) % 16 == 0) // 매 16바이트마다 개행
                cout << endl;
        }

        delete[] buffer;
    }
    else cerr << "Failed to open the file." << endl;
    */


    return 0;
}
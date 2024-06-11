#include <iostream>
#include <fstream>
#include <string>

#include "params.h"

#ifndef CLASS_HPP
#define CLASS_HPP

class Data
{
private:
    std::ofstream output_file;
    unsigned int start;  //開始アドレス
    unsigned int length; //データ長
    unsigned int number; //データ数

public:
    Data();
    Data(unsigned int s ,unsigned int l, unsigned int n, std::string path);
    template<typename T>
    void output(const T& data);
    void output2(char data);
    unsigned int getStart()  const; // メンバー変数 start  のゲッター
    unsigned int getLength() const; // メンバー変数 length のゲッター
    unsigned int getNumber() const; // メンバー変数 number のゲッター
};

Data::Data()
{
    output_file.open("output.txt");
    start  = 0;
    length = 0;
    number = 0;
}

Data::Data(unsigned int s, unsigned int l, unsigned int n, std::string path)
{
    output_file.open(path);
    start  = s;
    length = l;
    number = n;
}

template<typename T>
void Data::output(const T& data)
{
    output_file << data;
}

void Data::output2(char data)
{
    output_file << (int)(unsigned char)data;
}

unsigned int Data::getStart() const
{
    return start;
}

unsigned int Data::getLength() const
{
    return length;
}

unsigned int Data::getNumber() const
{
    return number;
}

#endif
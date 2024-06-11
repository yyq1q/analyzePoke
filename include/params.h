#include <string>

#ifndef PARAMS_H
#define PARAMS_H

//ROMのファイルパス
std::string rom_file_path = "rom/rom.gba";

//output file
std::string output_file_path = "output/output.csv";

//名前
unsigned int NameStartAddress      = 0x00AA5400;
unsigned int NameLength            = 6;
//unsigned int NameNumber            = 896;
unsigned int NameNumber            = 413;

//ステータス
unsigned int BaseStatsStartAddress = 0x00AA8C00;
unsigned int BaseStatsLength       = 28;
unsigned int BaseStatsNumber       = 896;

//進化情報
unsigned int EvolveStartAddress    = 0x00AC3300;
unsigned int EvolveLength          = 40;
unsigned int EvolveNumber          = 896;
unsigned int EvoSkipValue          = 411;
unsigned int EvoSkipAddress        = 0x00AB32C0;

//特性名
unsigned int AbilityStartAddress    = 0x00B20000;
unsigned int AbilityLength          = 8;
unsigned int AbilityNumber          = 166;

//特性説明
unsigned int AbilityExpStartAddress = 0x00B21000;

#endif
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

#include "params.h"
#include "CLASS.hpp"
#include "charSet.hpp"
#include "itemSet.hpp"
#include "typeSet.hpp"
#include "abilitySet.hpp"
#include "evoSet.hpp"
#include "pokemonName.hpp"

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

void readName(std::string romPath, Data& obj, int mode)
{
    std::ifstream rom(romPath, std::ios::binary); // バイナリモードでファイルを開く

    if (!rom) {
        std::cerr << "Couldn't open Files" << std::endl;
        return;
    }else{
        std::cout << "Open files" << std::endl;

        std::cout << "Start : " << obj.getStart()  << std::endl
                  << "Length: " << obj.getLength() << std::endl
                  << "Number: " << obj.getNumber() << std::endl;

        char byte;
        if((obj.getStart()) >= 0){
            rom.seekg(obj.getStart());
        }else{
            std::cerr << "ERROR: Address is negative." << std::endl;
            rom.seekg(0);
        }

        initializeCharSet();

        for(unsigned int i = 0; i < obj.getNumber(); i++){
            if(mode = 2){
                obj.output("abilitySet[");
                obj.output(i);
                obj.output("] = \"");
            }
            for(unsigned int n = 0; n < obj.getLength(); n++){
                if(rom.get(byte)){
                    switch (mode)
                    {
                    case 0:
                        obj.output(charset[(int)(unsigned char)byte]);
                        break;
                    case 1:
                        obj.output2(byte);
                        obj.output(" ");
                        break;
                    case 2:
                        obj.output(charset[(int)(unsigned char)byte]);
                        break;
                    default:
                        std::cerr << "ERROR: Unknown mode." << std::endl;
                        return;
                    }
                }else{
                    std::cerr << "ERROR: Failed to read byte." << std::endl;
                    return;
                }
            }
            if(mode = 2){
                obj.output("\";");
            }
            obj.output("\n");
        }

        std::cout << "Conversion complete." << std::endl << std::endl;
        rom.close();
        return;
    }
}

void readData(std::string romPath, Data& obj1, Data& obj2, Data& obj3)
{
    std::ifstream rom(romPath, std::ios::binary); // バイナリモードでファイルを開く

    if (!rom) {
        std::cerr << "Couldn't open Files" << std::endl;
        return;
    }else{
        std::cout << "Open files" << std::endl;

        char buffer[4];

        initializeCharSet();
        initializeItemSet();
        initializeTypeSet();
        initializeAbilitySet();
        initializeEvoSet();
        initializePokemonName();

        auto currentAddress_obj1 = obj1.getStart();
        auto currentAddress_obj2 = obj2.getStart();
        auto currentAddress_obj3 = obj3.getStart();

        obj1.output("順番"); obj1.output(",");
        obj1.output("名前"); obj1.output(",");
        obj1.output("H"); obj1.output(",");
        obj1.output("A"); obj1.output(",");
        obj1.output("B"); obj1.output(",");
        obj1.output("S"); obj1.output(",");
        obj1.output("C"); obj1.output(",");
        obj1.output("D"); obj1.output(",");
        obj1.output("タイプ1"); obj1.output(",");
        obj1.output("タイプ2"); obj1.output(",");
        obj1.output("捕獲率"); obj1.output(",");
        obj1.output("基礎経験値"); obj1.output(",");
        obj1.output("努力値1"); obj1.output(",");
        obj1.output("努力値2"); obj1.output(",");
        obj1.output("持ち物50%"); obj1.output(",");
        obj1.output("持ち物5%"); obj1.output(",");
        obj1.output("性別判定"); obj1.output(",");
        obj1.output("孵化歩数"); obj1.output(",");
        obj1.output("初期懐き度"); obj1.output(",");
        obj1.output("経験値タイプ"); obj1.output(",");
        obj1.output("タマゴグループ1"); obj1.output(",");
        obj1.output("タマゴグループ2"); obj1.output(",");
        obj1.output("特性1"); obj1.output(",");
        obj1.output("特性2"); obj1.output(",");
        obj1.output("逃走値"); obj1.output(",");
        obj1.output("色，向き"); obj1.output(",");
        obj1.output("夢特性"); obj1.output(",");
        obj1.output("28byte目"); obj1.output(",");
        for(unsigned int i = 1; i <= 5; i++){
            obj1.output("進化条件");          obj1.output(i); obj1.output(",");
            obj1.output("汎用変数");          obj1.output(i); obj1.output(",");
            obj1.output("進化先");            obj1.output(i); obj1.output(",");
            obj1.output("進化に必要なレベル"); obj1.output(i); obj1.output(",");
        }
        obj1.output("\n");

        for(unsigned int i = 0; i < obj1.getNumber(); i++){
            obj1.output(i);
            obj1.output(",");

            //名前
            rom.seekg(currentAddress_obj1);
            for(unsigned int j = 0; j < obj1.getLength(); j++){
                rom.read(buffer, 1);
                obj1.output(charset[(int)(unsigned char)buffer[0]]);
            }
            obj1.output(",");
            currentAddress_obj1 = rom.tellg();
            
            //種族値
            rom.seekg(currentAddress_obj2);
            for(unsigned int j = 0; j < 6; j++){
                rom.read(buffer, 1);
                obj1.output((int)(unsigned char)buffer[0]);
                obj1.output(",");
            }
            //タイプ
            for(unsigned int j = 0; j < 2; j++){
                rom.read(buffer, 1);
                obj1.output(typeSet[(int)(unsigned char)buffer[0]]);
                obj1.output(",");
            }
            //捕獲率
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //基礎経験値
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //努力値 2byte
            for(unsigned int j = 0; j < 2; j++){
                rom.read(buffer, 1);
                obj1.output((int)(unsigned char)buffer[0]);
                obj1.output(",");
            }
            //持ち物50%
            rom.read(buffer, 2);
            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
            obj1.output(",");
            //持ち物5%
            rom.read(buffer, 2);
            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
            obj1.output(",");
            //性別判定
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //孵化歩数
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //初期懐き度
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //経験値タイプ
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //タマゴグループ1
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //タマゴグループ2
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //特性1
            rom.read(buffer, 1);
            obj1.output(abilitySet[(int)(unsigned char)buffer[0]]);
            obj1.output(",");
            //特性2
            rom.read(buffer, 1);
            obj1.output(abilitySet[(int)(unsigned char)buffer[0]]);
            obj1.output(",");
            //逃走値
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //色，向き
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //夢特性
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //28byte目: 現状謎
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            currentAddress_obj2 = rom.tellg();

            //進化情報
            rom.seekg(currentAddress_obj3);
            for(unsigned int j = 0; j < 5; j++){
                //進化コード
                rom.read(buffer, 1);
                obj1.output(evoSet[(int)(unsigned char)buffer[0]]);
                obj1.output(",");
                //空1byteと汎用変数
                switch ((int)(unsigned char)buffer[0])
                {
                    case 0x00:
                    case 0x01:
                    case 0x02:
                    case 0x03:
                    case 0x05:
                    case 0x0E:
                        //設定なし
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x04:
                    case 0x08:
                    case 0x09:
                    case 0x0A:
                    case 0x0B:
                    case 0x0C:
                    case 0x0D:
                    case 0x10:
                        //レベル
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x06:
                    case 0x07:
                    case 0x13:
                    case 0x14:
                    case 0x16:
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                        break;
                    case 0x0F:
                        //美しさ
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x11:
                        //マップコード
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x12:
                        //技コード
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x15:
                        //手持ちに入れるポケモン指定
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x17:
                        //通信交換のポケモン指定
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    case 0x18:
                        //天候
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                    default:
                        rom.read(buffer, 1);
                        rom.read(buffer, 2);
                        obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                        break;
                }
                obj1.output(",");
                //進化先
                rom.read(buffer, 2);
                obj1.output(pokemonName[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                obj1.output(",");
                //進化に必要なレベル
                rom.read(buffer, 1);
                obj1.output((int)(unsigned char)buffer[0]);
                obj1.output(",");
                //空1byte
                rom.read(buffer, 1);
            }
            currentAddress_obj3 = rom.tellg();

            obj1.output("\n");
        }

        std::cout << "Conversion complete." << std::endl << std::endl;
        rom.close();
        return;
    }
}

void readAbility(std::string romPath, Data& obj, unsigned int ExpStartAddress)
{
    std::ifstream rom(romPath, std::ios::binary); // バイナリモードでファイルを開く

    if (!rom) {
        std::cerr << "Couldn't open Files" << std::endl;
        return;
    }else{
        std::cout << "Open files" << std::endl;

        char buffer[4];

        auto currentAddress_AbilityName = obj.getStart();
        auto currentAddress_AbilityExp  = ExpStartAddress;

        initializeCharSet();

        for(unsigned int i = 0; i < obj.getNumber(); i++){
            obj.output(i);
            obj.output(",");

            //特性名
            rom.seekg(currentAddress_AbilityName);
            for(unsigned int j = 0; j < obj.getLength(); j++){
                rom.read(buffer, 1);
                obj.output(charset[(int)(unsigned char)buffer[0]]);
            }
            obj.output(",");
            currentAddress_AbilityName = rom.tellg();

            //特性説明
            rom.seekg(currentAddress_AbilityExp);
            while(rom.read(buffer, 1)){
                obj.output(charset[(int)(unsigned char)buffer[0]]);
                if((int)(unsigned char)buffer[0] == 0xFF){
                    break;
                }
            }
            currentAddress_AbilityExp = rom.tellg();
            obj.output("\n");
        }

        std::cout << "Conversion complete." << std::endl << std::endl;
        rom.close();
        return;
    }
}

void readData2(std::string romPath, Data& obj1, Data& obj2, Data& obj3)
{
    std::ifstream rom(romPath, std::ios::binary); // バイナリモードでファイルを開く

    if (!rom) {
        std::cerr << "Couldn't open Files" << std::endl;
        return;
    }else{
        std::cout << "Open files" << std::endl;

        char buffer[4];

        initializeCharSet();
        initializeItemSet();
        initializeTypeSet();
        initializeAbilitySet();
        initializeEvoSet();
        initializePokemonName();

        auto currentAddress_obj1 = obj1.getStart();
        auto currentAddress_obj2 = obj2.getStart();
        auto currentAddress_obj3 = obj3.getStart();

        obj1.output("順番"); obj1.output(",");
        obj1.output("名前"); obj1.output(",");
        obj1.output("H"); obj1.output(",");
        obj1.output("A"); obj1.output(",");
        obj1.output("B"); obj1.output(",");
        obj1.output("S"); obj1.output(",");
        obj1.output("C"); obj1.output(",");
        obj1.output("D"); obj1.output(",");
        obj1.output("タイプ1"); obj1.output(",");
        obj1.output("タイプ2"); obj1.output(",");
        obj1.output("捕獲率"); obj1.output(",");
        obj1.output("基礎経験値"); obj1.output(",");
        obj1.output("努力値1"); obj1.output(",");
        obj1.output("努力値2"); obj1.output(",");
        obj1.output("持ち物50%"); obj1.output(",");
        obj1.output("持ち物5%"); obj1.output(",");
        obj1.output("性別判定"); obj1.output(",");
        obj1.output("孵化歩数"); obj1.output(",");
        obj1.output("初期懐き度"); obj1.output(",");
        obj1.output("経験値タイプ"); obj1.output(",");
        obj1.output("タマゴグループ1"); obj1.output(",");
        obj1.output("タマゴグループ2"); obj1.output(",");
        obj1.output("特性1"); obj1.output(",");
        obj1.output("特性2"); obj1.output(",");
        obj1.output("逃走値"); obj1.output(",");
        obj1.output("色，向き"); obj1.output(",");
        obj1.output("夢特性"); obj1.output(",");
        obj1.output("28byte目"); obj1.output(",");
        for(unsigned int i = 1; i <= 5; i++){
            obj1.output("進化条件");          obj1.output(i); obj1.output(",");
            obj1.output("汎用変数");          obj1.output(i); obj1.output(",");
            obj1.output("進化先");            obj1.output(i); obj1.output(",");
            obj1.output("進化に必要なレベル"); obj1.output(i); obj1.output(",");
        }
        obj1.output("\n");

        for(unsigned int i = 0; i < obj1.getNumber(); i++){
            obj1.output(i);
            obj1.output(",");

            //名前
            rom.seekg(currentAddress_obj1);
            for(unsigned int j = 0; j < obj1.getLength(); j++){
                rom.read(buffer, 1);
                obj1.output(charset[(int)(unsigned char)buffer[0]]);
            }
            obj1.output(",");
            currentAddress_obj1 = rom.tellg();
            
            //種族値
            rom.seekg(currentAddress_obj2);
            for(unsigned int j = 0; j < 6; j++){
                rom.read(buffer, 1);
                obj1.output((int)(unsigned char)buffer[0]);
                obj1.output(",");
            }
            //タイプ
            for(unsigned int j = 0; j < 2; j++){
                rom.read(buffer, 1);
                obj1.output(typeSet[(int)(unsigned char)buffer[0]]);
                obj1.output(",");
            }
            //捕獲率
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //基礎経験値
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //努力値 2byte
            for(unsigned int j = 0; j < 2; j++){
                rom.read(buffer, 1);
                obj1.output((int)(unsigned char)buffer[0]);
                obj1.output(",");
            }
            //持ち物50%
            rom.read(buffer, 2);
            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
            obj1.output(",");
            //持ち物5%
            rom.read(buffer, 2);
            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
            obj1.output(",");
            //性別判定
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //孵化歩数
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //初期懐き度
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //経験値タイプ
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //タマゴグループ1
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //タマゴグループ2
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //特性1
            rom.read(buffer, 1);
            obj1.output(abilitySet[(int)(unsigned char)buffer[0]]);
            obj1.output(",");
            //特性2
            rom.read(buffer, 1);
            obj1.output(abilitySet[(int)(unsigned char)buffer[0]]);
            obj1.output(",");
            //逃走値
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //色，向き
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //夢特性
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            //28byte目: 現状謎
            rom.read(buffer, 1);
            obj1.output((int)(unsigned char)buffer[0]);
            obj1.output(",");
            currentAddress_obj2 = rom.tellg();

            if(i <= EvoSkipValue){
                //進化情報
                rom.seekg(currentAddress_obj3);
                for(unsigned int j = 0; j < 5; j++){
                    //進化コード
                    rom.read(buffer, 1);
                    obj1.output(evoSet[(int)(unsigned char)buffer[0]]);
                    obj1.output(",");
                    //空1byteと汎用変数
                    switch ((int)(unsigned char)buffer[0])
                    {
                        case 0x00:
                        case 0x01:
                        case 0x02:
                        case 0x03:
                        case 0x05:
                        case 0x0E:
                            //設定なし
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x04:
                        case 0x08:
                        case 0x09:
                        case 0x0A:
                        case 0x0B:
                        case 0x0C:
                        case 0x0D:
                        case 0x10:
                            //レベル
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x06:
                        case 0x07:
                        case 0x13:
                        case 0x14:
                        case 0x16:
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                            break;
                        case 0x0F:
                            //美しさ
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x11:
                            //マップコード
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x12:
                            //技コード
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x15:
                            //手持ちに入れるポケモン指定
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x17:
                            //通信交換のポケモン指定
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x18:
                            //天候
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        default:
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                    }
                    obj1.output(",");
                    //進化先
                    rom.read(buffer, 2);
                    obj1.output(pokemonName[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                    obj1.output(",");
                    //進化に必要なレベル
                    rom.read(buffer, 1);
                    obj1.output((int)(unsigned char)buffer[0]);
                    obj1.output(",");
                    //空1byte
                    rom.read(buffer, 1);
                }
                currentAddress_obj3 = rom.tellg();
                if(i == EvoSkipValue){
                    currentAddress_obj3 = EvoSkipAddress;
                }
            }else{
                //進化情報
                rom.seekg(currentAddress_obj3);
                for(unsigned int j = 0; j < 5; j++){
                    //進化コード
                    rom.read(buffer, 1);
                    obj1.output(evoSet[(int)(unsigned char)buffer[0]]);
                    obj1.output(",");
                    //空1byteと汎用変数
                    switch ((int)(unsigned char)buffer[0])
                    {
                        case 0x00:
                        case 0x01:
                        case 0x02:
                        case 0x03:
                        case 0x05:
                        case 0x0E:
                            //設定なし
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x04:
                        case 0x08:
                        case 0x09:
                        case 0x0A:
                        case 0x0B:
                        case 0x0C:
                        case 0x0D:
                        case 0x10:
                            //レベル
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x06:
                        case 0x07:
                        case 0x13:
                        case 0x14:
                        case 0x16:
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(itemSet[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                            break;
                        case 0x0F:
                            //美しさ
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x11:
                            //マップコード
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x12:
                            //技コード
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x15:
                            //手持ちに入れるポケモン指定
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x17:
                            //通信交換のポケモン指定
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        case 0x18:
                            //天候
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                        default:
                            rom.read(buffer, 1);
                            rom.read(buffer, 2);
                            obj1.output(static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0])));
                            break;
                    }
                    obj1.output(",");
                    //進化先
                    rom.read(buffer, 2);
                    obj1.output(pokemonName[static_cast<unsigned short>((static_cast<unsigned char>(buffer[1]) << 8) | static_cast<unsigned char>(buffer[0]))]);
                    obj1.output(",");
                    //進化に必要なレベル
                    rom.read(buffer, 1);
                    obj1.output((int)(unsigned char)buffer[0]);
                    obj1.output(",");
                    //空1byte
                    rom.read(buffer, 1);
                }
                currentAddress_obj3 = rom.tellg();
            }

            obj1.output("\n");
        }

        std::cout << "Conversion complete." << std::endl << std::endl;
        rom.close();
        return;
    }
}

#endif
#include <iostream>
#include <string>

#ifndef TYPESET_HPP
#define TYPESET_HPP

std::string typeSet[0xFF + 1];

void initializeTypeSet()
{
    typeSet[ 0] = "無";
    typeSet[ 1] = "闘";
    typeSet[ 2] = "飛";
    typeSet[ 3] = "毒";
    typeSet[ 4] = "地";
    typeSet[ 5] = "岩";
    typeSet[ 6] = "虫";
    typeSet[ 7] = "霊";
    typeSet[ 8] = "鋼";
    typeSet[ 9] = "？";
    typeSet[10] = "炎";
    typeSet[11] = "水";
    typeSet[12] = "草";
    typeSet[13] = "電";
    typeSet[14] = "超";
    typeSet[15] = "氷";
    typeSet[16] = "竜";
    typeSet[17] = "悪";
    typeSet[18] = "";
    typeSet[19] = "";
    typeSet[20] = "";
    typeSet[21] = "";
    typeSet[22] = "";
    typeSet[23] = "妖";
    typeSet[24] = "闇"; //ダーク
}

#endif
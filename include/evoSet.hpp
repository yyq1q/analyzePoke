#include <iostream>
#include <string>

#ifndef EVOSET_HPP
#define EVOSET_HPP

std::string evoSet[0xFF + 1];

void initializeEvoSet()
{
    evoSet[0x00] = "進化なし";
    evoSet[0x01] = "懐き度220以上でレベルアップ";
    evoSet[0x02] = "懐き度220以上で午後にレベルアップ";
    evoSet[0x03] = "懐き度220以上で午前にレベルアップ";
    evoSet[0x04] = "普通にレベルアップ";
    evoSet[0x05] = "通信交換";
    evoSet[0x06] = "特定のアイテムを持たせた状態で通信交換";
    evoSet[0x07] = "アイテム使用";
    evoSet[0x08] = "レベルアップ時攻撃＞防御";
    evoSet[0x09] = "レベルアップ時攻撃＝防御";
    evoSet[0x0A] = "レベルアップ時攻撃＜防御";
    evoSet[0x0B] = "性格値%10≧5でレベルアップ";
    evoSet[0x0C] = "性格値%10＜5でレベルアップ";
    evoSet[0x0D] = "増殖";
    evoSet[0x0E] = "増殖2";
    evoSet[0x0F] = "美しさが指定値以上でレベルアップ";
    evoSet[0x10] = "性別進化";
    evoSet[0x11] = "特定の場所でレベルアップ";
    evoSet[0x12] = "特定の技を覚えてレベルアップ";
    evoSet[0x13] = "特定のアイテムを持たせて午後にレベルアップ";
    evoSet[0x14] = "特定のアイテムを持たせて午前にレベルアップ";
    evoSet[0x15] = "特定のポケモンを手持ちに入れてレベルアップ";
    evoSet[0x16] = "性別＋アイテム使用";
    evoSet[0x17] = "特定のポケモンと通信交換";
    evoSet[0x18] = "特定の天候のマップでレベルアップ";

    for (int i = 0x19; i <= 0xFF; i++) {
        evoSet[i] = i + "未定義";
    }
}

#endif
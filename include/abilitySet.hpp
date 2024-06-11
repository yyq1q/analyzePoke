#include <iostream>
#include <string>

#ifndef ABILITYSET_HPP
#define ABILITYSET_HPP

std::string abilitySet[0xFF + 1];

void initializeAbilitySet()
{
    abilitySet[  0] = "ーーーーーーー終";
    abilitySet[  1] = "あくしゅう終　　";
    abilitySet[  2] = "あめふらし終　　";
    abilitySet[  3] = "かそく終　　　　";
    abilitySet[  4] = "カブトアーマー終";
    abilitySet[  5] = "がんじょう終　　";
    abilitySet[  6] = "しめりけ終　　　";
    abilitySet[  7] = "じゅうなん終　　";
    abilitySet[  8] = "すながくれ終　　";
    abilitySet[  9] = "せいでんき終　　";
    abilitySet[ 10] = "ちくでん終　　　";
    abilitySet[ 11] = "ちょすい終　　　";
    abilitySet[ 12] = "どんかん終　　　";
    abilitySet[ 13] = "ノーてんき終　　";
    abilitySet[ 14] = "ふくがん終　　　";
    abilitySet[ 15] = "ふみん終　　　　";
    abilitySet[ 16] = "へんしょく終　　";
    abilitySet[ 17] = "めんえき終　　　";
    abilitySet[ 18] = "もらいび終　　　";
    abilitySet[ 19] = "りんぷん終　　　";
    abilitySet[ 20] = "マイペース終　　";
    abilitySet[ 21] = "きゅうばん終　　";
    abilitySet[ 22] = "いかく終　　　　";
    abilitySet[ 23] = "かげふみ終　　　";
    abilitySet[ 24] = "はんげき終　　　";
    abilitySet[ 25] = "ふしぎなまもり終";
    abilitySet[ 26] = "ふゆう終　　　　";
    abilitySet[ 27] = "ほうし終　　　　";
    abilitySet[ 28] = "シンクロ終　　　";
    abilitySet[ 29] = "クリアボディ終　";
    abilitySet[ 30] = "しぜんかいふく終";
    abilitySet[ 31] = "ひらいしん終　　";
    abilitySet[ 32] = "てんのめぐみ終　";
    abilitySet[ 33] = "すいすい終　　　";
    abilitySet[ 34] = "ようりょくそ終　";
    abilitySet[ 35] = "はっこう終　　　";
    abilitySet[ 36] = "トレース終　　　";
    abilitySet[ 37] = "ちからもち終　　";
    abilitySet[ 38] = "どくのトゲ終　　";
    abilitySet[ 39] = "せいしんりょく終";
    abilitySet[ 40] = "マグマのよろい終";
    abilitySet[ 41] = "みずのベール終　";
    abilitySet[ 42] = "じりょく終　　　";
    abilitySet[ 43] = "ぼうおん終　　　";
    abilitySet[ 44] = "あめうけざら終　";
    abilitySet[ 45] = "すなおこし終　　";
    abilitySet[ 46] = "プレッシャー終　";
    abilitySet[ 47] = "あついしぼう終　";
    abilitySet[ 48] = "はやおき終　　　";
    abilitySet[ 49] = "ほのおのからだ終";
    abilitySet[ 50] = "にげあし終　　　";
    abilitySet[ 51] = "するどいめ終　　";
    abilitySet[ 52] = "かいりきバサミ終";
    abilitySet[ 53] = "ものひろい終　　";
    abilitySet[ 54] = "なまけ終　　　　";
    abilitySet[ 55] = "はりきり終　　　";
    abilitySet[ 56] = "メロメロボディ終";
    abilitySet[ 57] = "プラス終　　　　";
    abilitySet[ 58] = "マイナス終　　　";
    abilitySet[ 59] = "てんきや終　　　";
    abilitySet[ 60] = "ねんちゃく終　　";
    abilitySet[ 61] = "だっぴ終　　　　";
    abilitySet[ 62] = "こんじょう終　　";
    abilitySet[ 63] = "ふしぎなうろこ終";
    abilitySet[ 64] = "へドロえき終　　";
    abilitySet[ 65] = "しんりょく終　　";
    abilitySet[ 66] = "もうか終　　　　";
    abilitySet[ 67] = "げきりゅう終　　";
    abilitySet[ 68] = "むしのしらせ終　";
    abilitySet[ 69] = "いしあたま終　　";
    abilitySet[ 70] = "ひでり終　　　　";
    abilitySet[ 71] = "ありじごく終　　";
    abilitySet[ 72] = "やるき終　　　　";
    abilitySet[ 73] = "しろいけむり終　";
    abilitySet[ 74] = "ヨガパワー終　　";
    abilitySet[ 75] = "シェルアーマー終";
    abilitySet[ 76] = "テクニシャン終　";
    abilitySet[ 77] = "エアロック終　　";
    abilitySet[ 78] = "ポイズンミスト終";
    abilitySet[ 79] = "はんこうしん終　";
    abilitySet[ 80] = "せんぷう終　　　";
    abilitySet[ 81] = "ふくつのこころ終";
    abilitySet[ 82] = "じしんかじょう終";
    abilitySet[ 83] = "おおきなつばさ終";
    abilitySet[ 84] = "ネガテÄモード終";
    abilitySet[ 85] = "ーーーーーーー終";
    abilitySet[ 86] = "ーーーーーーー終";
    abilitySet[ 87] = "ーーーーーーー終";
    abilitySet[ 88] = "ーーーーーーー終";
    abilitySet[ 89] = "ーーーーーーー終";
    abilitySet[ 90] = "ーーーーーーー終";
    abilitySet[ 91] = "ーーーーーーー終";
    abilitySet[ 92] = "ーーーーーーー終";
    abilitySet[ 93] = "ーーーーーーー終";
    abilitySet[ 94] = "ーーーーーーー終";
    abilitySet[ 95] = "ーーーーーーー終";
    abilitySet[ 96] = "ーーーーーーー終";
    abilitySet[ 97] = "ーーーーーーー終";
    abilitySet[ 98] = "ーーーーーーー終";
    abilitySet[ 99] = "ーーーーーーー終";
    abilitySet[100] = "ーーーーーーー終";
    abilitySet[101] = "ーーーーーーー終";
    abilitySet[102] = "ーーーーーーー終";
    abilitySet[103] = "ーーーーーーー終";
    abilitySet[104] = "ーーーーーーー終";
    abilitySet[105] = "ーーーーーーー終";
    abilitySet[106] = "ーーーーーーー終";
    abilitySet[107] = "ーーーーーーー終";
    abilitySet[108] = "ーーーーーーー終";
    abilitySet[109] = "ーーーーーーー終";
    abilitySet[110] = "ーーーーーーー終";
    abilitySet[111] = "ーーーーーーー終";
    abilitySet[112] = "ーーーーーーー終";
    abilitySet[113] = "ーーーーーーー終";
    abilitySet[114] = "ーーーーーーー終";
    abilitySet[115] = "ーーーーーーー終";
    abilitySet[116] = "ーーーーーーー終";
    abilitySet[117] = "ーーーーーーー終";
    abilitySet[118] = "ーーーーーーー終";
    abilitySet[119] = "ーーーーーーー終";
    abilitySet[120] = "ーーーーーーー終";
    abilitySet[121] = "ーーーーーーー終";
    abilitySet[122] = "ーーーーーーー終";
    abilitySet[123] = "ーーーーーーー終";
    abilitySet[124] = "ーーーーーーー終";
    abilitySet[125] = "ーーーーーーー終";
    abilitySet[126] = "ーーーーーーー終";
    abilitySet[127] = "ーーーーーーー終";
    abilitySet[128] = "ーーーーーーー終";
    abilitySet[129] = "ーーーーーーー終";
    abilitySet[130] = "ーーーーーーー終";
    abilitySet[131] = "ーーーーーーー終";
    abilitySet[132] = "ーーーーーーー終";
    abilitySet[133] = "ーーーーーーー終";
    abilitySet[134] = "ーーーーーーー終";
    abilitySet[135] = "ーーーーーーー終";
    abilitySet[136] = "ーーーーーーー終";
    abilitySet[137] = "ーーーーーーー終";
    abilitySet[138] = "ーーーーーーー終";
    abilitySet[139] = "ーーーーーーー終";
    abilitySet[140] = "ーーーーーーー終";
    abilitySet[141] = "ーーーーーーー終";
    abilitySet[142] = "ーーーーーーー終";
    abilitySet[143] = "ーーーーーーー終";
    abilitySet[144] = "ーーーーーーー終";
    abilitySet[145] = "ーーーーーーー終";
    abilitySet[146] = "ーーーーーーー終";
    abilitySet[147] = "ーーーーーーー終";
    abilitySet[148] = "ーーーーーーー終";
    abilitySet[149] = "ーーーーーーー終";
    abilitySet[150] = "ーーーーーーー終";
    abilitySet[151] = "ーーーーーーー終";
    abilitySet[152] = "ーーーーーーー終";
    abilitySet[153] = "ーーーーーーー終";
    abilitySet[154] = "ーーーーーーー終";
    abilitySet[155] = "ーーーーーーー終";
    abilitySet[156] = "ーーーーーーー終";
    abilitySet[157] = "ーーーーーーー終";
    abilitySet[158] = "ーーーーーーー終";
    abilitySet[159] = "ーーーーーーー終";
    abilitySet[160] = "ーーーーーーー終";
    abilitySet[161] = "ーーーーーーー終";
    abilitySet[162] = "ーーーーーーー終";
    abilitySet[163] = "ーーーーーーー終";
    abilitySet[164] = "ーーーーーーー終";
    abilitySet[165] = "テストとくせい終";

    for (int i = 166; i <= 0xFF; ++i) {
        abilitySet[i] = "未定義";
    }
}

#endif

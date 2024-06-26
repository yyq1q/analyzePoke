#include <iostream>
#include <string>

#ifndef CHARSET_HPP
#define CHARSET_HPP

std::string charset[0xFF + 1];

void initializeCharSet()
{
    charset[0x00] = "　"; //   0
    charset[0x01] = "あ"; //   1
    charset[0x02] = "い"; //   2
    charset[0x03] = "う"; //   3
    charset[0x04] = "え"; //   4
    charset[0x05] = "お"; //   5
    charset[0x06] = "か"; //   6
    charset[0x07] = "き"; //   7
    charset[0x08] = "く"; //   8
    charset[0x09] = "け"; //   9
    charset[0x0A] = "こ"; //  10
    charset[0x0B] = "さ"; //  11
    charset[0x0C] = "し"; //  12
    charset[0x0D] = "す"; //  13 
    charset[0x0E] = "せ"; //  14
    charset[0x0F] = "そ"; //  15
    charset[0x10] = "た"; //  16
    charset[0x11] = "ち"; //  17
    charset[0x12] = "つ"; //  18
    charset[0x13] = "て"; //  19
    charset[0x14] = "と"; //  20
    charset[0x15] = "な"; //  21
    charset[0x16] = "に"; //  22
    charset[0x17] = "ぬ"; //  23
    charset[0x18] = "ね"; //  24
    charset[0x19] = "の"; //  25
    charset[0x1A] = "は"; //  26
    charset[0x1B] = "ひ"; //  27
    charset[0x1C] = "ふ"; //  28
    charset[0x1D] = "へ"; //  29
    charset[0x1E] = "ほ"; //  30
    charset[0x1F] = "ま"; //  31
    charset[0x20] = "み"; //  32
    charset[0x21] = "む"; //  33
    charset[0x22] = "め"; //  34
    charset[0x23] = "も"; //  35
    charset[0x24] = "や"; //  36
    charset[0x25] = "ゆ"; //  37
    charset[0x26] = "よ"; //  38
    charset[0x27] = "ら"; //  39
    charset[0x28] = "り"; //  40
    charset[0x29] = "る"; //  41
    charset[0x2A] = "れ"; //  42
    charset[0x2B] = "ろ"; //  43
    charset[0x2C] = "わ"; //  44
    charset[0x2D] = "を"; //  45
    charset[0x2E] = "ん"; //  46
    charset[0x2F] = "ぁ"; //  47
    charset[0x30] = "ぃ"; //  48
    charset[0x31] = "ぅ"; //  49
    charset[0x32] = "ぇ"; //  50
    charset[0x33] = "ぉ"; //  51
    charset[0x34] = "ゃ"; //  52
    charset[0x35] = "ゅ"; //  53
    charset[0x36] = "ょ"; //  54
    charset[0x37] = "が"; //  55
    charset[0x38] = "ぎ"; //  56
    charset[0x39] = "ぐ"; //  57
    charset[0x3A] = "げ"; //  58
    charset[0x3B] = "ご"; //  59
    charset[0x3C] = "ざ"; //  60
    charset[0x3D] = "じ"; //  61
    charset[0x3E] = "ず"; //  62
    charset[0x3F] = "ぜ"; //  63
    charset[0x40] = "ぞ"; //  64
    charset[0x41] = "だ"; //  65
    charset[0x42] = "ぢ"; //  66
    charset[0x43] = "づ"; //  67
    charset[0x44] = "で"; //  68
    charset[0x45] = "ど"; //  69　
    charset[0x46] = "ば"; //  70
    charset[0x47] = "び"; //  71
    charset[0x48] = "ぶ"; //  72
    charset[0x49] = "べ"; //  73
    charset[0x4A] = "ぼ"; //  74
    charset[0x4B] = "ぱ"; //  75
    charset[0x4C] = "ぴ"; //  76
    charset[0x4D] = "ぷ"; //  77
    charset[0x4E] = "ぺ"; //  78
    charset[0x4F] = "ぽ"; //  79
    charset[0x50] = "っ"; //  80
    charset[0x51] = "ア"; //  81
    charset[0x52] = "イ"; //  82
    charset[0x53] = "ウ"; //  83
    charset[0x54] = "エ"; //  84
    charset[0x55] = "オ"; //  85
    charset[0x56] = "カ"; //  86
    charset[0x57] = "キ"; //  87
    charset[0x58] = "ク"; //  88
    charset[0x59] = "ケ"; //  89
    charset[0x5A] = "コ"; //  90
    charset[0x5B] = "サ"; //  91
    charset[0x5C] = "シ"; //  92
    charset[0x5D] = "ス"; //  93
    charset[0x5E] = "セ"; //  94
    charset[0x5F] = "ソ"; //  95
    charset[0x60] = "タ"; //  96
    charset[0x61] = "チ"; //  97
    charset[0x62] = "ツ"; //  98
    charset[0x63] = "テ"; //  99
    charset[0x64] = "ト"; // 100
    charset[0x65] = "ナ"; // 101
    charset[0x66] = "ニ"; // 102
    charset[0x67] = "ヌ"; // 103
    charset[0x68] = "ネ"; // 104
    charset[0x69] = "ノ"; // 105
    charset[0x6A] = "ハ"; // 106
    charset[0x6B] = "ヒ"; // 107
    charset[0x6C] = "フ"; // 108
    charset[0x6D] = "へ"; // 109
    charset[0x6E] = "ホ"; // 110
    charset[0x6F] = "マ"; // 111
    charset[0x70] = "ミ"; // 112
    charset[0x71] = "ム"; // 113
    charset[0x72] = "メ"; // 114
    charset[0x73] = "モ"; // 115
    charset[0x74] = "ヤ"; // 116
    charset[0x75] = "ユ"; // 117
    charset[0x76] = "ヨ"; // 118
    charset[0x77] = "ラ"; // 119
    charset[0x78] = "リ"; // 120
    charset[0x79] = "ル"; // 121
    charset[0x7A] = "レ"; // 122
    charset[0x7B] = "ロ"; // 123
    charset[0x7C] = "ワ"; // 124
    charset[0x7D] = "ヲ"; // 125
    charset[0x7E] = "ン"; // 126
    charset[0x7F] = "ァ"; // 127
    charset[0x80] = "ィ"; // 128
    charset[0x81] = "ゥ"; // 129
    charset[0x82] = "ェ"; // 130
    charset[0x83] = "ォ"; // 131
    charset[0x84] = "ャ"; // 132
    charset[0x85] = "ュ"; // 133
    charset[0x86] = "ョ"; // 134
    charset[0x87] = "ガ"; // 135
    charset[0x88] = "ギ"; // 136
    charset[0x89] = "グ"; // 137
    charset[0x8A] = "ゲ"; // 138
    charset[0x8B] = "ゴ"; // 139
    charset[0x8C] = "ザ"; // 140
    charset[0x8D] = "ジ"; // 141
    charset[0x8E] = "ズ"; // 142
    charset[0x8F] = "ゼ"; // 143
    charset[0x90] = "ゾ"; // 144
    charset[0x91] = "ダ"; // 145
    charset[0x92] = "ヂ"; // 146
    charset[0x93] = "ヅ"; // 147
    charset[0x94] = "デ"; // 148
    charset[0x95] = "ド"; // 149
    charset[0x96] = "バ"; // 150
    charset[0x97] = "ビ"; // 151
    charset[0x98] = "ブ"; // 152
    charset[0x99] = "ベ"; // 153
    charset[0x9A] = "ボ"; // 154
    charset[0x9B] = "パ"; // 155
    charset[0x9C] = "ピ"; // 156
    charset[0x9D] = "プ"; // 157
    charset[0x9E] = "ペ"; // 158
    charset[0x9F] = "ポ"; // 159
    charset[0xA0] = "ッ"; // 160
    charset[0xA1] = "０"; // 161
    charset[0xA2] = "１"; // 162
    charset[0xA3] = "２"; // 163
    charset[0xA4] = "３"; // 164
    charset[0xA5] = "４"; // 165
    charset[0xA6] = "５"; // 166
    charset[0xA7] = "６"; // 167
    charset[0xA8] = "７"; // 168
    charset[0xA9] = "８"; // 169
    charset[0xAA] = "９"; // 170
    charset[0xAB] = "！"; // 171
    charset[0xAC] = "？"; // 172
    charset[0xAD] = "。"; // 173
    charset[0xAE] = "ー"; // 174
    charset[0xAF] = "・"; // 175
    charset[0xB0] = "…";  // 176
    charset[0xB1] = "『"; // 177
    charset[0xB2] = "』"; // 178
    charset[0xB3] = "「"; // 179
    charset[0xB4] = "」"; // 180
    charset[0xB5] = "♂";  // 181
    charset[0xB6] = "♀";  // 182
    charset[0xB7] = "円"; // 183
    charset[0xB8] = "．"; // 184
    charset[0xB9] = "×";  // 185
    charset[0xBA] = "／"; // 186
    charset[0xBB] = "Ａ"; // 187
    charset[0xBC] = "Ｂ"; // 188
    charset[0xBD] = "Ｃ"; // 189
    charset[0xBE] = "Ｄ"; // 190
    charset[0xBF] = "Ｅ"; // 191
    charset[0xC0] = "Ｆ"; // 192
    charset[0xC1] = "Ｇ"; // 193
    charset[0xC2] = "Ｈ"; // 194
    charset[0xC3] = "Ｉ"; // 195
    charset[0xC4] = "Ｊ"; // 196
    charset[0xC5] = "Ｋ"; // 197
    charset[0xC6] = "Ｌ"; // 198
    charset[0xC7] = "Ｍ"; // 199
    charset[0xC8] = "Ｎ"; // 200
    charset[0xC9] = "Ｏ"; // 201
    charset[0xCA] = "Ｐ"; // 202
    charset[0xCB] = "Ｑ"; // 203
    charset[0xCC] = "Ｒ"; // 204
    charset[0xCD] = "Ｓ"; // 205
    charset[0xCE] = "Ｔ"; // 206
    charset[0xCF] = "Ｕ"; // 207
    charset[0xD0] = "Ｖ"; // 208
    charset[0xD1] = "Ｗ"; // 209
    charset[0xD2] = "Ｘ"; // 210
    charset[0xD3] = "Ｙ"; // 211
    charset[0xD4] = "Ｚ"; // 212
    charset[0xD5] = "ａ"; // 213
    charset[0xD6] = "ｂ"; // 214
    charset[0xD7] = "ｃ"; // 215
    charset[0xD8] = "ｄ"; // 216
    charset[0xD9] = "ｅ"; // 217
    charset[0xDA] = "ｆ"; // 218
    charset[0xDB] = "ｇ"; // 219
    charset[0xDC] = "ｈ"; // 220
    charset[0xDD] = "ｉ"; // 221
    charset[0xDE] = "ｊ"; // 222
    charset[0xDF] = "ｋ"; // 223
    charset[0xE0] = "ｌ"; // 224
    charset[0xE1] = "ｍ"; // 225
    charset[0xE2] = "ｎ"; // 226
    charset[0xE3] = "ｏ"; // 227
    charset[0xE4] = "ｐ"; // 228
    charset[0xE5] = "ｑ"; // 229
    charset[0xE6] = "ｒ"; // 230
    charset[0xE7] = "ｓ"; // 231
    charset[0xE8] = "ｔ"; // 232
    charset[0xE9] = "ｕ"; // 233
    charset[0xEA] = "ｖ"; // 234
    charset[0xEB] = "ｗ"; // 235
    charset[0xEC] = "ｘ"; // 236
    charset[0xED] = "ｙ"; // 237
    charset[0xEE] = "ｚ"; // 238
    charset[0xEF] = "⇒"; // 239
    charset[0xF0] = "："; // 240
    charset[0xF1] = "Ä";  // 241
    charset[0xF2] = "Ö";  // 242
    charset[0xF3] = "Ü";  // 243
    charset[0xF4] = "ä";  // 244
    charset[0xF5] = "ö";  // 245
    charset[0xF6] = "ü";  // 246
    charset[0xF7] = "　"; // 247
    charset[0xF8] = "　"; // 248
    charset[0xF9] = "　"; // 249
    charset[0xFA] = "　"; // 250
    charset[0xFB] = "　"; // 251
    charset[0xFC] = "　"; // 252
    charset[0xFD] = "　"; // 253
    charset[0xFE] = "　"; // 254
    charset[0xFF] = "終"; // 255
} 

#endif
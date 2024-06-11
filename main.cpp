#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "include/params.h"
#include "include/CLASS.hpp"
#include "include/function.hpp"

int main() {
    Data Name(NameStartAddress,NameLength, NameNumber, output_file_path);
    Data BaseStats(BaseStatsStartAddress, BaseStatsLength, BaseStatsNumber, output_file_path);
    Data Evolve(EvolveStartAddress, EvolveLength, EvolveNumber, output_file_path);
    Data Ability(AbilityStartAddress, AbilityLength, AbilityNumber, "output/ability.csv");
    //readName(rom_file_path, Ability, 2);
    //readAbility(rom_file_path, Ability, AbilityExpStartAddress);
    readData(rom_file_path, Name, BaseStats, Evolve);
    //readData2(rom_file_path, Name, BaseStats, Evolve);

    return 0;
}

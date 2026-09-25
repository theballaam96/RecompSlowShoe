#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"

extern u8 *D_boss_80035AA4[];
extern Maps current_map;

RECOMP_CALLBACK("*", recomp_on_map_load) void changeShoeTimings(void) {
    s32 i, j;

    if (current_map != MAP_KROOLS_SHOE) return;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            D_boss_80035AA4[i][3 + (j * 4)] = 90; // Anim speed
            D_boss_80035AA4[i][4 + (j * 4)] = 30; // Wait after slam down
        }
    }
}

// extern u16 newly_pressed_input[];
// void func_global_asm_805FF378(Maps nextMap, s32 nextExit); 
// RECOMP_CALLBACK("*", dk64recomp_every_frame) void cheatyWarp(void) {
//     if (newly_pressed_input[0] & 0x0800) {
//         func_global_asm_805FF378(MAP_KROOLS_SHOE, 0);
//     }
// }
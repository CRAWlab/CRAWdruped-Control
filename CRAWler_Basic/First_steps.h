#ifndef QUADTR_POSES
#define QUADTR_POSES

#include <avr/pgmspace.h>

PROGMEM prog_uint16_t Forward_5[] = {12, 535, 438, 338, 653, 809, 197, 449, 577, 342, 669, 791, 250};
PROGMEM prog_uint16_t Forward_2[] = {12, 550, 505, 357, 672, 809, 197, 383, 569, 338, 657, 766, 239};
PROGMEM prog_uint16_t Forward_7[] = {12, 466, 438, 323, 653, 808, 197, 449, 639, 342, 684, 791, 250};
PROGMEM prog_uint16_t Forward_9[] = {12, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
PROGMEM prog_uint16_t Forward_8[] = {12, 451, 423, 354, 666, 808, 194, 448, 651, 340, 671, 795, 249};
PROGMEM prog_uint16_t Forward[] = {12, 552, 439, 355, 654, 810, 196, 451, 570, 345, 666, 793, 241};
PROGMEM prog_uint16_t Forward_6[] = {12, 500, 438, 323, 653, 808, 197, 449, 605, 342, 684, 791, 250};
PROGMEM prog_uint16_t Forward_4[] = {12, 551, 558, 352, 649, 819, 197, 335, 550, 342, 669, 771, 235};
PROGMEM prog_uint16_t Forward_3[] = {12, 551, 548, 357, 672, 809, 197, 341, 569, 339, 657, 767, 239};
PROGMEM prog_uint16_t Forward_1[] = {12, 551, 453, 357, 662, 809, 197, 431, 569, 342, 657, 770, 239};

PROGMEM transition_t Go_Forward[] = {{0,42} ,{Forward,100} ,{Forward_1,100} ,{Forward_2,100} ,{Forward_3,100} ,{Forward_4,100} ,{Forward_5,100} ,{Forward_6,100} ,{Forward_7,100} ,{Forward_8,100} ,{Forward_1,100} ,{Forward_2,100} ,{Forward_3,100} ,{Forward_4,100} ,{Forward_5,100} ,{Forward_6,100} ,{Forward_7,100} ,{Forward_8,100} ,{Forward_1,100} ,{Forward_2,100} ,{Forward_3,100} ,{Forward_4,100} ,{Forward_5,100} ,{Forward_6,100} ,{Forward_7,100} ,{Forward_8,100} ,{Forward_1,70} ,{Forward_2,70} ,{Forward_3,70} ,{Forward_4,70} ,{Forward_5,70} ,{Forward_6,70} ,{Forward_7,70} ,{Forward_8,70} ,{Forward_1,70} ,{Forward_2,70} ,{Forward_3,70} ,{Forward_4,70} ,{Forward_5,70} ,{Forward_6,70} ,{Forward_7,70} ,{Forward_8,70} ,{Forward,100} };

#endif


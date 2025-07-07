#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3316257012826674087) {
   out_3316257012826674087[0] = delta_x[0] + nom_x[0];
   out_3316257012826674087[1] = delta_x[1] + nom_x[1];
   out_3316257012826674087[2] = delta_x[2] + nom_x[2];
   out_3316257012826674087[3] = delta_x[3] + nom_x[3];
   out_3316257012826674087[4] = delta_x[4] + nom_x[4];
   out_3316257012826674087[5] = delta_x[5] + nom_x[5];
   out_3316257012826674087[6] = delta_x[6] + nom_x[6];
   out_3316257012826674087[7] = delta_x[7] + nom_x[7];
   out_3316257012826674087[8] = delta_x[8] + nom_x[8];
   out_3316257012826674087[9] = delta_x[9] + nom_x[9];
   out_3316257012826674087[10] = delta_x[10] + nom_x[10];
   out_3316257012826674087[11] = delta_x[11] + nom_x[11];
   out_3316257012826674087[12] = delta_x[12] + nom_x[12];
   out_3316257012826674087[13] = delta_x[13] + nom_x[13];
   out_3316257012826674087[14] = delta_x[14] + nom_x[14];
   out_3316257012826674087[15] = delta_x[15] + nom_x[15];
   out_3316257012826674087[16] = delta_x[16] + nom_x[16];
   out_3316257012826674087[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2057247982490778565) {
   out_2057247982490778565[0] = -nom_x[0] + true_x[0];
   out_2057247982490778565[1] = -nom_x[1] + true_x[1];
   out_2057247982490778565[2] = -nom_x[2] + true_x[2];
   out_2057247982490778565[3] = -nom_x[3] + true_x[3];
   out_2057247982490778565[4] = -nom_x[4] + true_x[4];
   out_2057247982490778565[5] = -nom_x[5] + true_x[5];
   out_2057247982490778565[6] = -nom_x[6] + true_x[6];
   out_2057247982490778565[7] = -nom_x[7] + true_x[7];
   out_2057247982490778565[8] = -nom_x[8] + true_x[8];
   out_2057247982490778565[9] = -nom_x[9] + true_x[9];
   out_2057247982490778565[10] = -nom_x[10] + true_x[10];
   out_2057247982490778565[11] = -nom_x[11] + true_x[11];
   out_2057247982490778565[12] = -nom_x[12] + true_x[12];
   out_2057247982490778565[13] = -nom_x[13] + true_x[13];
   out_2057247982490778565[14] = -nom_x[14] + true_x[14];
   out_2057247982490778565[15] = -nom_x[15] + true_x[15];
   out_2057247982490778565[16] = -nom_x[16] + true_x[16];
   out_2057247982490778565[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4138089403229407673) {
   out_4138089403229407673[0] = 1.0;
   out_4138089403229407673[1] = 0.0;
   out_4138089403229407673[2] = 0.0;
   out_4138089403229407673[3] = 0.0;
   out_4138089403229407673[4] = 0.0;
   out_4138089403229407673[5] = 0.0;
   out_4138089403229407673[6] = 0.0;
   out_4138089403229407673[7] = 0.0;
   out_4138089403229407673[8] = 0.0;
   out_4138089403229407673[9] = 0.0;
   out_4138089403229407673[10] = 0.0;
   out_4138089403229407673[11] = 0.0;
   out_4138089403229407673[12] = 0.0;
   out_4138089403229407673[13] = 0.0;
   out_4138089403229407673[14] = 0.0;
   out_4138089403229407673[15] = 0.0;
   out_4138089403229407673[16] = 0.0;
   out_4138089403229407673[17] = 0.0;
   out_4138089403229407673[18] = 0.0;
   out_4138089403229407673[19] = 1.0;
   out_4138089403229407673[20] = 0.0;
   out_4138089403229407673[21] = 0.0;
   out_4138089403229407673[22] = 0.0;
   out_4138089403229407673[23] = 0.0;
   out_4138089403229407673[24] = 0.0;
   out_4138089403229407673[25] = 0.0;
   out_4138089403229407673[26] = 0.0;
   out_4138089403229407673[27] = 0.0;
   out_4138089403229407673[28] = 0.0;
   out_4138089403229407673[29] = 0.0;
   out_4138089403229407673[30] = 0.0;
   out_4138089403229407673[31] = 0.0;
   out_4138089403229407673[32] = 0.0;
   out_4138089403229407673[33] = 0.0;
   out_4138089403229407673[34] = 0.0;
   out_4138089403229407673[35] = 0.0;
   out_4138089403229407673[36] = 0.0;
   out_4138089403229407673[37] = 0.0;
   out_4138089403229407673[38] = 1.0;
   out_4138089403229407673[39] = 0.0;
   out_4138089403229407673[40] = 0.0;
   out_4138089403229407673[41] = 0.0;
   out_4138089403229407673[42] = 0.0;
   out_4138089403229407673[43] = 0.0;
   out_4138089403229407673[44] = 0.0;
   out_4138089403229407673[45] = 0.0;
   out_4138089403229407673[46] = 0.0;
   out_4138089403229407673[47] = 0.0;
   out_4138089403229407673[48] = 0.0;
   out_4138089403229407673[49] = 0.0;
   out_4138089403229407673[50] = 0.0;
   out_4138089403229407673[51] = 0.0;
   out_4138089403229407673[52] = 0.0;
   out_4138089403229407673[53] = 0.0;
   out_4138089403229407673[54] = 0.0;
   out_4138089403229407673[55] = 0.0;
   out_4138089403229407673[56] = 0.0;
   out_4138089403229407673[57] = 1.0;
   out_4138089403229407673[58] = 0.0;
   out_4138089403229407673[59] = 0.0;
   out_4138089403229407673[60] = 0.0;
   out_4138089403229407673[61] = 0.0;
   out_4138089403229407673[62] = 0.0;
   out_4138089403229407673[63] = 0.0;
   out_4138089403229407673[64] = 0.0;
   out_4138089403229407673[65] = 0.0;
   out_4138089403229407673[66] = 0.0;
   out_4138089403229407673[67] = 0.0;
   out_4138089403229407673[68] = 0.0;
   out_4138089403229407673[69] = 0.0;
   out_4138089403229407673[70] = 0.0;
   out_4138089403229407673[71] = 0.0;
   out_4138089403229407673[72] = 0.0;
   out_4138089403229407673[73] = 0.0;
   out_4138089403229407673[74] = 0.0;
   out_4138089403229407673[75] = 0.0;
   out_4138089403229407673[76] = 1.0;
   out_4138089403229407673[77] = 0.0;
   out_4138089403229407673[78] = 0.0;
   out_4138089403229407673[79] = 0.0;
   out_4138089403229407673[80] = 0.0;
   out_4138089403229407673[81] = 0.0;
   out_4138089403229407673[82] = 0.0;
   out_4138089403229407673[83] = 0.0;
   out_4138089403229407673[84] = 0.0;
   out_4138089403229407673[85] = 0.0;
   out_4138089403229407673[86] = 0.0;
   out_4138089403229407673[87] = 0.0;
   out_4138089403229407673[88] = 0.0;
   out_4138089403229407673[89] = 0.0;
   out_4138089403229407673[90] = 0.0;
   out_4138089403229407673[91] = 0.0;
   out_4138089403229407673[92] = 0.0;
   out_4138089403229407673[93] = 0.0;
   out_4138089403229407673[94] = 0.0;
   out_4138089403229407673[95] = 1.0;
   out_4138089403229407673[96] = 0.0;
   out_4138089403229407673[97] = 0.0;
   out_4138089403229407673[98] = 0.0;
   out_4138089403229407673[99] = 0.0;
   out_4138089403229407673[100] = 0.0;
   out_4138089403229407673[101] = 0.0;
   out_4138089403229407673[102] = 0.0;
   out_4138089403229407673[103] = 0.0;
   out_4138089403229407673[104] = 0.0;
   out_4138089403229407673[105] = 0.0;
   out_4138089403229407673[106] = 0.0;
   out_4138089403229407673[107] = 0.0;
   out_4138089403229407673[108] = 0.0;
   out_4138089403229407673[109] = 0.0;
   out_4138089403229407673[110] = 0.0;
   out_4138089403229407673[111] = 0.0;
   out_4138089403229407673[112] = 0.0;
   out_4138089403229407673[113] = 0.0;
   out_4138089403229407673[114] = 1.0;
   out_4138089403229407673[115] = 0.0;
   out_4138089403229407673[116] = 0.0;
   out_4138089403229407673[117] = 0.0;
   out_4138089403229407673[118] = 0.0;
   out_4138089403229407673[119] = 0.0;
   out_4138089403229407673[120] = 0.0;
   out_4138089403229407673[121] = 0.0;
   out_4138089403229407673[122] = 0.0;
   out_4138089403229407673[123] = 0.0;
   out_4138089403229407673[124] = 0.0;
   out_4138089403229407673[125] = 0.0;
   out_4138089403229407673[126] = 0.0;
   out_4138089403229407673[127] = 0.0;
   out_4138089403229407673[128] = 0.0;
   out_4138089403229407673[129] = 0.0;
   out_4138089403229407673[130] = 0.0;
   out_4138089403229407673[131] = 0.0;
   out_4138089403229407673[132] = 0.0;
   out_4138089403229407673[133] = 1.0;
   out_4138089403229407673[134] = 0.0;
   out_4138089403229407673[135] = 0.0;
   out_4138089403229407673[136] = 0.0;
   out_4138089403229407673[137] = 0.0;
   out_4138089403229407673[138] = 0.0;
   out_4138089403229407673[139] = 0.0;
   out_4138089403229407673[140] = 0.0;
   out_4138089403229407673[141] = 0.0;
   out_4138089403229407673[142] = 0.0;
   out_4138089403229407673[143] = 0.0;
   out_4138089403229407673[144] = 0.0;
   out_4138089403229407673[145] = 0.0;
   out_4138089403229407673[146] = 0.0;
   out_4138089403229407673[147] = 0.0;
   out_4138089403229407673[148] = 0.0;
   out_4138089403229407673[149] = 0.0;
   out_4138089403229407673[150] = 0.0;
   out_4138089403229407673[151] = 0.0;
   out_4138089403229407673[152] = 1.0;
   out_4138089403229407673[153] = 0.0;
   out_4138089403229407673[154] = 0.0;
   out_4138089403229407673[155] = 0.0;
   out_4138089403229407673[156] = 0.0;
   out_4138089403229407673[157] = 0.0;
   out_4138089403229407673[158] = 0.0;
   out_4138089403229407673[159] = 0.0;
   out_4138089403229407673[160] = 0.0;
   out_4138089403229407673[161] = 0.0;
   out_4138089403229407673[162] = 0.0;
   out_4138089403229407673[163] = 0.0;
   out_4138089403229407673[164] = 0.0;
   out_4138089403229407673[165] = 0.0;
   out_4138089403229407673[166] = 0.0;
   out_4138089403229407673[167] = 0.0;
   out_4138089403229407673[168] = 0.0;
   out_4138089403229407673[169] = 0.0;
   out_4138089403229407673[170] = 0.0;
   out_4138089403229407673[171] = 1.0;
   out_4138089403229407673[172] = 0.0;
   out_4138089403229407673[173] = 0.0;
   out_4138089403229407673[174] = 0.0;
   out_4138089403229407673[175] = 0.0;
   out_4138089403229407673[176] = 0.0;
   out_4138089403229407673[177] = 0.0;
   out_4138089403229407673[178] = 0.0;
   out_4138089403229407673[179] = 0.0;
   out_4138089403229407673[180] = 0.0;
   out_4138089403229407673[181] = 0.0;
   out_4138089403229407673[182] = 0.0;
   out_4138089403229407673[183] = 0.0;
   out_4138089403229407673[184] = 0.0;
   out_4138089403229407673[185] = 0.0;
   out_4138089403229407673[186] = 0.0;
   out_4138089403229407673[187] = 0.0;
   out_4138089403229407673[188] = 0.0;
   out_4138089403229407673[189] = 0.0;
   out_4138089403229407673[190] = 1.0;
   out_4138089403229407673[191] = 0.0;
   out_4138089403229407673[192] = 0.0;
   out_4138089403229407673[193] = 0.0;
   out_4138089403229407673[194] = 0.0;
   out_4138089403229407673[195] = 0.0;
   out_4138089403229407673[196] = 0.0;
   out_4138089403229407673[197] = 0.0;
   out_4138089403229407673[198] = 0.0;
   out_4138089403229407673[199] = 0.0;
   out_4138089403229407673[200] = 0.0;
   out_4138089403229407673[201] = 0.0;
   out_4138089403229407673[202] = 0.0;
   out_4138089403229407673[203] = 0.0;
   out_4138089403229407673[204] = 0.0;
   out_4138089403229407673[205] = 0.0;
   out_4138089403229407673[206] = 0.0;
   out_4138089403229407673[207] = 0.0;
   out_4138089403229407673[208] = 0.0;
   out_4138089403229407673[209] = 1.0;
   out_4138089403229407673[210] = 0.0;
   out_4138089403229407673[211] = 0.0;
   out_4138089403229407673[212] = 0.0;
   out_4138089403229407673[213] = 0.0;
   out_4138089403229407673[214] = 0.0;
   out_4138089403229407673[215] = 0.0;
   out_4138089403229407673[216] = 0.0;
   out_4138089403229407673[217] = 0.0;
   out_4138089403229407673[218] = 0.0;
   out_4138089403229407673[219] = 0.0;
   out_4138089403229407673[220] = 0.0;
   out_4138089403229407673[221] = 0.0;
   out_4138089403229407673[222] = 0.0;
   out_4138089403229407673[223] = 0.0;
   out_4138089403229407673[224] = 0.0;
   out_4138089403229407673[225] = 0.0;
   out_4138089403229407673[226] = 0.0;
   out_4138089403229407673[227] = 0.0;
   out_4138089403229407673[228] = 1.0;
   out_4138089403229407673[229] = 0.0;
   out_4138089403229407673[230] = 0.0;
   out_4138089403229407673[231] = 0.0;
   out_4138089403229407673[232] = 0.0;
   out_4138089403229407673[233] = 0.0;
   out_4138089403229407673[234] = 0.0;
   out_4138089403229407673[235] = 0.0;
   out_4138089403229407673[236] = 0.0;
   out_4138089403229407673[237] = 0.0;
   out_4138089403229407673[238] = 0.0;
   out_4138089403229407673[239] = 0.0;
   out_4138089403229407673[240] = 0.0;
   out_4138089403229407673[241] = 0.0;
   out_4138089403229407673[242] = 0.0;
   out_4138089403229407673[243] = 0.0;
   out_4138089403229407673[244] = 0.0;
   out_4138089403229407673[245] = 0.0;
   out_4138089403229407673[246] = 0.0;
   out_4138089403229407673[247] = 1.0;
   out_4138089403229407673[248] = 0.0;
   out_4138089403229407673[249] = 0.0;
   out_4138089403229407673[250] = 0.0;
   out_4138089403229407673[251] = 0.0;
   out_4138089403229407673[252] = 0.0;
   out_4138089403229407673[253] = 0.0;
   out_4138089403229407673[254] = 0.0;
   out_4138089403229407673[255] = 0.0;
   out_4138089403229407673[256] = 0.0;
   out_4138089403229407673[257] = 0.0;
   out_4138089403229407673[258] = 0.0;
   out_4138089403229407673[259] = 0.0;
   out_4138089403229407673[260] = 0.0;
   out_4138089403229407673[261] = 0.0;
   out_4138089403229407673[262] = 0.0;
   out_4138089403229407673[263] = 0.0;
   out_4138089403229407673[264] = 0.0;
   out_4138089403229407673[265] = 0.0;
   out_4138089403229407673[266] = 1.0;
   out_4138089403229407673[267] = 0.0;
   out_4138089403229407673[268] = 0.0;
   out_4138089403229407673[269] = 0.0;
   out_4138089403229407673[270] = 0.0;
   out_4138089403229407673[271] = 0.0;
   out_4138089403229407673[272] = 0.0;
   out_4138089403229407673[273] = 0.0;
   out_4138089403229407673[274] = 0.0;
   out_4138089403229407673[275] = 0.0;
   out_4138089403229407673[276] = 0.0;
   out_4138089403229407673[277] = 0.0;
   out_4138089403229407673[278] = 0.0;
   out_4138089403229407673[279] = 0.0;
   out_4138089403229407673[280] = 0.0;
   out_4138089403229407673[281] = 0.0;
   out_4138089403229407673[282] = 0.0;
   out_4138089403229407673[283] = 0.0;
   out_4138089403229407673[284] = 0.0;
   out_4138089403229407673[285] = 1.0;
   out_4138089403229407673[286] = 0.0;
   out_4138089403229407673[287] = 0.0;
   out_4138089403229407673[288] = 0.0;
   out_4138089403229407673[289] = 0.0;
   out_4138089403229407673[290] = 0.0;
   out_4138089403229407673[291] = 0.0;
   out_4138089403229407673[292] = 0.0;
   out_4138089403229407673[293] = 0.0;
   out_4138089403229407673[294] = 0.0;
   out_4138089403229407673[295] = 0.0;
   out_4138089403229407673[296] = 0.0;
   out_4138089403229407673[297] = 0.0;
   out_4138089403229407673[298] = 0.0;
   out_4138089403229407673[299] = 0.0;
   out_4138089403229407673[300] = 0.0;
   out_4138089403229407673[301] = 0.0;
   out_4138089403229407673[302] = 0.0;
   out_4138089403229407673[303] = 0.0;
   out_4138089403229407673[304] = 1.0;
   out_4138089403229407673[305] = 0.0;
   out_4138089403229407673[306] = 0.0;
   out_4138089403229407673[307] = 0.0;
   out_4138089403229407673[308] = 0.0;
   out_4138089403229407673[309] = 0.0;
   out_4138089403229407673[310] = 0.0;
   out_4138089403229407673[311] = 0.0;
   out_4138089403229407673[312] = 0.0;
   out_4138089403229407673[313] = 0.0;
   out_4138089403229407673[314] = 0.0;
   out_4138089403229407673[315] = 0.0;
   out_4138089403229407673[316] = 0.0;
   out_4138089403229407673[317] = 0.0;
   out_4138089403229407673[318] = 0.0;
   out_4138089403229407673[319] = 0.0;
   out_4138089403229407673[320] = 0.0;
   out_4138089403229407673[321] = 0.0;
   out_4138089403229407673[322] = 0.0;
   out_4138089403229407673[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7388093933502948823) {
   out_7388093933502948823[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7388093933502948823[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7388093933502948823[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7388093933502948823[3] = dt*state[12] + state[3];
   out_7388093933502948823[4] = dt*state[13] + state[4];
   out_7388093933502948823[5] = dt*state[14] + state[5];
   out_7388093933502948823[6] = state[6];
   out_7388093933502948823[7] = state[7];
   out_7388093933502948823[8] = state[8];
   out_7388093933502948823[9] = state[9];
   out_7388093933502948823[10] = state[10];
   out_7388093933502948823[11] = state[11];
   out_7388093933502948823[12] = state[12];
   out_7388093933502948823[13] = state[13];
   out_7388093933502948823[14] = state[14];
   out_7388093933502948823[15] = state[15];
   out_7388093933502948823[16] = state[16];
   out_7388093933502948823[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5999254502567580570) {
   out_5999254502567580570[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5999254502567580570[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5999254502567580570[2] = 0;
   out_5999254502567580570[3] = 0;
   out_5999254502567580570[4] = 0;
   out_5999254502567580570[5] = 0;
   out_5999254502567580570[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5999254502567580570[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5999254502567580570[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5999254502567580570[9] = 0;
   out_5999254502567580570[10] = 0;
   out_5999254502567580570[11] = 0;
   out_5999254502567580570[12] = 0;
   out_5999254502567580570[13] = 0;
   out_5999254502567580570[14] = 0;
   out_5999254502567580570[15] = 0;
   out_5999254502567580570[16] = 0;
   out_5999254502567580570[17] = 0;
   out_5999254502567580570[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5999254502567580570[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5999254502567580570[20] = 0;
   out_5999254502567580570[21] = 0;
   out_5999254502567580570[22] = 0;
   out_5999254502567580570[23] = 0;
   out_5999254502567580570[24] = 0;
   out_5999254502567580570[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5999254502567580570[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5999254502567580570[27] = 0;
   out_5999254502567580570[28] = 0;
   out_5999254502567580570[29] = 0;
   out_5999254502567580570[30] = 0;
   out_5999254502567580570[31] = 0;
   out_5999254502567580570[32] = 0;
   out_5999254502567580570[33] = 0;
   out_5999254502567580570[34] = 0;
   out_5999254502567580570[35] = 0;
   out_5999254502567580570[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5999254502567580570[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5999254502567580570[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5999254502567580570[39] = 0;
   out_5999254502567580570[40] = 0;
   out_5999254502567580570[41] = 0;
   out_5999254502567580570[42] = 0;
   out_5999254502567580570[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5999254502567580570[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5999254502567580570[45] = 0;
   out_5999254502567580570[46] = 0;
   out_5999254502567580570[47] = 0;
   out_5999254502567580570[48] = 0;
   out_5999254502567580570[49] = 0;
   out_5999254502567580570[50] = 0;
   out_5999254502567580570[51] = 0;
   out_5999254502567580570[52] = 0;
   out_5999254502567580570[53] = 0;
   out_5999254502567580570[54] = 0;
   out_5999254502567580570[55] = 0;
   out_5999254502567580570[56] = 0;
   out_5999254502567580570[57] = 1;
   out_5999254502567580570[58] = 0;
   out_5999254502567580570[59] = 0;
   out_5999254502567580570[60] = 0;
   out_5999254502567580570[61] = 0;
   out_5999254502567580570[62] = 0;
   out_5999254502567580570[63] = 0;
   out_5999254502567580570[64] = 0;
   out_5999254502567580570[65] = 0;
   out_5999254502567580570[66] = dt;
   out_5999254502567580570[67] = 0;
   out_5999254502567580570[68] = 0;
   out_5999254502567580570[69] = 0;
   out_5999254502567580570[70] = 0;
   out_5999254502567580570[71] = 0;
   out_5999254502567580570[72] = 0;
   out_5999254502567580570[73] = 0;
   out_5999254502567580570[74] = 0;
   out_5999254502567580570[75] = 0;
   out_5999254502567580570[76] = 1;
   out_5999254502567580570[77] = 0;
   out_5999254502567580570[78] = 0;
   out_5999254502567580570[79] = 0;
   out_5999254502567580570[80] = 0;
   out_5999254502567580570[81] = 0;
   out_5999254502567580570[82] = 0;
   out_5999254502567580570[83] = 0;
   out_5999254502567580570[84] = 0;
   out_5999254502567580570[85] = dt;
   out_5999254502567580570[86] = 0;
   out_5999254502567580570[87] = 0;
   out_5999254502567580570[88] = 0;
   out_5999254502567580570[89] = 0;
   out_5999254502567580570[90] = 0;
   out_5999254502567580570[91] = 0;
   out_5999254502567580570[92] = 0;
   out_5999254502567580570[93] = 0;
   out_5999254502567580570[94] = 0;
   out_5999254502567580570[95] = 1;
   out_5999254502567580570[96] = 0;
   out_5999254502567580570[97] = 0;
   out_5999254502567580570[98] = 0;
   out_5999254502567580570[99] = 0;
   out_5999254502567580570[100] = 0;
   out_5999254502567580570[101] = 0;
   out_5999254502567580570[102] = 0;
   out_5999254502567580570[103] = 0;
   out_5999254502567580570[104] = dt;
   out_5999254502567580570[105] = 0;
   out_5999254502567580570[106] = 0;
   out_5999254502567580570[107] = 0;
   out_5999254502567580570[108] = 0;
   out_5999254502567580570[109] = 0;
   out_5999254502567580570[110] = 0;
   out_5999254502567580570[111] = 0;
   out_5999254502567580570[112] = 0;
   out_5999254502567580570[113] = 0;
   out_5999254502567580570[114] = 1;
   out_5999254502567580570[115] = 0;
   out_5999254502567580570[116] = 0;
   out_5999254502567580570[117] = 0;
   out_5999254502567580570[118] = 0;
   out_5999254502567580570[119] = 0;
   out_5999254502567580570[120] = 0;
   out_5999254502567580570[121] = 0;
   out_5999254502567580570[122] = 0;
   out_5999254502567580570[123] = 0;
   out_5999254502567580570[124] = 0;
   out_5999254502567580570[125] = 0;
   out_5999254502567580570[126] = 0;
   out_5999254502567580570[127] = 0;
   out_5999254502567580570[128] = 0;
   out_5999254502567580570[129] = 0;
   out_5999254502567580570[130] = 0;
   out_5999254502567580570[131] = 0;
   out_5999254502567580570[132] = 0;
   out_5999254502567580570[133] = 1;
   out_5999254502567580570[134] = 0;
   out_5999254502567580570[135] = 0;
   out_5999254502567580570[136] = 0;
   out_5999254502567580570[137] = 0;
   out_5999254502567580570[138] = 0;
   out_5999254502567580570[139] = 0;
   out_5999254502567580570[140] = 0;
   out_5999254502567580570[141] = 0;
   out_5999254502567580570[142] = 0;
   out_5999254502567580570[143] = 0;
   out_5999254502567580570[144] = 0;
   out_5999254502567580570[145] = 0;
   out_5999254502567580570[146] = 0;
   out_5999254502567580570[147] = 0;
   out_5999254502567580570[148] = 0;
   out_5999254502567580570[149] = 0;
   out_5999254502567580570[150] = 0;
   out_5999254502567580570[151] = 0;
   out_5999254502567580570[152] = 1;
   out_5999254502567580570[153] = 0;
   out_5999254502567580570[154] = 0;
   out_5999254502567580570[155] = 0;
   out_5999254502567580570[156] = 0;
   out_5999254502567580570[157] = 0;
   out_5999254502567580570[158] = 0;
   out_5999254502567580570[159] = 0;
   out_5999254502567580570[160] = 0;
   out_5999254502567580570[161] = 0;
   out_5999254502567580570[162] = 0;
   out_5999254502567580570[163] = 0;
   out_5999254502567580570[164] = 0;
   out_5999254502567580570[165] = 0;
   out_5999254502567580570[166] = 0;
   out_5999254502567580570[167] = 0;
   out_5999254502567580570[168] = 0;
   out_5999254502567580570[169] = 0;
   out_5999254502567580570[170] = 0;
   out_5999254502567580570[171] = 1;
   out_5999254502567580570[172] = 0;
   out_5999254502567580570[173] = 0;
   out_5999254502567580570[174] = 0;
   out_5999254502567580570[175] = 0;
   out_5999254502567580570[176] = 0;
   out_5999254502567580570[177] = 0;
   out_5999254502567580570[178] = 0;
   out_5999254502567580570[179] = 0;
   out_5999254502567580570[180] = 0;
   out_5999254502567580570[181] = 0;
   out_5999254502567580570[182] = 0;
   out_5999254502567580570[183] = 0;
   out_5999254502567580570[184] = 0;
   out_5999254502567580570[185] = 0;
   out_5999254502567580570[186] = 0;
   out_5999254502567580570[187] = 0;
   out_5999254502567580570[188] = 0;
   out_5999254502567580570[189] = 0;
   out_5999254502567580570[190] = 1;
   out_5999254502567580570[191] = 0;
   out_5999254502567580570[192] = 0;
   out_5999254502567580570[193] = 0;
   out_5999254502567580570[194] = 0;
   out_5999254502567580570[195] = 0;
   out_5999254502567580570[196] = 0;
   out_5999254502567580570[197] = 0;
   out_5999254502567580570[198] = 0;
   out_5999254502567580570[199] = 0;
   out_5999254502567580570[200] = 0;
   out_5999254502567580570[201] = 0;
   out_5999254502567580570[202] = 0;
   out_5999254502567580570[203] = 0;
   out_5999254502567580570[204] = 0;
   out_5999254502567580570[205] = 0;
   out_5999254502567580570[206] = 0;
   out_5999254502567580570[207] = 0;
   out_5999254502567580570[208] = 0;
   out_5999254502567580570[209] = 1;
   out_5999254502567580570[210] = 0;
   out_5999254502567580570[211] = 0;
   out_5999254502567580570[212] = 0;
   out_5999254502567580570[213] = 0;
   out_5999254502567580570[214] = 0;
   out_5999254502567580570[215] = 0;
   out_5999254502567580570[216] = 0;
   out_5999254502567580570[217] = 0;
   out_5999254502567580570[218] = 0;
   out_5999254502567580570[219] = 0;
   out_5999254502567580570[220] = 0;
   out_5999254502567580570[221] = 0;
   out_5999254502567580570[222] = 0;
   out_5999254502567580570[223] = 0;
   out_5999254502567580570[224] = 0;
   out_5999254502567580570[225] = 0;
   out_5999254502567580570[226] = 0;
   out_5999254502567580570[227] = 0;
   out_5999254502567580570[228] = 1;
   out_5999254502567580570[229] = 0;
   out_5999254502567580570[230] = 0;
   out_5999254502567580570[231] = 0;
   out_5999254502567580570[232] = 0;
   out_5999254502567580570[233] = 0;
   out_5999254502567580570[234] = 0;
   out_5999254502567580570[235] = 0;
   out_5999254502567580570[236] = 0;
   out_5999254502567580570[237] = 0;
   out_5999254502567580570[238] = 0;
   out_5999254502567580570[239] = 0;
   out_5999254502567580570[240] = 0;
   out_5999254502567580570[241] = 0;
   out_5999254502567580570[242] = 0;
   out_5999254502567580570[243] = 0;
   out_5999254502567580570[244] = 0;
   out_5999254502567580570[245] = 0;
   out_5999254502567580570[246] = 0;
   out_5999254502567580570[247] = 1;
   out_5999254502567580570[248] = 0;
   out_5999254502567580570[249] = 0;
   out_5999254502567580570[250] = 0;
   out_5999254502567580570[251] = 0;
   out_5999254502567580570[252] = 0;
   out_5999254502567580570[253] = 0;
   out_5999254502567580570[254] = 0;
   out_5999254502567580570[255] = 0;
   out_5999254502567580570[256] = 0;
   out_5999254502567580570[257] = 0;
   out_5999254502567580570[258] = 0;
   out_5999254502567580570[259] = 0;
   out_5999254502567580570[260] = 0;
   out_5999254502567580570[261] = 0;
   out_5999254502567580570[262] = 0;
   out_5999254502567580570[263] = 0;
   out_5999254502567580570[264] = 0;
   out_5999254502567580570[265] = 0;
   out_5999254502567580570[266] = 1;
   out_5999254502567580570[267] = 0;
   out_5999254502567580570[268] = 0;
   out_5999254502567580570[269] = 0;
   out_5999254502567580570[270] = 0;
   out_5999254502567580570[271] = 0;
   out_5999254502567580570[272] = 0;
   out_5999254502567580570[273] = 0;
   out_5999254502567580570[274] = 0;
   out_5999254502567580570[275] = 0;
   out_5999254502567580570[276] = 0;
   out_5999254502567580570[277] = 0;
   out_5999254502567580570[278] = 0;
   out_5999254502567580570[279] = 0;
   out_5999254502567580570[280] = 0;
   out_5999254502567580570[281] = 0;
   out_5999254502567580570[282] = 0;
   out_5999254502567580570[283] = 0;
   out_5999254502567580570[284] = 0;
   out_5999254502567580570[285] = 1;
   out_5999254502567580570[286] = 0;
   out_5999254502567580570[287] = 0;
   out_5999254502567580570[288] = 0;
   out_5999254502567580570[289] = 0;
   out_5999254502567580570[290] = 0;
   out_5999254502567580570[291] = 0;
   out_5999254502567580570[292] = 0;
   out_5999254502567580570[293] = 0;
   out_5999254502567580570[294] = 0;
   out_5999254502567580570[295] = 0;
   out_5999254502567580570[296] = 0;
   out_5999254502567580570[297] = 0;
   out_5999254502567580570[298] = 0;
   out_5999254502567580570[299] = 0;
   out_5999254502567580570[300] = 0;
   out_5999254502567580570[301] = 0;
   out_5999254502567580570[302] = 0;
   out_5999254502567580570[303] = 0;
   out_5999254502567580570[304] = 1;
   out_5999254502567580570[305] = 0;
   out_5999254502567580570[306] = 0;
   out_5999254502567580570[307] = 0;
   out_5999254502567580570[308] = 0;
   out_5999254502567580570[309] = 0;
   out_5999254502567580570[310] = 0;
   out_5999254502567580570[311] = 0;
   out_5999254502567580570[312] = 0;
   out_5999254502567580570[313] = 0;
   out_5999254502567580570[314] = 0;
   out_5999254502567580570[315] = 0;
   out_5999254502567580570[316] = 0;
   out_5999254502567580570[317] = 0;
   out_5999254502567580570[318] = 0;
   out_5999254502567580570[319] = 0;
   out_5999254502567580570[320] = 0;
   out_5999254502567580570[321] = 0;
   out_5999254502567580570[322] = 0;
   out_5999254502567580570[323] = 1;
}
void h_4(double *state, double *unused, double *out_1537498951801424975) {
   out_1537498951801424975[0] = state[6] + state[9];
   out_1537498951801424975[1] = state[7] + state[10];
   out_1537498951801424975[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_863867324438458420) {
   out_863867324438458420[0] = 0;
   out_863867324438458420[1] = 0;
   out_863867324438458420[2] = 0;
   out_863867324438458420[3] = 0;
   out_863867324438458420[4] = 0;
   out_863867324438458420[5] = 0;
   out_863867324438458420[6] = 1;
   out_863867324438458420[7] = 0;
   out_863867324438458420[8] = 0;
   out_863867324438458420[9] = 1;
   out_863867324438458420[10] = 0;
   out_863867324438458420[11] = 0;
   out_863867324438458420[12] = 0;
   out_863867324438458420[13] = 0;
   out_863867324438458420[14] = 0;
   out_863867324438458420[15] = 0;
   out_863867324438458420[16] = 0;
   out_863867324438458420[17] = 0;
   out_863867324438458420[18] = 0;
   out_863867324438458420[19] = 0;
   out_863867324438458420[20] = 0;
   out_863867324438458420[21] = 0;
   out_863867324438458420[22] = 0;
   out_863867324438458420[23] = 0;
   out_863867324438458420[24] = 0;
   out_863867324438458420[25] = 1;
   out_863867324438458420[26] = 0;
   out_863867324438458420[27] = 0;
   out_863867324438458420[28] = 1;
   out_863867324438458420[29] = 0;
   out_863867324438458420[30] = 0;
   out_863867324438458420[31] = 0;
   out_863867324438458420[32] = 0;
   out_863867324438458420[33] = 0;
   out_863867324438458420[34] = 0;
   out_863867324438458420[35] = 0;
   out_863867324438458420[36] = 0;
   out_863867324438458420[37] = 0;
   out_863867324438458420[38] = 0;
   out_863867324438458420[39] = 0;
   out_863867324438458420[40] = 0;
   out_863867324438458420[41] = 0;
   out_863867324438458420[42] = 0;
   out_863867324438458420[43] = 0;
   out_863867324438458420[44] = 1;
   out_863867324438458420[45] = 0;
   out_863867324438458420[46] = 0;
   out_863867324438458420[47] = 1;
   out_863867324438458420[48] = 0;
   out_863867324438458420[49] = 0;
   out_863867324438458420[50] = 0;
   out_863867324438458420[51] = 0;
   out_863867324438458420[52] = 0;
   out_863867324438458420[53] = 0;
}
void h_10(double *state, double *unused, double *out_374102871883193337) {
   out_374102871883193337[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_374102871883193337[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_374102871883193337[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7438576236994118175) {
   out_7438576236994118175[0] = 0;
   out_7438576236994118175[1] = 9.8100000000000005*cos(state[1]);
   out_7438576236994118175[2] = 0;
   out_7438576236994118175[3] = 0;
   out_7438576236994118175[4] = -state[8];
   out_7438576236994118175[5] = state[7];
   out_7438576236994118175[6] = 0;
   out_7438576236994118175[7] = state[5];
   out_7438576236994118175[8] = -state[4];
   out_7438576236994118175[9] = 0;
   out_7438576236994118175[10] = 0;
   out_7438576236994118175[11] = 0;
   out_7438576236994118175[12] = 1;
   out_7438576236994118175[13] = 0;
   out_7438576236994118175[14] = 0;
   out_7438576236994118175[15] = 1;
   out_7438576236994118175[16] = 0;
   out_7438576236994118175[17] = 0;
   out_7438576236994118175[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7438576236994118175[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7438576236994118175[20] = 0;
   out_7438576236994118175[21] = state[8];
   out_7438576236994118175[22] = 0;
   out_7438576236994118175[23] = -state[6];
   out_7438576236994118175[24] = -state[5];
   out_7438576236994118175[25] = 0;
   out_7438576236994118175[26] = state[3];
   out_7438576236994118175[27] = 0;
   out_7438576236994118175[28] = 0;
   out_7438576236994118175[29] = 0;
   out_7438576236994118175[30] = 0;
   out_7438576236994118175[31] = 1;
   out_7438576236994118175[32] = 0;
   out_7438576236994118175[33] = 0;
   out_7438576236994118175[34] = 1;
   out_7438576236994118175[35] = 0;
   out_7438576236994118175[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7438576236994118175[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7438576236994118175[38] = 0;
   out_7438576236994118175[39] = -state[7];
   out_7438576236994118175[40] = state[6];
   out_7438576236994118175[41] = 0;
   out_7438576236994118175[42] = state[4];
   out_7438576236994118175[43] = -state[3];
   out_7438576236994118175[44] = 0;
   out_7438576236994118175[45] = 0;
   out_7438576236994118175[46] = 0;
   out_7438576236994118175[47] = 0;
   out_7438576236994118175[48] = 0;
   out_7438576236994118175[49] = 0;
   out_7438576236994118175[50] = 1;
   out_7438576236994118175[51] = 0;
   out_7438576236994118175[52] = 0;
   out_7438576236994118175[53] = 1;
}
void h_13(double *state, double *unused, double *out_8419386726014748872) {
   out_8419386726014748872[0] = state[3];
   out_8419386726014748872[1] = state[4];
   out_8419386726014748872[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4076141149770791221) {
   out_4076141149770791221[0] = 0;
   out_4076141149770791221[1] = 0;
   out_4076141149770791221[2] = 0;
   out_4076141149770791221[3] = 1;
   out_4076141149770791221[4] = 0;
   out_4076141149770791221[5] = 0;
   out_4076141149770791221[6] = 0;
   out_4076141149770791221[7] = 0;
   out_4076141149770791221[8] = 0;
   out_4076141149770791221[9] = 0;
   out_4076141149770791221[10] = 0;
   out_4076141149770791221[11] = 0;
   out_4076141149770791221[12] = 0;
   out_4076141149770791221[13] = 0;
   out_4076141149770791221[14] = 0;
   out_4076141149770791221[15] = 0;
   out_4076141149770791221[16] = 0;
   out_4076141149770791221[17] = 0;
   out_4076141149770791221[18] = 0;
   out_4076141149770791221[19] = 0;
   out_4076141149770791221[20] = 0;
   out_4076141149770791221[21] = 0;
   out_4076141149770791221[22] = 1;
   out_4076141149770791221[23] = 0;
   out_4076141149770791221[24] = 0;
   out_4076141149770791221[25] = 0;
   out_4076141149770791221[26] = 0;
   out_4076141149770791221[27] = 0;
   out_4076141149770791221[28] = 0;
   out_4076141149770791221[29] = 0;
   out_4076141149770791221[30] = 0;
   out_4076141149770791221[31] = 0;
   out_4076141149770791221[32] = 0;
   out_4076141149770791221[33] = 0;
   out_4076141149770791221[34] = 0;
   out_4076141149770791221[35] = 0;
   out_4076141149770791221[36] = 0;
   out_4076141149770791221[37] = 0;
   out_4076141149770791221[38] = 0;
   out_4076141149770791221[39] = 0;
   out_4076141149770791221[40] = 0;
   out_4076141149770791221[41] = 1;
   out_4076141149770791221[42] = 0;
   out_4076141149770791221[43] = 0;
   out_4076141149770791221[44] = 0;
   out_4076141149770791221[45] = 0;
   out_4076141149770791221[46] = 0;
   out_4076141149770791221[47] = 0;
   out_4076141149770791221[48] = 0;
   out_4076141149770791221[49] = 0;
   out_4076141149770791221[50] = 0;
   out_4076141149770791221[51] = 0;
   out_4076141149770791221[52] = 0;
   out_4076141149770791221[53] = 0;
}
void h_14(double *state, double *unused, double *out_1661055795387027664) {
   out_1661055795387027664[0] = state[6];
   out_1661055795387027664[1] = state[7];
   out_1661055795387027664[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4827108180777942949) {
   out_4827108180777942949[0] = 0;
   out_4827108180777942949[1] = 0;
   out_4827108180777942949[2] = 0;
   out_4827108180777942949[3] = 0;
   out_4827108180777942949[4] = 0;
   out_4827108180777942949[5] = 0;
   out_4827108180777942949[6] = 1;
   out_4827108180777942949[7] = 0;
   out_4827108180777942949[8] = 0;
   out_4827108180777942949[9] = 0;
   out_4827108180777942949[10] = 0;
   out_4827108180777942949[11] = 0;
   out_4827108180777942949[12] = 0;
   out_4827108180777942949[13] = 0;
   out_4827108180777942949[14] = 0;
   out_4827108180777942949[15] = 0;
   out_4827108180777942949[16] = 0;
   out_4827108180777942949[17] = 0;
   out_4827108180777942949[18] = 0;
   out_4827108180777942949[19] = 0;
   out_4827108180777942949[20] = 0;
   out_4827108180777942949[21] = 0;
   out_4827108180777942949[22] = 0;
   out_4827108180777942949[23] = 0;
   out_4827108180777942949[24] = 0;
   out_4827108180777942949[25] = 1;
   out_4827108180777942949[26] = 0;
   out_4827108180777942949[27] = 0;
   out_4827108180777942949[28] = 0;
   out_4827108180777942949[29] = 0;
   out_4827108180777942949[30] = 0;
   out_4827108180777942949[31] = 0;
   out_4827108180777942949[32] = 0;
   out_4827108180777942949[33] = 0;
   out_4827108180777942949[34] = 0;
   out_4827108180777942949[35] = 0;
   out_4827108180777942949[36] = 0;
   out_4827108180777942949[37] = 0;
   out_4827108180777942949[38] = 0;
   out_4827108180777942949[39] = 0;
   out_4827108180777942949[40] = 0;
   out_4827108180777942949[41] = 0;
   out_4827108180777942949[42] = 0;
   out_4827108180777942949[43] = 0;
   out_4827108180777942949[44] = 1;
   out_4827108180777942949[45] = 0;
   out_4827108180777942949[46] = 0;
   out_4827108180777942949[47] = 0;
   out_4827108180777942949[48] = 0;
   out_4827108180777942949[49] = 0;
   out_4827108180777942949[50] = 0;
   out_4827108180777942949[51] = 0;
   out_4827108180777942949[52] = 0;
   out_4827108180777942949[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3316257012826674087) {
  err_fun(nom_x, delta_x, out_3316257012826674087);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2057247982490778565) {
  inv_err_fun(nom_x, true_x, out_2057247982490778565);
}
void pose_H_mod_fun(double *state, double *out_4138089403229407673) {
  H_mod_fun(state, out_4138089403229407673);
}
void pose_f_fun(double *state, double dt, double *out_7388093933502948823) {
  f_fun(state,  dt, out_7388093933502948823);
}
void pose_F_fun(double *state, double dt, double *out_5999254502567580570) {
  F_fun(state,  dt, out_5999254502567580570);
}
void pose_h_4(double *state, double *unused, double *out_1537498951801424975) {
  h_4(state, unused, out_1537498951801424975);
}
void pose_H_4(double *state, double *unused, double *out_863867324438458420) {
  H_4(state, unused, out_863867324438458420);
}
void pose_h_10(double *state, double *unused, double *out_374102871883193337) {
  h_10(state, unused, out_374102871883193337);
}
void pose_H_10(double *state, double *unused, double *out_7438576236994118175) {
  H_10(state, unused, out_7438576236994118175);
}
void pose_h_13(double *state, double *unused, double *out_8419386726014748872) {
  h_13(state, unused, out_8419386726014748872);
}
void pose_H_13(double *state, double *unused, double *out_4076141149770791221) {
  H_13(state, unused, out_4076141149770791221);
}
void pose_h_14(double *state, double *unused, double *out_1661055795387027664) {
  h_14(state, unused, out_1661055795387027664);
}
void pose_H_14(double *state, double *unused, double *out_4827108180777942949) {
  H_14(state, unused, out_4827108180777942949);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)

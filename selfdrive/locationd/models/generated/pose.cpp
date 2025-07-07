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
void err_fun(double *nom_x, double *delta_x, double *out_1249208308935262671) {
   out_1249208308935262671[0] = delta_x[0] + nom_x[0];
   out_1249208308935262671[1] = delta_x[1] + nom_x[1];
   out_1249208308935262671[2] = delta_x[2] + nom_x[2];
   out_1249208308935262671[3] = delta_x[3] + nom_x[3];
   out_1249208308935262671[4] = delta_x[4] + nom_x[4];
   out_1249208308935262671[5] = delta_x[5] + nom_x[5];
   out_1249208308935262671[6] = delta_x[6] + nom_x[6];
   out_1249208308935262671[7] = delta_x[7] + nom_x[7];
   out_1249208308935262671[8] = delta_x[8] + nom_x[8];
   out_1249208308935262671[9] = delta_x[9] + nom_x[9];
   out_1249208308935262671[10] = delta_x[10] + nom_x[10];
   out_1249208308935262671[11] = delta_x[11] + nom_x[11];
   out_1249208308935262671[12] = delta_x[12] + nom_x[12];
   out_1249208308935262671[13] = delta_x[13] + nom_x[13];
   out_1249208308935262671[14] = delta_x[14] + nom_x[14];
   out_1249208308935262671[15] = delta_x[15] + nom_x[15];
   out_1249208308935262671[16] = delta_x[16] + nom_x[16];
   out_1249208308935262671[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7760717880286684729) {
   out_7760717880286684729[0] = -nom_x[0] + true_x[0];
   out_7760717880286684729[1] = -nom_x[1] + true_x[1];
   out_7760717880286684729[2] = -nom_x[2] + true_x[2];
   out_7760717880286684729[3] = -nom_x[3] + true_x[3];
   out_7760717880286684729[4] = -nom_x[4] + true_x[4];
   out_7760717880286684729[5] = -nom_x[5] + true_x[5];
   out_7760717880286684729[6] = -nom_x[6] + true_x[6];
   out_7760717880286684729[7] = -nom_x[7] + true_x[7];
   out_7760717880286684729[8] = -nom_x[8] + true_x[8];
   out_7760717880286684729[9] = -nom_x[9] + true_x[9];
   out_7760717880286684729[10] = -nom_x[10] + true_x[10];
   out_7760717880286684729[11] = -nom_x[11] + true_x[11];
   out_7760717880286684729[12] = -nom_x[12] + true_x[12];
   out_7760717880286684729[13] = -nom_x[13] + true_x[13];
   out_7760717880286684729[14] = -nom_x[14] + true_x[14];
   out_7760717880286684729[15] = -nom_x[15] + true_x[15];
   out_7760717880286684729[16] = -nom_x[16] + true_x[16];
   out_7760717880286684729[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_114789788435639618) {
   out_114789788435639618[0] = 1.0;
   out_114789788435639618[1] = 0.0;
   out_114789788435639618[2] = 0.0;
   out_114789788435639618[3] = 0.0;
   out_114789788435639618[4] = 0.0;
   out_114789788435639618[5] = 0.0;
   out_114789788435639618[6] = 0.0;
   out_114789788435639618[7] = 0.0;
   out_114789788435639618[8] = 0.0;
   out_114789788435639618[9] = 0.0;
   out_114789788435639618[10] = 0.0;
   out_114789788435639618[11] = 0.0;
   out_114789788435639618[12] = 0.0;
   out_114789788435639618[13] = 0.0;
   out_114789788435639618[14] = 0.0;
   out_114789788435639618[15] = 0.0;
   out_114789788435639618[16] = 0.0;
   out_114789788435639618[17] = 0.0;
   out_114789788435639618[18] = 0.0;
   out_114789788435639618[19] = 1.0;
   out_114789788435639618[20] = 0.0;
   out_114789788435639618[21] = 0.0;
   out_114789788435639618[22] = 0.0;
   out_114789788435639618[23] = 0.0;
   out_114789788435639618[24] = 0.0;
   out_114789788435639618[25] = 0.0;
   out_114789788435639618[26] = 0.0;
   out_114789788435639618[27] = 0.0;
   out_114789788435639618[28] = 0.0;
   out_114789788435639618[29] = 0.0;
   out_114789788435639618[30] = 0.0;
   out_114789788435639618[31] = 0.0;
   out_114789788435639618[32] = 0.0;
   out_114789788435639618[33] = 0.0;
   out_114789788435639618[34] = 0.0;
   out_114789788435639618[35] = 0.0;
   out_114789788435639618[36] = 0.0;
   out_114789788435639618[37] = 0.0;
   out_114789788435639618[38] = 1.0;
   out_114789788435639618[39] = 0.0;
   out_114789788435639618[40] = 0.0;
   out_114789788435639618[41] = 0.0;
   out_114789788435639618[42] = 0.0;
   out_114789788435639618[43] = 0.0;
   out_114789788435639618[44] = 0.0;
   out_114789788435639618[45] = 0.0;
   out_114789788435639618[46] = 0.0;
   out_114789788435639618[47] = 0.0;
   out_114789788435639618[48] = 0.0;
   out_114789788435639618[49] = 0.0;
   out_114789788435639618[50] = 0.0;
   out_114789788435639618[51] = 0.0;
   out_114789788435639618[52] = 0.0;
   out_114789788435639618[53] = 0.0;
   out_114789788435639618[54] = 0.0;
   out_114789788435639618[55] = 0.0;
   out_114789788435639618[56] = 0.0;
   out_114789788435639618[57] = 1.0;
   out_114789788435639618[58] = 0.0;
   out_114789788435639618[59] = 0.0;
   out_114789788435639618[60] = 0.0;
   out_114789788435639618[61] = 0.0;
   out_114789788435639618[62] = 0.0;
   out_114789788435639618[63] = 0.0;
   out_114789788435639618[64] = 0.0;
   out_114789788435639618[65] = 0.0;
   out_114789788435639618[66] = 0.0;
   out_114789788435639618[67] = 0.0;
   out_114789788435639618[68] = 0.0;
   out_114789788435639618[69] = 0.0;
   out_114789788435639618[70] = 0.0;
   out_114789788435639618[71] = 0.0;
   out_114789788435639618[72] = 0.0;
   out_114789788435639618[73] = 0.0;
   out_114789788435639618[74] = 0.0;
   out_114789788435639618[75] = 0.0;
   out_114789788435639618[76] = 1.0;
   out_114789788435639618[77] = 0.0;
   out_114789788435639618[78] = 0.0;
   out_114789788435639618[79] = 0.0;
   out_114789788435639618[80] = 0.0;
   out_114789788435639618[81] = 0.0;
   out_114789788435639618[82] = 0.0;
   out_114789788435639618[83] = 0.0;
   out_114789788435639618[84] = 0.0;
   out_114789788435639618[85] = 0.0;
   out_114789788435639618[86] = 0.0;
   out_114789788435639618[87] = 0.0;
   out_114789788435639618[88] = 0.0;
   out_114789788435639618[89] = 0.0;
   out_114789788435639618[90] = 0.0;
   out_114789788435639618[91] = 0.0;
   out_114789788435639618[92] = 0.0;
   out_114789788435639618[93] = 0.0;
   out_114789788435639618[94] = 0.0;
   out_114789788435639618[95] = 1.0;
   out_114789788435639618[96] = 0.0;
   out_114789788435639618[97] = 0.0;
   out_114789788435639618[98] = 0.0;
   out_114789788435639618[99] = 0.0;
   out_114789788435639618[100] = 0.0;
   out_114789788435639618[101] = 0.0;
   out_114789788435639618[102] = 0.0;
   out_114789788435639618[103] = 0.0;
   out_114789788435639618[104] = 0.0;
   out_114789788435639618[105] = 0.0;
   out_114789788435639618[106] = 0.0;
   out_114789788435639618[107] = 0.0;
   out_114789788435639618[108] = 0.0;
   out_114789788435639618[109] = 0.0;
   out_114789788435639618[110] = 0.0;
   out_114789788435639618[111] = 0.0;
   out_114789788435639618[112] = 0.0;
   out_114789788435639618[113] = 0.0;
   out_114789788435639618[114] = 1.0;
   out_114789788435639618[115] = 0.0;
   out_114789788435639618[116] = 0.0;
   out_114789788435639618[117] = 0.0;
   out_114789788435639618[118] = 0.0;
   out_114789788435639618[119] = 0.0;
   out_114789788435639618[120] = 0.0;
   out_114789788435639618[121] = 0.0;
   out_114789788435639618[122] = 0.0;
   out_114789788435639618[123] = 0.0;
   out_114789788435639618[124] = 0.0;
   out_114789788435639618[125] = 0.0;
   out_114789788435639618[126] = 0.0;
   out_114789788435639618[127] = 0.0;
   out_114789788435639618[128] = 0.0;
   out_114789788435639618[129] = 0.0;
   out_114789788435639618[130] = 0.0;
   out_114789788435639618[131] = 0.0;
   out_114789788435639618[132] = 0.0;
   out_114789788435639618[133] = 1.0;
   out_114789788435639618[134] = 0.0;
   out_114789788435639618[135] = 0.0;
   out_114789788435639618[136] = 0.0;
   out_114789788435639618[137] = 0.0;
   out_114789788435639618[138] = 0.0;
   out_114789788435639618[139] = 0.0;
   out_114789788435639618[140] = 0.0;
   out_114789788435639618[141] = 0.0;
   out_114789788435639618[142] = 0.0;
   out_114789788435639618[143] = 0.0;
   out_114789788435639618[144] = 0.0;
   out_114789788435639618[145] = 0.0;
   out_114789788435639618[146] = 0.0;
   out_114789788435639618[147] = 0.0;
   out_114789788435639618[148] = 0.0;
   out_114789788435639618[149] = 0.0;
   out_114789788435639618[150] = 0.0;
   out_114789788435639618[151] = 0.0;
   out_114789788435639618[152] = 1.0;
   out_114789788435639618[153] = 0.0;
   out_114789788435639618[154] = 0.0;
   out_114789788435639618[155] = 0.0;
   out_114789788435639618[156] = 0.0;
   out_114789788435639618[157] = 0.0;
   out_114789788435639618[158] = 0.0;
   out_114789788435639618[159] = 0.0;
   out_114789788435639618[160] = 0.0;
   out_114789788435639618[161] = 0.0;
   out_114789788435639618[162] = 0.0;
   out_114789788435639618[163] = 0.0;
   out_114789788435639618[164] = 0.0;
   out_114789788435639618[165] = 0.0;
   out_114789788435639618[166] = 0.0;
   out_114789788435639618[167] = 0.0;
   out_114789788435639618[168] = 0.0;
   out_114789788435639618[169] = 0.0;
   out_114789788435639618[170] = 0.0;
   out_114789788435639618[171] = 1.0;
   out_114789788435639618[172] = 0.0;
   out_114789788435639618[173] = 0.0;
   out_114789788435639618[174] = 0.0;
   out_114789788435639618[175] = 0.0;
   out_114789788435639618[176] = 0.0;
   out_114789788435639618[177] = 0.0;
   out_114789788435639618[178] = 0.0;
   out_114789788435639618[179] = 0.0;
   out_114789788435639618[180] = 0.0;
   out_114789788435639618[181] = 0.0;
   out_114789788435639618[182] = 0.0;
   out_114789788435639618[183] = 0.0;
   out_114789788435639618[184] = 0.0;
   out_114789788435639618[185] = 0.0;
   out_114789788435639618[186] = 0.0;
   out_114789788435639618[187] = 0.0;
   out_114789788435639618[188] = 0.0;
   out_114789788435639618[189] = 0.0;
   out_114789788435639618[190] = 1.0;
   out_114789788435639618[191] = 0.0;
   out_114789788435639618[192] = 0.0;
   out_114789788435639618[193] = 0.0;
   out_114789788435639618[194] = 0.0;
   out_114789788435639618[195] = 0.0;
   out_114789788435639618[196] = 0.0;
   out_114789788435639618[197] = 0.0;
   out_114789788435639618[198] = 0.0;
   out_114789788435639618[199] = 0.0;
   out_114789788435639618[200] = 0.0;
   out_114789788435639618[201] = 0.0;
   out_114789788435639618[202] = 0.0;
   out_114789788435639618[203] = 0.0;
   out_114789788435639618[204] = 0.0;
   out_114789788435639618[205] = 0.0;
   out_114789788435639618[206] = 0.0;
   out_114789788435639618[207] = 0.0;
   out_114789788435639618[208] = 0.0;
   out_114789788435639618[209] = 1.0;
   out_114789788435639618[210] = 0.0;
   out_114789788435639618[211] = 0.0;
   out_114789788435639618[212] = 0.0;
   out_114789788435639618[213] = 0.0;
   out_114789788435639618[214] = 0.0;
   out_114789788435639618[215] = 0.0;
   out_114789788435639618[216] = 0.0;
   out_114789788435639618[217] = 0.0;
   out_114789788435639618[218] = 0.0;
   out_114789788435639618[219] = 0.0;
   out_114789788435639618[220] = 0.0;
   out_114789788435639618[221] = 0.0;
   out_114789788435639618[222] = 0.0;
   out_114789788435639618[223] = 0.0;
   out_114789788435639618[224] = 0.0;
   out_114789788435639618[225] = 0.0;
   out_114789788435639618[226] = 0.0;
   out_114789788435639618[227] = 0.0;
   out_114789788435639618[228] = 1.0;
   out_114789788435639618[229] = 0.0;
   out_114789788435639618[230] = 0.0;
   out_114789788435639618[231] = 0.0;
   out_114789788435639618[232] = 0.0;
   out_114789788435639618[233] = 0.0;
   out_114789788435639618[234] = 0.0;
   out_114789788435639618[235] = 0.0;
   out_114789788435639618[236] = 0.0;
   out_114789788435639618[237] = 0.0;
   out_114789788435639618[238] = 0.0;
   out_114789788435639618[239] = 0.0;
   out_114789788435639618[240] = 0.0;
   out_114789788435639618[241] = 0.0;
   out_114789788435639618[242] = 0.0;
   out_114789788435639618[243] = 0.0;
   out_114789788435639618[244] = 0.0;
   out_114789788435639618[245] = 0.0;
   out_114789788435639618[246] = 0.0;
   out_114789788435639618[247] = 1.0;
   out_114789788435639618[248] = 0.0;
   out_114789788435639618[249] = 0.0;
   out_114789788435639618[250] = 0.0;
   out_114789788435639618[251] = 0.0;
   out_114789788435639618[252] = 0.0;
   out_114789788435639618[253] = 0.0;
   out_114789788435639618[254] = 0.0;
   out_114789788435639618[255] = 0.0;
   out_114789788435639618[256] = 0.0;
   out_114789788435639618[257] = 0.0;
   out_114789788435639618[258] = 0.0;
   out_114789788435639618[259] = 0.0;
   out_114789788435639618[260] = 0.0;
   out_114789788435639618[261] = 0.0;
   out_114789788435639618[262] = 0.0;
   out_114789788435639618[263] = 0.0;
   out_114789788435639618[264] = 0.0;
   out_114789788435639618[265] = 0.0;
   out_114789788435639618[266] = 1.0;
   out_114789788435639618[267] = 0.0;
   out_114789788435639618[268] = 0.0;
   out_114789788435639618[269] = 0.0;
   out_114789788435639618[270] = 0.0;
   out_114789788435639618[271] = 0.0;
   out_114789788435639618[272] = 0.0;
   out_114789788435639618[273] = 0.0;
   out_114789788435639618[274] = 0.0;
   out_114789788435639618[275] = 0.0;
   out_114789788435639618[276] = 0.0;
   out_114789788435639618[277] = 0.0;
   out_114789788435639618[278] = 0.0;
   out_114789788435639618[279] = 0.0;
   out_114789788435639618[280] = 0.0;
   out_114789788435639618[281] = 0.0;
   out_114789788435639618[282] = 0.0;
   out_114789788435639618[283] = 0.0;
   out_114789788435639618[284] = 0.0;
   out_114789788435639618[285] = 1.0;
   out_114789788435639618[286] = 0.0;
   out_114789788435639618[287] = 0.0;
   out_114789788435639618[288] = 0.0;
   out_114789788435639618[289] = 0.0;
   out_114789788435639618[290] = 0.0;
   out_114789788435639618[291] = 0.0;
   out_114789788435639618[292] = 0.0;
   out_114789788435639618[293] = 0.0;
   out_114789788435639618[294] = 0.0;
   out_114789788435639618[295] = 0.0;
   out_114789788435639618[296] = 0.0;
   out_114789788435639618[297] = 0.0;
   out_114789788435639618[298] = 0.0;
   out_114789788435639618[299] = 0.0;
   out_114789788435639618[300] = 0.0;
   out_114789788435639618[301] = 0.0;
   out_114789788435639618[302] = 0.0;
   out_114789788435639618[303] = 0.0;
   out_114789788435639618[304] = 1.0;
   out_114789788435639618[305] = 0.0;
   out_114789788435639618[306] = 0.0;
   out_114789788435639618[307] = 0.0;
   out_114789788435639618[308] = 0.0;
   out_114789788435639618[309] = 0.0;
   out_114789788435639618[310] = 0.0;
   out_114789788435639618[311] = 0.0;
   out_114789788435639618[312] = 0.0;
   out_114789788435639618[313] = 0.0;
   out_114789788435639618[314] = 0.0;
   out_114789788435639618[315] = 0.0;
   out_114789788435639618[316] = 0.0;
   out_114789788435639618[317] = 0.0;
   out_114789788435639618[318] = 0.0;
   out_114789788435639618[319] = 0.0;
   out_114789788435639618[320] = 0.0;
   out_114789788435639618[321] = 0.0;
   out_114789788435639618[322] = 0.0;
   out_114789788435639618[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3550080477287595771) {
   out_3550080477287595771[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3550080477287595771[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3550080477287595771[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3550080477287595771[3] = dt*state[12] + state[3];
   out_3550080477287595771[4] = dt*state[13] + state[4];
   out_3550080477287595771[5] = dt*state[14] + state[5];
   out_3550080477287595771[6] = state[6];
   out_3550080477287595771[7] = state[7];
   out_3550080477287595771[8] = state[8];
   out_3550080477287595771[9] = state[9];
   out_3550080477287595771[10] = state[10];
   out_3550080477287595771[11] = state[11];
   out_3550080477287595771[12] = state[12];
   out_3550080477287595771[13] = state[13];
   out_3550080477287595771[14] = state[14];
   out_3550080477287595771[15] = state[15];
   out_3550080477287595771[16] = state[16];
   out_3550080477287595771[17] = state[17];
}
void F_fun(double *state, double dt, double *out_9179238613370202642) {
   out_9179238613370202642[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9179238613370202642[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9179238613370202642[2] = 0;
   out_9179238613370202642[3] = 0;
   out_9179238613370202642[4] = 0;
   out_9179238613370202642[5] = 0;
   out_9179238613370202642[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9179238613370202642[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9179238613370202642[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9179238613370202642[9] = 0;
   out_9179238613370202642[10] = 0;
   out_9179238613370202642[11] = 0;
   out_9179238613370202642[12] = 0;
   out_9179238613370202642[13] = 0;
   out_9179238613370202642[14] = 0;
   out_9179238613370202642[15] = 0;
   out_9179238613370202642[16] = 0;
   out_9179238613370202642[17] = 0;
   out_9179238613370202642[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9179238613370202642[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9179238613370202642[20] = 0;
   out_9179238613370202642[21] = 0;
   out_9179238613370202642[22] = 0;
   out_9179238613370202642[23] = 0;
   out_9179238613370202642[24] = 0;
   out_9179238613370202642[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9179238613370202642[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9179238613370202642[27] = 0;
   out_9179238613370202642[28] = 0;
   out_9179238613370202642[29] = 0;
   out_9179238613370202642[30] = 0;
   out_9179238613370202642[31] = 0;
   out_9179238613370202642[32] = 0;
   out_9179238613370202642[33] = 0;
   out_9179238613370202642[34] = 0;
   out_9179238613370202642[35] = 0;
   out_9179238613370202642[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9179238613370202642[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9179238613370202642[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9179238613370202642[39] = 0;
   out_9179238613370202642[40] = 0;
   out_9179238613370202642[41] = 0;
   out_9179238613370202642[42] = 0;
   out_9179238613370202642[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9179238613370202642[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9179238613370202642[45] = 0;
   out_9179238613370202642[46] = 0;
   out_9179238613370202642[47] = 0;
   out_9179238613370202642[48] = 0;
   out_9179238613370202642[49] = 0;
   out_9179238613370202642[50] = 0;
   out_9179238613370202642[51] = 0;
   out_9179238613370202642[52] = 0;
   out_9179238613370202642[53] = 0;
   out_9179238613370202642[54] = 0;
   out_9179238613370202642[55] = 0;
   out_9179238613370202642[56] = 0;
   out_9179238613370202642[57] = 1;
   out_9179238613370202642[58] = 0;
   out_9179238613370202642[59] = 0;
   out_9179238613370202642[60] = 0;
   out_9179238613370202642[61] = 0;
   out_9179238613370202642[62] = 0;
   out_9179238613370202642[63] = 0;
   out_9179238613370202642[64] = 0;
   out_9179238613370202642[65] = 0;
   out_9179238613370202642[66] = dt;
   out_9179238613370202642[67] = 0;
   out_9179238613370202642[68] = 0;
   out_9179238613370202642[69] = 0;
   out_9179238613370202642[70] = 0;
   out_9179238613370202642[71] = 0;
   out_9179238613370202642[72] = 0;
   out_9179238613370202642[73] = 0;
   out_9179238613370202642[74] = 0;
   out_9179238613370202642[75] = 0;
   out_9179238613370202642[76] = 1;
   out_9179238613370202642[77] = 0;
   out_9179238613370202642[78] = 0;
   out_9179238613370202642[79] = 0;
   out_9179238613370202642[80] = 0;
   out_9179238613370202642[81] = 0;
   out_9179238613370202642[82] = 0;
   out_9179238613370202642[83] = 0;
   out_9179238613370202642[84] = 0;
   out_9179238613370202642[85] = dt;
   out_9179238613370202642[86] = 0;
   out_9179238613370202642[87] = 0;
   out_9179238613370202642[88] = 0;
   out_9179238613370202642[89] = 0;
   out_9179238613370202642[90] = 0;
   out_9179238613370202642[91] = 0;
   out_9179238613370202642[92] = 0;
   out_9179238613370202642[93] = 0;
   out_9179238613370202642[94] = 0;
   out_9179238613370202642[95] = 1;
   out_9179238613370202642[96] = 0;
   out_9179238613370202642[97] = 0;
   out_9179238613370202642[98] = 0;
   out_9179238613370202642[99] = 0;
   out_9179238613370202642[100] = 0;
   out_9179238613370202642[101] = 0;
   out_9179238613370202642[102] = 0;
   out_9179238613370202642[103] = 0;
   out_9179238613370202642[104] = dt;
   out_9179238613370202642[105] = 0;
   out_9179238613370202642[106] = 0;
   out_9179238613370202642[107] = 0;
   out_9179238613370202642[108] = 0;
   out_9179238613370202642[109] = 0;
   out_9179238613370202642[110] = 0;
   out_9179238613370202642[111] = 0;
   out_9179238613370202642[112] = 0;
   out_9179238613370202642[113] = 0;
   out_9179238613370202642[114] = 1;
   out_9179238613370202642[115] = 0;
   out_9179238613370202642[116] = 0;
   out_9179238613370202642[117] = 0;
   out_9179238613370202642[118] = 0;
   out_9179238613370202642[119] = 0;
   out_9179238613370202642[120] = 0;
   out_9179238613370202642[121] = 0;
   out_9179238613370202642[122] = 0;
   out_9179238613370202642[123] = 0;
   out_9179238613370202642[124] = 0;
   out_9179238613370202642[125] = 0;
   out_9179238613370202642[126] = 0;
   out_9179238613370202642[127] = 0;
   out_9179238613370202642[128] = 0;
   out_9179238613370202642[129] = 0;
   out_9179238613370202642[130] = 0;
   out_9179238613370202642[131] = 0;
   out_9179238613370202642[132] = 0;
   out_9179238613370202642[133] = 1;
   out_9179238613370202642[134] = 0;
   out_9179238613370202642[135] = 0;
   out_9179238613370202642[136] = 0;
   out_9179238613370202642[137] = 0;
   out_9179238613370202642[138] = 0;
   out_9179238613370202642[139] = 0;
   out_9179238613370202642[140] = 0;
   out_9179238613370202642[141] = 0;
   out_9179238613370202642[142] = 0;
   out_9179238613370202642[143] = 0;
   out_9179238613370202642[144] = 0;
   out_9179238613370202642[145] = 0;
   out_9179238613370202642[146] = 0;
   out_9179238613370202642[147] = 0;
   out_9179238613370202642[148] = 0;
   out_9179238613370202642[149] = 0;
   out_9179238613370202642[150] = 0;
   out_9179238613370202642[151] = 0;
   out_9179238613370202642[152] = 1;
   out_9179238613370202642[153] = 0;
   out_9179238613370202642[154] = 0;
   out_9179238613370202642[155] = 0;
   out_9179238613370202642[156] = 0;
   out_9179238613370202642[157] = 0;
   out_9179238613370202642[158] = 0;
   out_9179238613370202642[159] = 0;
   out_9179238613370202642[160] = 0;
   out_9179238613370202642[161] = 0;
   out_9179238613370202642[162] = 0;
   out_9179238613370202642[163] = 0;
   out_9179238613370202642[164] = 0;
   out_9179238613370202642[165] = 0;
   out_9179238613370202642[166] = 0;
   out_9179238613370202642[167] = 0;
   out_9179238613370202642[168] = 0;
   out_9179238613370202642[169] = 0;
   out_9179238613370202642[170] = 0;
   out_9179238613370202642[171] = 1;
   out_9179238613370202642[172] = 0;
   out_9179238613370202642[173] = 0;
   out_9179238613370202642[174] = 0;
   out_9179238613370202642[175] = 0;
   out_9179238613370202642[176] = 0;
   out_9179238613370202642[177] = 0;
   out_9179238613370202642[178] = 0;
   out_9179238613370202642[179] = 0;
   out_9179238613370202642[180] = 0;
   out_9179238613370202642[181] = 0;
   out_9179238613370202642[182] = 0;
   out_9179238613370202642[183] = 0;
   out_9179238613370202642[184] = 0;
   out_9179238613370202642[185] = 0;
   out_9179238613370202642[186] = 0;
   out_9179238613370202642[187] = 0;
   out_9179238613370202642[188] = 0;
   out_9179238613370202642[189] = 0;
   out_9179238613370202642[190] = 1;
   out_9179238613370202642[191] = 0;
   out_9179238613370202642[192] = 0;
   out_9179238613370202642[193] = 0;
   out_9179238613370202642[194] = 0;
   out_9179238613370202642[195] = 0;
   out_9179238613370202642[196] = 0;
   out_9179238613370202642[197] = 0;
   out_9179238613370202642[198] = 0;
   out_9179238613370202642[199] = 0;
   out_9179238613370202642[200] = 0;
   out_9179238613370202642[201] = 0;
   out_9179238613370202642[202] = 0;
   out_9179238613370202642[203] = 0;
   out_9179238613370202642[204] = 0;
   out_9179238613370202642[205] = 0;
   out_9179238613370202642[206] = 0;
   out_9179238613370202642[207] = 0;
   out_9179238613370202642[208] = 0;
   out_9179238613370202642[209] = 1;
   out_9179238613370202642[210] = 0;
   out_9179238613370202642[211] = 0;
   out_9179238613370202642[212] = 0;
   out_9179238613370202642[213] = 0;
   out_9179238613370202642[214] = 0;
   out_9179238613370202642[215] = 0;
   out_9179238613370202642[216] = 0;
   out_9179238613370202642[217] = 0;
   out_9179238613370202642[218] = 0;
   out_9179238613370202642[219] = 0;
   out_9179238613370202642[220] = 0;
   out_9179238613370202642[221] = 0;
   out_9179238613370202642[222] = 0;
   out_9179238613370202642[223] = 0;
   out_9179238613370202642[224] = 0;
   out_9179238613370202642[225] = 0;
   out_9179238613370202642[226] = 0;
   out_9179238613370202642[227] = 0;
   out_9179238613370202642[228] = 1;
   out_9179238613370202642[229] = 0;
   out_9179238613370202642[230] = 0;
   out_9179238613370202642[231] = 0;
   out_9179238613370202642[232] = 0;
   out_9179238613370202642[233] = 0;
   out_9179238613370202642[234] = 0;
   out_9179238613370202642[235] = 0;
   out_9179238613370202642[236] = 0;
   out_9179238613370202642[237] = 0;
   out_9179238613370202642[238] = 0;
   out_9179238613370202642[239] = 0;
   out_9179238613370202642[240] = 0;
   out_9179238613370202642[241] = 0;
   out_9179238613370202642[242] = 0;
   out_9179238613370202642[243] = 0;
   out_9179238613370202642[244] = 0;
   out_9179238613370202642[245] = 0;
   out_9179238613370202642[246] = 0;
   out_9179238613370202642[247] = 1;
   out_9179238613370202642[248] = 0;
   out_9179238613370202642[249] = 0;
   out_9179238613370202642[250] = 0;
   out_9179238613370202642[251] = 0;
   out_9179238613370202642[252] = 0;
   out_9179238613370202642[253] = 0;
   out_9179238613370202642[254] = 0;
   out_9179238613370202642[255] = 0;
   out_9179238613370202642[256] = 0;
   out_9179238613370202642[257] = 0;
   out_9179238613370202642[258] = 0;
   out_9179238613370202642[259] = 0;
   out_9179238613370202642[260] = 0;
   out_9179238613370202642[261] = 0;
   out_9179238613370202642[262] = 0;
   out_9179238613370202642[263] = 0;
   out_9179238613370202642[264] = 0;
   out_9179238613370202642[265] = 0;
   out_9179238613370202642[266] = 1;
   out_9179238613370202642[267] = 0;
   out_9179238613370202642[268] = 0;
   out_9179238613370202642[269] = 0;
   out_9179238613370202642[270] = 0;
   out_9179238613370202642[271] = 0;
   out_9179238613370202642[272] = 0;
   out_9179238613370202642[273] = 0;
   out_9179238613370202642[274] = 0;
   out_9179238613370202642[275] = 0;
   out_9179238613370202642[276] = 0;
   out_9179238613370202642[277] = 0;
   out_9179238613370202642[278] = 0;
   out_9179238613370202642[279] = 0;
   out_9179238613370202642[280] = 0;
   out_9179238613370202642[281] = 0;
   out_9179238613370202642[282] = 0;
   out_9179238613370202642[283] = 0;
   out_9179238613370202642[284] = 0;
   out_9179238613370202642[285] = 1;
   out_9179238613370202642[286] = 0;
   out_9179238613370202642[287] = 0;
   out_9179238613370202642[288] = 0;
   out_9179238613370202642[289] = 0;
   out_9179238613370202642[290] = 0;
   out_9179238613370202642[291] = 0;
   out_9179238613370202642[292] = 0;
   out_9179238613370202642[293] = 0;
   out_9179238613370202642[294] = 0;
   out_9179238613370202642[295] = 0;
   out_9179238613370202642[296] = 0;
   out_9179238613370202642[297] = 0;
   out_9179238613370202642[298] = 0;
   out_9179238613370202642[299] = 0;
   out_9179238613370202642[300] = 0;
   out_9179238613370202642[301] = 0;
   out_9179238613370202642[302] = 0;
   out_9179238613370202642[303] = 0;
   out_9179238613370202642[304] = 1;
   out_9179238613370202642[305] = 0;
   out_9179238613370202642[306] = 0;
   out_9179238613370202642[307] = 0;
   out_9179238613370202642[308] = 0;
   out_9179238613370202642[309] = 0;
   out_9179238613370202642[310] = 0;
   out_9179238613370202642[311] = 0;
   out_9179238613370202642[312] = 0;
   out_9179238613370202642[313] = 0;
   out_9179238613370202642[314] = 0;
   out_9179238613370202642[315] = 0;
   out_9179238613370202642[316] = 0;
   out_9179238613370202642[317] = 0;
   out_9179238613370202642[318] = 0;
   out_9179238613370202642[319] = 0;
   out_9179238613370202642[320] = 0;
   out_9179238613370202642[321] = 0;
   out_9179238613370202642[322] = 0;
   out_9179238613370202642[323] = 1;
}
void h_4(double *state, double *unused, double *out_3974230882824720906) {
   out_3974230882824720906[0] = state[6] + state[9];
   out_3974230882824720906[1] = state[7] + state[10];
   out_3974230882824720906[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3122410822710806054) {
   out_3122410822710806054[0] = 0;
   out_3122410822710806054[1] = 0;
   out_3122410822710806054[2] = 0;
   out_3122410822710806054[3] = 0;
   out_3122410822710806054[4] = 0;
   out_3122410822710806054[5] = 0;
   out_3122410822710806054[6] = 1;
   out_3122410822710806054[7] = 0;
   out_3122410822710806054[8] = 0;
   out_3122410822710806054[9] = 1;
   out_3122410822710806054[10] = 0;
   out_3122410822710806054[11] = 0;
   out_3122410822710806054[12] = 0;
   out_3122410822710806054[13] = 0;
   out_3122410822710806054[14] = 0;
   out_3122410822710806054[15] = 0;
   out_3122410822710806054[16] = 0;
   out_3122410822710806054[17] = 0;
   out_3122410822710806054[18] = 0;
   out_3122410822710806054[19] = 0;
   out_3122410822710806054[20] = 0;
   out_3122410822710806054[21] = 0;
   out_3122410822710806054[22] = 0;
   out_3122410822710806054[23] = 0;
   out_3122410822710806054[24] = 0;
   out_3122410822710806054[25] = 1;
   out_3122410822710806054[26] = 0;
   out_3122410822710806054[27] = 0;
   out_3122410822710806054[28] = 1;
   out_3122410822710806054[29] = 0;
   out_3122410822710806054[30] = 0;
   out_3122410822710806054[31] = 0;
   out_3122410822710806054[32] = 0;
   out_3122410822710806054[33] = 0;
   out_3122410822710806054[34] = 0;
   out_3122410822710806054[35] = 0;
   out_3122410822710806054[36] = 0;
   out_3122410822710806054[37] = 0;
   out_3122410822710806054[38] = 0;
   out_3122410822710806054[39] = 0;
   out_3122410822710806054[40] = 0;
   out_3122410822710806054[41] = 0;
   out_3122410822710806054[42] = 0;
   out_3122410822710806054[43] = 0;
   out_3122410822710806054[44] = 1;
   out_3122410822710806054[45] = 0;
   out_3122410822710806054[46] = 0;
   out_3122410822710806054[47] = 1;
   out_3122410822710806054[48] = 0;
   out_3122410822710806054[49] = 0;
   out_3122410822710806054[50] = 0;
   out_3122410822710806054[51] = 0;
   out_3122410822710806054[52] = 0;
   out_3122410822710806054[53] = 0;
}
void h_10(double *state, double *unused, double *out_1332363883864616286) {
   out_1332363883864616286[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1332363883864616286[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1332363883864616286[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4657406456673431633) {
   out_4657406456673431633[0] = 0;
   out_4657406456673431633[1] = 9.8100000000000005*cos(state[1]);
   out_4657406456673431633[2] = 0;
   out_4657406456673431633[3] = 0;
   out_4657406456673431633[4] = -state[8];
   out_4657406456673431633[5] = state[7];
   out_4657406456673431633[6] = 0;
   out_4657406456673431633[7] = state[5];
   out_4657406456673431633[8] = -state[4];
   out_4657406456673431633[9] = 0;
   out_4657406456673431633[10] = 0;
   out_4657406456673431633[11] = 0;
   out_4657406456673431633[12] = 1;
   out_4657406456673431633[13] = 0;
   out_4657406456673431633[14] = 0;
   out_4657406456673431633[15] = 1;
   out_4657406456673431633[16] = 0;
   out_4657406456673431633[17] = 0;
   out_4657406456673431633[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4657406456673431633[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4657406456673431633[20] = 0;
   out_4657406456673431633[21] = state[8];
   out_4657406456673431633[22] = 0;
   out_4657406456673431633[23] = -state[6];
   out_4657406456673431633[24] = -state[5];
   out_4657406456673431633[25] = 0;
   out_4657406456673431633[26] = state[3];
   out_4657406456673431633[27] = 0;
   out_4657406456673431633[28] = 0;
   out_4657406456673431633[29] = 0;
   out_4657406456673431633[30] = 0;
   out_4657406456673431633[31] = 1;
   out_4657406456673431633[32] = 0;
   out_4657406456673431633[33] = 0;
   out_4657406456673431633[34] = 1;
   out_4657406456673431633[35] = 0;
   out_4657406456673431633[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4657406456673431633[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4657406456673431633[38] = 0;
   out_4657406456673431633[39] = -state[7];
   out_4657406456673431633[40] = state[6];
   out_4657406456673431633[41] = 0;
   out_4657406456673431633[42] = state[4];
   out_4657406456673431633[43] = -state[3];
   out_4657406456673431633[44] = 0;
   out_4657406456673431633[45] = 0;
   out_4657406456673431633[46] = 0;
   out_4657406456673431633[47] = 0;
   out_4657406456673431633[48] = 0;
   out_4657406456673431633[49] = 0;
   out_4657406456673431633[50] = 1;
   out_4657406456673431633[51] = 0;
   out_4657406456673431633[52] = 0;
   out_4657406456673431633[53] = 1;
}
void h_13(double *state, double *unused, double *out_8605248053788070713) {
   out_8605248053788070713[0] = state[3];
   out_8605248053788070713[1] = state[4];
   out_8605248053788070713[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6334684648043138855) {
   out_6334684648043138855[0] = 0;
   out_6334684648043138855[1] = 0;
   out_6334684648043138855[2] = 0;
   out_6334684648043138855[3] = 1;
   out_6334684648043138855[4] = 0;
   out_6334684648043138855[5] = 0;
   out_6334684648043138855[6] = 0;
   out_6334684648043138855[7] = 0;
   out_6334684648043138855[8] = 0;
   out_6334684648043138855[9] = 0;
   out_6334684648043138855[10] = 0;
   out_6334684648043138855[11] = 0;
   out_6334684648043138855[12] = 0;
   out_6334684648043138855[13] = 0;
   out_6334684648043138855[14] = 0;
   out_6334684648043138855[15] = 0;
   out_6334684648043138855[16] = 0;
   out_6334684648043138855[17] = 0;
   out_6334684648043138855[18] = 0;
   out_6334684648043138855[19] = 0;
   out_6334684648043138855[20] = 0;
   out_6334684648043138855[21] = 0;
   out_6334684648043138855[22] = 1;
   out_6334684648043138855[23] = 0;
   out_6334684648043138855[24] = 0;
   out_6334684648043138855[25] = 0;
   out_6334684648043138855[26] = 0;
   out_6334684648043138855[27] = 0;
   out_6334684648043138855[28] = 0;
   out_6334684648043138855[29] = 0;
   out_6334684648043138855[30] = 0;
   out_6334684648043138855[31] = 0;
   out_6334684648043138855[32] = 0;
   out_6334684648043138855[33] = 0;
   out_6334684648043138855[34] = 0;
   out_6334684648043138855[35] = 0;
   out_6334684648043138855[36] = 0;
   out_6334684648043138855[37] = 0;
   out_6334684648043138855[38] = 0;
   out_6334684648043138855[39] = 0;
   out_6334684648043138855[40] = 0;
   out_6334684648043138855[41] = 1;
   out_6334684648043138855[42] = 0;
   out_6334684648043138855[43] = 0;
   out_6334684648043138855[44] = 0;
   out_6334684648043138855[45] = 0;
   out_6334684648043138855[46] = 0;
   out_6334684648043138855[47] = 0;
   out_6334684648043138855[48] = 0;
   out_6334684648043138855[49] = 0;
   out_6334684648043138855[50] = 0;
   out_6334684648043138855[51] = 0;
   out_6334684648043138855[52] = 0;
   out_6334684648043138855[53] = 0;
}
void h_14(double *state, double *unused, double *out_5600738675960527785) {
   out_5600738675960527785[0] = state[6];
   out_5600738675960527785[1] = state[7];
   out_5600738675960527785[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7085651679050290583) {
   out_7085651679050290583[0] = 0;
   out_7085651679050290583[1] = 0;
   out_7085651679050290583[2] = 0;
   out_7085651679050290583[3] = 0;
   out_7085651679050290583[4] = 0;
   out_7085651679050290583[5] = 0;
   out_7085651679050290583[6] = 1;
   out_7085651679050290583[7] = 0;
   out_7085651679050290583[8] = 0;
   out_7085651679050290583[9] = 0;
   out_7085651679050290583[10] = 0;
   out_7085651679050290583[11] = 0;
   out_7085651679050290583[12] = 0;
   out_7085651679050290583[13] = 0;
   out_7085651679050290583[14] = 0;
   out_7085651679050290583[15] = 0;
   out_7085651679050290583[16] = 0;
   out_7085651679050290583[17] = 0;
   out_7085651679050290583[18] = 0;
   out_7085651679050290583[19] = 0;
   out_7085651679050290583[20] = 0;
   out_7085651679050290583[21] = 0;
   out_7085651679050290583[22] = 0;
   out_7085651679050290583[23] = 0;
   out_7085651679050290583[24] = 0;
   out_7085651679050290583[25] = 1;
   out_7085651679050290583[26] = 0;
   out_7085651679050290583[27] = 0;
   out_7085651679050290583[28] = 0;
   out_7085651679050290583[29] = 0;
   out_7085651679050290583[30] = 0;
   out_7085651679050290583[31] = 0;
   out_7085651679050290583[32] = 0;
   out_7085651679050290583[33] = 0;
   out_7085651679050290583[34] = 0;
   out_7085651679050290583[35] = 0;
   out_7085651679050290583[36] = 0;
   out_7085651679050290583[37] = 0;
   out_7085651679050290583[38] = 0;
   out_7085651679050290583[39] = 0;
   out_7085651679050290583[40] = 0;
   out_7085651679050290583[41] = 0;
   out_7085651679050290583[42] = 0;
   out_7085651679050290583[43] = 0;
   out_7085651679050290583[44] = 1;
   out_7085651679050290583[45] = 0;
   out_7085651679050290583[46] = 0;
   out_7085651679050290583[47] = 0;
   out_7085651679050290583[48] = 0;
   out_7085651679050290583[49] = 0;
   out_7085651679050290583[50] = 0;
   out_7085651679050290583[51] = 0;
   out_7085651679050290583[52] = 0;
   out_7085651679050290583[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1249208308935262671) {
  err_fun(nom_x, delta_x, out_1249208308935262671);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7760717880286684729) {
  inv_err_fun(nom_x, true_x, out_7760717880286684729);
}
void pose_H_mod_fun(double *state, double *out_114789788435639618) {
  H_mod_fun(state, out_114789788435639618);
}
void pose_f_fun(double *state, double dt, double *out_3550080477287595771) {
  f_fun(state,  dt, out_3550080477287595771);
}
void pose_F_fun(double *state, double dt, double *out_9179238613370202642) {
  F_fun(state,  dt, out_9179238613370202642);
}
void pose_h_4(double *state, double *unused, double *out_3974230882824720906) {
  h_4(state, unused, out_3974230882824720906);
}
void pose_H_4(double *state, double *unused, double *out_3122410822710806054) {
  H_4(state, unused, out_3122410822710806054);
}
void pose_h_10(double *state, double *unused, double *out_1332363883864616286) {
  h_10(state, unused, out_1332363883864616286);
}
void pose_H_10(double *state, double *unused, double *out_4657406456673431633) {
  H_10(state, unused, out_4657406456673431633);
}
void pose_h_13(double *state, double *unused, double *out_8605248053788070713) {
  h_13(state, unused, out_8605248053788070713);
}
void pose_H_13(double *state, double *unused, double *out_6334684648043138855) {
  H_13(state, unused, out_6334684648043138855);
}
void pose_h_14(double *state, double *unused, double *out_5600738675960527785) {
  h_14(state, unused, out_5600738675960527785);
}
void pose_H_14(double *state, double *unused, double *out_7085651679050290583) {
  H_14(state, unused, out_7085651679050290583);
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

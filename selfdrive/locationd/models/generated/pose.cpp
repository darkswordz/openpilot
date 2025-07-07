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
void err_fun(double *nom_x, double *delta_x, double *out_3178519467950773499) {
   out_3178519467950773499[0] = delta_x[0] + nom_x[0];
   out_3178519467950773499[1] = delta_x[1] + nom_x[1];
   out_3178519467950773499[2] = delta_x[2] + nom_x[2];
   out_3178519467950773499[3] = delta_x[3] + nom_x[3];
   out_3178519467950773499[4] = delta_x[4] + nom_x[4];
   out_3178519467950773499[5] = delta_x[5] + nom_x[5];
   out_3178519467950773499[6] = delta_x[6] + nom_x[6];
   out_3178519467950773499[7] = delta_x[7] + nom_x[7];
   out_3178519467950773499[8] = delta_x[8] + nom_x[8];
   out_3178519467950773499[9] = delta_x[9] + nom_x[9];
   out_3178519467950773499[10] = delta_x[10] + nom_x[10];
   out_3178519467950773499[11] = delta_x[11] + nom_x[11];
   out_3178519467950773499[12] = delta_x[12] + nom_x[12];
   out_3178519467950773499[13] = delta_x[13] + nom_x[13];
   out_3178519467950773499[14] = delta_x[14] + nom_x[14];
   out_3178519467950773499[15] = delta_x[15] + nom_x[15];
   out_3178519467950773499[16] = delta_x[16] + nom_x[16];
   out_3178519467950773499[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4057631928554815578) {
   out_4057631928554815578[0] = -nom_x[0] + true_x[0];
   out_4057631928554815578[1] = -nom_x[1] + true_x[1];
   out_4057631928554815578[2] = -nom_x[2] + true_x[2];
   out_4057631928554815578[3] = -nom_x[3] + true_x[3];
   out_4057631928554815578[4] = -nom_x[4] + true_x[4];
   out_4057631928554815578[5] = -nom_x[5] + true_x[5];
   out_4057631928554815578[6] = -nom_x[6] + true_x[6];
   out_4057631928554815578[7] = -nom_x[7] + true_x[7];
   out_4057631928554815578[8] = -nom_x[8] + true_x[8];
   out_4057631928554815578[9] = -nom_x[9] + true_x[9];
   out_4057631928554815578[10] = -nom_x[10] + true_x[10];
   out_4057631928554815578[11] = -nom_x[11] + true_x[11];
   out_4057631928554815578[12] = -nom_x[12] + true_x[12];
   out_4057631928554815578[13] = -nom_x[13] + true_x[13];
   out_4057631928554815578[14] = -nom_x[14] + true_x[14];
   out_4057631928554815578[15] = -nom_x[15] + true_x[15];
   out_4057631928554815578[16] = -nom_x[16] + true_x[16];
   out_4057631928554815578[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7284952421974239963) {
   out_7284952421974239963[0] = 1.0;
   out_7284952421974239963[1] = 0.0;
   out_7284952421974239963[2] = 0.0;
   out_7284952421974239963[3] = 0.0;
   out_7284952421974239963[4] = 0.0;
   out_7284952421974239963[5] = 0.0;
   out_7284952421974239963[6] = 0.0;
   out_7284952421974239963[7] = 0.0;
   out_7284952421974239963[8] = 0.0;
   out_7284952421974239963[9] = 0.0;
   out_7284952421974239963[10] = 0.0;
   out_7284952421974239963[11] = 0.0;
   out_7284952421974239963[12] = 0.0;
   out_7284952421974239963[13] = 0.0;
   out_7284952421974239963[14] = 0.0;
   out_7284952421974239963[15] = 0.0;
   out_7284952421974239963[16] = 0.0;
   out_7284952421974239963[17] = 0.0;
   out_7284952421974239963[18] = 0.0;
   out_7284952421974239963[19] = 1.0;
   out_7284952421974239963[20] = 0.0;
   out_7284952421974239963[21] = 0.0;
   out_7284952421974239963[22] = 0.0;
   out_7284952421974239963[23] = 0.0;
   out_7284952421974239963[24] = 0.0;
   out_7284952421974239963[25] = 0.0;
   out_7284952421974239963[26] = 0.0;
   out_7284952421974239963[27] = 0.0;
   out_7284952421974239963[28] = 0.0;
   out_7284952421974239963[29] = 0.0;
   out_7284952421974239963[30] = 0.0;
   out_7284952421974239963[31] = 0.0;
   out_7284952421974239963[32] = 0.0;
   out_7284952421974239963[33] = 0.0;
   out_7284952421974239963[34] = 0.0;
   out_7284952421974239963[35] = 0.0;
   out_7284952421974239963[36] = 0.0;
   out_7284952421974239963[37] = 0.0;
   out_7284952421974239963[38] = 1.0;
   out_7284952421974239963[39] = 0.0;
   out_7284952421974239963[40] = 0.0;
   out_7284952421974239963[41] = 0.0;
   out_7284952421974239963[42] = 0.0;
   out_7284952421974239963[43] = 0.0;
   out_7284952421974239963[44] = 0.0;
   out_7284952421974239963[45] = 0.0;
   out_7284952421974239963[46] = 0.0;
   out_7284952421974239963[47] = 0.0;
   out_7284952421974239963[48] = 0.0;
   out_7284952421974239963[49] = 0.0;
   out_7284952421974239963[50] = 0.0;
   out_7284952421974239963[51] = 0.0;
   out_7284952421974239963[52] = 0.0;
   out_7284952421974239963[53] = 0.0;
   out_7284952421974239963[54] = 0.0;
   out_7284952421974239963[55] = 0.0;
   out_7284952421974239963[56] = 0.0;
   out_7284952421974239963[57] = 1.0;
   out_7284952421974239963[58] = 0.0;
   out_7284952421974239963[59] = 0.0;
   out_7284952421974239963[60] = 0.0;
   out_7284952421974239963[61] = 0.0;
   out_7284952421974239963[62] = 0.0;
   out_7284952421974239963[63] = 0.0;
   out_7284952421974239963[64] = 0.0;
   out_7284952421974239963[65] = 0.0;
   out_7284952421974239963[66] = 0.0;
   out_7284952421974239963[67] = 0.0;
   out_7284952421974239963[68] = 0.0;
   out_7284952421974239963[69] = 0.0;
   out_7284952421974239963[70] = 0.0;
   out_7284952421974239963[71] = 0.0;
   out_7284952421974239963[72] = 0.0;
   out_7284952421974239963[73] = 0.0;
   out_7284952421974239963[74] = 0.0;
   out_7284952421974239963[75] = 0.0;
   out_7284952421974239963[76] = 1.0;
   out_7284952421974239963[77] = 0.0;
   out_7284952421974239963[78] = 0.0;
   out_7284952421974239963[79] = 0.0;
   out_7284952421974239963[80] = 0.0;
   out_7284952421974239963[81] = 0.0;
   out_7284952421974239963[82] = 0.0;
   out_7284952421974239963[83] = 0.0;
   out_7284952421974239963[84] = 0.0;
   out_7284952421974239963[85] = 0.0;
   out_7284952421974239963[86] = 0.0;
   out_7284952421974239963[87] = 0.0;
   out_7284952421974239963[88] = 0.0;
   out_7284952421974239963[89] = 0.0;
   out_7284952421974239963[90] = 0.0;
   out_7284952421974239963[91] = 0.0;
   out_7284952421974239963[92] = 0.0;
   out_7284952421974239963[93] = 0.0;
   out_7284952421974239963[94] = 0.0;
   out_7284952421974239963[95] = 1.0;
   out_7284952421974239963[96] = 0.0;
   out_7284952421974239963[97] = 0.0;
   out_7284952421974239963[98] = 0.0;
   out_7284952421974239963[99] = 0.0;
   out_7284952421974239963[100] = 0.0;
   out_7284952421974239963[101] = 0.0;
   out_7284952421974239963[102] = 0.0;
   out_7284952421974239963[103] = 0.0;
   out_7284952421974239963[104] = 0.0;
   out_7284952421974239963[105] = 0.0;
   out_7284952421974239963[106] = 0.0;
   out_7284952421974239963[107] = 0.0;
   out_7284952421974239963[108] = 0.0;
   out_7284952421974239963[109] = 0.0;
   out_7284952421974239963[110] = 0.0;
   out_7284952421974239963[111] = 0.0;
   out_7284952421974239963[112] = 0.0;
   out_7284952421974239963[113] = 0.0;
   out_7284952421974239963[114] = 1.0;
   out_7284952421974239963[115] = 0.0;
   out_7284952421974239963[116] = 0.0;
   out_7284952421974239963[117] = 0.0;
   out_7284952421974239963[118] = 0.0;
   out_7284952421974239963[119] = 0.0;
   out_7284952421974239963[120] = 0.0;
   out_7284952421974239963[121] = 0.0;
   out_7284952421974239963[122] = 0.0;
   out_7284952421974239963[123] = 0.0;
   out_7284952421974239963[124] = 0.0;
   out_7284952421974239963[125] = 0.0;
   out_7284952421974239963[126] = 0.0;
   out_7284952421974239963[127] = 0.0;
   out_7284952421974239963[128] = 0.0;
   out_7284952421974239963[129] = 0.0;
   out_7284952421974239963[130] = 0.0;
   out_7284952421974239963[131] = 0.0;
   out_7284952421974239963[132] = 0.0;
   out_7284952421974239963[133] = 1.0;
   out_7284952421974239963[134] = 0.0;
   out_7284952421974239963[135] = 0.0;
   out_7284952421974239963[136] = 0.0;
   out_7284952421974239963[137] = 0.0;
   out_7284952421974239963[138] = 0.0;
   out_7284952421974239963[139] = 0.0;
   out_7284952421974239963[140] = 0.0;
   out_7284952421974239963[141] = 0.0;
   out_7284952421974239963[142] = 0.0;
   out_7284952421974239963[143] = 0.0;
   out_7284952421974239963[144] = 0.0;
   out_7284952421974239963[145] = 0.0;
   out_7284952421974239963[146] = 0.0;
   out_7284952421974239963[147] = 0.0;
   out_7284952421974239963[148] = 0.0;
   out_7284952421974239963[149] = 0.0;
   out_7284952421974239963[150] = 0.0;
   out_7284952421974239963[151] = 0.0;
   out_7284952421974239963[152] = 1.0;
   out_7284952421974239963[153] = 0.0;
   out_7284952421974239963[154] = 0.0;
   out_7284952421974239963[155] = 0.0;
   out_7284952421974239963[156] = 0.0;
   out_7284952421974239963[157] = 0.0;
   out_7284952421974239963[158] = 0.0;
   out_7284952421974239963[159] = 0.0;
   out_7284952421974239963[160] = 0.0;
   out_7284952421974239963[161] = 0.0;
   out_7284952421974239963[162] = 0.0;
   out_7284952421974239963[163] = 0.0;
   out_7284952421974239963[164] = 0.0;
   out_7284952421974239963[165] = 0.0;
   out_7284952421974239963[166] = 0.0;
   out_7284952421974239963[167] = 0.0;
   out_7284952421974239963[168] = 0.0;
   out_7284952421974239963[169] = 0.0;
   out_7284952421974239963[170] = 0.0;
   out_7284952421974239963[171] = 1.0;
   out_7284952421974239963[172] = 0.0;
   out_7284952421974239963[173] = 0.0;
   out_7284952421974239963[174] = 0.0;
   out_7284952421974239963[175] = 0.0;
   out_7284952421974239963[176] = 0.0;
   out_7284952421974239963[177] = 0.0;
   out_7284952421974239963[178] = 0.0;
   out_7284952421974239963[179] = 0.0;
   out_7284952421974239963[180] = 0.0;
   out_7284952421974239963[181] = 0.0;
   out_7284952421974239963[182] = 0.0;
   out_7284952421974239963[183] = 0.0;
   out_7284952421974239963[184] = 0.0;
   out_7284952421974239963[185] = 0.0;
   out_7284952421974239963[186] = 0.0;
   out_7284952421974239963[187] = 0.0;
   out_7284952421974239963[188] = 0.0;
   out_7284952421974239963[189] = 0.0;
   out_7284952421974239963[190] = 1.0;
   out_7284952421974239963[191] = 0.0;
   out_7284952421974239963[192] = 0.0;
   out_7284952421974239963[193] = 0.0;
   out_7284952421974239963[194] = 0.0;
   out_7284952421974239963[195] = 0.0;
   out_7284952421974239963[196] = 0.0;
   out_7284952421974239963[197] = 0.0;
   out_7284952421974239963[198] = 0.0;
   out_7284952421974239963[199] = 0.0;
   out_7284952421974239963[200] = 0.0;
   out_7284952421974239963[201] = 0.0;
   out_7284952421974239963[202] = 0.0;
   out_7284952421974239963[203] = 0.0;
   out_7284952421974239963[204] = 0.0;
   out_7284952421974239963[205] = 0.0;
   out_7284952421974239963[206] = 0.0;
   out_7284952421974239963[207] = 0.0;
   out_7284952421974239963[208] = 0.0;
   out_7284952421974239963[209] = 1.0;
   out_7284952421974239963[210] = 0.0;
   out_7284952421974239963[211] = 0.0;
   out_7284952421974239963[212] = 0.0;
   out_7284952421974239963[213] = 0.0;
   out_7284952421974239963[214] = 0.0;
   out_7284952421974239963[215] = 0.0;
   out_7284952421974239963[216] = 0.0;
   out_7284952421974239963[217] = 0.0;
   out_7284952421974239963[218] = 0.0;
   out_7284952421974239963[219] = 0.0;
   out_7284952421974239963[220] = 0.0;
   out_7284952421974239963[221] = 0.0;
   out_7284952421974239963[222] = 0.0;
   out_7284952421974239963[223] = 0.0;
   out_7284952421974239963[224] = 0.0;
   out_7284952421974239963[225] = 0.0;
   out_7284952421974239963[226] = 0.0;
   out_7284952421974239963[227] = 0.0;
   out_7284952421974239963[228] = 1.0;
   out_7284952421974239963[229] = 0.0;
   out_7284952421974239963[230] = 0.0;
   out_7284952421974239963[231] = 0.0;
   out_7284952421974239963[232] = 0.0;
   out_7284952421974239963[233] = 0.0;
   out_7284952421974239963[234] = 0.0;
   out_7284952421974239963[235] = 0.0;
   out_7284952421974239963[236] = 0.0;
   out_7284952421974239963[237] = 0.0;
   out_7284952421974239963[238] = 0.0;
   out_7284952421974239963[239] = 0.0;
   out_7284952421974239963[240] = 0.0;
   out_7284952421974239963[241] = 0.0;
   out_7284952421974239963[242] = 0.0;
   out_7284952421974239963[243] = 0.0;
   out_7284952421974239963[244] = 0.0;
   out_7284952421974239963[245] = 0.0;
   out_7284952421974239963[246] = 0.0;
   out_7284952421974239963[247] = 1.0;
   out_7284952421974239963[248] = 0.0;
   out_7284952421974239963[249] = 0.0;
   out_7284952421974239963[250] = 0.0;
   out_7284952421974239963[251] = 0.0;
   out_7284952421974239963[252] = 0.0;
   out_7284952421974239963[253] = 0.0;
   out_7284952421974239963[254] = 0.0;
   out_7284952421974239963[255] = 0.0;
   out_7284952421974239963[256] = 0.0;
   out_7284952421974239963[257] = 0.0;
   out_7284952421974239963[258] = 0.0;
   out_7284952421974239963[259] = 0.0;
   out_7284952421974239963[260] = 0.0;
   out_7284952421974239963[261] = 0.0;
   out_7284952421974239963[262] = 0.0;
   out_7284952421974239963[263] = 0.0;
   out_7284952421974239963[264] = 0.0;
   out_7284952421974239963[265] = 0.0;
   out_7284952421974239963[266] = 1.0;
   out_7284952421974239963[267] = 0.0;
   out_7284952421974239963[268] = 0.0;
   out_7284952421974239963[269] = 0.0;
   out_7284952421974239963[270] = 0.0;
   out_7284952421974239963[271] = 0.0;
   out_7284952421974239963[272] = 0.0;
   out_7284952421974239963[273] = 0.0;
   out_7284952421974239963[274] = 0.0;
   out_7284952421974239963[275] = 0.0;
   out_7284952421974239963[276] = 0.0;
   out_7284952421974239963[277] = 0.0;
   out_7284952421974239963[278] = 0.0;
   out_7284952421974239963[279] = 0.0;
   out_7284952421974239963[280] = 0.0;
   out_7284952421974239963[281] = 0.0;
   out_7284952421974239963[282] = 0.0;
   out_7284952421974239963[283] = 0.0;
   out_7284952421974239963[284] = 0.0;
   out_7284952421974239963[285] = 1.0;
   out_7284952421974239963[286] = 0.0;
   out_7284952421974239963[287] = 0.0;
   out_7284952421974239963[288] = 0.0;
   out_7284952421974239963[289] = 0.0;
   out_7284952421974239963[290] = 0.0;
   out_7284952421974239963[291] = 0.0;
   out_7284952421974239963[292] = 0.0;
   out_7284952421974239963[293] = 0.0;
   out_7284952421974239963[294] = 0.0;
   out_7284952421974239963[295] = 0.0;
   out_7284952421974239963[296] = 0.0;
   out_7284952421974239963[297] = 0.0;
   out_7284952421974239963[298] = 0.0;
   out_7284952421974239963[299] = 0.0;
   out_7284952421974239963[300] = 0.0;
   out_7284952421974239963[301] = 0.0;
   out_7284952421974239963[302] = 0.0;
   out_7284952421974239963[303] = 0.0;
   out_7284952421974239963[304] = 1.0;
   out_7284952421974239963[305] = 0.0;
   out_7284952421974239963[306] = 0.0;
   out_7284952421974239963[307] = 0.0;
   out_7284952421974239963[308] = 0.0;
   out_7284952421974239963[309] = 0.0;
   out_7284952421974239963[310] = 0.0;
   out_7284952421974239963[311] = 0.0;
   out_7284952421974239963[312] = 0.0;
   out_7284952421974239963[313] = 0.0;
   out_7284952421974239963[314] = 0.0;
   out_7284952421974239963[315] = 0.0;
   out_7284952421974239963[316] = 0.0;
   out_7284952421974239963[317] = 0.0;
   out_7284952421974239963[318] = 0.0;
   out_7284952421974239963[319] = 0.0;
   out_7284952421974239963[320] = 0.0;
   out_7284952421974239963[321] = 0.0;
   out_7284952421974239963[322] = 0.0;
   out_7284952421974239963[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6622003215066724253) {
   out_6622003215066724253[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6622003215066724253[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6622003215066724253[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6622003215066724253[3] = dt*state[12] + state[3];
   out_6622003215066724253[4] = dt*state[13] + state[4];
   out_6622003215066724253[5] = dt*state[14] + state[5];
   out_6622003215066724253[6] = state[6];
   out_6622003215066724253[7] = state[7];
   out_6622003215066724253[8] = state[8];
   out_6622003215066724253[9] = state[9];
   out_6622003215066724253[10] = state[10];
   out_6622003215066724253[11] = state[11];
   out_6622003215066724253[12] = state[12];
   out_6622003215066724253[13] = state[13];
   out_6622003215066724253[14] = state[14];
   out_6622003215066724253[15] = state[15];
   out_6622003215066724253[16] = state[16];
   out_6622003215066724253[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1840911802440980771) {
   out_1840911802440980771[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1840911802440980771[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1840911802440980771[2] = 0;
   out_1840911802440980771[3] = 0;
   out_1840911802440980771[4] = 0;
   out_1840911802440980771[5] = 0;
   out_1840911802440980771[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1840911802440980771[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1840911802440980771[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1840911802440980771[9] = 0;
   out_1840911802440980771[10] = 0;
   out_1840911802440980771[11] = 0;
   out_1840911802440980771[12] = 0;
   out_1840911802440980771[13] = 0;
   out_1840911802440980771[14] = 0;
   out_1840911802440980771[15] = 0;
   out_1840911802440980771[16] = 0;
   out_1840911802440980771[17] = 0;
   out_1840911802440980771[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1840911802440980771[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1840911802440980771[20] = 0;
   out_1840911802440980771[21] = 0;
   out_1840911802440980771[22] = 0;
   out_1840911802440980771[23] = 0;
   out_1840911802440980771[24] = 0;
   out_1840911802440980771[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1840911802440980771[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1840911802440980771[27] = 0;
   out_1840911802440980771[28] = 0;
   out_1840911802440980771[29] = 0;
   out_1840911802440980771[30] = 0;
   out_1840911802440980771[31] = 0;
   out_1840911802440980771[32] = 0;
   out_1840911802440980771[33] = 0;
   out_1840911802440980771[34] = 0;
   out_1840911802440980771[35] = 0;
   out_1840911802440980771[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1840911802440980771[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1840911802440980771[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1840911802440980771[39] = 0;
   out_1840911802440980771[40] = 0;
   out_1840911802440980771[41] = 0;
   out_1840911802440980771[42] = 0;
   out_1840911802440980771[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1840911802440980771[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1840911802440980771[45] = 0;
   out_1840911802440980771[46] = 0;
   out_1840911802440980771[47] = 0;
   out_1840911802440980771[48] = 0;
   out_1840911802440980771[49] = 0;
   out_1840911802440980771[50] = 0;
   out_1840911802440980771[51] = 0;
   out_1840911802440980771[52] = 0;
   out_1840911802440980771[53] = 0;
   out_1840911802440980771[54] = 0;
   out_1840911802440980771[55] = 0;
   out_1840911802440980771[56] = 0;
   out_1840911802440980771[57] = 1;
   out_1840911802440980771[58] = 0;
   out_1840911802440980771[59] = 0;
   out_1840911802440980771[60] = 0;
   out_1840911802440980771[61] = 0;
   out_1840911802440980771[62] = 0;
   out_1840911802440980771[63] = 0;
   out_1840911802440980771[64] = 0;
   out_1840911802440980771[65] = 0;
   out_1840911802440980771[66] = dt;
   out_1840911802440980771[67] = 0;
   out_1840911802440980771[68] = 0;
   out_1840911802440980771[69] = 0;
   out_1840911802440980771[70] = 0;
   out_1840911802440980771[71] = 0;
   out_1840911802440980771[72] = 0;
   out_1840911802440980771[73] = 0;
   out_1840911802440980771[74] = 0;
   out_1840911802440980771[75] = 0;
   out_1840911802440980771[76] = 1;
   out_1840911802440980771[77] = 0;
   out_1840911802440980771[78] = 0;
   out_1840911802440980771[79] = 0;
   out_1840911802440980771[80] = 0;
   out_1840911802440980771[81] = 0;
   out_1840911802440980771[82] = 0;
   out_1840911802440980771[83] = 0;
   out_1840911802440980771[84] = 0;
   out_1840911802440980771[85] = dt;
   out_1840911802440980771[86] = 0;
   out_1840911802440980771[87] = 0;
   out_1840911802440980771[88] = 0;
   out_1840911802440980771[89] = 0;
   out_1840911802440980771[90] = 0;
   out_1840911802440980771[91] = 0;
   out_1840911802440980771[92] = 0;
   out_1840911802440980771[93] = 0;
   out_1840911802440980771[94] = 0;
   out_1840911802440980771[95] = 1;
   out_1840911802440980771[96] = 0;
   out_1840911802440980771[97] = 0;
   out_1840911802440980771[98] = 0;
   out_1840911802440980771[99] = 0;
   out_1840911802440980771[100] = 0;
   out_1840911802440980771[101] = 0;
   out_1840911802440980771[102] = 0;
   out_1840911802440980771[103] = 0;
   out_1840911802440980771[104] = dt;
   out_1840911802440980771[105] = 0;
   out_1840911802440980771[106] = 0;
   out_1840911802440980771[107] = 0;
   out_1840911802440980771[108] = 0;
   out_1840911802440980771[109] = 0;
   out_1840911802440980771[110] = 0;
   out_1840911802440980771[111] = 0;
   out_1840911802440980771[112] = 0;
   out_1840911802440980771[113] = 0;
   out_1840911802440980771[114] = 1;
   out_1840911802440980771[115] = 0;
   out_1840911802440980771[116] = 0;
   out_1840911802440980771[117] = 0;
   out_1840911802440980771[118] = 0;
   out_1840911802440980771[119] = 0;
   out_1840911802440980771[120] = 0;
   out_1840911802440980771[121] = 0;
   out_1840911802440980771[122] = 0;
   out_1840911802440980771[123] = 0;
   out_1840911802440980771[124] = 0;
   out_1840911802440980771[125] = 0;
   out_1840911802440980771[126] = 0;
   out_1840911802440980771[127] = 0;
   out_1840911802440980771[128] = 0;
   out_1840911802440980771[129] = 0;
   out_1840911802440980771[130] = 0;
   out_1840911802440980771[131] = 0;
   out_1840911802440980771[132] = 0;
   out_1840911802440980771[133] = 1;
   out_1840911802440980771[134] = 0;
   out_1840911802440980771[135] = 0;
   out_1840911802440980771[136] = 0;
   out_1840911802440980771[137] = 0;
   out_1840911802440980771[138] = 0;
   out_1840911802440980771[139] = 0;
   out_1840911802440980771[140] = 0;
   out_1840911802440980771[141] = 0;
   out_1840911802440980771[142] = 0;
   out_1840911802440980771[143] = 0;
   out_1840911802440980771[144] = 0;
   out_1840911802440980771[145] = 0;
   out_1840911802440980771[146] = 0;
   out_1840911802440980771[147] = 0;
   out_1840911802440980771[148] = 0;
   out_1840911802440980771[149] = 0;
   out_1840911802440980771[150] = 0;
   out_1840911802440980771[151] = 0;
   out_1840911802440980771[152] = 1;
   out_1840911802440980771[153] = 0;
   out_1840911802440980771[154] = 0;
   out_1840911802440980771[155] = 0;
   out_1840911802440980771[156] = 0;
   out_1840911802440980771[157] = 0;
   out_1840911802440980771[158] = 0;
   out_1840911802440980771[159] = 0;
   out_1840911802440980771[160] = 0;
   out_1840911802440980771[161] = 0;
   out_1840911802440980771[162] = 0;
   out_1840911802440980771[163] = 0;
   out_1840911802440980771[164] = 0;
   out_1840911802440980771[165] = 0;
   out_1840911802440980771[166] = 0;
   out_1840911802440980771[167] = 0;
   out_1840911802440980771[168] = 0;
   out_1840911802440980771[169] = 0;
   out_1840911802440980771[170] = 0;
   out_1840911802440980771[171] = 1;
   out_1840911802440980771[172] = 0;
   out_1840911802440980771[173] = 0;
   out_1840911802440980771[174] = 0;
   out_1840911802440980771[175] = 0;
   out_1840911802440980771[176] = 0;
   out_1840911802440980771[177] = 0;
   out_1840911802440980771[178] = 0;
   out_1840911802440980771[179] = 0;
   out_1840911802440980771[180] = 0;
   out_1840911802440980771[181] = 0;
   out_1840911802440980771[182] = 0;
   out_1840911802440980771[183] = 0;
   out_1840911802440980771[184] = 0;
   out_1840911802440980771[185] = 0;
   out_1840911802440980771[186] = 0;
   out_1840911802440980771[187] = 0;
   out_1840911802440980771[188] = 0;
   out_1840911802440980771[189] = 0;
   out_1840911802440980771[190] = 1;
   out_1840911802440980771[191] = 0;
   out_1840911802440980771[192] = 0;
   out_1840911802440980771[193] = 0;
   out_1840911802440980771[194] = 0;
   out_1840911802440980771[195] = 0;
   out_1840911802440980771[196] = 0;
   out_1840911802440980771[197] = 0;
   out_1840911802440980771[198] = 0;
   out_1840911802440980771[199] = 0;
   out_1840911802440980771[200] = 0;
   out_1840911802440980771[201] = 0;
   out_1840911802440980771[202] = 0;
   out_1840911802440980771[203] = 0;
   out_1840911802440980771[204] = 0;
   out_1840911802440980771[205] = 0;
   out_1840911802440980771[206] = 0;
   out_1840911802440980771[207] = 0;
   out_1840911802440980771[208] = 0;
   out_1840911802440980771[209] = 1;
   out_1840911802440980771[210] = 0;
   out_1840911802440980771[211] = 0;
   out_1840911802440980771[212] = 0;
   out_1840911802440980771[213] = 0;
   out_1840911802440980771[214] = 0;
   out_1840911802440980771[215] = 0;
   out_1840911802440980771[216] = 0;
   out_1840911802440980771[217] = 0;
   out_1840911802440980771[218] = 0;
   out_1840911802440980771[219] = 0;
   out_1840911802440980771[220] = 0;
   out_1840911802440980771[221] = 0;
   out_1840911802440980771[222] = 0;
   out_1840911802440980771[223] = 0;
   out_1840911802440980771[224] = 0;
   out_1840911802440980771[225] = 0;
   out_1840911802440980771[226] = 0;
   out_1840911802440980771[227] = 0;
   out_1840911802440980771[228] = 1;
   out_1840911802440980771[229] = 0;
   out_1840911802440980771[230] = 0;
   out_1840911802440980771[231] = 0;
   out_1840911802440980771[232] = 0;
   out_1840911802440980771[233] = 0;
   out_1840911802440980771[234] = 0;
   out_1840911802440980771[235] = 0;
   out_1840911802440980771[236] = 0;
   out_1840911802440980771[237] = 0;
   out_1840911802440980771[238] = 0;
   out_1840911802440980771[239] = 0;
   out_1840911802440980771[240] = 0;
   out_1840911802440980771[241] = 0;
   out_1840911802440980771[242] = 0;
   out_1840911802440980771[243] = 0;
   out_1840911802440980771[244] = 0;
   out_1840911802440980771[245] = 0;
   out_1840911802440980771[246] = 0;
   out_1840911802440980771[247] = 1;
   out_1840911802440980771[248] = 0;
   out_1840911802440980771[249] = 0;
   out_1840911802440980771[250] = 0;
   out_1840911802440980771[251] = 0;
   out_1840911802440980771[252] = 0;
   out_1840911802440980771[253] = 0;
   out_1840911802440980771[254] = 0;
   out_1840911802440980771[255] = 0;
   out_1840911802440980771[256] = 0;
   out_1840911802440980771[257] = 0;
   out_1840911802440980771[258] = 0;
   out_1840911802440980771[259] = 0;
   out_1840911802440980771[260] = 0;
   out_1840911802440980771[261] = 0;
   out_1840911802440980771[262] = 0;
   out_1840911802440980771[263] = 0;
   out_1840911802440980771[264] = 0;
   out_1840911802440980771[265] = 0;
   out_1840911802440980771[266] = 1;
   out_1840911802440980771[267] = 0;
   out_1840911802440980771[268] = 0;
   out_1840911802440980771[269] = 0;
   out_1840911802440980771[270] = 0;
   out_1840911802440980771[271] = 0;
   out_1840911802440980771[272] = 0;
   out_1840911802440980771[273] = 0;
   out_1840911802440980771[274] = 0;
   out_1840911802440980771[275] = 0;
   out_1840911802440980771[276] = 0;
   out_1840911802440980771[277] = 0;
   out_1840911802440980771[278] = 0;
   out_1840911802440980771[279] = 0;
   out_1840911802440980771[280] = 0;
   out_1840911802440980771[281] = 0;
   out_1840911802440980771[282] = 0;
   out_1840911802440980771[283] = 0;
   out_1840911802440980771[284] = 0;
   out_1840911802440980771[285] = 1;
   out_1840911802440980771[286] = 0;
   out_1840911802440980771[287] = 0;
   out_1840911802440980771[288] = 0;
   out_1840911802440980771[289] = 0;
   out_1840911802440980771[290] = 0;
   out_1840911802440980771[291] = 0;
   out_1840911802440980771[292] = 0;
   out_1840911802440980771[293] = 0;
   out_1840911802440980771[294] = 0;
   out_1840911802440980771[295] = 0;
   out_1840911802440980771[296] = 0;
   out_1840911802440980771[297] = 0;
   out_1840911802440980771[298] = 0;
   out_1840911802440980771[299] = 0;
   out_1840911802440980771[300] = 0;
   out_1840911802440980771[301] = 0;
   out_1840911802440980771[302] = 0;
   out_1840911802440980771[303] = 0;
   out_1840911802440980771[304] = 1;
   out_1840911802440980771[305] = 0;
   out_1840911802440980771[306] = 0;
   out_1840911802440980771[307] = 0;
   out_1840911802440980771[308] = 0;
   out_1840911802440980771[309] = 0;
   out_1840911802440980771[310] = 0;
   out_1840911802440980771[311] = 0;
   out_1840911802440980771[312] = 0;
   out_1840911802440980771[313] = 0;
   out_1840911802440980771[314] = 0;
   out_1840911802440980771[315] = 0;
   out_1840911802440980771[316] = 0;
   out_1840911802440980771[317] = 0;
   out_1840911802440980771[318] = 0;
   out_1840911802440980771[319] = 0;
   out_1840911802440980771[320] = 0;
   out_1840911802440980771[321] = 0;
   out_1840911802440980771[322] = 0;
   out_1840911802440980771[323] = 1;
}
void h_4(double *state, double *unused, double *out_7825755614403114749) {
   out_7825755614403114749[0] = state[6] + state[9];
   out_7825755614403114749[1] = state[7] + state[10];
   out_7825755614403114749[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2423595419652322515) {
   out_2423595419652322515[0] = 0;
   out_2423595419652322515[1] = 0;
   out_2423595419652322515[2] = 0;
   out_2423595419652322515[3] = 0;
   out_2423595419652322515[4] = 0;
   out_2423595419652322515[5] = 0;
   out_2423595419652322515[6] = 1;
   out_2423595419652322515[7] = 0;
   out_2423595419652322515[8] = 0;
   out_2423595419652322515[9] = 1;
   out_2423595419652322515[10] = 0;
   out_2423595419652322515[11] = 0;
   out_2423595419652322515[12] = 0;
   out_2423595419652322515[13] = 0;
   out_2423595419652322515[14] = 0;
   out_2423595419652322515[15] = 0;
   out_2423595419652322515[16] = 0;
   out_2423595419652322515[17] = 0;
   out_2423595419652322515[18] = 0;
   out_2423595419652322515[19] = 0;
   out_2423595419652322515[20] = 0;
   out_2423595419652322515[21] = 0;
   out_2423595419652322515[22] = 0;
   out_2423595419652322515[23] = 0;
   out_2423595419652322515[24] = 0;
   out_2423595419652322515[25] = 1;
   out_2423595419652322515[26] = 0;
   out_2423595419652322515[27] = 0;
   out_2423595419652322515[28] = 1;
   out_2423595419652322515[29] = 0;
   out_2423595419652322515[30] = 0;
   out_2423595419652322515[31] = 0;
   out_2423595419652322515[32] = 0;
   out_2423595419652322515[33] = 0;
   out_2423595419652322515[34] = 0;
   out_2423595419652322515[35] = 0;
   out_2423595419652322515[36] = 0;
   out_2423595419652322515[37] = 0;
   out_2423595419652322515[38] = 0;
   out_2423595419652322515[39] = 0;
   out_2423595419652322515[40] = 0;
   out_2423595419652322515[41] = 0;
   out_2423595419652322515[42] = 0;
   out_2423595419652322515[43] = 0;
   out_2423595419652322515[44] = 1;
   out_2423595419652322515[45] = 0;
   out_2423595419652322515[46] = 0;
   out_2423595419652322515[47] = 1;
   out_2423595419652322515[48] = 0;
   out_2423595419652322515[49] = 0;
   out_2423595419652322515[50] = 0;
   out_2423595419652322515[51] = 0;
   out_2423595419652322515[52] = 0;
   out_2423595419652322515[53] = 0;
}
void h_10(double *state, double *unused, double *out_4958115583477493940) {
   out_4958115583477493940[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4958115583477493940[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4958115583477493940[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3173840665802663140) {
   out_3173840665802663140[0] = 0;
   out_3173840665802663140[1] = 9.8100000000000005*cos(state[1]);
   out_3173840665802663140[2] = 0;
   out_3173840665802663140[3] = 0;
   out_3173840665802663140[4] = -state[8];
   out_3173840665802663140[5] = state[7];
   out_3173840665802663140[6] = 0;
   out_3173840665802663140[7] = state[5];
   out_3173840665802663140[8] = -state[4];
   out_3173840665802663140[9] = 0;
   out_3173840665802663140[10] = 0;
   out_3173840665802663140[11] = 0;
   out_3173840665802663140[12] = 1;
   out_3173840665802663140[13] = 0;
   out_3173840665802663140[14] = 0;
   out_3173840665802663140[15] = 1;
   out_3173840665802663140[16] = 0;
   out_3173840665802663140[17] = 0;
   out_3173840665802663140[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3173840665802663140[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3173840665802663140[20] = 0;
   out_3173840665802663140[21] = state[8];
   out_3173840665802663140[22] = 0;
   out_3173840665802663140[23] = -state[6];
   out_3173840665802663140[24] = -state[5];
   out_3173840665802663140[25] = 0;
   out_3173840665802663140[26] = state[3];
   out_3173840665802663140[27] = 0;
   out_3173840665802663140[28] = 0;
   out_3173840665802663140[29] = 0;
   out_3173840665802663140[30] = 0;
   out_3173840665802663140[31] = 1;
   out_3173840665802663140[32] = 0;
   out_3173840665802663140[33] = 0;
   out_3173840665802663140[34] = 1;
   out_3173840665802663140[35] = 0;
   out_3173840665802663140[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3173840665802663140[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3173840665802663140[38] = 0;
   out_3173840665802663140[39] = -state[7];
   out_3173840665802663140[40] = state[6];
   out_3173840665802663140[41] = 0;
   out_3173840665802663140[42] = state[4];
   out_3173840665802663140[43] = -state[3];
   out_3173840665802663140[44] = 0;
   out_3173840665802663140[45] = 0;
   out_3173840665802663140[46] = 0;
   out_3173840665802663140[47] = 0;
   out_3173840665802663140[48] = 0;
   out_3173840665802663140[49] = 0;
   out_3173840665802663140[50] = 1;
   out_3173840665802663140[51] = 0;
   out_3173840665802663140[52] = 0;
   out_3173840665802663140[53] = 1;
}
void h_13(double *state, double *unused, double *out_5148403869590084901) {
   out_5148403869590084901[0] = state[3];
   out_5148403869590084901[1] = state[4];
   out_5148403869590084901[2] = state[5];
}
void H_13(double *state, double *unused, double *out_788678405680010286) {
   out_788678405680010286[0] = 0;
   out_788678405680010286[1] = 0;
   out_788678405680010286[2] = 0;
   out_788678405680010286[3] = 1;
   out_788678405680010286[4] = 0;
   out_788678405680010286[5] = 0;
   out_788678405680010286[6] = 0;
   out_788678405680010286[7] = 0;
   out_788678405680010286[8] = 0;
   out_788678405680010286[9] = 0;
   out_788678405680010286[10] = 0;
   out_788678405680010286[11] = 0;
   out_788678405680010286[12] = 0;
   out_788678405680010286[13] = 0;
   out_788678405680010286[14] = 0;
   out_788678405680010286[15] = 0;
   out_788678405680010286[16] = 0;
   out_788678405680010286[17] = 0;
   out_788678405680010286[18] = 0;
   out_788678405680010286[19] = 0;
   out_788678405680010286[20] = 0;
   out_788678405680010286[21] = 0;
   out_788678405680010286[22] = 1;
   out_788678405680010286[23] = 0;
   out_788678405680010286[24] = 0;
   out_788678405680010286[25] = 0;
   out_788678405680010286[26] = 0;
   out_788678405680010286[27] = 0;
   out_788678405680010286[28] = 0;
   out_788678405680010286[29] = 0;
   out_788678405680010286[30] = 0;
   out_788678405680010286[31] = 0;
   out_788678405680010286[32] = 0;
   out_788678405680010286[33] = 0;
   out_788678405680010286[34] = 0;
   out_788678405680010286[35] = 0;
   out_788678405680010286[36] = 0;
   out_788678405680010286[37] = 0;
   out_788678405680010286[38] = 0;
   out_788678405680010286[39] = 0;
   out_788678405680010286[40] = 0;
   out_788678405680010286[41] = 1;
   out_788678405680010286[42] = 0;
   out_788678405680010286[43] = 0;
   out_788678405680010286[44] = 0;
   out_788678405680010286[45] = 0;
   out_788678405680010286[46] = 0;
   out_788678405680010286[47] = 0;
   out_788678405680010286[48] = 0;
   out_788678405680010286[49] = 0;
   out_788678405680010286[50] = 0;
   out_788678405680010286[51] = 0;
   out_788678405680010286[52] = 0;
   out_788678405680010286[53] = 0;
}
void h_14(double *state, double *unused, double *out_6092356580819784195) {
   out_6092356580819784195[0] = state[6];
   out_6092356580819784195[1] = state[7];
   out_6092356580819784195[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2858711946297206114) {
   out_2858711946297206114[0] = 0;
   out_2858711946297206114[1] = 0;
   out_2858711946297206114[2] = 0;
   out_2858711946297206114[3] = 0;
   out_2858711946297206114[4] = 0;
   out_2858711946297206114[5] = 0;
   out_2858711946297206114[6] = 1;
   out_2858711946297206114[7] = 0;
   out_2858711946297206114[8] = 0;
   out_2858711946297206114[9] = 0;
   out_2858711946297206114[10] = 0;
   out_2858711946297206114[11] = 0;
   out_2858711946297206114[12] = 0;
   out_2858711946297206114[13] = 0;
   out_2858711946297206114[14] = 0;
   out_2858711946297206114[15] = 0;
   out_2858711946297206114[16] = 0;
   out_2858711946297206114[17] = 0;
   out_2858711946297206114[18] = 0;
   out_2858711946297206114[19] = 0;
   out_2858711946297206114[20] = 0;
   out_2858711946297206114[21] = 0;
   out_2858711946297206114[22] = 0;
   out_2858711946297206114[23] = 0;
   out_2858711946297206114[24] = 0;
   out_2858711946297206114[25] = 1;
   out_2858711946297206114[26] = 0;
   out_2858711946297206114[27] = 0;
   out_2858711946297206114[28] = 0;
   out_2858711946297206114[29] = 0;
   out_2858711946297206114[30] = 0;
   out_2858711946297206114[31] = 0;
   out_2858711946297206114[32] = 0;
   out_2858711946297206114[33] = 0;
   out_2858711946297206114[34] = 0;
   out_2858711946297206114[35] = 0;
   out_2858711946297206114[36] = 0;
   out_2858711946297206114[37] = 0;
   out_2858711946297206114[38] = 0;
   out_2858711946297206114[39] = 0;
   out_2858711946297206114[40] = 0;
   out_2858711946297206114[41] = 0;
   out_2858711946297206114[42] = 0;
   out_2858711946297206114[43] = 0;
   out_2858711946297206114[44] = 1;
   out_2858711946297206114[45] = 0;
   out_2858711946297206114[46] = 0;
   out_2858711946297206114[47] = 0;
   out_2858711946297206114[48] = 0;
   out_2858711946297206114[49] = 0;
   out_2858711946297206114[50] = 0;
   out_2858711946297206114[51] = 0;
   out_2858711946297206114[52] = 0;
   out_2858711946297206114[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3178519467950773499) {
  err_fun(nom_x, delta_x, out_3178519467950773499);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4057631928554815578) {
  inv_err_fun(nom_x, true_x, out_4057631928554815578);
}
void pose_H_mod_fun(double *state, double *out_7284952421974239963) {
  H_mod_fun(state, out_7284952421974239963);
}
void pose_f_fun(double *state, double dt, double *out_6622003215066724253) {
  f_fun(state,  dt, out_6622003215066724253);
}
void pose_F_fun(double *state, double dt, double *out_1840911802440980771) {
  F_fun(state,  dt, out_1840911802440980771);
}
void pose_h_4(double *state, double *unused, double *out_7825755614403114749) {
  h_4(state, unused, out_7825755614403114749);
}
void pose_H_4(double *state, double *unused, double *out_2423595419652322515) {
  H_4(state, unused, out_2423595419652322515);
}
void pose_h_10(double *state, double *unused, double *out_4958115583477493940) {
  h_10(state, unused, out_4958115583477493940);
}
void pose_H_10(double *state, double *unused, double *out_3173840665802663140) {
  H_10(state, unused, out_3173840665802663140);
}
void pose_h_13(double *state, double *unused, double *out_5148403869590084901) {
  h_13(state, unused, out_5148403869590084901);
}
void pose_H_13(double *state, double *unused, double *out_788678405680010286) {
  H_13(state, unused, out_788678405680010286);
}
void pose_h_14(double *state, double *unused, double *out_6092356580819784195) {
  h_14(state, unused, out_6092356580819784195);
}
void pose_H_14(double *state, double *unused, double *out_2858711946297206114) {
  H_14(state, unused, out_2858711946297206114);
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

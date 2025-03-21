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
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7933576979540076638) {
   out_7933576979540076638[0] = delta_x[0] + nom_x[0];
   out_7933576979540076638[1] = delta_x[1] + nom_x[1];
   out_7933576979540076638[2] = delta_x[2] + nom_x[2];
   out_7933576979540076638[3] = delta_x[3] + nom_x[3];
   out_7933576979540076638[4] = delta_x[4] + nom_x[4];
   out_7933576979540076638[5] = delta_x[5] + nom_x[5];
   out_7933576979540076638[6] = delta_x[6] + nom_x[6];
   out_7933576979540076638[7] = delta_x[7] + nom_x[7];
   out_7933576979540076638[8] = delta_x[8] + nom_x[8];
   out_7933576979540076638[9] = delta_x[9] + nom_x[9];
   out_7933576979540076638[10] = delta_x[10] + nom_x[10];
   out_7933576979540076638[11] = delta_x[11] + nom_x[11];
   out_7933576979540076638[12] = delta_x[12] + nom_x[12];
   out_7933576979540076638[13] = delta_x[13] + nom_x[13];
   out_7933576979540076638[14] = delta_x[14] + nom_x[14];
   out_7933576979540076638[15] = delta_x[15] + nom_x[15];
   out_7933576979540076638[16] = delta_x[16] + nom_x[16];
   out_7933576979540076638[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5065143061833041119) {
   out_5065143061833041119[0] = -nom_x[0] + true_x[0];
   out_5065143061833041119[1] = -nom_x[1] + true_x[1];
   out_5065143061833041119[2] = -nom_x[2] + true_x[2];
   out_5065143061833041119[3] = -nom_x[3] + true_x[3];
   out_5065143061833041119[4] = -nom_x[4] + true_x[4];
   out_5065143061833041119[5] = -nom_x[5] + true_x[5];
   out_5065143061833041119[6] = -nom_x[6] + true_x[6];
   out_5065143061833041119[7] = -nom_x[7] + true_x[7];
   out_5065143061833041119[8] = -nom_x[8] + true_x[8];
   out_5065143061833041119[9] = -nom_x[9] + true_x[9];
   out_5065143061833041119[10] = -nom_x[10] + true_x[10];
   out_5065143061833041119[11] = -nom_x[11] + true_x[11];
   out_5065143061833041119[12] = -nom_x[12] + true_x[12];
   out_5065143061833041119[13] = -nom_x[13] + true_x[13];
   out_5065143061833041119[14] = -nom_x[14] + true_x[14];
   out_5065143061833041119[15] = -nom_x[15] + true_x[15];
   out_5065143061833041119[16] = -nom_x[16] + true_x[16];
   out_5065143061833041119[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4406180249320939490) {
   out_4406180249320939490[0] = 1.0;
   out_4406180249320939490[1] = 0.0;
   out_4406180249320939490[2] = 0.0;
   out_4406180249320939490[3] = 0.0;
   out_4406180249320939490[4] = 0.0;
   out_4406180249320939490[5] = 0.0;
   out_4406180249320939490[6] = 0.0;
   out_4406180249320939490[7] = 0.0;
   out_4406180249320939490[8] = 0.0;
   out_4406180249320939490[9] = 0.0;
   out_4406180249320939490[10] = 0.0;
   out_4406180249320939490[11] = 0.0;
   out_4406180249320939490[12] = 0.0;
   out_4406180249320939490[13] = 0.0;
   out_4406180249320939490[14] = 0.0;
   out_4406180249320939490[15] = 0.0;
   out_4406180249320939490[16] = 0.0;
   out_4406180249320939490[17] = 0.0;
   out_4406180249320939490[18] = 0.0;
   out_4406180249320939490[19] = 1.0;
   out_4406180249320939490[20] = 0.0;
   out_4406180249320939490[21] = 0.0;
   out_4406180249320939490[22] = 0.0;
   out_4406180249320939490[23] = 0.0;
   out_4406180249320939490[24] = 0.0;
   out_4406180249320939490[25] = 0.0;
   out_4406180249320939490[26] = 0.0;
   out_4406180249320939490[27] = 0.0;
   out_4406180249320939490[28] = 0.0;
   out_4406180249320939490[29] = 0.0;
   out_4406180249320939490[30] = 0.0;
   out_4406180249320939490[31] = 0.0;
   out_4406180249320939490[32] = 0.0;
   out_4406180249320939490[33] = 0.0;
   out_4406180249320939490[34] = 0.0;
   out_4406180249320939490[35] = 0.0;
   out_4406180249320939490[36] = 0.0;
   out_4406180249320939490[37] = 0.0;
   out_4406180249320939490[38] = 1.0;
   out_4406180249320939490[39] = 0.0;
   out_4406180249320939490[40] = 0.0;
   out_4406180249320939490[41] = 0.0;
   out_4406180249320939490[42] = 0.0;
   out_4406180249320939490[43] = 0.0;
   out_4406180249320939490[44] = 0.0;
   out_4406180249320939490[45] = 0.0;
   out_4406180249320939490[46] = 0.0;
   out_4406180249320939490[47] = 0.0;
   out_4406180249320939490[48] = 0.0;
   out_4406180249320939490[49] = 0.0;
   out_4406180249320939490[50] = 0.0;
   out_4406180249320939490[51] = 0.0;
   out_4406180249320939490[52] = 0.0;
   out_4406180249320939490[53] = 0.0;
   out_4406180249320939490[54] = 0.0;
   out_4406180249320939490[55] = 0.0;
   out_4406180249320939490[56] = 0.0;
   out_4406180249320939490[57] = 1.0;
   out_4406180249320939490[58] = 0.0;
   out_4406180249320939490[59] = 0.0;
   out_4406180249320939490[60] = 0.0;
   out_4406180249320939490[61] = 0.0;
   out_4406180249320939490[62] = 0.0;
   out_4406180249320939490[63] = 0.0;
   out_4406180249320939490[64] = 0.0;
   out_4406180249320939490[65] = 0.0;
   out_4406180249320939490[66] = 0.0;
   out_4406180249320939490[67] = 0.0;
   out_4406180249320939490[68] = 0.0;
   out_4406180249320939490[69] = 0.0;
   out_4406180249320939490[70] = 0.0;
   out_4406180249320939490[71] = 0.0;
   out_4406180249320939490[72] = 0.0;
   out_4406180249320939490[73] = 0.0;
   out_4406180249320939490[74] = 0.0;
   out_4406180249320939490[75] = 0.0;
   out_4406180249320939490[76] = 1.0;
   out_4406180249320939490[77] = 0.0;
   out_4406180249320939490[78] = 0.0;
   out_4406180249320939490[79] = 0.0;
   out_4406180249320939490[80] = 0.0;
   out_4406180249320939490[81] = 0.0;
   out_4406180249320939490[82] = 0.0;
   out_4406180249320939490[83] = 0.0;
   out_4406180249320939490[84] = 0.0;
   out_4406180249320939490[85] = 0.0;
   out_4406180249320939490[86] = 0.0;
   out_4406180249320939490[87] = 0.0;
   out_4406180249320939490[88] = 0.0;
   out_4406180249320939490[89] = 0.0;
   out_4406180249320939490[90] = 0.0;
   out_4406180249320939490[91] = 0.0;
   out_4406180249320939490[92] = 0.0;
   out_4406180249320939490[93] = 0.0;
   out_4406180249320939490[94] = 0.0;
   out_4406180249320939490[95] = 1.0;
   out_4406180249320939490[96] = 0.0;
   out_4406180249320939490[97] = 0.0;
   out_4406180249320939490[98] = 0.0;
   out_4406180249320939490[99] = 0.0;
   out_4406180249320939490[100] = 0.0;
   out_4406180249320939490[101] = 0.0;
   out_4406180249320939490[102] = 0.0;
   out_4406180249320939490[103] = 0.0;
   out_4406180249320939490[104] = 0.0;
   out_4406180249320939490[105] = 0.0;
   out_4406180249320939490[106] = 0.0;
   out_4406180249320939490[107] = 0.0;
   out_4406180249320939490[108] = 0.0;
   out_4406180249320939490[109] = 0.0;
   out_4406180249320939490[110] = 0.0;
   out_4406180249320939490[111] = 0.0;
   out_4406180249320939490[112] = 0.0;
   out_4406180249320939490[113] = 0.0;
   out_4406180249320939490[114] = 1.0;
   out_4406180249320939490[115] = 0.0;
   out_4406180249320939490[116] = 0.0;
   out_4406180249320939490[117] = 0.0;
   out_4406180249320939490[118] = 0.0;
   out_4406180249320939490[119] = 0.0;
   out_4406180249320939490[120] = 0.0;
   out_4406180249320939490[121] = 0.0;
   out_4406180249320939490[122] = 0.0;
   out_4406180249320939490[123] = 0.0;
   out_4406180249320939490[124] = 0.0;
   out_4406180249320939490[125] = 0.0;
   out_4406180249320939490[126] = 0.0;
   out_4406180249320939490[127] = 0.0;
   out_4406180249320939490[128] = 0.0;
   out_4406180249320939490[129] = 0.0;
   out_4406180249320939490[130] = 0.0;
   out_4406180249320939490[131] = 0.0;
   out_4406180249320939490[132] = 0.0;
   out_4406180249320939490[133] = 1.0;
   out_4406180249320939490[134] = 0.0;
   out_4406180249320939490[135] = 0.0;
   out_4406180249320939490[136] = 0.0;
   out_4406180249320939490[137] = 0.0;
   out_4406180249320939490[138] = 0.0;
   out_4406180249320939490[139] = 0.0;
   out_4406180249320939490[140] = 0.0;
   out_4406180249320939490[141] = 0.0;
   out_4406180249320939490[142] = 0.0;
   out_4406180249320939490[143] = 0.0;
   out_4406180249320939490[144] = 0.0;
   out_4406180249320939490[145] = 0.0;
   out_4406180249320939490[146] = 0.0;
   out_4406180249320939490[147] = 0.0;
   out_4406180249320939490[148] = 0.0;
   out_4406180249320939490[149] = 0.0;
   out_4406180249320939490[150] = 0.0;
   out_4406180249320939490[151] = 0.0;
   out_4406180249320939490[152] = 1.0;
   out_4406180249320939490[153] = 0.0;
   out_4406180249320939490[154] = 0.0;
   out_4406180249320939490[155] = 0.0;
   out_4406180249320939490[156] = 0.0;
   out_4406180249320939490[157] = 0.0;
   out_4406180249320939490[158] = 0.0;
   out_4406180249320939490[159] = 0.0;
   out_4406180249320939490[160] = 0.0;
   out_4406180249320939490[161] = 0.0;
   out_4406180249320939490[162] = 0.0;
   out_4406180249320939490[163] = 0.0;
   out_4406180249320939490[164] = 0.0;
   out_4406180249320939490[165] = 0.0;
   out_4406180249320939490[166] = 0.0;
   out_4406180249320939490[167] = 0.0;
   out_4406180249320939490[168] = 0.0;
   out_4406180249320939490[169] = 0.0;
   out_4406180249320939490[170] = 0.0;
   out_4406180249320939490[171] = 1.0;
   out_4406180249320939490[172] = 0.0;
   out_4406180249320939490[173] = 0.0;
   out_4406180249320939490[174] = 0.0;
   out_4406180249320939490[175] = 0.0;
   out_4406180249320939490[176] = 0.0;
   out_4406180249320939490[177] = 0.0;
   out_4406180249320939490[178] = 0.0;
   out_4406180249320939490[179] = 0.0;
   out_4406180249320939490[180] = 0.0;
   out_4406180249320939490[181] = 0.0;
   out_4406180249320939490[182] = 0.0;
   out_4406180249320939490[183] = 0.0;
   out_4406180249320939490[184] = 0.0;
   out_4406180249320939490[185] = 0.0;
   out_4406180249320939490[186] = 0.0;
   out_4406180249320939490[187] = 0.0;
   out_4406180249320939490[188] = 0.0;
   out_4406180249320939490[189] = 0.0;
   out_4406180249320939490[190] = 1.0;
   out_4406180249320939490[191] = 0.0;
   out_4406180249320939490[192] = 0.0;
   out_4406180249320939490[193] = 0.0;
   out_4406180249320939490[194] = 0.0;
   out_4406180249320939490[195] = 0.0;
   out_4406180249320939490[196] = 0.0;
   out_4406180249320939490[197] = 0.0;
   out_4406180249320939490[198] = 0.0;
   out_4406180249320939490[199] = 0.0;
   out_4406180249320939490[200] = 0.0;
   out_4406180249320939490[201] = 0.0;
   out_4406180249320939490[202] = 0.0;
   out_4406180249320939490[203] = 0.0;
   out_4406180249320939490[204] = 0.0;
   out_4406180249320939490[205] = 0.0;
   out_4406180249320939490[206] = 0.0;
   out_4406180249320939490[207] = 0.0;
   out_4406180249320939490[208] = 0.0;
   out_4406180249320939490[209] = 1.0;
   out_4406180249320939490[210] = 0.0;
   out_4406180249320939490[211] = 0.0;
   out_4406180249320939490[212] = 0.0;
   out_4406180249320939490[213] = 0.0;
   out_4406180249320939490[214] = 0.0;
   out_4406180249320939490[215] = 0.0;
   out_4406180249320939490[216] = 0.0;
   out_4406180249320939490[217] = 0.0;
   out_4406180249320939490[218] = 0.0;
   out_4406180249320939490[219] = 0.0;
   out_4406180249320939490[220] = 0.0;
   out_4406180249320939490[221] = 0.0;
   out_4406180249320939490[222] = 0.0;
   out_4406180249320939490[223] = 0.0;
   out_4406180249320939490[224] = 0.0;
   out_4406180249320939490[225] = 0.0;
   out_4406180249320939490[226] = 0.0;
   out_4406180249320939490[227] = 0.0;
   out_4406180249320939490[228] = 1.0;
   out_4406180249320939490[229] = 0.0;
   out_4406180249320939490[230] = 0.0;
   out_4406180249320939490[231] = 0.0;
   out_4406180249320939490[232] = 0.0;
   out_4406180249320939490[233] = 0.0;
   out_4406180249320939490[234] = 0.0;
   out_4406180249320939490[235] = 0.0;
   out_4406180249320939490[236] = 0.0;
   out_4406180249320939490[237] = 0.0;
   out_4406180249320939490[238] = 0.0;
   out_4406180249320939490[239] = 0.0;
   out_4406180249320939490[240] = 0.0;
   out_4406180249320939490[241] = 0.0;
   out_4406180249320939490[242] = 0.0;
   out_4406180249320939490[243] = 0.0;
   out_4406180249320939490[244] = 0.0;
   out_4406180249320939490[245] = 0.0;
   out_4406180249320939490[246] = 0.0;
   out_4406180249320939490[247] = 1.0;
   out_4406180249320939490[248] = 0.0;
   out_4406180249320939490[249] = 0.0;
   out_4406180249320939490[250] = 0.0;
   out_4406180249320939490[251] = 0.0;
   out_4406180249320939490[252] = 0.0;
   out_4406180249320939490[253] = 0.0;
   out_4406180249320939490[254] = 0.0;
   out_4406180249320939490[255] = 0.0;
   out_4406180249320939490[256] = 0.0;
   out_4406180249320939490[257] = 0.0;
   out_4406180249320939490[258] = 0.0;
   out_4406180249320939490[259] = 0.0;
   out_4406180249320939490[260] = 0.0;
   out_4406180249320939490[261] = 0.0;
   out_4406180249320939490[262] = 0.0;
   out_4406180249320939490[263] = 0.0;
   out_4406180249320939490[264] = 0.0;
   out_4406180249320939490[265] = 0.0;
   out_4406180249320939490[266] = 1.0;
   out_4406180249320939490[267] = 0.0;
   out_4406180249320939490[268] = 0.0;
   out_4406180249320939490[269] = 0.0;
   out_4406180249320939490[270] = 0.0;
   out_4406180249320939490[271] = 0.0;
   out_4406180249320939490[272] = 0.0;
   out_4406180249320939490[273] = 0.0;
   out_4406180249320939490[274] = 0.0;
   out_4406180249320939490[275] = 0.0;
   out_4406180249320939490[276] = 0.0;
   out_4406180249320939490[277] = 0.0;
   out_4406180249320939490[278] = 0.0;
   out_4406180249320939490[279] = 0.0;
   out_4406180249320939490[280] = 0.0;
   out_4406180249320939490[281] = 0.0;
   out_4406180249320939490[282] = 0.0;
   out_4406180249320939490[283] = 0.0;
   out_4406180249320939490[284] = 0.0;
   out_4406180249320939490[285] = 1.0;
   out_4406180249320939490[286] = 0.0;
   out_4406180249320939490[287] = 0.0;
   out_4406180249320939490[288] = 0.0;
   out_4406180249320939490[289] = 0.0;
   out_4406180249320939490[290] = 0.0;
   out_4406180249320939490[291] = 0.0;
   out_4406180249320939490[292] = 0.0;
   out_4406180249320939490[293] = 0.0;
   out_4406180249320939490[294] = 0.0;
   out_4406180249320939490[295] = 0.0;
   out_4406180249320939490[296] = 0.0;
   out_4406180249320939490[297] = 0.0;
   out_4406180249320939490[298] = 0.0;
   out_4406180249320939490[299] = 0.0;
   out_4406180249320939490[300] = 0.0;
   out_4406180249320939490[301] = 0.0;
   out_4406180249320939490[302] = 0.0;
   out_4406180249320939490[303] = 0.0;
   out_4406180249320939490[304] = 1.0;
   out_4406180249320939490[305] = 0.0;
   out_4406180249320939490[306] = 0.0;
   out_4406180249320939490[307] = 0.0;
   out_4406180249320939490[308] = 0.0;
   out_4406180249320939490[309] = 0.0;
   out_4406180249320939490[310] = 0.0;
   out_4406180249320939490[311] = 0.0;
   out_4406180249320939490[312] = 0.0;
   out_4406180249320939490[313] = 0.0;
   out_4406180249320939490[314] = 0.0;
   out_4406180249320939490[315] = 0.0;
   out_4406180249320939490[316] = 0.0;
   out_4406180249320939490[317] = 0.0;
   out_4406180249320939490[318] = 0.0;
   out_4406180249320939490[319] = 0.0;
   out_4406180249320939490[320] = 0.0;
   out_4406180249320939490[321] = 0.0;
   out_4406180249320939490[322] = 0.0;
   out_4406180249320939490[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5789342857202452257) {
   out_5789342857202452257[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5789342857202452257[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5789342857202452257[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5789342857202452257[3] = dt*state[12] + state[3];
   out_5789342857202452257[4] = dt*state[13] + state[4];
   out_5789342857202452257[5] = dt*state[14] + state[5];
   out_5789342857202452257[6] = state[6];
   out_5789342857202452257[7] = state[7];
   out_5789342857202452257[8] = state[8];
   out_5789342857202452257[9] = state[9];
   out_5789342857202452257[10] = state[10];
   out_5789342857202452257[11] = state[11];
   out_5789342857202452257[12] = state[12];
   out_5789342857202452257[13] = state[13];
   out_5789342857202452257[14] = state[14];
   out_5789342857202452257[15] = state[15];
   out_5789342857202452257[16] = state[16];
   out_5789342857202452257[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7439668240279836342) {
   out_7439668240279836342[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7439668240279836342[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7439668240279836342[2] = 0;
   out_7439668240279836342[3] = 0;
   out_7439668240279836342[4] = 0;
   out_7439668240279836342[5] = 0;
   out_7439668240279836342[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7439668240279836342[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7439668240279836342[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7439668240279836342[9] = 0;
   out_7439668240279836342[10] = 0;
   out_7439668240279836342[11] = 0;
   out_7439668240279836342[12] = 0;
   out_7439668240279836342[13] = 0;
   out_7439668240279836342[14] = 0;
   out_7439668240279836342[15] = 0;
   out_7439668240279836342[16] = 0;
   out_7439668240279836342[17] = 0;
   out_7439668240279836342[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7439668240279836342[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7439668240279836342[20] = 0;
   out_7439668240279836342[21] = 0;
   out_7439668240279836342[22] = 0;
   out_7439668240279836342[23] = 0;
   out_7439668240279836342[24] = 0;
   out_7439668240279836342[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7439668240279836342[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7439668240279836342[27] = 0;
   out_7439668240279836342[28] = 0;
   out_7439668240279836342[29] = 0;
   out_7439668240279836342[30] = 0;
   out_7439668240279836342[31] = 0;
   out_7439668240279836342[32] = 0;
   out_7439668240279836342[33] = 0;
   out_7439668240279836342[34] = 0;
   out_7439668240279836342[35] = 0;
   out_7439668240279836342[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7439668240279836342[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7439668240279836342[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7439668240279836342[39] = 0;
   out_7439668240279836342[40] = 0;
   out_7439668240279836342[41] = 0;
   out_7439668240279836342[42] = 0;
   out_7439668240279836342[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7439668240279836342[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7439668240279836342[45] = 0;
   out_7439668240279836342[46] = 0;
   out_7439668240279836342[47] = 0;
   out_7439668240279836342[48] = 0;
   out_7439668240279836342[49] = 0;
   out_7439668240279836342[50] = 0;
   out_7439668240279836342[51] = 0;
   out_7439668240279836342[52] = 0;
   out_7439668240279836342[53] = 0;
   out_7439668240279836342[54] = 0;
   out_7439668240279836342[55] = 0;
   out_7439668240279836342[56] = 0;
   out_7439668240279836342[57] = 1;
   out_7439668240279836342[58] = 0;
   out_7439668240279836342[59] = 0;
   out_7439668240279836342[60] = 0;
   out_7439668240279836342[61] = 0;
   out_7439668240279836342[62] = 0;
   out_7439668240279836342[63] = 0;
   out_7439668240279836342[64] = 0;
   out_7439668240279836342[65] = 0;
   out_7439668240279836342[66] = dt;
   out_7439668240279836342[67] = 0;
   out_7439668240279836342[68] = 0;
   out_7439668240279836342[69] = 0;
   out_7439668240279836342[70] = 0;
   out_7439668240279836342[71] = 0;
   out_7439668240279836342[72] = 0;
   out_7439668240279836342[73] = 0;
   out_7439668240279836342[74] = 0;
   out_7439668240279836342[75] = 0;
   out_7439668240279836342[76] = 1;
   out_7439668240279836342[77] = 0;
   out_7439668240279836342[78] = 0;
   out_7439668240279836342[79] = 0;
   out_7439668240279836342[80] = 0;
   out_7439668240279836342[81] = 0;
   out_7439668240279836342[82] = 0;
   out_7439668240279836342[83] = 0;
   out_7439668240279836342[84] = 0;
   out_7439668240279836342[85] = dt;
   out_7439668240279836342[86] = 0;
   out_7439668240279836342[87] = 0;
   out_7439668240279836342[88] = 0;
   out_7439668240279836342[89] = 0;
   out_7439668240279836342[90] = 0;
   out_7439668240279836342[91] = 0;
   out_7439668240279836342[92] = 0;
   out_7439668240279836342[93] = 0;
   out_7439668240279836342[94] = 0;
   out_7439668240279836342[95] = 1;
   out_7439668240279836342[96] = 0;
   out_7439668240279836342[97] = 0;
   out_7439668240279836342[98] = 0;
   out_7439668240279836342[99] = 0;
   out_7439668240279836342[100] = 0;
   out_7439668240279836342[101] = 0;
   out_7439668240279836342[102] = 0;
   out_7439668240279836342[103] = 0;
   out_7439668240279836342[104] = dt;
   out_7439668240279836342[105] = 0;
   out_7439668240279836342[106] = 0;
   out_7439668240279836342[107] = 0;
   out_7439668240279836342[108] = 0;
   out_7439668240279836342[109] = 0;
   out_7439668240279836342[110] = 0;
   out_7439668240279836342[111] = 0;
   out_7439668240279836342[112] = 0;
   out_7439668240279836342[113] = 0;
   out_7439668240279836342[114] = 1;
   out_7439668240279836342[115] = 0;
   out_7439668240279836342[116] = 0;
   out_7439668240279836342[117] = 0;
   out_7439668240279836342[118] = 0;
   out_7439668240279836342[119] = 0;
   out_7439668240279836342[120] = 0;
   out_7439668240279836342[121] = 0;
   out_7439668240279836342[122] = 0;
   out_7439668240279836342[123] = 0;
   out_7439668240279836342[124] = 0;
   out_7439668240279836342[125] = 0;
   out_7439668240279836342[126] = 0;
   out_7439668240279836342[127] = 0;
   out_7439668240279836342[128] = 0;
   out_7439668240279836342[129] = 0;
   out_7439668240279836342[130] = 0;
   out_7439668240279836342[131] = 0;
   out_7439668240279836342[132] = 0;
   out_7439668240279836342[133] = 1;
   out_7439668240279836342[134] = 0;
   out_7439668240279836342[135] = 0;
   out_7439668240279836342[136] = 0;
   out_7439668240279836342[137] = 0;
   out_7439668240279836342[138] = 0;
   out_7439668240279836342[139] = 0;
   out_7439668240279836342[140] = 0;
   out_7439668240279836342[141] = 0;
   out_7439668240279836342[142] = 0;
   out_7439668240279836342[143] = 0;
   out_7439668240279836342[144] = 0;
   out_7439668240279836342[145] = 0;
   out_7439668240279836342[146] = 0;
   out_7439668240279836342[147] = 0;
   out_7439668240279836342[148] = 0;
   out_7439668240279836342[149] = 0;
   out_7439668240279836342[150] = 0;
   out_7439668240279836342[151] = 0;
   out_7439668240279836342[152] = 1;
   out_7439668240279836342[153] = 0;
   out_7439668240279836342[154] = 0;
   out_7439668240279836342[155] = 0;
   out_7439668240279836342[156] = 0;
   out_7439668240279836342[157] = 0;
   out_7439668240279836342[158] = 0;
   out_7439668240279836342[159] = 0;
   out_7439668240279836342[160] = 0;
   out_7439668240279836342[161] = 0;
   out_7439668240279836342[162] = 0;
   out_7439668240279836342[163] = 0;
   out_7439668240279836342[164] = 0;
   out_7439668240279836342[165] = 0;
   out_7439668240279836342[166] = 0;
   out_7439668240279836342[167] = 0;
   out_7439668240279836342[168] = 0;
   out_7439668240279836342[169] = 0;
   out_7439668240279836342[170] = 0;
   out_7439668240279836342[171] = 1;
   out_7439668240279836342[172] = 0;
   out_7439668240279836342[173] = 0;
   out_7439668240279836342[174] = 0;
   out_7439668240279836342[175] = 0;
   out_7439668240279836342[176] = 0;
   out_7439668240279836342[177] = 0;
   out_7439668240279836342[178] = 0;
   out_7439668240279836342[179] = 0;
   out_7439668240279836342[180] = 0;
   out_7439668240279836342[181] = 0;
   out_7439668240279836342[182] = 0;
   out_7439668240279836342[183] = 0;
   out_7439668240279836342[184] = 0;
   out_7439668240279836342[185] = 0;
   out_7439668240279836342[186] = 0;
   out_7439668240279836342[187] = 0;
   out_7439668240279836342[188] = 0;
   out_7439668240279836342[189] = 0;
   out_7439668240279836342[190] = 1;
   out_7439668240279836342[191] = 0;
   out_7439668240279836342[192] = 0;
   out_7439668240279836342[193] = 0;
   out_7439668240279836342[194] = 0;
   out_7439668240279836342[195] = 0;
   out_7439668240279836342[196] = 0;
   out_7439668240279836342[197] = 0;
   out_7439668240279836342[198] = 0;
   out_7439668240279836342[199] = 0;
   out_7439668240279836342[200] = 0;
   out_7439668240279836342[201] = 0;
   out_7439668240279836342[202] = 0;
   out_7439668240279836342[203] = 0;
   out_7439668240279836342[204] = 0;
   out_7439668240279836342[205] = 0;
   out_7439668240279836342[206] = 0;
   out_7439668240279836342[207] = 0;
   out_7439668240279836342[208] = 0;
   out_7439668240279836342[209] = 1;
   out_7439668240279836342[210] = 0;
   out_7439668240279836342[211] = 0;
   out_7439668240279836342[212] = 0;
   out_7439668240279836342[213] = 0;
   out_7439668240279836342[214] = 0;
   out_7439668240279836342[215] = 0;
   out_7439668240279836342[216] = 0;
   out_7439668240279836342[217] = 0;
   out_7439668240279836342[218] = 0;
   out_7439668240279836342[219] = 0;
   out_7439668240279836342[220] = 0;
   out_7439668240279836342[221] = 0;
   out_7439668240279836342[222] = 0;
   out_7439668240279836342[223] = 0;
   out_7439668240279836342[224] = 0;
   out_7439668240279836342[225] = 0;
   out_7439668240279836342[226] = 0;
   out_7439668240279836342[227] = 0;
   out_7439668240279836342[228] = 1;
   out_7439668240279836342[229] = 0;
   out_7439668240279836342[230] = 0;
   out_7439668240279836342[231] = 0;
   out_7439668240279836342[232] = 0;
   out_7439668240279836342[233] = 0;
   out_7439668240279836342[234] = 0;
   out_7439668240279836342[235] = 0;
   out_7439668240279836342[236] = 0;
   out_7439668240279836342[237] = 0;
   out_7439668240279836342[238] = 0;
   out_7439668240279836342[239] = 0;
   out_7439668240279836342[240] = 0;
   out_7439668240279836342[241] = 0;
   out_7439668240279836342[242] = 0;
   out_7439668240279836342[243] = 0;
   out_7439668240279836342[244] = 0;
   out_7439668240279836342[245] = 0;
   out_7439668240279836342[246] = 0;
   out_7439668240279836342[247] = 1;
   out_7439668240279836342[248] = 0;
   out_7439668240279836342[249] = 0;
   out_7439668240279836342[250] = 0;
   out_7439668240279836342[251] = 0;
   out_7439668240279836342[252] = 0;
   out_7439668240279836342[253] = 0;
   out_7439668240279836342[254] = 0;
   out_7439668240279836342[255] = 0;
   out_7439668240279836342[256] = 0;
   out_7439668240279836342[257] = 0;
   out_7439668240279836342[258] = 0;
   out_7439668240279836342[259] = 0;
   out_7439668240279836342[260] = 0;
   out_7439668240279836342[261] = 0;
   out_7439668240279836342[262] = 0;
   out_7439668240279836342[263] = 0;
   out_7439668240279836342[264] = 0;
   out_7439668240279836342[265] = 0;
   out_7439668240279836342[266] = 1;
   out_7439668240279836342[267] = 0;
   out_7439668240279836342[268] = 0;
   out_7439668240279836342[269] = 0;
   out_7439668240279836342[270] = 0;
   out_7439668240279836342[271] = 0;
   out_7439668240279836342[272] = 0;
   out_7439668240279836342[273] = 0;
   out_7439668240279836342[274] = 0;
   out_7439668240279836342[275] = 0;
   out_7439668240279836342[276] = 0;
   out_7439668240279836342[277] = 0;
   out_7439668240279836342[278] = 0;
   out_7439668240279836342[279] = 0;
   out_7439668240279836342[280] = 0;
   out_7439668240279836342[281] = 0;
   out_7439668240279836342[282] = 0;
   out_7439668240279836342[283] = 0;
   out_7439668240279836342[284] = 0;
   out_7439668240279836342[285] = 1;
   out_7439668240279836342[286] = 0;
   out_7439668240279836342[287] = 0;
   out_7439668240279836342[288] = 0;
   out_7439668240279836342[289] = 0;
   out_7439668240279836342[290] = 0;
   out_7439668240279836342[291] = 0;
   out_7439668240279836342[292] = 0;
   out_7439668240279836342[293] = 0;
   out_7439668240279836342[294] = 0;
   out_7439668240279836342[295] = 0;
   out_7439668240279836342[296] = 0;
   out_7439668240279836342[297] = 0;
   out_7439668240279836342[298] = 0;
   out_7439668240279836342[299] = 0;
   out_7439668240279836342[300] = 0;
   out_7439668240279836342[301] = 0;
   out_7439668240279836342[302] = 0;
   out_7439668240279836342[303] = 0;
   out_7439668240279836342[304] = 1;
   out_7439668240279836342[305] = 0;
   out_7439668240279836342[306] = 0;
   out_7439668240279836342[307] = 0;
   out_7439668240279836342[308] = 0;
   out_7439668240279836342[309] = 0;
   out_7439668240279836342[310] = 0;
   out_7439668240279836342[311] = 0;
   out_7439668240279836342[312] = 0;
   out_7439668240279836342[313] = 0;
   out_7439668240279836342[314] = 0;
   out_7439668240279836342[315] = 0;
   out_7439668240279836342[316] = 0;
   out_7439668240279836342[317] = 0;
   out_7439668240279836342[318] = 0;
   out_7439668240279836342[319] = 0;
   out_7439668240279836342[320] = 0;
   out_7439668240279836342[321] = 0;
   out_7439668240279836342[322] = 0;
   out_7439668240279836342[323] = 1;
}
void h_4(double *state, double *unused, double *out_5360875806741274404) {
   out_5360875806741274404[0] = state[6] + state[9];
   out_5360875806741274404[1] = state[7] + state[10];
   out_5360875806741274404[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5604127731203837594) {
   out_5604127731203837594[0] = 0;
   out_5604127731203837594[1] = 0;
   out_5604127731203837594[2] = 0;
   out_5604127731203837594[3] = 0;
   out_5604127731203837594[4] = 0;
   out_5604127731203837594[5] = 0;
   out_5604127731203837594[6] = 1;
   out_5604127731203837594[7] = 0;
   out_5604127731203837594[8] = 0;
   out_5604127731203837594[9] = 1;
   out_5604127731203837594[10] = 0;
   out_5604127731203837594[11] = 0;
   out_5604127731203837594[12] = 0;
   out_5604127731203837594[13] = 0;
   out_5604127731203837594[14] = 0;
   out_5604127731203837594[15] = 0;
   out_5604127731203837594[16] = 0;
   out_5604127731203837594[17] = 0;
   out_5604127731203837594[18] = 0;
   out_5604127731203837594[19] = 0;
   out_5604127731203837594[20] = 0;
   out_5604127731203837594[21] = 0;
   out_5604127731203837594[22] = 0;
   out_5604127731203837594[23] = 0;
   out_5604127731203837594[24] = 0;
   out_5604127731203837594[25] = 1;
   out_5604127731203837594[26] = 0;
   out_5604127731203837594[27] = 0;
   out_5604127731203837594[28] = 1;
   out_5604127731203837594[29] = 0;
   out_5604127731203837594[30] = 0;
   out_5604127731203837594[31] = 0;
   out_5604127731203837594[32] = 0;
   out_5604127731203837594[33] = 0;
   out_5604127731203837594[34] = 0;
   out_5604127731203837594[35] = 0;
   out_5604127731203837594[36] = 0;
   out_5604127731203837594[37] = 0;
   out_5604127731203837594[38] = 0;
   out_5604127731203837594[39] = 0;
   out_5604127731203837594[40] = 0;
   out_5604127731203837594[41] = 0;
   out_5604127731203837594[42] = 0;
   out_5604127731203837594[43] = 0;
   out_5604127731203837594[44] = 1;
   out_5604127731203837594[45] = 0;
   out_5604127731203837594[46] = 0;
   out_5604127731203837594[47] = 1;
   out_5604127731203837594[48] = 0;
   out_5604127731203837594[49] = 0;
   out_5604127731203837594[50] = 0;
   out_5604127731203837594[51] = 0;
   out_5604127731203837594[52] = 0;
   out_5604127731203837594[53] = 0;
}
void h_10(double *state, double *unused, double *out_4540478366959744077) {
   out_4540478366959744077[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4540478366959744077[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4540478366959744077[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4521937472762374184) {
   out_4521937472762374184[0] = 0;
   out_4521937472762374184[1] = 9.8100000000000005*cos(state[1]);
   out_4521937472762374184[2] = 0;
   out_4521937472762374184[3] = 0;
   out_4521937472762374184[4] = -state[8];
   out_4521937472762374184[5] = state[7];
   out_4521937472762374184[6] = 0;
   out_4521937472762374184[7] = state[5];
   out_4521937472762374184[8] = -state[4];
   out_4521937472762374184[9] = 0;
   out_4521937472762374184[10] = 0;
   out_4521937472762374184[11] = 0;
   out_4521937472762374184[12] = 1;
   out_4521937472762374184[13] = 0;
   out_4521937472762374184[14] = 0;
   out_4521937472762374184[15] = 1;
   out_4521937472762374184[16] = 0;
   out_4521937472762374184[17] = 0;
   out_4521937472762374184[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4521937472762374184[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4521937472762374184[20] = 0;
   out_4521937472762374184[21] = state[8];
   out_4521937472762374184[22] = 0;
   out_4521937472762374184[23] = -state[6];
   out_4521937472762374184[24] = -state[5];
   out_4521937472762374184[25] = 0;
   out_4521937472762374184[26] = state[3];
   out_4521937472762374184[27] = 0;
   out_4521937472762374184[28] = 0;
   out_4521937472762374184[29] = 0;
   out_4521937472762374184[30] = 0;
   out_4521937472762374184[31] = 1;
   out_4521937472762374184[32] = 0;
   out_4521937472762374184[33] = 0;
   out_4521937472762374184[34] = 1;
   out_4521937472762374184[35] = 0;
   out_4521937472762374184[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4521937472762374184[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4521937472762374184[38] = 0;
   out_4521937472762374184[39] = -state[7];
   out_4521937472762374184[40] = state[6];
   out_4521937472762374184[41] = 0;
   out_4521937472762374184[42] = state[4];
   out_4521937472762374184[43] = -state[3];
   out_4521937472762374184[44] = 0;
   out_4521937472762374184[45] = 0;
   out_4521937472762374184[46] = 0;
   out_4521937472762374184[47] = 0;
   out_4521937472762374184[48] = 0;
   out_4521937472762374184[49] = 0;
   out_4521937472762374184[50] = 1;
   out_4521937472762374184[51] = 0;
   out_4521937472762374184[52] = 0;
   out_4521937472762374184[53] = 1;
}
void h_13(double *state, double *unused, double *out_6919871191790631617) {
   out_6919871191790631617[0] = state[3];
   out_6919871191790631617[1] = state[4];
   out_6919871191790631617[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1770372267901313570) {
   out_1770372267901313570[0] = 0;
   out_1770372267901313570[1] = 0;
   out_1770372267901313570[2] = 0;
   out_1770372267901313570[3] = 1;
   out_1770372267901313570[4] = 0;
   out_1770372267901313570[5] = 0;
   out_1770372267901313570[6] = 0;
   out_1770372267901313570[7] = 0;
   out_1770372267901313570[8] = 0;
   out_1770372267901313570[9] = 0;
   out_1770372267901313570[10] = 0;
   out_1770372267901313570[11] = 0;
   out_1770372267901313570[12] = 0;
   out_1770372267901313570[13] = 0;
   out_1770372267901313570[14] = 0;
   out_1770372267901313570[15] = 0;
   out_1770372267901313570[16] = 0;
   out_1770372267901313570[17] = 0;
   out_1770372267901313570[18] = 0;
   out_1770372267901313570[19] = 0;
   out_1770372267901313570[20] = 0;
   out_1770372267901313570[21] = 0;
   out_1770372267901313570[22] = 1;
   out_1770372267901313570[23] = 0;
   out_1770372267901313570[24] = 0;
   out_1770372267901313570[25] = 0;
   out_1770372267901313570[26] = 0;
   out_1770372267901313570[27] = 0;
   out_1770372267901313570[28] = 0;
   out_1770372267901313570[29] = 0;
   out_1770372267901313570[30] = 0;
   out_1770372267901313570[31] = 0;
   out_1770372267901313570[32] = 0;
   out_1770372267901313570[33] = 0;
   out_1770372267901313570[34] = 0;
   out_1770372267901313570[35] = 0;
   out_1770372267901313570[36] = 0;
   out_1770372267901313570[37] = 0;
   out_1770372267901313570[38] = 0;
   out_1770372267901313570[39] = 0;
   out_1770372267901313570[40] = 0;
   out_1770372267901313570[41] = 1;
   out_1770372267901313570[42] = 0;
   out_1770372267901313570[43] = 0;
   out_1770372267901313570[44] = 0;
   out_1770372267901313570[45] = 0;
   out_1770372267901313570[46] = 0;
   out_1770372267901313570[47] = 0;
   out_1770372267901313570[48] = 0;
   out_1770372267901313570[49] = 0;
   out_1770372267901313570[50] = 0;
   out_1770372267901313570[51] = 0;
   out_1770372267901313570[52] = 0;
   out_1770372267901313570[53] = 0;
}
void h_14(double *state, double *unused, double *out_2250614527328198032) {
   out_2250614527328198032[0] = state[6];
   out_2250614527328198032[1] = state[7];
   out_2250614527328198032[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2521339298908465298) {
   out_2521339298908465298[0] = 0;
   out_2521339298908465298[1] = 0;
   out_2521339298908465298[2] = 0;
   out_2521339298908465298[3] = 0;
   out_2521339298908465298[4] = 0;
   out_2521339298908465298[5] = 0;
   out_2521339298908465298[6] = 1;
   out_2521339298908465298[7] = 0;
   out_2521339298908465298[8] = 0;
   out_2521339298908465298[9] = 0;
   out_2521339298908465298[10] = 0;
   out_2521339298908465298[11] = 0;
   out_2521339298908465298[12] = 0;
   out_2521339298908465298[13] = 0;
   out_2521339298908465298[14] = 0;
   out_2521339298908465298[15] = 0;
   out_2521339298908465298[16] = 0;
   out_2521339298908465298[17] = 0;
   out_2521339298908465298[18] = 0;
   out_2521339298908465298[19] = 0;
   out_2521339298908465298[20] = 0;
   out_2521339298908465298[21] = 0;
   out_2521339298908465298[22] = 0;
   out_2521339298908465298[23] = 0;
   out_2521339298908465298[24] = 0;
   out_2521339298908465298[25] = 1;
   out_2521339298908465298[26] = 0;
   out_2521339298908465298[27] = 0;
   out_2521339298908465298[28] = 0;
   out_2521339298908465298[29] = 0;
   out_2521339298908465298[30] = 0;
   out_2521339298908465298[31] = 0;
   out_2521339298908465298[32] = 0;
   out_2521339298908465298[33] = 0;
   out_2521339298908465298[34] = 0;
   out_2521339298908465298[35] = 0;
   out_2521339298908465298[36] = 0;
   out_2521339298908465298[37] = 0;
   out_2521339298908465298[38] = 0;
   out_2521339298908465298[39] = 0;
   out_2521339298908465298[40] = 0;
   out_2521339298908465298[41] = 0;
   out_2521339298908465298[42] = 0;
   out_2521339298908465298[43] = 0;
   out_2521339298908465298[44] = 1;
   out_2521339298908465298[45] = 0;
   out_2521339298908465298[46] = 0;
   out_2521339298908465298[47] = 0;
   out_2521339298908465298[48] = 0;
   out_2521339298908465298[49] = 0;
   out_2521339298908465298[50] = 0;
   out_2521339298908465298[51] = 0;
   out_2521339298908465298[52] = 0;
   out_2521339298908465298[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7933576979540076638) {
  err_fun(nom_x, delta_x, out_7933576979540076638);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5065143061833041119) {
  inv_err_fun(nom_x, true_x, out_5065143061833041119);
}
void pose_H_mod_fun(double *state, double *out_4406180249320939490) {
  H_mod_fun(state, out_4406180249320939490);
}
void pose_f_fun(double *state, double dt, double *out_5789342857202452257) {
  f_fun(state,  dt, out_5789342857202452257);
}
void pose_F_fun(double *state, double dt, double *out_7439668240279836342) {
  F_fun(state,  dt, out_7439668240279836342);
}
void pose_h_4(double *state, double *unused, double *out_5360875806741274404) {
  h_4(state, unused, out_5360875806741274404);
}
void pose_H_4(double *state, double *unused, double *out_5604127731203837594) {
  H_4(state, unused, out_5604127731203837594);
}
void pose_h_10(double *state, double *unused, double *out_4540478366959744077) {
  h_10(state, unused, out_4540478366959744077);
}
void pose_H_10(double *state, double *unused, double *out_4521937472762374184) {
  H_10(state, unused, out_4521937472762374184);
}
void pose_h_13(double *state, double *unused, double *out_6919871191790631617) {
  h_13(state, unused, out_6919871191790631617);
}
void pose_H_13(double *state, double *unused, double *out_1770372267901313570) {
  H_13(state, unused, out_1770372267901313570);
}
void pose_h_14(double *state, double *unused, double *out_2250614527328198032) {
  h_14(state, unused, out_2250614527328198032);
}
void pose_H_14(double *state, double *unused, double *out_2521339298908465298) {
  H_14(state, unused, out_2521339298908465298);
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

#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8001680306801626526) {
   out_8001680306801626526[0] = delta_x[0] + nom_x[0];
   out_8001680306801626526[1] = delta_x[1] + nom_x[1];
   out_8001680306801626526[2] = delta_x[2] + nom_x[2];
   out_8001680306801626526[3] = delta_x[3] + nom_x[3];
   out_8001680306801626526[4] = delta_x[4] + nom_x[4];
   out_8001680306801626526[5] = delta_x[5] + nom_x[5];
   out_8001680306801626526[6] = delta_x[6] + nom_x[6];
   out_8001680306801626526[7] = delta_x[7] + nom_x[7];
   out_8001680306801626526[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1068882163142728924) {
   out_1068882163142728924[0] = -nom_x[0] + true_x[0];
   out_1068882163142728924[1] = -nom_x[1] + true_x[1];
   out_1068882163142728924[2] = -nom_x[2] + true_x[2];
   out_1068882163142728924[3] = -nom_x[3] + true_x[3];
   out_1068882163142728924[4] = -nom_x[4] + true_x[4];
   out_1068882163142728924[5] = -nom_x[5] + true_x[5];
   out_1068882163142728924[6] = -nom_x[6] + true_x[6];
   out_1068882163142728924[7] = -nom_x[7] + true_x[7];
   out_1068882163142728924[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6531048219085982157) {
   out_6531048219085982157[0] = 1.0;
   out_6531048219085982157[1] = 0.0;
   out_6531048219085982157[2] = 0.0;
   out_6531048219085982157[3] = 0.0;
   out_6531048219085982157[4] = 0.0;
   out_6531048219085982157[5] = 0.0;
   out_6531048219085982157[6] = 0.0;
   out_6531048219085982157[7] = 0.0;
   out_6531048219085982157[8] = 0.0;
   out_6531048219085982157[9] = 0.0;
   out_6531048219085982157[10] = 1.0;
   out_6531048219085982157[11] = 0.0;
   out_6531048219085982157[12] = 0.0;
   out_6531048219085982157[13] = 0.0;
   out_6531048219085982157[14] = 0.0;
   out_6531048219085982157[15] = 0.0;
   out_6531048219085982157[16] = 0.0;
   out_6531048219085982157[17] = 0.0;
   out_6531048219085982157[18] = 0.0;
   out_6531048219085982157[19] = 0.0;
   out_6531048219085982157[20] = 1.0;
   out_6531048219085982157[21] = 0.0;
   out_6531048219085982157[22] = 0.0;
   out_6531048219085982157[23] = 0.0;
   out_6531048219085982157[24] = 0.0;
   out_6531048219085982157[25] = 0.0;
   out_6531048219085982157[26] = 0.0;
   out_6531048219085982157[27] = 0.0;
   out_6531048219085982157[28] = 0.0;
   out_6531048219085982157[29] = 0.0;
   out_6531048219085982157[30] = 1.0;
   out_6531048219085982157[31] = 0.0;
   out_6531048219085982157[32] = 0.0;
   out_6531048219085982157[33] = 0.0;
   out_6531048219085982157[34] = 0.0;
   out_6531048219085982157[35] = 0.0;
   out_6531048219085982157[36] = 0.0;
   out_6531048219085982157[37] = 0.0;
   out_6531048219085982157[38] = 0.0;
   out_6531048219085982157[39] = 0.0;
   out_6531048219085982157[40] = 1.0;
   out_6531048219085982157[41] = 0.0;
   out_6531048219085982157[42] = 0.0;
   out_6531048219085982157[43] = 0.0;
   out_6531048219085982157[44] = 0.0;
   out_6531048219085982157[45] = 0.0;
   out_6531048219085982157[46] = 0.0;
   out_6531048219085982157[47] = 0.0;
   out_6531048219085982157[48] = 0.0;
   out_6531048219085982157[49] = 0.0;
   out_6531048219085982157[50] = 1.0;
   out_6531048219085982157[51] = 0.0;
   out_6531048219085982157[52] = 0.0;
   out_6531048219085982157[53] = 0.0;
   out_6531048219085982157[54] = 0.0;
   out_6531048219085982157[55] = 0.0;
   out_6531048219085982157[56] = 0.0;
   out_6531048219085982157[57] = 0.0;
   out_6531048219085982157[58] = 0.0;
   out_6531048219085982157[59] = 0.0;
   out_6531048219085982157[60] = 1.0;
   out_6531048219085982157[61] = 0.0;
   out_6531048219085982157[62] = 0.0;
   out_6531048219085982157[63] = 0.0;
   out_6531048219085982157[64] = 0.0;
   out_6531048219085982157[65] = 0.0;
   out_6531048219085982157[66] = 0.0;
   out_6531048219085982157[67] = 0.0;
   out_6531048219085982157[68] = 0.0;
   out_6531048219085982157[69] = 0.0;
   out_6531048219085982157[70] = 1.0;
   out_6531048219085982157[71] = 0.0;
   out_6531048219085982157[72] = 0.0;
   out_6531048219085982157[73] = 0.0;
   out_6531048219085982157[74] = 0.0;
   out_6531048219085982157[75] = 0.0;
   out_6531048219085982157[76] = 0.0;
   out_6531048219085982157[77] = 0.0;
   out_6531048219085982157[78] = 0.0;
   out_6531048219085982157[79] = 0.0;
   out_6531048219085982157[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2545992086197038934) {
   out_2545992086197038934[0] = state[0];
   out_2545992086197038934[1] = state[1];
   out_2545992086197038934[2] = state[2];
   out_2545992086197038934[3] = state[3];
   out_2545992086197038934[4] = state[4];
   out_2545992086197038934[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2545992086197038934[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2545992086197038934[7] = state[7];
   out_2545992086197038934[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1857247477970760710) {
   out_1857247477970760710[0] = 1;
   out_1857247477970760710[1] = 0;
   out_1857247477970760710[2] = 0;
   out_1857247477970760710[3] = 0;
   out_1857247477970760710[4] = 0;
   out_1857247477970760710[5] = 0;
   out_1857247477970760710[6] = 0;
   out_1857247477970760710[7] = 0;
   out_1857247477970760710[8] = 0;
   out_1857247477970760710[9] = 0;
   out_1857247477970760710[10] = 1;
   out_1857247477970760710[11] = 0;
   out_1857247477970760710[12] = 0;
   out_1857247477970760710[13] = 0;
   out_1857247477970760710[14] = 0;
   out_1857247477970760710[15] = 0;
   out_1857247477970760710[16] = 0;
   out_1857247477970760710[17] = 0;
   out_1857247477970760710[18] = 0;
   out_1857247477970760710[19] = 0;
   out_1857247477970760710[20] = 1;
   out_1857247477970760710[21] = 0;
   out_1857247477970760710[22] = 0;
   out_1857247477970760710[23] = 0;
   out_1857247477970760710[24] = 0;
   out_1857247477970760710[25] = 0;
   out_1857247477970760710[26] = 0;
   out_1857247477970760710[27] = 0;
   out_1857247477970760710[28] = 0;
   out_1857247477970760710[29] = 0;
   out_1857247477970760710[30] = 1;
   out_1857247477970760710[31] = 0;
   out_1857247477970760710[32] = 0;
   out_1857247477970760710[33] = 0;
   out_1857247477970760710[34] = 0;
   out_1857247477970760710[35] = 0;
   out_1857247477970760710[36] = 0;
   out_1857247477970760710[37] = 0;
   out_1857247477970760710[38] = 0;
   out_1857247477970760710[39] = 0;
   out_1857247477970760710[40] = 1;
   out_1857247477970760710[41] = 0;
   out_1857247477970760710[42] = 0;
   out_1857247477970760710[43] = 0;
   out_1857247477970760710[44] = 0;
   out_1857247477970760710[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1857247477970760710[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1857247477970760710[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1857247477970760710[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1857247477970760710[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1857247477970760710[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1857247477970760710[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1857247477970760710[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1857247477970760710[53] = -9.8000000000000007*dt;
   out_1857247477970760710[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1857247477970760710[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1857247477970760710[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1857247477970760710[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1857247477970760710[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1857247477970760710[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1857247477970760710[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1857247477970760710[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1857247477970760710[62] = 0;
   out_1857247477970760710[63] = 0;
   out_1857247477970760710[64] = 0;
   out_1857247477970760710[65] = 0;
   out_1857247477970760710[66] = 0;
   out_1857247477970760710[67] = 0;
   out_1857247477970760710[68] = 0;
   out_1857247477970760710[69] = 0;
   out_1857247477970760710[70] = 1;
   out_1857247477970760710[71] = 0;
   out_1857247477970760710[72] = 0;
   out_1857247477970760710[73] = 0;
   out_1857247477970760710[74] = 0;
   out_1857247477970760710[75] = 0;
   out_1857247477970760710[76] = 0;
   out_1857247477970760710[77] = 0;
   out_1857247477970760710[78] = 0;
   out_1857247477970760710[79] = 0;
   out_1857247477970760710[80] = 1;
}
void h_25(double *state, double *unused, double *out_4496148941933348904) {
   out_4496148941933348904[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6025713776885685445) {
   out_6025713776885685445[0] = 0;
   out_6025713776885685445[1] = 0;
   out_6025713776885685445[2] = 0;
   out_6025713776885685445[3] = 0;
   out_6025713776885685445[4] = 0;
   out_6025713776885685445[5] = 0;
   out_6025713776885685445[6] = 1;
   out_6025713776885685445[7] = 0;
   out_6025713776885685445[8] = 0;
}
void h_24(double *state, double *unused, double *out_8007957969388563441) {
   out_8007957969388563441[0] = state[4];
   out_8007957969388563441[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7754576896062999514) {
   out_7754576896062999514[0] = 0;
   out_7754576896062999514[1] = 0;
   out_7754576896062999514[2] = 0;
   out_7754576896062999514[3] = 0;
   out_7754576896062999514[4] = 1;
   out_7754576896062999514[5] = 0;
   out_7754576896062999514[6] = 0;
   out_7754576896062999514[7] = 0;
   out_7754576896062999514[8] = 0;
   out_7754576896062999514[9] = 0;
   out_7754576896062999514[10] = 0;
   out_7754576896062999514[11] = 0;
   out_7754576896062999514[12] = 0;
   out_7754576896062999514[13] = 0;
   out_7754576896062999514[14] = 1;
   out_7754576896062999514[15] = 0;
   out_7754576896062999514[16] = 0;
   out_7754576896062999514[17] = 0;
}
void h_30(double *state, double *unused, double *out_7179759905425851776) {
   out_7179759905425851776[0] = state[4];
}
void H_30(double *state, double *unused, double *out_890976564605931310) {
   out_890976564605931310[0] = 0;
   out_890976564605931310[1] = 0;
   out_890976564605931310[2] = 0;
   out_890976564605931310[3] = 0;
   out_890976564605931310[4] = 1;
   out_890976564605931310[5] = 0;
   out_890976564605931310[6] = 0;
   out_890976564605931310[7] = 0;
   out_890976564605931310[8] = 0;
}
void h_26(double *state, double *unused, double *out_2178086637765006131) {
   out_2178086637765006131[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8679526977949809947) {
   out_8679526977949809947[0] = 0;
   out_8679526977949809947[1] = 0;
   out_8679526977949809947[2] = 0;
   out_8679526977949809947[3] = 0;
   out_8679526977949809947[4] = 0;
   out_8679526977949809947[5] = 0;
   out_8679526977949809947[6] = 0;
   out_8679526977949809947[7] = 1;
   out_8679526977949809947[8] = 0;
}
void h_27(double *state, double *unused, double *out_6186596776669029864) {
   out_6186596776669029864[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1283786747194493601) {
   out_1283786747194493601[0] = 0;
   out_1283786747194493601[1] = 0;
   out_1283786747194493601[2] = 0;
   out_1283786747194493601[3] = 1;
   out_1283786747194493601[4] = 0;
   out_1283786747194493601[5] = 0;
   out_1283786747194493601[6] = 0;
   out_1283786747194493601[7] = 0;
   out_1283786747194493601[8] = 0;
}
void h_29(double *state, double *unused, double *out_3763486615776781760) {
   out_3763486615776781760[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1401207908920323494) {
   out_1401207908920323494[0] = 0;
   out_1401207908920323494[1] = 1;
   out_1401207908920323494[2] = 0;
   out_1401207908920323494[3] = 0;
   out_1401207908920323494[4] = 0;
   out_1401207908920323494[5] = 0;
   out_1401207908920323494[6] = 0;
   out_1401207908920323494[7] = 0;
   out_1401207908920323494[8] = 0;
}
void h_28(double *state, double *unused, double *out_1041706713553382327) {
   out_1041706713553382327[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3681191108149207080) {
   out_3681191108149207080[0] = 1;
   out_3681191108149207080[1] = 0;
   out_3681191108149207080[2] = 0;
   out_3681191108149207080[3] = 0;
   out_3681191108149207080[4] = 0;
   out_3681191108149207080[5] = 0;
   out_3681191108149207080[6] = 0;
   out_3681191108149207080[7] = 0;
   out_3681191108149207080[8] = 0;
}
void h_31(double *state, double *unused, double *out_3649238735683682370) {
   out_3649238735683682370[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5995067815008725017) {
   out_5995067815008725017[0] = 0;
   out_5995067815008725017[1] = 0;
   out_5995067815008725017[2] = 0;
   out_5995067815008725017[3] = 0;
   out_5995067815008725017[4] = 0;
   out_5995067815008725017[5] = 0;
   out_5995067815008725017[6] = 0;
   out_5995067815008725017[7] = 0;
   out_5995067815008725017[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8001680306801626526) {
  err_fun(nom_x, delta_x, out_8001680306801626526);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1068882163142728924) {
  inv_err_fun(nom_x, true_x, out_1068882163142728924);
}
void car_H_mod_fun(double *state, double *out_6531048219085982157) {
  H_mod_fun(state, out_6531048219085982157);
}
void car_f_fun(double *state, double dt, double *out_2545992086197038934) {
  f_fun(state,  dt, out_2545992086197038934);
}
void car_F_fun(double *state, double dt, double *out_1857247477970760710) {
  F_fun(state,  dt, out_1857247477970760710);
}
void car_h_25(double *state, double *unused, double *out_4496148941933348904) {
  h_25(state, unused, out_4496148941933348904);
}
void car_H_25(double *state, double *unused, double *out_6025713776885685445) {
  H_25(state, unused, out_6025713776885685445);
}
void car_h_24(double *state, double *unused, double *out_8007957969388563441) {
  h_24(state, unused, out_8007957969388563441);
}
void car_H_24(double *state, double *unused, double *out_7754576896062999514) {
  H_24(state, unused, out_7754576896062999514);
}
void car_h_30(double *state, double *unused, double *out_7179759905425851776) {
  h_30(state, unused, out_7179759905425851776);
}
void car_H_30(double *state, double *unused, double *out_890976564605931310) {
  H_30(state, unused, out_890976564605931310);
}
void car_h_26(double *state, double *unused, double *out_2178086637765006131) {
  h_26(state, unused, out_2178086637765006131);
}
void car_H_26(double *state, double *unused, double *out_8679526977949809947) {
  H_26(state, unused, out_8679526977949809947);
}
void car_h_27(double *state, double *unused, double *out_6186596776669029864) {
  h_27(state, unused, out_6186596776669029864);
}
void car_H_27(double *state, double *unused, double *out_1283786747194493601) {
  H_27(state, unused, out_1283786747194493601);
}
void car_h_29(double *state, double *unused, double *out_3763486615776781760) {
  h_29(state, unused, out_3763486615776781760);
}
void car_H_29(double *state, double *unused, double *out_1401207908920323494) {
  H_29(state, unused, out_1401207908920323494);
}
void car_h_28(double *state, double *unused, double *out_1041706713553382327) {
  h_28(state, unused, out_1041706713553382327);
}
void car_H_28(double *state, double *unused, double *out_3681191108149207080) {
  H_28(state, unused, out_3681191108149207080);
}
void car_h_31(double *state, double *unused, double *out_3649238735683682370) {
  h_31(state, unused, out_3649238735683682370);
}
void car_H_31(double *state, double *unused, double *out_5995067815008725017) {
  H_31(state, unused, out_5995067815008725017);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)

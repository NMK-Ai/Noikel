#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7933576979540076638);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5065143061833041119);
void pose_H_mod_fun(double *state, double *out_4406180249320939490);
void pose_f_fun(double *state, double dt, double *out_5789342857202452257);
void pose_F_fun(double *state, double dt, double *out_7439668240279836342);
void pose_h_4(double *state, double *unused, double *out_5360875806741274404);
void pose_H_4(double *state, double *unused, double *out_5604127731203837594);
void pose_h_10(double *state, double *unused, double *out_4540478366959744077);
void pose_H_10(double *state, double *unused, double *out_4521937472762374184);
void pose_h_13(double *state, double *unused, double *out_6919871191790631617);
void pose_H_13(double *state, double *unused, double *out_1770372267901313570);
void pose_h_14(double *state, double *unused, double *out_2250614527328198032);
void pose_H_14(double *state, double *unused, double *out_2521339298908465298);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}
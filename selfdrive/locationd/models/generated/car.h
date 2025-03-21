#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8001680306801626526);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1068882163142728924);
void car_H_mod_fun(double *state, double *out_6531048219085982157);
void car_f_fun(double *state, double dt, double *out_2545992086197038934);
void car_F_fun(double *state, double dt, double *out_1857247477970760710);
void car_h_25(double *state, double *unused, double *out_4496148941933348904);
void car_H_25(double *state, double *unused, double *out_6025713776885685445);
void car_h_24(double *state, double *unused, double *out_8007957969388563441);
void car_H_24(double *state, double *unused, double *out_7754576896062999514);
void car_h_30(double *state, double *unused, double *out_7179759905425851776);
void car_H_30(double *state, double *unused, double *out_890976564605931310);
void car_h_26(double *state, double *unused, double *out_2178086637765006131);
void car_H_26(double *state, double *unused, double *out_8679526977949809947);
void car_h_27(double *state, double *unused, double *out_6186596776669029864);
void car_H_27(double *state, double *unused, double *out_1283786747194493601);
void car_h_29(double *state, double *unused, double *out_3763486615776781760);
void car_H_29(double *state, double *unused, double *out_1401207908920323494);
void car_h_28(double *state, double *unused, double *out_1041706713553382327);
void car_H_28(double *state, double *unused, double *out_3681191108149207080);
void car_h_31(double *state, double *unused, double *out_3649238735683682370);
void car_H_31(double *state, double *unused, double *out_5995067815008725017);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
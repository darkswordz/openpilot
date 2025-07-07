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
void car_err_fun(double *nom_x, double *delta_x, double *out_4921979020263470919);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5793501166514543589);
void car_H_mod_fun(double *state, double *out_6600467950446601229);
void car_f_fun(double *state, double dt, double *out_6326970151791565085);
void car_F_fun(double *state, double dt, double *out_1427379255351035177);
void car_h_25(double *state, double *unused, double *out_8944009748765760257);
void car_H_25(double *state, double *unused, double *out_6262982565561489149);
void car_h_24(double *state, double *unused, double *out_1034060610014588393);
void car_H_24(double *state, double *unused, double *out_2511909842250681745);
void car_h_30(double *state, double *unused, double *out_9219203811050266146);
void car_H_30(double *state, double *unused, double *out_6133643618418249079);
void car_h_26(double *state, double *unused, double *out_6623134941850587819);
void car_H_26(double *state, double *unused, double *out_2521479246687432925);
void car_h_27(double *state, double *unused, double *out_4501061057282945714);
void car_H_27(double *state, double *unused, double *out_3958880306617824168);
void car_h_29(double *state, double *unused, double *out_6182417759605933461);
void car_H_29(double *state, double *unused, double *out_6643874962732641263);
void car_h_28(double *state, double *unused, double *out_2291181916348786065);
void car_H_28(double *state, double *unused, double *out_4209147851313599386);
void car_h_31(double *state, double *unused, double *out_1006073643680051367);
void car_H_31(double *state, double *unused, double *out_6293628527438449577);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
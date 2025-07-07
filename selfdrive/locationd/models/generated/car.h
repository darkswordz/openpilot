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
void car_err_fun(double *nom_x, double *delta_x, double *out_2909014152569429438);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3506388048039691216);
void car_H_mod_fun(double *state, double *out_3077895882544465700);
void car_f_fun(double *state, double dt, double *out_1552203416377598284);
void car_F_fun(double *state, double dt, double *out_3354320759522276357);
void car_h_25(double *state, double *unused, double *out_7616639442381210710);
void car_H_25(double *state, double *unused, double *out_4027016804572947909);
void car_h_24(double *state, double *unused, double *out_397640950787353078);
void car_H_24(double *state, double *unused, double *out_5191662083067408482);
void car_h_30(double *state, double *unused, double *out_264633208372838475);
void car_H_30(double *state, double *unused, double *out_500679525554660289);
void car_h_26(double *state, double *unused, double *out_710303253309191612);
void car_H_26(double *state, double *unused, double *out_285513485698891685);
void car_h_27(double *state, double *unused, double *out_7013323557704733193);
void car_H_27(double *state, double *unused, double *out_2675442837355085200);
void car_h_29(double *state, double *unused, double *out_6738129495420227304);
void car_H_29(double *state, double *unused, double *out_9551818759731895);
void car_h_28(double *state, double *unused, double *out_7956833410606395628);
void car_H_28(double *state, double *unused, double *out_5072847198309798679);
void car_h_31(double *state, double *unused, double *out_7192655103074318556);
void car_H_31(double *state, double *unused, double *out_340694616534459791);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6941032043484408543);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_753730219599213751);
void car_H_mod_fun(double *state, double *out_7551379231098493241);
void car_f_fun(double *state, double dt, double *out_2372527136668379326);
void car_F_fun(double *state, double dt, double *out_1385423313901720448);
void car_h_25(double *state, double *unused, double *out_1285866181057576823);
void car_H_25(double *state, double *unused, double *out_369958801875366564);
void car_h_24(double *state, double *unused, double *out_609100606795207148);
void car_H_24(double *state, double *unused, double *out_1782987049913775401);
void car_h_30(double *state, double *unused, double *out_1128679512706447678);
void car_H_30(double *state, double *unused, double *out_4157737528252241634);
void car_h_26(double *state, double *unused, double *out_525363628029970161);
void car_H_26(double *state, double *unused, double *out_3371544516998689660);
void car_h_27(double *state, double *unused, double *out_6956004886155136179);
void car_H_27(double *state, double *unused, double *out_6332500840052666545);
void car_h_29(double *state, double *unused, double *out_6130352780367293323);
void car_H_29(double *state, double *unused, double *out_3647506183937849450);
void car_h_28(double *state, double *unused, double *out_2694429723288418297);
void car_H_28(double *state, double *unused, double *out_1683875912372523199);
void car_h_31(double *state, double *unused, double *out_8056701407407927759);
void car_H_31(double *state, double *unused, double *out_3997752619232041136);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
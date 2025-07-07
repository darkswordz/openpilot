#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3178519467950773499);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4057631928554815578);
void pose_H_mod_fun(double *state, double *out_7284952421974239963);
void pose_f_fun(double *state, double dt, double *out_6622003215066724253);
void pose_F_fun(double *state, double dt, double *out_1840911802440980771);
void pose_h_4(double *state, double *unused, double *out_7825755614403114749);
void pose_H_4(double *state, double *unused, double *out_2423595419652322515);
void pose_h_10(double *state, double *unused, double *out_4958115583477493940);
void pose_H_10(double *state, double *unused, double *out_3173840665802663140);
void pose_h_13(double *state, double *unused, double *out_5148403869590084901);
void pose_H_13(double *state, double *unused, double *out_788678405680010286);
void pose_h_14(double *state, double *unused, double *out_6092356580819784195);
void pose_H_14(double *state, double *unused, double *out_2858711946297206114);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}